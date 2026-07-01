// ========== libpng PNG → RGBA Surface → DirectDraw BackBuffer ==========

#include <png.h>

struct PngSupportSurface
{
    int width;
    int height;
    int stride_bytes; // RGBA stride
    unsigned char* rgba;
};

static unsigned short PngSupport_Rgb565(unsigned char r, unsigned char g, unsigned char b)
{
    return (unsigned short)((((int)r >> 3) << 11) | (((int)g >> 2) << 5) | (((int)b) >> 3));
}

static unsigned short PngSupport_Rgb555(unsigned char r, unsigned char g, unsigned char b)
{
    return (unsigned short)((((int)r >> 3) << 10) | (((int)g >> 3) << 5) | (((int)b) >> 3));
}

extern "C" __declspec(dllexport) int __stdcall PngSupport_GetApiVersion()
{
    return 2;
}

extern "C" __declspec(dllexport) const char* __stdcall PngSupport_GetName()
{
    return "PngSupport(libpng+DirectDraw)";
}

static bool PngSupport_ReadFileSignature(FILE* fp)
{
    unsigned char sig[8];
    if (fread(sig, 1, 8, fp) != 8) return false;
    return png_sig_cmp(sig, 0, 8) == 0;
}

extern "C" __declspec(dllexport) PngSupportSurface* __stdcall PngSupport_LoadPng(const char* path)
{
    if (!path || !path[0]) return nullptr;

    FILE* fp = nullptr;
    fopen_s(&fp, path, "rb");
    if (!fp) {
        WriteLog("LoadPng open failed: %s", path);
        return nullptr;
    }

    if (!PngSupport_ReadFileSignature(fp)) {
        fclose(fp);
        WriteLog("LoadPng not a PNG: %s", path);
        return nullptr;
    }

    png_structp png = png_create_read_struct(PNG_LIBPNG_VER_STRING, nullptr, nullptr, nullptr);
    if (!png) {
        fclose(fp);
        WriteLog("png_create_read_struct failed: %s", path);
        return nullptr;
    }

    png_infop info = png_create_info_struct(png);
    if (!info) {
        png_destroy_read_struct(&png, nullptr, nullptr);
        fclose(fp);
        WriteLog("png_create_info_struct failed: %s", path);
        return nullptr;
    }

    if (setjmp(png_jmpbuf(png))) {
        png_destroy_read_struct(&png, &info, nullptr);
        fclose(fp);
        WriteLog("libpng read error: %s", path);
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
        WriteLog("LoadPng invalid size: %s size=%ux%u", path, (unsigned)w, (unsigned)h);
        return nullptr;
    }

    // 统一输出 RGBA8。
    if (bit_depth == 16) png_set_strip_16(png);
    if (color_type == PNG_COLOR_TYPE_PALETTE) png_set_palette_to_rgb(png);
    if (color_type == PNG_COLOR_TYPE_GRAY && bit_depth < 8) png_set_expand_gray_1_2_4_to_8(png);
    if (png_get_valid(png, info, PNG_INFO_tRNS)) png_set_tRNS_to_alpha(png);
    if (color_type == PNG_COLOR_TYPE_GRAY || color_type == PNG_COLOR_TYPE_GRAY_ALPHA) png_set_gray_to_rgb(png);
    if (!(color_type & PNG_COLOR_MASK_ALPHA)) png_set_add_alpha(png, 0xFF, PNG_FILLER_AFTER);

    png_read_update_info(png, info);

    png_size_t rowbytes = png_get_rowbytes(png, info);
    unsigned char* rgba = (unsigned char*)HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, rowbytes * h);
    if (!rgba) {
        png_destroy_read_struct(&png, &info, nullptr);
        fclose(fp);
        WriteLog("LoadPng rgba alloc failed: %s", path);
        return nullptr;
    }

    png_bytep* rows = (png_bytep*)HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, sizeof(png_bytep) * h);
    if (!rows) {
        HeapFree(GetProcessHeap(), 0, rgba);
        png_destroy_read_struct(&png, &info, nullptr);
        fclose(fp);
        WriteLog("LoadPng rows alloc failed: %s", path);
        return nullptr;
    }
    for (png_uint_32 y = 0; y < h; ++y) rows[y] = rgba + y * rowbytes;

    png_read_image(png, rows);
    png_read_end(png, nullptr);

    HeapFree(GetProcessHeap(), 0, rows);
    png_destroy_read_struct(&png, &info, nullptr);
    fclose(fp);

    PngSupportSurface* surface = (PngSupportSurface*)HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, sizeof(PngSupportSurface));
    if (!surface) {
        HeapFree(GetProcessHeap(), 0, rgba);
        return nullptr;
    }
    surface->width = (int)w;
    surface->height = (int)h;
    surface->stride_bytes = (int)rowbytes;
    surface->rgba = rgba;

    WriteLog("LoadPng ok: %s size=%dx%d stride=%d libpng=%s", path, surface->width, surface->height, surface->stride_bytes, PNG_LIBPNG_VER_STRING);
    return surface;
}

extern "C" __declspec(dllexport) void __stdcall PngSupport_Free(PngSupportSurface* surface)
{
    if (!surface) return;
    if (surface->rgba) HeapFree(GetProcessHeap(), 0, surface->rgba);
    HeapFree(GetProcessHeap(), 0, surface);
}

static unsigned PngSupport_MaskShift(DWORD mask)
{
    if (!mask) return 0;
    unsigned s = 0;
    while ((mask & 1) == 0) { mask >>= 1; ++s; }
    return s;
}

static unsigned PngSupport_MaskBits(DWORD mask)
{
    unsigned b = 0;
    while (mask) { if (mask & 1) ++b; mask >>= 1; }
    return b;
}

static DWORD PngSupport_PackByMasks(unsigned char r, unsigned char g, unsigned char b, DWORD rmask, DWORD gmask, DWORD bmask)
{
    unsigned rs = PngSupport_MaskShift(rmask), gs = PngSupport_MaskShift(gmask), bs = PngSupport_MaskShift(bmask);
    unsigned rb = PngSupport_MaskBits(rmask), gb = PngSupport_MaskBits(gmask), bb = PngSupport_MaskBits(bmask);
    DWORD rv = rb ? (((DWORD)r * ((1u << rb) - 1) / 255u) << rs) : 0;
    DWORD gv = gb ? (((DWORD)g * ((1u << gb) - 1) / 255u) << gs) : 0;
    DWORD bv = bb ? (((DWORD)b * ((1u << bb) - 1) / 255u) << bs) : 0;
    return (rv & rmask) | (gv & gmask) | (bv & bmask);
}

extern "C" __declspec(dllexport) int __stdcall PngSupport_DrawToBackBuffer(
    PngSupportSurface* surface,
    int src_x,
    int src_y,
    int width,
    int height,
    int dst_x,
    int dst_y,
    int alpha_mode)
{
    if (!surface || !surface->rgba || !o_DDSurfaceBackBuffer) return 0;
    if (src_x < 0 || src_y < 0 || width <= 0 || height <= 0) return 0;
    if (src_x + width > surface->width) width = surface->width - src_x;
    if (src_y + height > surface->height) height = surface->height - src_y;
    if (width <= 0 || height <= 0) return 0;

    DDSURFACEDESC desc;
    memset(&desc, 0, sizeof(desc));
    desc.dwSize = sizeof(desc);

    HRESULT hr = o_DDSurfaceBackBuffer->Lock(nullptr, &desc, DDLOCK_WAIT, nullptr);
    if (hr == DDERR_SURFACELOST) {
        o_DDSurfaceBackBuffer->Restore();
        hr = o_DDSurfaceBackBuffer->Lock(nullptr, &desc, DDLOCK_WAIT, nullptr);
    }
    if (FAILED(hr)) {
        WriteLog("DrawToBackBuffer Lock failed: hr=0x%08X", (unsigned)hr);
        return 0;
    }

    int bpp = (int)desc.ddpfPixelFormat.dwRGBBitCount;
    DWORD rmask = desc.ddpfPixelFormat.dwRBitMask;
    DWORD gmask = desc.ddpfPixelFormat.dwGBitMask;
    DWORD bmask = desc.ddpfPixelFormat.dwBBitMask;

    for (int y = 0; y < height; ++y) {
        int dy = dst_y + y;
        if (dy < 0 || dy >= (int)desc.dwHeight) continue;
        unsigned char* dst_row = (unsigned char*)desc.lpSurface + dy * desc.lPitch;
        unsigned char* src_row = surface->rgba + (src_y + y) * surface->stride_bytes + src_x * 4;

        for (int x = 0; x < width; ++x) {
            int dx = dst_x + x;
            if (dx < 0 || dx >= (int)desc.dwWidth) continue;

            unsigned char* src = src_row + x * 4;
            unsigned char sr = src[0], sg = src[1], sb = src[2], sa = src[3];
            if (alpha_mode != 0 && sa == 0) continue;

            if (bpp == 16) {
                unsigned short* dst_px = (unsigned short*)(dst_row + dx * 2);
                if (alpha_mode != 0 && sa < 255) {
                    unsigned short old = *dst_px;
                    unsigned char dr = 0, dg = 0, db = 0;
                    if (rmask == 0xF800 && gmask == 0x07E0 && bmask == 0x001F) {
                        dr = (unsigned char)(((old & 0xF800) >> 11) << 3);
                        dg = (unsigned char)(((old & 0x07E0) >> 5) << 2);
                        db = (unsigned char)((old & 0x001F) << 3);
                    } else if (rmask == 0x7C00 && gmask == 0x03E0 && bmask == 0x001F) {
                        dr = (unsigned char)(((old & 0x7C00) >> 10) << 3);
                        dg = (unsigned char)(((old & 0x03E0) >> 5) << 3);
                        db = (unsigned char)((old & 0x001F) << 3);
                    }
                    sr = (unsigned char)((sr * sa + dr * (255 - sa)) / 255);
                    sg = (unsigned char)((sg * sa + dg * (255 - sa)) / 255);
                    sb = (unsigned char)((sb * sa + db * (255 - sa)) / 255);
                }
                if (rmask == 0xF800 && gmask == 0x07E0 && bmask == 0x001F)
                    *dst_px = PngSupport_Rgb565(sr, sg, sb);
                else if (rmask == 0x7C00 && gmask == 0x03E0 && bmask == 0x001F)
                    *dst_px = PngSupport_Rgb555(sr, sg, sb);
                else
                    *dst_px = (unsigned short)PngSupport_PackByMasks(sr, sg, sb, rmask, gmask, bmask);
            } else if (bpp == 32) {
                DWORD* dst_px = (DWORD*)(dst_row + dx * 4);
                if (alpha_mode != 0 && sa < 255) {
                    DWORD old = *dst_px;
                    unsigned char dr = (unsigned char)((old & rmask) >> PngSupport_MaskShift(rmask));
                    unsigned char dg = (unsigned char)((old & gmask) >> PngSupport_MaskShift(gmask));
                    unsigned char db = (unsigned char)((old & bmask) >> PngSupport_MaskShift(bmask));
                    sr = (unsigned char)((sr * sa + dr * (255 - sa)) / 255);
                    sg = (unsigned char)((sg * sa + dg * (255 - sa)) / 255);
                    sb = (unsigned char)((sb * sa + db * (255 - sa)) / 255);
                }
                *dst_px = PngSupport_PackByMasks(sr, sg, sb, rmask, gmask, bmask);
            }
        }
    }

    o_DDSurfaceBackBuffer->Unlock(nullptr);
    return 1;
}

extern "C" __declspec(dllexport) int __stdcall PngSupport_DrawToBackBufferFull(
    PngSupportSurface* surface,
    int dst_x,
    int dst_y,
    int alpha_mode)
{
    if (!surface) return 0;
    return PngSupport_DrawToBackBuffer(surface, 0, 0, surface->width, surface->height, dst_x, dst_y, alpha_mode);
}

