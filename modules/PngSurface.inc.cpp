// ========== libpng PNG → DirectDraw 离屏 Surface → Blt 到 BackBuffer ==========
//
// 渲染管线：
//   PNG 文件 → libpng 解码 RGBA8 → 创建 DD 离屏 surface → Lock 写入像素 → Blt 到 backbuffer
//
// 完全绕开 _Pcx8_/_Pcx16_ 体系和 HD_TC2 hook，
// 使用 DirectDraw 原生 Blt 进行格式转换和 blit。

#include <png.h>

// ---- 导出的 surface 句柄 ----
// 内部包含一个 DirectDraw 离屏 surface，像素已在 LoadPng 时写入。
struct PngSupportSurface
{
    LPDIRECTDRAWSURFACE dd_surface;
    int width;
    int height;
};

// ---- API 版本 ----
extern "C" __declspec(dllexport) int __stdcall PngSupport_GetApiVersion()
{
    return 3;
}

extern "C" __declspec(dllexport) const char* __stdcall PngSupport_GetName()
{
    return "PngSupport(libpng+DDOffscreen)";
}

// ---- libpng 辅助 ----
static bool PngSupport_ReadFileSignature(FILE* fp)
{
    unsigned char sig[8];
    if (fread(sig, 1, 8, fp) != 8) return false;
    return png_sig_cmp(sig, 0, 8) == 0;
}

// ---- DD 像素格式辅助 ----
static unsigned MaskShift(DWORD mask)
{
    if (!mask) return 0;
    unsigned s = 0;
    while ((mask & 1) == 0) { mask >>= 1; ++s; }
    return s;
}

static unsigned MaskBits(DWORD mask)
{
    unsigned b = 0;
    while (mask) { if (mask & 1) ++b; mask >>= 1; }
    return b;
}

static DWORD PackPixel(unsigned char r, unsigned char g, unsigned char b,
                       DWORD rmask, DWORD gmask, DWORD bmask)
{
    unsigned rs = MaskShift(rmask), gs = MaskShift(gmask), bs = MaskShift(bmask);
    unsigned rb = MaskBits(rmask), gb = MaskBits(gmask), bb = MaskBits(bmask);
    DWORD rv = rb ? (((DWORD)r * ((1u << rb) - 1u) / 255u) << rs) : 0;
    DWORD gv = gb ? (((DWORD)g * ((1u << gb) - 1u) / 255u) << gs) : 0;
    DWORD bv = bb ? (((DWORD)b * ((1u << bb) - 1u) / 255u) << bs) : 0;
    return (rv & rmask) | (gv & gmask) | (bv & bmask);
}

// ---- 核心：加载 PNG → 创建离屏 DD surface → 写入像素 ----
extern "C" __declspec(dllexport) PngSupportSurface* __stdcall PngSupport_LoadPng(const char* path)
{
    if (!path || !path[0]) return nullptr;

    // === 1. libpng 解码 ===
    FILE* fp = nullptr;
    fopen_s(&fp, path, "rb");
    if (!fp) {
        WriteLog("LoadPng: open failed: %s", path);
        return nullptr;
    }

    if (!PngSupport_ReadFileSignature(fp)) {
        fclose(fp);
        WriteLog("LoadPng: not a PNG: %s", path);
        return nullptr;
    }

    png_structp png = png_create_read_struct(PNG_LIBPNG_VER_STRING, nullptr, nullptr, nullptr);
    if (!png) { fclose(fp); return nullptr; }

    png_infop info = png_create_info_struct(png);
    if (!info) {
        png_destroy_read_struct(&png, nullptr, nullptr);
        fclose(fp);
        return nullptr;
    }

    if (setjmp(png_jmpbuf(png))) {
        png_destroy_read_struct(&png, &info, nullptr);
        fclose(fp);
        WriteLog("LoadPng: libpng error: %s", path);
        return nullptr;
    }

    png_init_io(png, fp);
    png_set_sig_bytes(png, 8);
    png_read_info(png, info);

    png_uint_32 w = png_get_image_width(png, info);
    png_uint_32 h = png_get_image_height(png, info);
    int color_type = png_get_color_type(png, info);
    int bit_depth = png_get_bit_depth(png, info);

    if (w == 0 || h == 0 || w > 4096 || h > 4096) {
        png_destroy_read_struct(&png, &info, nullptr);
        fclose(fp);
        WriteLog("LoadPng: invalid size %ux%u: %s", (unsigned)w, (unsigned)h, path);
        return nullptr;
    }

    // 统一输出 RGBA8
    if (bit_depth == 16) png_set_strip_16(png);
    if (color_type == PNG_COLOR_TYPE_PALETTE) png_set_palette_to_rgb(png);
    if (color_type == PNG_COLOR_TYPE_GRAY && bit_depth < 8) png_set_expand_gray_1_2_4_to_8(png);
    if (png_get_valid(png, info, PNG_INFO_tRNS)) png_set_tRNS_to_alpha(png);
    if (color_type == PNG_COLOR_TYPE_GRAY || color_type == PNG_COLOR_TYPE_GRAY_ALPHA) png_set_gray_to_rgb(png);
    if (!(color_type & PNG_COLOR_MASK_ALPHA)) png_set_add_alpha(png, 0xFF, PNG_FILLER_AFTER);

    png_read_update_info(png, info);

    png_size_t rowbytes = png_get_rowbytes(png, info);
    unsigned char* rgba = (unsigned char*)HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, rowbytes * h);
    png_bytep* rows = (png_bytep*)HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, sizeof(png_bytep) * h);
    if (!rgba || !rows) {
        if (rgba) HeapFree(GetProcessHeap(), 0, rgba);
        if (rows) HeapFree(GetProcessHeap(), 0, rows);
        png_destroy_read_struct(&png, &info, nullptr);
        fclose(fp);
        WriteLog("LoadPng: alloc failed: %s", path);
        return nullptr;
    }
    for (png_uint_32 y = 0; y < h; ++y) rows[y] = rgba + y * rowbytes;

    png_read_image(png, rows);
    png_read_end(png, nullptr);

    HeapFree(GetProcessHeap(), 0, rows);
    png_destroy_read_struct(&png, &info, nullptr);
    fclose(fp);

    // === 2. 创建离屏 DirectDraw surface ===
    if (!o_DD) {
        WriteLog("LoadPng: o_DD is null");
        HeapFree(GetProcessHeap(), 0, rgba);
        return nullptr;
    }

    DDSURFACEDESC ddsd;
    memset(&ddsd, 0, sizeof(ddsd));
    ddsd.dwSize = sizeof(ddsd);
    ddsd.dwFlags = DDSD_CAPS | DDSD_WIDTH | DDSD_HEIGHT;
    ddsd.ddsCaps.dwCaps = DDSCAPS_OFFSCREENPLAIN;
    ddsd.dwWidth = w;
    ddsd.dwHeight = h;

    LPDIRECTDRAWSURFACE dd_surf = nullptr;
    HRESULT hr = o_DD->CreateSurface(&ddsd, &dd_surf, nullptr);
    if (FAILED(hr) || !dd_surf) {
        WriteLog("LoadPng: CreateSurface failed hr=0x%08X w=%u h=%u: %s", (unsigned)hr, (unsigned)w, (unsigned)h, path);
        HeapFree(GetProcessHeap(), 0, rgba);
        return nullptr;
    }

    // === 3. Lock surface，查询像素格式，写入 ===
    DDSURFACEDESC lock_desc;
    memset(&lock_desc, 0, sizeof(lock_desc));
    lock_desc.dwSize = sizeof(lock_desc);
    hr = dd_surf->Lock(nullptr, &lock_desc, DDLOCK_WAIT | DDLOCK_SURFACEMEMORYPTR, nullptr);
    if (FAILED(hr)) {
        WriteLog("LoadPng: Lock failed hr=0x%08X: %s", (unsigned)hr, path);
        dd_surf->Release();
        HeapFree(GetProcessHeap(), 0, rgba);
        return nullptr;
    }

    DDPIXELFORMAT pf;
    memset(&pf, 0, sizeof(pf));
    pf.dwSize = sizeof(pf);
    dd_surf->GetPixelFormat(&pf);

    int bpp = (int)pf.dwRGBBitCount;
    DWORD rmask = pf.dwRBitMask;
    DWORD gmask = pf.dwGBitMask;
    DWORD bmask = pf.dwBBitMask;

    WriteLog("LoadPng: surface %ux%u bpp=%d R=0x%08X G=0x%08X B=0x%08X pitch=%d: %s",
        (unsigned)w, (unsigned)h, bpp, (unsigned)rmask, (unsigned)gmask, (unsigned)bmask,
        lock_desc.lPitch, path);

    for (png_uint_32 y = 0; y < h; ++y) {
        unsigned char* src_row = rgba + y * rowbytes;
        unsigned char* dst_row = (unsigned char*)lock_desc.lpSurface + y * lock_desc.lPitch;

        for (png_uint_32 x = 0; x < w; ++x) {
            unsigned char* px = src_row + x * 4;
            unsigned char r = px[0], g = px[1], b = px[2];
            // alpha 忽略——离屏 surface 不支持 alpha blending，Blt 时整图不透明

            if (bpp == 16) {
                unsigned short* d = (unsigned short*)(dst_row + x * 2);
                *d = (unsigned short)PackPixel(r, g, b, rmask, gmask, bmask);
            } else if (bpp == 32) {
                DWORD* d = (DWORD*)(dst_row + x * 4);
                *d = PackPixel(r, g, b, rmask, gmask, bmask);
            } else if (bpp == 24) {
                DWORD packed = PackPixel(r, g, b, rmask, gmask, bmask);
                dst_row[x * 3] = (unsigned char)(packed);
                dst_row[x * 3 + 1] = (unsigned char)(packed >> 8);
                dst_row[x * 3 + 2] = (unsigned char)(packed >> 16);
            }
        }
    }

    dd_surf->Unlock(nullptr);
    HeapFree(GetProcessHeap(), 0, rgba);

    // === 4. 返回 surface 句柄 ===
    PngSupportSurface* surface = (PngSupportSurface*)HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, sizeof(PngSupportSurface));
    if (!surface) {
        dd_surf->Release();
        WriteLog("LoadPng: surface struct alloc failed: %s", path);
        return nullptr;
    }
    surface->dd_surface = dd_surf;
    surface->width = (int)w;
    surface->height = (int)h;

    WriteLog("LoadPng: ok %dx%d: %s", surface->width, surface->height, path);
    return surface;
}

// ---- 释放 ----
extern "C" __declspec(dllexport) void __stdcall PngSupport_Free(PngSupportSurface* surface)
{
    if (!surface) return;
    if (surface->dd_surface) {
        surface->dd_surface->Release();
        surface->dd_surface = nullptr;
    }
    HeapFree(GetProcessHeap(), 0, surface);
}

// ---- 通过 Blt 绘制到 backbuffer ----
extern "C" __declspec(dllexport) int __stdcall PngSupport_DrawToBackBuffer(
    PngSupportSurface* surface,
    int src_x, int src_y,
    int width, int height,
    int dst_x, int dst_y,
    int alpha_mode)
{
    if (!surface || !surface->dd_surface || !o_DDSurfaceBackBuffer) return 0;
    if (src_x < 0 || src_y < 0 || width <= 0 || height <= 0) return 0;
    if (src_x + width > surface->width) width = surface->width - src_x;
    if (src_y + height > surface->height) height = surface->height - src_y;
    if (width <= 0 || height <= 0) return 0;

    RECT src_rect;
    src_rect.left = src_x;
    src_rect.top = src_y;
    src_rect.right = src_x + width;
    src_rect.bottom = src_y + height;

    RECT dst_rect;
    dst_rect.left = dst_x;
    dst_rect.top = dst_y;
    dst_rect.right = dst_x + width;
    dst_rect.bottom = dst_y + height;

    // alpha_mode 当前被忽略——DD Blt 不支持逐像素 alpha blending。
    // 0 = 不透明绘制（默认），1 = 原计划 alpha 但当前实现等同 0。
    DWORD flags = DDBLT_WAIT;

    HRESULT hr = o_DDSurfaceBackBuffer->Blt(&dst_rect, surface->dd_surface, &src_rect, flags, nullptr);
    if (FAILED(hr)) {
        WriteLog("DrawToBackBuffer: Blt failed hr=0x%08X", (unsigned)hr);
        return 0;
    }
    return 1;
}

extern "C" __declspec(dllexport) int __stdcall PngSupport_DrawToBackBufferFull(
    PngSupportSurface* surface,
    int dst_x, int dst_y,
    int alpha_mode)
{
    if (!surface) return 0;
    return PngSupport_DrawToBackBuffer(surface, 0, 0, surface->width, surface->height, dst_x, dst_y, alpha_mode);
}
