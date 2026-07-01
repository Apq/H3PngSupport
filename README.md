# PngSupport

英雄无敌 3 SoD x86 插件：使用 libpng 解码 PNG，创建 DirectDraw 离屏 surface，通过 Blt 绘制到 backbuffer。

## 定位

PngSupport **不依赖** `_Pcx8_`/`_Pcx16_` 体系，也不调用被 HD_TC2 hook 的游戏绘制函数。

渲染管线：

```
PNG 文件 → libpng 解码 RGBA8
  → o_DD->CreateSurface() 创建离屏 DD surface
  → Lock surface，按实际像素格式（16/24/32-bit）写入
  → o_DDSurfaceBackBuffer->Blt() 绘制到后备缓冲区
```

## 为什么用离屏 surface + Blt？

HD_TC2 hook 了 `_Pcx8_::DrawToPcx16`（0x44FA80），自定义 `_Pcx8_` 对象会崩溃。
直接写 `screen_pcx16->buffer` 也会因 HD_TC2 渲染管线覆盖而颜色/位置错乱。

DirectDraw Blt 是原生硬件加速操作，HD_TC2 不干预，颜色和位置都正确。
详见 `H3BattleValueInfo/背景图渲染方案.md`。

## 导出 API（API version 3）

| 函数 | 说明 |
|------|------|
| `PngSupport_GetApiVersion()` | 返回 `3` |
| `PngSupport_GetName()` | 返回 `"PngSupport(libpng+DDOffscreen)"` |
| `PngSupport_LoadPng(const char* path)` | 加载 PNG，创建离屏 DD surface，返回 `PngSupportSurface*` |
| `PngSupport_Free(PngSupportSurface*)` | 释放 surface 及 DD 资源 |
| `PngSupport_DrawToBackBuffer(surface, src_x, src_y, w, h, dst_x, dst_y, alpha_mode)` | Blt 到 backbuffer |
| `PngSupport_DrawToBackBufferFull(surface, dst_x, dst_y, alpha_mode)` | 整图 Blt |

### PngSupportSurface 结构

```cpp
struct PngSupportSurface {
    LPDIRECTDRAWSURFACE dd_surface;  // DirectDraw 离屏 surface
    int width;
    int height;
};
```

### alpha_mode

- `0` = 不透明绘制（默认）
- `1` = 预留（当前实现等同 0，DD Blt 不支持逐像素 alpha）

## 其它插件如何使用

### 1. 运行时加载

PngSupport 是独立的 HoMM3 插件 DLL，由 HD mod 在启动时加载。
其它插件通过 `LoadLibrary` + `GetProcAddress` 调用其导出 API：

```cpp
// --- 在你的插件中 ---

typedef int               (__stdcall *PFN_GetApiVersion)();
typedef const char*       (__stdcall *PFN_GetName)();
typedef void*             (__stdcall *PFN_LoadPng)(const char* path);
typedef void              (__stdcall *PFN_Free)(void* surface);
typedef int               (__stdcall *PFN_DrawToBackBuffer)(
    void* surface, int src_x, int src_y, int width, int height,
    int dst_x, int dst_y, int alpha_mode);
typedef int               (__stdcall *PFN_DrawToBackBufferFull)(
    void* surface, int dst_x, int dst_y, int alpha_mode);

static HMODULE              g_PngSupportDll = nullptr;
static PFN_GetApiVersion    g_Png_GetApiVersion = nullptr;
static PFN_LoadPng          g_Png_LoadPng = nullptr;
static PFN_Free             g_Png_Free = nullptr;
static PFN_DrawToBackBuffer g_Png_Draw = nullptr;
static PFN_DrawToBackBufferFull g_Png_DrawFull = nullptr;

// 初始化时调用一次
bool LoadPngSupport()
{
    g_PngSupportDll = LoadLibraryA("PngSupport.dll");
    if (!g_PngSupportDll) return false;

    g_Png_GetApiVersion = (PFN_GetApiVersion)GetProcAddress(g_PngSupportDll, "PngSupport_GetApiVersion");
    g_Png_LoadPng       = (PFN_LoadPng)GetProcAddress(g_PngSupportDll, "PngSupport_LoadPng");
    g_Png_Free          = (PFN_Free)GetProcAddress(g_PngSupportDll, "PngSupport_Free");
    g_Png_Draw          = (PFN_DrawToBackBuffer)GetProcAddress(g_PngSupportDll, "PngSupport_DrawToBackBuffer");
    g_Png_DrawFull      = (PFN_DrawToBackBufferFull)GetProcAddress(g_PngSupportDll, "PngSupport_DrawToBackBufferFull");

    if (!g_Png_GetApiVersion || !g_Png_LoadPng || !g_Png_Free || !g_Png_Draw) {
        FreeLibrary(g_PngSupportDll);
        g_PngSupportDll = nullptr;
        return false;
    }

    int ver = g_Png_GetApiVersion();
    if (ver < 3) {
        // API 版本不兼容
        FreeLibrary(g_PngSupportDll);
        g_PngSupportDll = nullptr;
        return false;
    }
    return true;
}
```

### 2. 加载和绘制 PNG

```cpp
// 加载 PNG 图片（路径为绝对路径）
void* bg = g_Png_LoadPng("D:\\Heroes3\\...\\img\\my_bg.png");
if (!bg) { /* 加载失败 */ }

// 绘制整张图到 backbuffer 的 (100, 200) 位置
g_Png_DrawFull(bg, 100, 200, 0);

// 或者绘制局部区域
g_Png_Draw(bg, 10, 10, 200, 100, 100, 200, 0);
//                   src_x=10 src_y=10 w=200 h=100  dst_x=100 dst_y=200

// 用完释放
g_Png_Free(bg);
```

### 3. 调用时机

`DrawToBackBuffer` 直接写入游戏 DirectDraw 后备缓冲区。
必须在游戏每帧渲染完成、present 之前调用。

典型 hook 点：
- 游戏的 `_Dlg_::RedrawScreenRect` 或类似绘制回调
- 战斗画面重绘 hook（如 `BattleRedraw`）

**注意**：backbuffer 会被游戏在下一次全屏重绘时覆盖，因此需要在每次需要显示
图片的绘制回调中重复调用 `DrawToBackBuffer`。

### 4. PngSupportSurface 内存布局

调用方不需要直接访问 `PngSupportSurface` 内部成员。
通过 `PngSupport_LoadPng` 获取不透明指针，传给其它 API 即可。
如需知道图片尺寸，在 `LoadPng` 后自行记录或使用以下辅助：

```cpp
// PngSupportSurface 的前 3 个成员是 { LPDIRECTDRAWSURFACE, int width, int height }
// 可以安全读取 width/height（偏移 4 和 8）：
struct PngSupportSurface { void* dd_surface; int width; int height; };
// 但不应修改任何字段。
```

## 依赖

- libpng + zlib 源码直接编译进 DLL（`D:\GitHub\H3\libpng`、`D:\GitHub\H3\zlib`）
- 不需要额外的 libpng/zlib DLL

## 部署

```powershell
pwsh.exe -NoProfile -ExecutionPolicy Bypass -File deploy.ps1
```

目标：`D:\Heroes3\Heroes3_2026.05.01\_HD3_Data\Packs\PNG支持`
