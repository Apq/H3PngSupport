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

## 依赖

- libpng + zlib 源码直接编译进 DLL（`D:\GitHub\H3\libpng`、`D:\GitHub\H3\zlib`）
- 不需要额外的 libpng/zlib DLL

## 部署

```powershell
pwsh.exe -NoProfile -ExecutionPolicy Bypass -File deploy.ps1
```

目标：`D:\Heroes3\Heroes3_2026.05.01\_HD3_Data\Packs\PNG支持`
