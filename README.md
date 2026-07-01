# PngSupport

英雄无敌 3 SoD x86 插件：使用 libpng 解码 PNG，维护自有 RGBA surface，并直接绘制到游戏 DirectDraw backbuffer。

## 定位

PngSupport **不是**修改原版资源系统，也不依赖 `_Pcx16_::DrawSurface16()`。

它做的是：

```text
PNG 文件
  -> libpng 解码为 RGBA surface
  -> PngSupport 自己 Lock DirectDraw backbuffer
  -> 根据 backbuffer 像素格式写入 RGB565/RGB555/32-bit 像素
  -> Unlock backbuffer
```

最终显示仍必须进入游戏的 DirectDraw backbuffer，这是“显示到游戏画面”无法绕开的目标；但中间不再依赖 HoMM3 的 `_Pcx16_` 绘制接口。

## 命名

- 目录名：`H3PngSupport`
- 解决方案名：`PngSupport`
- 项目名：`PngSupport`
- DLL 名：`PngSupport.dll`

## 源码依赖

本项目直接编译相邻目录中的源码，不依赖预编译 `.lib` / `.dll`：

```text
D:/GitHub/H3/libpng
D:/GitHub/H3/zlib
```

工程 include 路径：

```text
$(ProjectDir)..\libpng
$(ProjectDir)..\zlib
```

工程会直接编译 libpng/zlib 的 `.c` 文件，最终能力静态包含在 `PngSupport.dll` 里。

注意：libpng 源码目录需要存在：

```text
libpng/pnglibconf.h
```

如果只有 `pnglibconf.h.prebuilt`，可复制一份命名为 `pnglibconf.h`。

## 导出 API

```cpp
struct PngSupportSurface
{
    int width;
    int height;
    int stride_bytes;
    unsigned char* rgba;
};

extern "C" __declspec(dllimport) int __stdcall PngSupport_GetApiVersion();
extern "C" __declspec(dllimport) const char* __stdcall PngSupport_GetName();
extern "C" __declspec(dllimport) PngSupportSurface* __stdcall PngSupport_LoadPng(const char* path);
extern "C" __declspec(dllimport) void __stdcall PngSupport_Free(PngSupportSurface* surface);
extern "C" __declspec(dllimport) int __stdcall PngSupport_DrawToBackBuffer(PngSupportSurface* surface, int src_x, int src_y, int width, int height, int dst_x, int dst_y, int alpha_mode);
extern "C" __declspec(dllimport) int __stdcall PngSupport_DrawToBackBufferFull(PngSupportSurface* surface, int dst_x, int dst_y, int alpha_mode);
```

## alpha_mode

```text
0 = 忽略 alpha，整张图不透明绘制
1 = 使用 PNG alpha，支持透明和半透明混合
```

## 当前实现

- 使用 libpng 解码 PNG。
- surface 内部保留 RGBA，不提前转为 `_Pcx16_`。
- 绘制时 Lock `o_DDSurfaceBackBuffer`。
- 支持常见 16-bit RGB565、16-bit RGB555、32-bit mask 打包。
- 不再调用 `_Pcx16_::DrawSurface16()`。
