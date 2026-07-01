// PngSupport.cpp
// 英雄无敌3 SoD 插件：为其他插件提供 PNG/JPG/BMP → RGB565 surface 的加载与绘制能力。
// 目标版本：Shadow of Death（SOD = 0xFFFFE403），仅 x86。

#include <ddraw.h>
#include "homm3.h"
#include <stdarg.h>
#include <wchar.h>
#include <stdint.h>

Patcher*         _P  = nullptr;
PatcherInstance* _PI = nullptr;

// 单翻译单元风格，参考 MegaDesc。
#include "modules/ConfigLog.inc.cpp"
#include "modules/PngSurface.inc.cpp"
#include "modules/Entry.inc.cpp"
