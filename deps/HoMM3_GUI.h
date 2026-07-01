////////////////////////////////////////////////////////////////////////////////////
// (HD 3.0) HoMM3 GUI (Window Manager, Dialogs, Control Elements (DlgItems) )
// Author: Alexander Barinov (aka baratorch, aka Bara) e-mail: baratorch@yandex.ru
// Thanks: ZVS, GrayFace
////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "HoMM3_Base.h"
#include "HoMM3_Res.h"


// _EventMsg_::type values
#define MT_MOUSEOVER 4
#define MT_MOUSEBUTTON 0x200
#define MT_KEYDOWN  1
#define MT_KEYUP  2

// MT_MOUSEBUTTON _EventMsg_::subtype values
#define MST_LBUTTONDOWN 0xc
#define MST_RBUTTONDOWN 0xe
#define MST_LBUTTONCLICK 0xd

// _EventMsg_::flags 
#define MF_SHIFT 1
#define MF_CTRL 4
#define MF_ALT 32


// _Dlg_::flags 
#define DF_NOTSCREEN 0x01
#define DF_SCREENSHOT 0x02
#define DF_SHADOW  0x10
// my _Dlg_::flags 
#define DF_HD   0x04
#define DF_SIMPLEFRAME 0x08
#define DF_GRAYFRAME 0x20
#define DF_FSSHADOW  0x40
#define DF_XORSCREEN 0x80

// _DlgItem_::flags
#define DIF_TRANSPARENT 0x0001
#define DIF_PCX   0x0800
#define DIF_DEF   0x0010
#define DIF_BUTTON  0x0002
#define DIF_TEXT  0x0008 // read only

#define DIID_OK 30725

#define DLG_X_CENTER -1
#define DLG_Y_CENTER -1


NOALIGN struct _DlgMsg_
{
 _dword_ type;
 _int_ subtype;
 _int_ item_id;
 _dword_ flags;
 _dword_ x_abs;
 _dword_ y_abs;
 _dword_ new_param ;
 _dword_ flags_2;
};
typedef _DlgMsg_ _EventMsg_;


////////////////////////////////////////////////////////////////////////////
NOALIGN struct _WndMgr_
{
 _dword_  field_0[14];

 _int_  result_dlg_item_id;
 
 _dword_  field_3C;
 
 _Pcx16_* screen_pcx16;
 
 _dword_  field_44;
 _byte_  field_48[4];
 _Pcx16_*  backup_screen_pcx16;
 
 _Dlg_*  dlg_first;
 _Dlg_*  dlg_last;

 _Dlg_*  field_58;
 _Dlg_*  field_5C;

 //normal
 inline void ShowRightMouseClickDlg(_Dlg_* dlg) {CALL_2(void, __thiscall, 0x603000, this, dlg);}
 inline void RemoveDialog(_Dlg_* dlg) {CALL_2(void, __thiscall, 0x602A60, this, dlg);}
 inline void RedrawScreenRect(_int_ x, _int_ y, _int_ width, _int_ height) {CALL_5(void, __thiscall, 0x603190, this, x,y,width,height);}
 
 
 inline void MakeBackupScreen(_int_ X_Pos, _int_ Y_Pos, _int_ Width, _int_ Height)
 {
   CALL_5(void, __thiscall, 0x603280, this, X_Pos, Y_Pos, Width, Height);
 }
 
 
 inline void SmoothImageChange(_int_ X_Pos, _int_ Y_Pos, _int_ Width, _int_ Height, _int_ FrameTime)
 {
   CALL_6(void, __thiscall, 0x603380, this, X_Pos, Y_Pos, Width, Height, FrameTime);
 }
 
 
 
 
 
 //my
 
};
////////////////////////////////////////////////////////////////////////////




struct _MouseMgr_
{
  _byte_ f0[144]; // +0h
};










////////////////////////////////////////////////////////////////////////////
NOALIGN struct _Dlg_
{
 _ptr_*  v_table;
 _dword_  z_order;
 _Dlg_*  next_dlg;
 _Dlg_*  last_dlg;
 _dword_  flags;
 _dword_  state;
 _dword_  x;
 _dword_  y;
 _dword_  width;
 _dword_  height;
 _DlgItem_* first_item;
 _DlgItem_* last_item;

 _ptr_  items_list;
 _ptr_  items_first;
 _ptr_  items_last;
 _ptr_  items_mem_end;

 _dword_  focused_item_id;
 _Pcx16_* screenshot_pcx16;

 //
 _ptr_ field_48;
 _ptr_ field_4C;
 _ptr_ field_50;

 _ptr_ field_54;
 _ptr_ field_58;
 _ptr_ field_5C;

 ///
 _ptr_ field_60;

 _dword_ field_64;
 _dword_ field_68;

//VIRTUAL/////////////////////////////////////////////////////////////////////////
 inline _Dlg_* Destroy(_bool_ delete_) {return CALL_2(_Dlg_*, __thiscall, this->v_table[0], this, delete_);}
 inline void  Show(_int_ z_order, _bool_ redraw_screen) {CALL_3(void, __thiscall, this->v_table[1], this, z_order, redraw_screen);}
 inline void  Hide(_bool_ redraw_screen) {CALL_2(void, __thiscall, this->v_table[2], this, redraw_screen);}
 inline void  Redraw(_bool_ redraw_screen, _dword_ item_id_start, _dword_ item_id_end) {CALL_4(void, __thiscall, this->v_table[5], this, redraw_screen, item_id_start, item_id_end);}
 inline void  Run(_dword_ a2) { CALL_2(void, __thiscall, this->v_table[6], this, a2);}
 inline _int_ Close(_EventMsg_* msg) {return CALL_2(_int_, __thiscall, this->v_table[14], this, msg); }
 inline int  RMC_Show() {return CALL_1(int, __thiscall, 0x5F4B90, this);}

//NORMAL//////////////////////////////////////////////////////////////////////////
 inline _DlgItem_* GetItem(_int_ id) {return CALL_2(_DlgItem_*, __thiscall, 0x5FF5B0, this, id);}
 inline _DlgItem_* FindItem(_int_ x, _int_ y) {return CALL_3(_DlgItem_*, __thiscall, 0x5FF9A0, this, x, y);}
 inline _int_  FindItemID(_int_ x, _int_ y) {return CALL_3(_int_, __thiscall, 0x5FF970, this, x, y);}
 
 inline _dword_  AttachItem(_DlgItem_* item, int z_order) {return CALL_3(_dword_, __thiscall, 0x5FF270, this, item, z_order);}
 inline _dword_  DetachItem(_DlgItem_* item) {return CALL_2(_dword_, __thiscall, 0x5FF320, this, item);}
 inline void   SetFocuseToItem(_int_ item_id) { CALL_2(void, __thiscall, 0x5FFA50, this, item_id); }
 
 inline _int_  SendItemCommand(_int_ cmd_type, _int_ cmd_subtype, _int_ item_id, _dword_ param)
  {return CALL_5(_int_, __thiscall, 0x5FF400,this,cmd_type,cmd_subtype,item_id,param);}

 inline _int_ DefProc(_EventMsg_* msg) {return CALL_2(_int_, __thiscall, 0x41B120, this, msg);}

//MY//////////////////////////////////////////////////////////////////////////////
 inline void Redraw(_bool_ redraw_screen) {Redraw(redraw_screen, -65535, 65535);}
 inline void Redraw() {Redraw(1, -65535, 65535);}
 inline void Run() { Run(0);}

 inline void AddItemToOwnArrayList(_DlgItem_* item) {CALL_4(void, __thiscall, 0x5FE2D0, &this->items_list, this->items_last, 1, &item);}
 inline _dword_ AttachItem(_DlgItem_* item) {return CALL_3(_dword_, __thiscall, 0x5FF270, this, item, -1);}
 inline void AddItem(_DlgItem_* item) {AddItemToOwnArrayList(item); AttachItem(item);}

 void SetItemsArrayListLength(int items_count);
 void AddItemByZOrder(_DlgItem_* item, int z_order);
 ////void DetachItem(_DlgItem_* item);
 void RemoveItem(_DlgItem_* item);
 void SetItemZOrder(_DlgItem_* item, int z_order);

 inline void SetRect(int x, int y, int width, int height) {this->x = x; this->y = y; this->width = width; this->height = height;}
 inline void SetPos(int x, int y) {this->x = x; this->y = y;}
 inline void SetSize(int width, int height) {this->width = width; this->height = height;}
};
////////////////////////////////////////////////////////////////////////////


#define b_DlgStaticPcx8_Create(x, y, width, height, id, pcx8_name, flags) \
 CALL_8(_DlgStaticPcx8_*, __thiscall, 0x44FFA0, o_New(sizeof(_DlgStaticPcx8_)), x, y, width, height, id, pcx8_name, flags)

#define b_DlgStaticText_Create(x, y, width, height, text, font_name, text_color, id, align, bkcolor, flags_notused) \
 CALL_12(_DlgStaticText_*, __thiscall, 0x5BC6A0, o_New(sizeof(_DlgStaticText_)), x, y, width, height, text, font_name, text_color, id, align, bkcolor, flags_notused)

#define b_DlgStaticTextPcx8ed_Create(x, y, width, height, text, font_name, bkground_pcx8, text_color, id, align, flags_notused) \
 CALL_12(_DlgStaticTextPcx8ed_*, __thiscall, 0x5BCB70, o_New(sizeof(_DlgStaticTextPcx8ed_)), x, y, width, height, text, font_name, bkground_pcx8, text_color, id, align, flags_notused)

#define b_DlgTextEdit_Create(x, y, width, height, max_len, text, font_name, text_color,  align, bkground_pcx8, bkcolor_notused, id, flags_notused, has_border, border_width, border_height) \
 CALL_17(_DlgTextEdit_*, __thiscall, 0x5BACD0, o_New(sizeof(_DlgTextEdit_)), x, y, width, height, max_len, text, font_name, text_color,  align, bkground_pcx8, bkcolor_notused, id, flags_notused, has_border, border_width, border_height)

#define b_DlgTextButton_Create(x, y, width, height, id, def_name, caption_text, font_name,  def_frame_ix, def_frame_press_ix, close_dlg, hotkey, flags, caption_color) \
 CALL_15(_DlgTextButton_*, __thiscall, 0x456730, o_New(sizeof(_DlgTextButton_)), x, y, width, height, id, def_name, caption_text, font_name,  def_frame_ix, def_frame_press_ix, close_dlg, hotkey, flags, caption_color)

#define b_DlgCallbackButton_Create(x, y, width, height, id, def_name, callback, def_frame_ix, def_frame_press_ix) \
 CALL_10(_DlgCallbackButton_*, __thiscall, 0x456A10, o_New(sizeof(_DlgCallbackButton_)), x, y, width, height, id, def_name, callback, def_frame_ix, def_frame_press_ix)

#define b_DlgButton_Create(x, y, width, height, id, def_name, def_frame_ix, def_frame_press_ix, close_dlg, hotkey, flags) \
 CALL_12(_DlgButton_*, __thiscall, 0x455bd0, o_New(sizeof(_DlgButton_)), x, y, width, height, id, def_name, def_frame_ix, def_frame_press_ix, close_dlg, hotkey, flags)

#define b_DlgStaticPcx16_Create(x, y, width, height, id, pcx16_name, flags) \
 CALL_8(_DlgStaticPcx16_*, __thiscall, 0x450340, o_New(0x52), x, y, width, height, id, pcx16_name, flags)

#define b_DlgEmptyStatic_Create(x, y, width, height, id, flags) \
 CALL_7(_DlgItem_*, __thiscall, 0x44FBE0, o_New(0x48), x, y, width, height, id, flags)

#define b_DlgStaticDef_Create(x, y, width, height, id, def_name, def_frame_ix, def_frame_press_ix, mirrored, close_dlg, flags) \
 CALL_12(_DlgStaticDef_*, __thiscall, 0x4EA800, o_New(0x48), x, y, width, height, id, def_name, def_frame_ix, def_frame_press_ix, mirrored, close_dlg, flags)

#define b_DlgScrollableText_Create(text, x, y, width, height, font_name, text_color, is_blue) \
 CALL_9(_DlgScrollableText_*, __thiscall, 0x5BA360, o_New(sizeof(_DlgScrollableText_)),text,x,y,width,height,font_name,text_color,is_blue)

#define b_DlgScroll_Create(x, y, width, height, id, ticks_count, callback, is_blue, a10, a11) \
 CALL_11(_DlgScroll_*, __thiscall, 0x5963C0, o_New(sizeof(_DlgScroll_)),x, y, width, height, id, ticks_count, callback, is_blue, a10, a11)

////////////////////////////////////////////////////////////////////////////
NOALIGN struct _DlgItem_
{
 _ptr_*  v_table;
 _Dlg_*  parent;
 _DlgItem_* prev_item;
 _DlgItem_* next_item;
 _word_  id;
 _word_  z_order;
 _word_  flags;
 _word_  state;
 _int16_  x;
 _int16_  y;
 _word_  width;
 _word_  height;
 _char_*  short_tip_text; // shown in status bar
 _char_*  full_tip_text; // shown in RMC Message Box
 _byte_  field_28[4];
 _dword_  field_2C;

 //virtual
 inline _DlgItem_* Destroy(_bool_ delete_this)  {return CALL_2(_DlgItem_*, __thiscall, this->v_table[0], this, delete_this);}
 inline void   Draw()       {CALL_1(void, __thiscall, this->v_table[4], this);}
 inline _dword_  Proc(_DlgMsg_* msg)    {return CALL_2(_dword_, __thiscall, this->v_table[2], this, msg);}
 inline _dword_  SetEnabled(_bool_ enabled)  {return CALL_2(_dword_, __thiscall, this->v_table[9], this, enabled);}
 inline void   SetFocus()      { CALL_1(void, __thiscall, this->v_table[10], this); }
 inline void   RemoveFocus()     { CALL_1(void, __thiscall, this->v_table[11], this); }

 // normal
 inline _dword_  SendCommand(_int_ new_param, _dword_ subtype) 
  {return CALL_3(_dword_, __thiscall, 0x5FED80, this, new_param, subtype);}

 // my
 inline void  Show()  {SendCommand(5, 6);}
 inline void  Hide()  {SendCommand(6, 6);}
 void RedrawScreen(); 
 inline void SetRect(int x, int y, int width, int height) {this->x = x; this->y = y; this->width = width; this->height = height;}
 inline void SetPos(int x, int y) {this->x = x; this->y = y;}
 inline void SetSize(int width, int height) {this->width = width; this->height = height;}
 static inline  _DlgItem_* Create(int x, int y, int width, int height, int id, _dword_ flags)
  {return b_DlgEmptyStatic_Create(x, y, width, height, id, flags);}
};
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
NOALIGN struct _DlgScroll_ : public _DlgItem_
{
 _Def_ *  def;
 _Pcx8_ * pcx;

 _dword_  tick_value;
 _int_  tick;
 _dword_  btn_position;
 _dword_  size_free;
 _dword_  ticks_count;
 _dword_  size_max;
 _dword_  a10;
 _dword_  btn_size2;
 _word_  some_x;
 _word_  some_y;
 _dword_  a11;
 _dword_  field_60;
 _ptr_  callback;

// my 
 static inline _DlgScroll_* Create(int x, int y, int width, int height, int id, int ticks_count, _ptr_ callback, _bool_ is_blue, _dword_ a10, _dword_ a11)
  {return b_DlgScroll_Create(x, y, width, height, id, ticks_count, callback, is_blue, a10, a11);}
};
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
NOALIGN struct _DlgStaticPcx8_ : public _DlgItem_
{
 _Pcx8_* pcx8;
 void Colorize(_int_ player_id) {CALL_2(void, __thiscall, 0x4501D0, this, player_id);}

// my 
 static inline _DlgStaticPcx8_* Create(int x, int y, int width, int height, int id, char* pcx8_name)
  {return b_DlgStaticPcx8_Create(x, y, width, height, id, pcx8_name, DIF_PCX);}
 static inline _DlgStaticPcx8_* Create(int x, int y, int id, char* pcx8_name)
 {
  _DlgStaticPcx8_* item = b_DlgStaticPcx8_Create(x, y, 0, 0, id, pcx8_name, DIF_PCX);
  if (item)
   if (item->pcx8)
   {
    item->width = item->pcx8->width;
    item->height = item->pcx8->height;
   }
  return item;
 }

};
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
NOALIGN struct _DlgStaticText_ : public _DlgItem_
{
 _char_* text_len;
 _char_* text;
 _char_* text_mem_end;
 _dword_ field_3C;
 _ptr_ font;
 _dword_ color;
 _dword_ back_color;
 _dword_ align;

// virtual
 void SetText(char* text) { CALL_2(void, __thiscall, this->v_table[13], this, text); }

// my 
 static inline _DlgStaticText_* Create(int x, int y, int width, int height, char* text, char* font_name, _dword_ text_color, int id, _dword_ align, int bkcolor)
  {return b_DlgStaticText_Create(x, y, width, height, text, font_name, text_color, id, align, bkcolor, 0);}
};
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
NOALIGN struct _DlgStaticTextPcx8ed_: public _DlgStaticText_
{
 _Pcx8_* pcx8;

// my 
 static inline _DlgStaticTextPcx8ed_* Create(int x, int y, int width, int height, char* text, char* font_name, char* bkground_pcx8_name, _dword_ text_color, int id, _dword_ text_align)
  {return b_DlgStaticTextPcx8ed_Create(x, y, width, height, text, font_name, bkground_pcx8_name, text_color, id, text_align, 0);}
 static inline _DlgStaticTextPcx8ed_* Create(int x, int y, char* text, char* font_name, char* bkground_pcx8_name, _dword_ text_color, int id, _dword_ text_align)
 {
  _DlgStaticTextPcx8ed_* item = b_DlgStaticTextPcx8ed_Create(x, y, 0, 0, text, font_name, bkground_pcx8_name, text_color, id, text_align, 0);
  if (item)
   if (item->pcx8)
   {
    item->width = item->pcx8->width;
    item->height = item->pcx8->height;
   }
  return item;
 }
};
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
NOALIGN struct _DlgTextEdit_ : public _DlgStaticTextPcx8ed_
{
 _Pcx16_* pcx16;
 _word_ caret_pos;
 _word_ max_len;

 _word_ field_width;
 _word_ field_height;
 _word_ field_x;
 _word_ field_y;

 _word_ field_64;
 _word_ field_66;
 _word_ field_68;
 _word_ field_6A;
 _byte_ field_6C;

 _bool8_ focused;

 _bool8_ redraw_actions;
 _byte_ field_6F;

// _DlgChatTextEdit_:
///////////////////////////////
 _byte_ field_70;
 _byte_ field_71[3];
///////////////////////////////

//virtual 
 inline void SetFocused(_bool8_ value) {CALL_2(void, __thiscall, this->v_table[14], this, value);}

// my 
 static inline _DlgTextEdit_* Create(int x, int y, int width, int height, int max_len, char* text, char* font_name, _dword_ text_color, _dword_ text_align, char* bkground_pcx8_name, int id, _bool_ has_border, int border_width, int border_height)
 {
  //////if ( (has_border) && (bkground_pcx8_name) )
  //////{
  ////// width += 2*border_width;
  ////// height += 2*border_height;
  //////}
  _DlgTextEdit_* it = b_DlgTextEdit_Create(x, y, width, height, max_len, text, font_name, text_color,  text_align, bkground_pcx8_name, 0, id, 0, has_border << 2, border_width, border_height);
  it->redraw_actions = TRUE;
  return it;
 }

};
////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////
NOALIGN struct _DlgStaticDef_ : public _DlgItem_
{
 _Def_* def;
 _dword_ def_frame_index;
 _dword_ press_def_frame_index;
 _dword_ mirrored;
 _dword_ field_40;
 _word_ close_dlg;
 _word_ field_46;

// my 
 static inline _DlgStaticDef_* Create(int x, int y, int width, int height, int id, char* def_name, int def_frame_ix, int mirrored, _bool_ close_dlg)
  {return b_DlgStaticDef_Create(x, y, width, height, id, def_name, def_frame_ix, 0, mirrored, close_dlg, DIF_DEF);}
 static inline _DlgStaticDef_* Create(int x, int y, int id, char* def_name, int def_frame_ix, int mirrored, _bool_ close_dlg)
 {
   _DlgStaticDef_* item = b_DlgStaticDef_Create(x, y, 0, 0, id, def_name, def_frame_ix, 0, mirrored, close_dlg, DIF_DEF);
   if (item)
   if (item->def)
   {
    item->width = item->def->width;
    item->height = item->def->height;
   }
   return item;
 }
};
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
NOALIGN struct _DlgStaticPcx16_ : public _DlgItem_
{
 _Pcx16_* pcx16;
 _dword_ field_34[7];
 _word_ field_50;

 static inline _DlgStaticPcx16_* Create(int x, int y, int width, int height, int id, char* pcx16_name, _dword_ flags)
  {return b_DlgStaticPcx16_Create(x, y, width, height, id, pcx16_name, flags);}
};
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
NOALIGN struct _DlgButton_ : public _DlgStaticDef_
{
 _ptr_ hotkeys_struct;
 _ptr_ hotkeys_start;
 _ptr_ hotkeys_end;
 _ptr_ hotkeys_mem_end;
 _ptr_ caption_struct;
 _ptr_ caption;
 _ptr_ caption_end;
 _ptr_ caption_mem_end;

// my 
 static inline _DlgButton_* Create(int x, int y, int width, int height, int id, char* def_name, int def_frame_ix, int def_frame_press_ix, _bool_ close_dlg, int hotkey, _dword_ flags)
  {return b_DlgButton_Create(x, y, width, height, id, def_name, def_frame_ix, def_frame_press_ix, close_dlg, hotkey, flags);}
 static inline _DlgButton_* Create(int x, int y, int id, char* def_name, int def_frame_ix, int def_frame_press_ix, _bool_ close_dlg, int hotkey)
 {
  _DlgButton_* item = b_DlgButton_Create(x, y, 0, 0, id, def_name, def_frame_ix, def_frame_press_ix, close_dlg, hotkey, DIF_BUTTON);

   if (item)
   if (item->def)
   {
    item->width = item->def->width;
    item->height = item->def->height;
   }
   return item;
 }
};
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
NOALIGN struct _DlgTextButton_ : public _DlgButton_
{
 _ptr_ caption_font;
 _dword_ caption_color;

// my 
 static inline _DlgTextButton_* Create(int x, int y, int width, int height, int id, char* def_name, char* caption_text, char* font_name, int def_frame_ix, int def_frame_press_ix, _bool_ close_dlg, int hotkey, _dword_ flags, int caption_color)
  {return b_DlgTextButton_Create(x, y, width, height, id, def_name, caption_text, font_name,  def_frame_ix, def_frame_press_ix, close_dlg, hotkey, flags, caption_color);}
 static inline _DlgTextButton_* Create(int x, int y, int id, char* def_name, char* caption_text, char* font_name, int def_frame_ix, int def_frame_press_ix, _bool_ close_dlg, int hotkey, int caption_color)
 {
  _DlgTextButton_* item = b_DlgTextButton_Create(x, y, 0, 0, id, def_name, caption_text, font_name,  def_frame_ix, def_frame_press_ix, close_dlg, hotkey, DIF_BUTTON, caption_color);

  if (item)
   if (item->def)
   {
    item->width = item->def->width;
    item->height = item->def->height;
   }
  return item;
 }
};
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
NOALIGN struct _DlgCallbackButton_ : public _DlgButton_
{
 _ptr_ callback;

// my 
 static inline _DlgCallbackButton_* Create(int x, int y, int width, int height, int id, char* def_name, _ptr_ callback, int def_frame_ix, int def_frame_press_ix)
  {return b_DlgCallbackButton_Create(x, y, width, height, id, def_name, callback, def_frame_ix, def_frame_press_ix);}
 static inline _DlgCallbackButton_* Create(int x, int y, int id, char* def_name, _ptr_ callback, int def_frame_ix, int def_frame_press_ix)
 {
  _DlgCallbackButton_* item = b_DlgCallbackButton_Create(x, y, 0, 0, id, def_name, callback, def_frame_ix, def_frame_press_ix);
  if (item)
   if (item->def)
   {
    item->width = item->def->width;
    item->height = item->def->height;
   }
  return item;
 }
};
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
NOALIGN struct _DlgScrollableText_ : public _DlgItem_
{
 _ptr_ font;
 _int_ lines_count; 
 _dword_ field_38[3];
 _ptr_ items_list;
 _ptr_ items_first;
 _ptr_ items_last;
 _ptr_ items_mem_end;
 _DlgScroll_* scroll_bar;
 _dword_ field_58;

// my 
 static inline _DlgScrollableText_* Create(char* text, int x, int y, int width, int height, char* font_name, _dword_ text_color, _bool_ is_blue)
  {return b_DlgScrollableText_Create(text, x, y, width, height, font_name, text_color, is_blue);}

};
////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////

// b_MsgBox style
#define MBX_OK   1
#define MBX_OKCANCEL 2
#define MBX_RMC   4

inline _bool_ b_MsgBox(char* text, int style)
{
 CALL_12(void, __fastcall, 0x4F6C00, text, style, -1, -1, -1, 0, -1, 0, -1, 0, -1, 0);
 return (o_WndMgr->result_dlg_item_id == DIID_OK);
}


/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////

//MY///////////////////////////////////////////////////////////////////////////////////

NOALIGN struct _DlgStdBackground_
{
 static _DlgStaticPcx16_* Create(int x, int y, int width, int height, int id, _bool_ have_bottombar, int player_id /*color*/);
 static inline _DlgStaticPcx16_* Create(_Dlg_* dlg, int id, _bool_ have_bottombar, int player_id /*color*/)
  {return Create(0, 0, dlg->width, dlg->height, id, have_bottombar, player_id);}
};

NOALIGN struct _DlgBlueBackground_
{
 static _DlgStaticPcx16_* Create(int x, int y, int width, int height, int id);
};

//MY///////////////////////////////////////////////////////////////////////////////////
typedef int (__stdcall *_func_CustomDlgProc)(_Dlg_* dlg, _EventMsg_* msg);

class _CustomDlg_ : public _Dlg_
{
public:
 _func_CustomDlgProc dlg_proc;
 static _ptr_ v_table_funcs[15];
 static int __fastcall DlgProcBridge(_CustomDlg_* this_, _dword_ not_used, _EventMsg_* msg);

 
public:
 static _Dlg_* Create(int x, int y, int width, int height, _dword_ flags, _func_CustomDlgProc dlg_proc);
};

_Pcx8_* CreateSimpleFrame(int width, int height);
