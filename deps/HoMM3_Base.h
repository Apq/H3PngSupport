////////////////////////////////////////////////////////////////////////////////////
// (HD 3.0) Some global HoMM3 functions and variables
// Author: Alexander Barinov (aka baratorch, aka Bara) e-mail: baratorch@yandex.ru
// Thanks: ZVS, GrayFace
////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "Base.h"

// res
struct _BinTree_;
struct _BinTreeItem_;
struct _Palette16_;
struct _Palette24_;
struct _Pcx8_;
struct _Pcx16_;
struct _DefFrame_;
struct _DefGroup_;
struct _Def_;
struct _TXT_;
// GUI
struct _DlgMsg_;
struct _WndMgr_;
struct _Dlg_;
struct _DlgItem_;
struct _DlgStaticPcx8_;
struct _DlgScroll_;
struct _DlgStaticText_;
struct _DlgTextEdit_;
struct _DlgStaticDef_;
struct _DlgStaticText_;
struct _DlgTextEdit_;
struct _DlgStaticDef_;
struct _DlgStaticPcx16_;
struct _DlgButton_;
struct _DlgTextButton_;
struct _DlgCallbackButton_;
struct _DlgScrollableText_;

#define o_New(size) CALL_1(_ptr_, __cdecl, 0x617492, size)
#define o_Delete(ptr) CALL_1(void, __cdecl, 0x60B0F0, ptr)


#define o_PauseVideo() CALL_0(void, __cdecl, 0x597AA0)
#define o_ContinueVideo() CALL_0(void, __cdecl, 0x597B50)

#define o_GetIngameCursorPos(px, py) CALL_2(void, __stdcall, 0x50D700, px, py);


#define o_WndMgr (*(_WndMgr_**)0x6992D0)
#define o_GameMgrPalette16 (*(_Palette16_**)0x6AAD18)
#define o_PlayersPalette16 (*(_Palette16_**)0x6AAD10)
#define o_PlayersPalette24 (*(_Palette24_**)0x6AAD14)

#define o_BinTreeHead (*(_BinTree_*)0x69E560)

#define o_GENRLTXT_TXT (*(_TXT_**)0x6A5DC4)
#define o_PLCOLORS_TXT (*(_TXT_**)0x6A7584)
#define o_TCOMMAND_TXT (*(_TXT_**)0x6A62F8)
// ..............

#define o_Tiny_Fnt  (*(_Fnt_**)0x698A54)
#define o_Smalfont_Fnt (*(_Fnt_**)0x698A58)
#define o_Medfont_Fnt (*(_Fnt_**)0x698A5C)
#define o_Bigfont_Fnt (*(_Fnt_**)0x698A60)
#define o_Calli10R_Fnt (*(_Fnt_**)0x698A64)


#define p_GameMgr (*(_ptr_*)0x699538)
#define o_GameMgrMgr_GetMeID() CALL_1(_int_, __thiscall, 0x4CE6E0, p_GameMgr)



#define RandSeed *(_dword_*)(CALL_0(_ptr_, __cdecl, 0x61D8C3) + 20)

#define SetRandSeed(Seed) CALL_1(void, __cdecl, 0x61841F, Seed)

#define o_MemAlloc(Size) CALL_1(_ptr_, __cdecl, 0x617492, Size)

// 务忸犷驿屙桢 镟?蜩.
#define o_MemFree(lpMem) CALL_1(void, __cdecl, 0x60B0F0, lpMem)



#define LIST_SIZE_ERROR_MESSAGE "Cannot do \"%s\" operation with type of size: %d"

#define LIST_SIZE_ERROR_SHORT_MESSAGE "List type size error"



#pragma pack(push, 1)
template <typename _type_> struct _List_
{
public:
  _byte_ Creation; // +0h;
  // 绣珞朦蜞?恹疣忭桠囗?, 礤 桉镱朦珞弪?.
  _byte_ Dummy_f1[3]; // +1h;
  // 冷疱?磬鬣豚 溧眄 耧桉赅.
  _type_* Data; // +4h;
  // 冷疱?觐眦?耧桉赅.
  _type_* EndData; // +8h;
  // 暑礤?恹溴脲眄铋 磬 耧桉铌 镟?蜩.
  _ptr_ EndMem; // +Ch;
  
  
  
  
  
  
  
  
  
  
  
  
  // built-in
  
  
  inline _int_ GetItemsCount()
  {
    switch (sizeof(_type_))
    {
      case 4:
        return CALL_1(_int_, __thiscall, 0x54D2B0, this);
        
      default:
        ShowVA(LIST_SIZE_ERROR_MESSAGE, "GetItemsCount", sizeof(_type_));
        throw LIST_SIZE_ERROR_SHORT_MESSAGE;
    }
  }
  
  
  
  
  
  
  inline void InsertRange(_type_* DestAddr, _int_ Count, _type_* SourceAddr)
  {
     switch (sizeof(_type_))
    {
      case 4:
        CALL_4(void, __thiscall, 0x4230D0, this, DestAddr, Count, SourceAddr);
        break;
        
      default:
        ShowVA(LIST_SIZE_ERROR_MESSAGE, "InsertRange", sizeof(_type_));
        throw LIST_SIZE_ERROR_SHORT_MESSAGE;
    }
  }
  
  
  
  
  
  
  inline void DeleteLastValue(_type_ Value)
  {
    switch (sizeof(_type_))
    {
      case 4:
        CALL_2(void, __fastcall, 0x43E720, this, Value);
        break;
        
      default:
        ShowVA(LIST_SIZE_ERROR_MESSAGE, "DeleteLastValue", sizeof(_type_));
        throw LIST_SIZE_ERROR_SHORT_MESSAGE;
    }
  }
  
  
  inline void DeleteEntry(_type_* Addr)
  {
    switch (sizeof(_type_))
    {
      case 4:
        CALL_2(void, __thiscall, 0x54CDC0, this, Addr);
        break;
        
      default:
        ShowVA(LIST_SIZE_ERROR_MESSAGE, "DeleteEntry", sizeof(_type_));
        throw LIST_SIZE_ERROR_SHORT_MESSAGE;
    }
  }
  
  
  inline void DeleteRange(_type_* FirstAddr, _type_* EndAddr)
  {
    switch (sizeof(_type_))
    {
      case 4:
        CALL_3(void, __thiscall, 0x4D4E90, this, FirstAddr, EndAddr);
        break;
        
      default:
        ShowVA(LIST_SIZE_ERROR_MESSAGE, "DeleteRange", sizeof(_type_));
        throw LIST_SIZE_ERROR_SHORT_MESSAGE;
    }
  }
  
  
  inline void DeleteAll()
  {
    switch (sizeof(_type_))
    {
      case 4:
        CALL_1(void, __thiscall, 0x448A40, this);
        break;
        
      default:
        ShowVA(LIST_SIZE_ERROR_MESSAGE, "DeleteAll", sizeof(_type_));
        throw LIST_SIZE_ERROR_SHORT_MESSAGE;
    }
  }
  
  
  
  
  
  
  
  
  
  
  
  
  // user
  
  
  
  
  inline _List_()
  {
    this->Data = 0;
    this->Creation = 0;
    this->EndData = 0;
    this->EndMem = 0;
  }
  
  
  // 腻耱痼牝铕 耧桉赅.
  inline ~_List_()
  {
    o_MemFree(this->Data);
    this->Data = 0;
    this->EndData = 0;
    this->EndMem = 0;
  }
  
  
  
  
  
  inline _bool_ HasValue(_type_ Value)
  {
    // 橡铛钿桁 镱 怦屐 屐屙蜞?耧桉赅.
    for (_int_ i = 0; i < this->GetItemsCount(); i++)
    {
      if ((*this)[i] == Value) return TRUE;
    }
    
    // 腕骓铄 珥圜屙桢 礤 磬殇屙?
    return FALSE;
  }
  
  
  
  
  
  inline _type_& operator[](_int_ index)
  {
    if (index >= 0)
    {
      return (this->Data)[index];
    }
    else
    {
      return *(_type_*)(this->EndData + index);
    }
  }
  
  
  
  
  
  
  // 念徉怆屙桢 屐屙蜞 ?觐礤?耧桉赅 镱 珥圜屙棹.
  inline void Append(_type_ Item)
  {
    this->InsertRange(this->EndData, 1, &Item);
  }
  
  
  
  
  inline _type_ Pop(_int_ index = -1)
  {
    _type_ res = (*this)[index];
    
    this->DeleteEntry(&((*this)[index]));
    
    return res;
  }
  
  
};
#pragma pack(pop)
