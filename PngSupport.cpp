// PngSupport.cpp
// 英雄无敌3 SoD 插件：为其他插件提供 PNG → DirectDraw 离屏 surface 的加载与绘制能力。
// 目标版本：Shadow of Death（SOD = 0xFFFFE403），仅 x86。

#define _H3API_PATCHER_X86_
#include <H3API.hpp>
#include <ddraw.h>
#include <stdarg.h>
#include <wchar.h>
#include <stdint.h>

// DirectDraw 全局变量（H3API.hpp 不包含 DD 封装，手动定义）
// 这些地址来自原版 homm3.h，在所有版本中固定不变。
namespace h3 {
    namespace H3Internal {
        inline LPDIRECTDRAW& _o_DD() { return *reinterpret_cast<LPDIRECTDRAW*>(0x6AAD20); }
        inline LPDIRECTDRAWSURFACE& _o_DDSurfaceBackBuffer() { return *reinterpret_cast<LPDIRECTDRAWSURFACE*>(0x6AAD28); }
    }
}
#define o_DD              (h3::H3Internal::_o_DD())
#define o_DDSurfaceBackBuffer  (h3::H3Internal::_o_DDSurfaceBackBuffer())

Patcher*         _P  = nullptr;
PatcherInstance* _PI = nullptr;

// 单翻译单元风格，参考 MegaDesc。
#include "modules/ConfigLog.inc.cpp"
#include "modules/PngSurface.inc.cpp"
#include "modules/Entry.inc.cpp"
