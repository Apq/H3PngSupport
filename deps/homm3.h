#pragma once

#include "patcher_x86.hpp"
#include "HoMM3_ids.h"
#include "HoMM3_Base.h"
#include "HoMM3_Res.h"
#include "HoMM3_GUI.h"


//#include <ddraw.h>

// 锌芯写泻谢褞褔邪褌褜 褌邪泻:
// #include "..\..\include\homm3.h"



#define EXE_VERSION *(_dword_*)0x588479
#define TE 0x001F0E12
#define WOG 0x001EC3A3
#define SOD 0xFFFFE403

// 袗斜褋芯谢褞褌薪褘泄 锌褍褌褜 泻 泻芯褉薪械胁芯泄 锌邪锌泻械 懈谐褉褘.
#define MAIN_ABSPATH *(_cstr_)0x698614

//#define o_HEROES_COUNT 156
//#define o_CREARURES_COUNT 150
#define o_HEROES_COUNT (*(_int_*)0x4BD145)
#define o_CREARURES_COUNT (*(_int_*)0x5C8047)




struct _Army_;
struct _CreatureInfo_;
struct _TurnTimeStruct_;
struct _MapItem_;
struct _Artifact_;
struct _ArtInfo_;
struct _Hero_;
struct _HeroInfo_;
struct _HeroSpecInfo_;
struct _Player_;
struct _Town_;
struct _MapGlobalEvent_;
struct _BattleAnim_;
// 袣邪褉褌邪 懈谐褉褘.
struct _GameMap_;
// 袨斜褗械泻褌 薪邪 泻邪褉褌械 锌褉懈泻谢褞褔械薪懈泄.
struct _Object_;
// 袨斜褗械泻褌 - 谢邪谐械褉褜 谐械褉芯褟 (锌褉懈 蟹邪谐褉褍蟹泻械 泻邪褉褌褘).
struct _PlaceHolder_;
// 小锌懈褋芯泻 谐械褉芯械胁.
struct _HeroesList_;
// 袙薪械褕薪械械 卸懈谢懈褖械 薪邪 泻邪褉褌械.
struct _Dwelling_;

// 袧邪褋褌褉芯泄泻懈 蟹芯薪褘 谐械薪械褉邪褌芯褉邪 褋谢褍褔泄薪褘褏 泻邪褉褌.
struct _ZoneSettings_;




// 袦械薪械写卸褉械褉褘 懈谐褉褘. 袧械褋泻芯谢褜泻芯 懈蟹 薪懈褏 械褖褢 薪械 褉邪褋锌芯蟹薪邪薪褘.
// _bool32_ __cdecl sub_4EE1D0() - 懈薪懈褑懈邪谢懈蟹邪褑懈褟 屑械薪械写卸械褉芯胁. 袩芯 薪械泄 褉邪褋锌芯蟹薪邪薪 懈褏 褉邪蟹屑械褉.

// Some Mgr 锌芯 0x699550, 褉邪蟹屑械褉: 16

// 袦械薪械写卸械褉 胁胁芯写邪, 褍锌褉邪胁谢褟褞褖懈泄 褋芯斜褘褌懈褟屑懈 胁胁芯写邪.
struct _InputMgr_; // 袪邪蟹屑械褉: 2400
#define o_InputMgr (*(_InputMgr_**)0x699530)

// 袦械薪械写卸械褉 屑褘褕懈.
struct _MouseMgr_; // 袪邪蟹屑械褉: 144
#define o_MouseMgr (*(_MouseMgr_**)0x6992B0)

// 袦械薪械写卸械褉 芯泻薪邪 锌褉芯谐褉邪屑屑褘.
struct _WndMgr_; // 袪邪蟹屑械褉: 96
#define o_WndMgr (*(_WndMgr_**)0x6992D0)

// 袦械薪械写卸械褉 蟹胁褍泻邪.
struct _SoundMgr_; // 袪邪蟹屑械褉: 216
#define o_SoundMgr (*(_SoundMgr_**)0x699414)

// Some Mgr 锌芯 0x69941C, 褉邪蟹屑械褉: 2260

// 袦械薪械写卸械褉 懈谐褉褘.
struct _GameMgr_; // 袪邪蟹屑械褉: 321488
#define o_GameMgr (*(_GameMgr_**)0x699538)

// 袦械薪械写卸械褉 泻邪褉褌褘 锌褉懈泻谢褞褔械薪懈泄.
struct _AdvMgr_; // 袪邪蟹屑械褉: 952
#define o_AdvMgr (*(_AdvMgr_**)0x6992B8)

// 袦械薪械写卸械褉 斜懈褌胁褘.
struct _BattleMgr_; // 袪邪蟹屑械褉: 82156
#define o_BattleMgr (*(_BattleMgr_**)0x699420)

// 袦械薪械写卸械褉 芯泻薪邪 谐芯褉芯写邪.
struct _TownMgr_; // 袪邪蟹屑械褉: 472
#define o_TownMgr (*(_TownMgr_**)0x69954C)

// Some Mgr 锌芯 0x6992D4, 褉邪蟹屑械褉: 112

// Some Mgr 锌芯 0x6992DC, 褉邪蟹屑械褉: 1










#define o_ScreenBPP (*(_int_*)0x68C8C0)
#define o_ScreenWidth (*(_int_*)0x68C8C4)
#define o_ScreenHeight (*(_int_*)0x68C8C8)
#define o_DD (*(LPDIRECTDRAW*)0x6AAD20)
#define o_DDSurfacePrimary (*(LPDIRECTDRAWSURFACE*)0x6AAD24)
#define o_DDSurfaceBackBuffer (*(LPDIRECTDRAWSURFACE*)0x6AAD28)
#define o_DDSurface6AAD2C (*(LPDIRECTDRAWSURFACE*)0x6AAD2C)
#define o_DDSurface6AAD30 (*(LPDIRECTDRAWSURFACE*)0x6AAD30)
#define o_DDSurface6AAD34 (*(LPDIRECTDRAWSURFACE*)0x6AAD34)
#define o_FullScreenMode (*(_bool_*)0x698808)
#define o_hWnd (*(HWND*)0x699650)

#define HERO_INFO_OFFSET (*(_ptr_*)0x67DCE8)
//#define o_HeroInfo ((_HeroInfo_*)0x679DD0)
#define o_HeroInfo ((_HeroInfo_*)HERO_INFO_OFFSET)
#define o_pHeroInfo (*(_HeroInfo_**)0x67DCE8)

// 孝邪斜谢懈褑邪 褋锌械褑懈邪谢懈蟹邪褑懈泄 谐械褉芯械胁.
#define o_pHero_Spec_Table (_ptr_)0x679C80

#define o_NetworkGame *(_bool_*)0x69959C
//#define o_CampaignGame *(_bool_*)0x69779C
#define o_ActivePlayer (*(_Player_**)0x69CCFC)
#define o_ActivePlayerID *(_int_*)0x69CCF4
#define o_MeID *(_int_*)0x6995A4

#define o_Market_Hero (*(_Hero_**)0x6AAAE0)
#define o_DirectPlayCOMObject *(_ptr_*)0x69D858

//#define CREATURE_INFO_OFFSET (*(_ptr_*)0x47ADD1)
#define CREATURE_INFO_OFFSET (*(_ptr_*)0x6747B0)
//#define o_CreatureInfo ((_CreatureInfo_*)0x6703B8)
#define o_CreatureInfo ((_CreatureInfo_*)CREATURE_INFO_OFFSET)
#define o_pCreatureInfo (*(_CreatureInfo_**)0x6747B0)

#define o_GameMgrType (*(_int_*)0x698A40)
#define o_QuickBattle (*(_int_*)0x6987CC)
#define o_AutoSolo *(_byte_*)0x691259
#define o_IsOnlineGame *(_bool_*)0x69959C

#define o_CombatOptionsDlg (*(_Dlg_**)0x694FE0)
#define o_MapWidth *(_dword_*)0x6783C8
#define o_MapHeight *(_dword_*)0x6783CC
#define o_ViewingWorldEarthAirNow *(_dword_*)0x6AACA4
#define o_ViewWorldEarthAirMapCellSize *(_float_*)0x68C708
#define o_MusicVolume (*(_byte_*)0x6987B0)
#define o_TextBuffer ((char*)0x697428)
#define o_TurnTimer ((_TurnTimeStruct_*)0x69D680)
#define o_ScreenLogStruct ((_ptr_)0x69D800)
#define o_ArtInfo (*(_ArtInfo_**)0x660B68)
#define o_RegKeyPath ((_char_*)0x67FE78)
#define o_RegKey_AppPath ((_char_*)0x67FC10)
#define o_RegKey_CDDrive ((_char_*)0x67FC08)

#define o_CurrentDlg (*(_Dlg_**)0x698AC8)

#define o_HeroDlg_Hero (*(_Hero_**)0x698B70)
#define o_HeroDlg_SelStackIndex (*(_int_*)0x697788)


//#define o_BattleAnimation ((_BattleAnim_*)0x641E18)
extern _BattleAnim_* o_BattleAnimation;
extern _int_ BattleAnims_Count;


#define p_NewScenarioDlg (*(_ptr_*)0x69FC44)

#define b_unpack_z(xyz) (((_int16_)(((_dword_)(xyz)) >> 14)) >> 12)
#define b_unpack_y(xyz) (((_int16_)(((_dword_)(xyz)) >> 10)) >> 6)
#define b_unpack_x(xyz) (((_int16_)(((_dword_)(xyz)) << 6)) >> 6)
#define b_pack_xyz(x, y, z) (_dword_)( (((_dword_)(((_word_)(y)) & 0x3FF)) << 16) | ((_dword_)(((_word_)(x)) & 0x3FF)) | (((_dword_)(((_word_)(z)) & 0xF)) << 26) )

// 孝械泻褍褖邪褟 懈谐褉邪 - 胁褋褌褉芯械薪薪邪褟 泻邪屑锌邪薪懈褟.
#define Game_Is_BuiltInCampaing (*(_bool8_*)0x69779C)


// 孝邪斜谢懈褑邪 蟹邪泻谢懈薪邪薪懈泄.
#define o_Spell (*(_Spell_**)0x687FA8)


// 袦懈薪懈屑邪谢褜薪芯械 胁褉械屑褟 屑械卸写褍 泻邪写褉邪屑懈 (user).
#define MIN_FRAME_PERIOD 10




// 袣芯谢懈褔械褋褌胁芯 谐械泻褋芯胁 锌芯谢褟 斜芯褟.
#define BATTLE_HEXES_COUNT 187


// 袣芯谢懈褔械褋褌胁芯 褋褌械泻芯胁 褍 泻邪卸写芯泄 褋褌芯褉芯薪褘 薪邪 锌芯谢械 斜芯褟.
#define BATTLE_SIDE_STACKS_COUNT 21


// 袣芯谢懈褔械褋褌胁芯 锌芯褉褟写泻芯胁 邪泻褌懈胁薪褘褏 褝谢械屑械薪褌芯胁 芯褌芯斜褉邪卸械薪懈褟 胁 斜芯褞.
#define BATTLE_MAPPING_PRIORITIES_COUNT 8



// 袣芯谢懈褔械褋褌胁芯 褝谢械屑械薪褌芯胁 蟹邪屑泻邪.
#define CASTLE_ELEMENTS_COUNT 8




// 袙褉械屑褟 芯卸懈写邪薪懈褟 芯写薪芯谐芯 泻邪写褉邪 芯褌褉芯懈褋芯胁泻懈 锌芯谢褢褌邪 薪械斜邪谢谢懈褋褌懈褔械褋泻芯谐芯 胁褘褋褌褉械谢邪 懈谢懈 蟹邪泻谢懈薪邪薪懈褟.
#define ShotFrameTime (*(_float_*)0x63B8A0)




// 袙褉械屑褟, 写芯 泻芯褌芯褉芯谐芯 斜褍写械褌 锌褉芯懈蟹胁芯写懈褌褜褋褟 芯卸懈写邪薪懈械 锌褉懈 褋谢械写褍褞褖械泄 芯褌褉懈褋芯胁泻械.
// 校褋褌邪薪邪胁谢懈胁邪械褌褋褟 泻邪卸写芯泄 芯褌褉懈褋芯胁泻芯泄 写谢褟 褋谢械写褍褞褖械泄...
// ...褔褌芯斜褘, 械褋谢懈 薪邪 锌褉芯褑械褋褋褘 屑械卸写褍 薪懈屑懈 蟹邪褌褉邪褌懈褌褋褟 胁褉械屑褟, 芯薪芯 邪胁褌芯屑邪褌懈褔械褋泻懈 胁褘褔谢芯褋褜 懈蟹 胁褉械屑械薪懈 芯卸懈写邪薪懈褟.
#define DrawingWaitTime (*(_dword_*)0x6989E8)



// 袙褉械屑褟 褋谢械写褍褞褖械谐芯 锌褉芯懈谐褉褘褕邪 邪薪懈屑邪褑懈懈 芯卸懈写邪薪懈褟 胁 斜芯褞.
#define WaitAnimTime (*(_dword_*)0x698A08)



// 袦邪褋褋懈胁 屑薪芯卸懈褌械谢械泄 锌械褉懈芯写芯胁 芯卸懈写邪薪懈泄 邪薪懈屑邪褑懈懈 写谢褟 薪邪褋褌褉芯泄泻懈 褋泻芯褉芯褋褌懈 斜芯褟.
#define BattleAnimPeriodFactors ((_float_*)0x63CF7C)

// 袧邪褋褌褉芯泄泻邪 褋泻芯褉芯褋褌懈 斜芯褟 (懈薪写械褋 薪褍卸薪芯谐芯 屑薪芯卸懈褌械谢褟 锌械褉懈芯写芯胁 芯卸懈写邪薪懈泄 胁 屑邪褋褋懈胁械).
#define Settind_BattleFast (*(_dword_*)0x69883C)


// 袙褉械屑械薪薪邪褟 褌械泻褋褌芯胁邪褟 锌械褉械屑械薪薪邪褟. 袪邪蟹屑械褉: 768 斜邪泄褌.
#define H3TempStr ((char*)0x697428)


// 袩褍褋褌邪褟 锌械褉械屑械薪薪邪褟.
#define EmptyVar (*(DWORD*)0x691260)


// 袩褍褋褌芯泄 蟹胁褍泻.
#define EmptySample (*(_Sample_*)0x6992A8)


// 小褌邪薪写邪褉褌薪褘泄 锌械褉懈芯写 邪薪懈屑邪褑懈懈.
#define STD_FRAME_PERIOD 100




// 袚褉邪薪懈褑褘 锌械褉械褉懈褋芯胁泻懈 锌芯谢褟 斜芯褟.
#define BattleRedraw_Borders (*(_RedrawBorders_*)0x694F68)




// 袘芯械胁褘械 褝谢械屑械薪褌褘 蟹邪屑泻邪.
#define CastleElements ((_CastleElement_*)0x63BE60)


// 袧芯屑械褉邪 谐械泻褋芯胁 泻褉械锌芯褋褌薪芯泄 褋褌械薪褘 锌芯 褉褟写邪屑 锌芯谢褟 斜芯褟.
#define CastleWall_Gexes ((_byte_*)0x63BD00)



//NOALIGN struct _XYZ_
//{
// _dword_ z : 6;
// _dword_ y : 10;
// _dword_ x : 10;
//}



NOALIGN struct _Resources_
{
 _int_ wood;
 _int_ mercury;
 _int_ ore;
 _int_ sulfur;
 _int_ crystal;
 _int_ jems;
 _int_ gold;
};

NOALIGN struct _Army_
{
 _int_ type[7];
 _int_ count[7];
 
 // 袣芯薪褋褌褉褍褌芯褉.
 inline _Army_* Construct()
 {
   return CALL_1(_Army_*, __thiscall, 0x44A750, this);
 }
 
 // normal
 inline int GetStacksCount() {return CALL_1(int, __thiscall, 0x44A990, this);}
 inline int GetCreaturesCount() {return CALL_1(int, __thiscall, 0x44AA70, this);}
 inline void SwapStackTo(int ix, _Army_* dst_army, int dst_ix) {CALL_4(void, __thiscall, 0x44AA30, this, ix, dst_army, dst_ix);}
 inline void SplitStackByDlgTo(int i, _Army_* dst_army, int dst_i, _bool8_ is_hero, _bool8_ dst_is_hero)
  {CALL_6(void, __thiscall, 0x449B60, this, i, dst_army, dst_i, is_hero, dst_is_hero);}
};

NOALIGN struct _CreatureInfo_
{
 _int_ town;
 _int_ level;
 _char_* sound_name;
 _char_* def_name;
 _int_ flags;
 _char_* name_single;
 _char_* name_plural;
 _char_* specification_description;

 //_int_ cost_wood;
 //_int_ cost_mercury;
 //_int_ cost_ore;
 //_int_ cost_sulfur;
 //_int_ cost_crystal;
 //_int_ cost_jems;
 //_int_ cost_gold;
 _Resources_ cost;

 _int_ fight_value;
 _int_ AI_value;
 _int_ growth;
 _int_ horde_growth;
 _int_ hit_points;
 _int_ speed;
 _int_ attack;
 _int_ defence;
 _int_ damage_min;
 _int_ damage_max;
 _int_ shots;
 _int_ spells_count;
 _int_ advmap_low;
 _int_ advmap_high;
};

NOALIGN struct _HeroInfo_
{
 // 袩芯谢 (0 - 卸械薪褋泻懈泄, 1 - 屑褍卸褋泻芯泄)
 _dword_ sex;
 _dword_ field_04[8];
 _dword_ army_type[3];
 _ptr_ hps_name;
 _ptr_ hpl_name;
 _byte_ allowed_in_roe; // 袪邪蟹褉械褕褢薪 谢懈 胁 袙芯蟹褉芯卸写械薪懈懈 协褉邪褎懈懈.
 _byte_ allowed_in_not_roe; // 袪邪蟹褉械褕褢薪 谢懈 薪械 胁 袙芯蟹褉芯卸写械薪懈懈 协褉邪褎懈懈.
 _byte_ is_campaing; // 袣邪屑锌邪薪械泄褋泻懈泄 谢懈.
 _byte_ field_38[5];
 _ptr_ name;
 _dword_ army_count[6];
};


NOALIGN struct _TurnTimeStruct_
{
 _dword_ last_shown;
 _dword_ turn_start;
 _dword_ turn_limit;
 _dword_ next_shown;
 _dword_ battle_start;

 inline void NewTurn() { CALL_1(void, __thiscall, 0x558130, this); }
};

NOALIGN struct _HString_
{
 _char_* c_str;
 _int_ length;
};
NOALIGN struct _HStringA_
{
 _HString_ h_str;
 _int_ a;
};
NOALIGN struct _HStringF_
{
 _bool8_ is_memory_allocated;
 _byte_ dummy_f1[3];
 _HString_ h_str;
 _int_ size;
};
NOALIGN struct _GlobalEvent_
{
 _HStringF_ message_f;
 _Resources_ resouces;
 _byte_ players_bits;
 _byte_ for_human;
 _byte_ for_ai;
 _word_ day;
 _word_ repeat;
};
NOALIGN struct _MapItem_
{
 _dword_  setup; //+0
 _byte_  land; // +4
 _byte_  land_type;//+5
 _byte_  river;//+6
 _byte_  river_type;//+7
 _byte_  road;//+8
 _byte_  road_type;//+9
 _word_  field_0A;//+10
 _byte_  mirror;//+12
 _byte_  attrib;//+13
 _word_  field_0E_bits;//+14

 _word_  field_10;//+16
 _dword_  draw;//+18
 _dword_  draw_end;//+22
 _dword_  draw_end_2;//+26
 _word_  object_type;//+30

 _word_  _u3;//+32
 _word_  os_type; //+34
 _word_  draw_num;//+36

 _dword_ GetReal__setup() { return CALL_1(_dword_, __thiscall, 0x4FD280, this);}
 _dword_ GetReal__object_type() { return CALL_1(_dword_, __thiscall, 0x4FD220, this);}
 
 // 小写械谢邪褌褜 芯斜褗械泻褌 锌芯褋械褖褢薪薪褘屑 懈谐褉芯泻芯屑.
 inline void SetAsVisited(_int_ player_ix)
 {
   CALL_2(void, __thiscall, 0x4FC620, this, player_ix);
 }
 
 // 小写械谢邪褌褜 芯斜褗械泻褌 锌芯褋械褖褢薪薪褘屑 懈谐褉芯泻芯屑.
 inline _bool8_ IsVisited(_int_ player_ix)
 {
   return CALL_2(_bool8_, __thiscall, 0x529B70, this, player_ix);
 }
 
 
};



NOALIGN struct _Artifact_
{
 _int_ id;
 _int_ mod;
};

// 32 bytes.
NOALIGN struct _ArtInfo_
{
 char* name;
 _int_ cost;
 _int_ position; // 孝懈锌 褋谢芯褌邪, 邪 薪械 薪芯屑械褉 (薪邪锌褉懈屑械褉, 芯斜邪 褋谢芯褌邪 泻芯谢褜褑邪 - 1 褌懈锌)
 _int_ type;
 char* description;
 _int_ supercomposite;
 _int_ part_of_supercomposite;
 _byte_ disabled;
 _byte_ new_spell;
 _byte_ field_1E;
 _byte_ field_1F;
};


// 8 bytes. 小谢芯褌 写谢褟 邪褉褌械褎邪泻褌邪.
NOALIGN struct _ArtSlotInfo_
{
  // +0. 袠屑褟 褋谢芯褌邪.
  _cstr_ name;
  
  // +4. 孝懈锌 褋谢芯褌邪.
  _int_ type;
};


NOALIGN struct _Hero_
{
 _int16_ x; // +0
 _int16_ y; // +2
 _int16_ z; // +4
 _byte_ visible; // +6
 _dword_ mui_xyz; // +7
 _byte_ field_0B; // +11
  // miu = map_item under hero
 _dword_ miu_object_type; // +12
 _dword_ miu_object_c_flag; // +16
 _dword_ miu_setup; // +20
 _word_ spell_points; // +24
 _dword_ id; // +26
 _dword_ id_wtf; // +30
 _int8_ owner_id; // +34
 _char_ name[13]; // +35
 _dword_ _class; // +48
 _byte_ pic; // +52
 _dword_ aim_x; // +53
 _dword_ aim_y; // +57
 _dword_ aim_z; // +61
 _byte_ field_41[3]; // +65
 _byte_ x_0; // +68
 _byte_ y_0; // +69
 _byte_ run; // +70
 _byte_ field_47; // +71
 _byte_ flags; // +72
 _dword_ movement_points_max; // +73
 _dword_ movement_points; // +77
 _dword_ expa; // +81
 _word_ level; // +85
 _dword_ visited[10]; // +87
 _byte_ field_7F[18]; // +127
 _Army_ army; // +145
 _byte_ second_skill[28]; // +201
 _byte_ second_skill_show[28]; // +229
 _dword_ second_skill_count; // +257
 _dword_ temp_mod_flags; // + 261
 _byte_ field_109[4]; // +265
 _byte_ dd_cast_this_turn; // +269
 _dword_ disguise; // +270
 _dword_ field_112; // +274
 _byte_ d_morale; // +278
 _byte_ field_117[3]; // +279
 _byte_ d_morale_1; // +282
 _byte_ d_luck; // +283
 _byte_ is_sleeping_byte11C; // +284
 _byte_ field_11E[16]; // +284
 _Artifact_ doll_art[19]; // +301
 _byte_ free_add_slots; // +453
 _byte_ locked_slot[14]; // +454
 _Artifact_ backpack_art[64]; // +468
 _byte_ backpack_arts_count; // +980
 _dword_ sex; // +981
 _bool8_ has_biography; // +985
 _HStringF_ biography; // +986
 _byte_ spell[70]; // +1002
 _byte_ spell_level[70]; // +1072
 //_byte_ primary_skill[4];
 _byte_ attack; // +1142
 _byte_ defence; // +1141
 _byte_ power; // +1142
 _byte_ knowledge; // +1143
 _byte_ field_47A[24]; // +1144

 // normal
 void Hide() {CALL_1(void, __thiscall, 0x4D7950, this);}
 void Show(_int_ mapitem_type, _int_ mapitem_setup) {CALL_3(void, __thiscall, 0x4D7840, this, mapitem_type, mapitem_setup);}
 char* Get_className() {return CALL_1(char*, __thiscall, 0x4D91E0, this);}
 int GetLandModifierUnder() {return CALL_1(int, __thiscall, 0x4E5210, this);}

 void GiveArtifact(_Artifact_* art, int a3, int a4) {CALL_4(void, __thiscall, 0x4E32E0, this, art, a3, a4);}
 void GiveArtifact(_int_ art_id, int a3, int a4) 
 {
  _Artifact_ art;
  art.id = art_id;
  art.mod = 0xFFFF;
  GiveArtifact(&art, a3, a4);
 }

 _bool_ DoesHasArtifact(int art_id) {return CALL_2(_bool_, __thiscall, 0x4D9420, this, art_id);}
 _bool_ DoesWearArtifact(int art_id) {return CALL_2(_bool_, __thiscall, 0x4D9460, this, art_id);}
 void RemoveBattleMachine(int creature_id) {CALL_2(void, __thiscall, 0x4D94D0, this, creature_id);}
 int RemoveDollArtifact(int doll_slot_index) {return CALL_2(int, __thiscall, 0x4E2E40, this, doll_slot_index);}
 int AddDollArtifact(_Artifact_* art, int doll_slot_index) {return CALL_3(int, __thiscall, 0x4E2C70, this, art, doll_slot_index);}
 int RemoveBackpackArtifact(int index) {return CALL_2(int, __thiscall, 0x4E2FC0, this, index);}
 int AddBackpackArtifact(_Artifact_* art, int index) {return CALL_3(int, __thiscall, 0x4E3200, this, art, index);}
 int LearnSecondarySkill(int skill_id, int skill_increase) { return CALL_3(int, __thiscall, 0x4E2540, this, skill_id, skill_increase); }
 // 袩芯谢褍褔械薪懈械 斜芯薪褍褋邪 泻 褝褎褎械泻褌褍 蟹邪泻谢懈薪邪薪懈褟 蟹邪 褋锌械褑懈邪谢懈蟹邪褑懈褞.
 _int_ GetSpell_Specialisation_Bonuses(_int_ Spell_id, _int_ Creature_level, _int_ BaseMidif)
 {
   return CALL_4(_int_, __thiscall, 0x4E6260, this, Spell_id, Creature_level, BaseMidif);
 }
 
 
 
 //my

 //inline _bool_ DoesHasDollArtifact(int art_id)
 //{
 // for (int i = 0; i < 19; i++)
 // {
 //  if (this->doll_art[i].id == art_id)
 //   return TRUE;
 // }
 // return FALSE;
 //}

 void ShowSpellBookDlg(int a1, int a2, int land_modifier)
 {
  if (this->doll_art[17].id != -1)
  {
   _Dlg_* dlg = (_Dlg_*)o_New(0xD0);
   // create spellbook dlg
   CALL_5(void, __thiscall, 0x59C0F0, dlg, this, a1, a2, land_modifier);
   dlg->Run();
   // destroy spellbook dlg
   CALL_1(void, __thiscall, 0x59CBF0, dlg);
   o_Delete(dlg);
  }
 }
 void ShowSpellBookDlg(int a1, int a2) 
  {ShowSpellBookDlg(a1, a2, this->GetLandModifierUnder());}
};



NOALIGN struct _Player_
{
 _int8_ id;
 _int8_ heroes_count;
 _word_ field_2;
 _int_ selected_hero_id;
 _int_ heroes_ids[8];

 _int_ tavern_heroes[2];

 _byte_ field_30[13];

 _byte_ days_to_kill; //褋泻芯谢褜泻芯 写薪械泄 写芯 褍斜懈胁邪薪懈褟 谐械褉芯褟 (屑芯卸械褌 斜褘褌褜 >7)
       //械褋谢懈 薪械 FF, 褌芯 胁褋械谐写邪 胁褘写邪械褌 褋芯芯斜褖械薪懈械

 _int8_ towns_count;
 _int8_ selected_town_id;
 _int8_ towns_ids[48];
 _byte_ field_70[44];
 _Resources_ resourses;

 _byte_ field_B8[45];

 _byte_ field_E5;
 _byte_ human;

 _byte_ IsHumanAndWTF() {return CALL_1(_byte_, __thiscall, 0x4BAA40, this);}
 _byte_ IsHuman() {return CALL_1(_byte_, __thiscall, 0x4BAA60, this);}

 void MoveHeroToTownUp(_Town_* town) { CALL_2(void, __thiscall, 0x4B9C80, this, town);}

 //my
 inline _bool_ IsActive() {return (_bool_)(this == o_ActivePlayer);}
};


NOALIGN struct _Town_
{
 _int8_ id;
 _int8_ owner_id;
 _int8_ built_this_turn;
 _byte_ field_03;
 _int8_ type;
 _byte_ x;
 _byte_ y;
 _byte_ z;
 _byte_ boat_x;
 _byte_ boat_y;

 _word_ field_0A;

 _int_ up_hero_id;
 _int_ down_hero_id;

 _int8_ mag_level;
 _byte_ field_15;

 _word_ available_creatures[14];

 _byte_ fields_32[6];
 _dword_ field_38;
 _dword_ field_3C;
 _word_ field_40;
 _word_ field_42;

 _dword_ spells[5][6];
 _byte_ magic_hild[5];

 _byte_ fields_C1[7];

 _char_ name[12];

  int   _u8[3];         //* +D4 = 0

  _Army_ guards; //+E0 = 芯褏褉邪薪邪 蟹邪屑泻邪
  _Army_ guards0; //+118 = 芯褏褉邪薪邪 蟹邪屑泻邪

  _dword_   built_bits; //*B +150h = 褍卸械 锌芯褋褌褉芯械薪薪褘械 蟹写邪薪懈褟 (0400)
  _dword_   built_bits2;
  _dword_   bonus_bits;//*B +158h = 斜芯薪褍褋 薪邪 褋褍褖械褋褌胁, 褉械褋褍褉褋褘 懈 褌.锌., 胁褘蟹胁邪薪薪褘泄 褋褌褉芯械薪懈褟屑懈
  _dword_   bonus_bits2;
  _dword_   available_bits;      //*B- +160h = 屑邪褋泻邪 写芯褋褌褍锌薪褘褏 写谢褟 褋褌褉芯械薪懈褟 褋褌褉芯械薪懈泄
  _dword_   available_bits2;     

 // normal

 char* GetTypeName() {return CALL_1(char*, __thiscall, 0x5C1850, this);}
 _Army_* GetUpArmy() {return CALL_1(_Army_*, __thiscall, 0x5C1860, this);}
 void SwapHeroes() {CALL_1(void, __thiscall, 0x5BE850, this);}
 void MoveHeroDown() {CALL_1(void, __thiscall, 0x5BE790, this);}
    
    // 袩芯褋褌褉芯械薪芯 谢懈 胁 谐芯褉芯写械 蟹写邪薪懈械.
    inline _bool32_ IsBuildingBuilt(_int32_ building_id, _bool32_ unk_unused)
    {
      return CALL_3(_bool32_, __thiscall, 0x4305A0, this, building_id, unk_unused);
    }
    
    
 // my

 //void MoveHeroUp() {o_GameMgr->GetPlayer(o_GameMgr->GetHero(this->down_hero_id)->owner_id)->MoveHeroToTownUp(this);}

};

NOALIGN struct _Spell_
{
 _int_ type; // -1 -enemy, 0 -area, +1 -friend
 _cstr_ wav_name;//+4
 _int_ animation_ix;//+8
 _dword_ flags; //+C
 _cstr_   name;            // +10h
 _cstr_   short_name;        // +14h
 _int_    level;           // +18h
 _dword_  school_flags; // +1Ch Air=1,Fire=2,Water=4,Earth=8
 _int_    mana_cost[4];         // +20h cost mana per skill level
 _int_    eff_power;       // +30h
 _int_    effect[4];       // +34h effect per skill level
 _int_    chance2get_var[9];// +44h chance per class
 _int_    ai_value[4];      // +68h 
 _cstr_   description[4];     // +78h
};


NOALIGN struct _CreatureAnim_ // size = 84 Cranim.txt
{ 
  _int16_ i[6];
  _float_ f[18];  
};

NOALIGN struct _BattleStack_ : _Struct_ // 褉邪蟹屑械褉 0x548
{
 _byte_ already_attack; // +0 ?
 _byte_ field_01;  // +1 ?
 _byte_ field_02;  // +2 ?
 _byte_ field_03;  // +3 ?
 _byte_ field_04[4];  // +4 ?

 _int32_ all_stacks_count; // +8  //锌芯谢薪芯械 褔懈褋谢芯 褋褌械泻芯胁 褍 懈谐褉芯泻邪

 _byte_ field_0C[4];  // +12 0x0C 
 _dword_ field_10;  // +16 0x10  //=-1 锌芯褋谢械 邪褌邪泻懈 懈/懈谢懈 芯褌胁械褌邪(????)
 _byte_ field_14[8];  // +20 0x14  ?

 _int32_ aim_to_move_or_shoot; // 28 +0x1C  //锌芯蟹懈褑懈褟 薪邪 锌芯谢械 斜芯褟 (泻褍写邪 斜械卸邪褌褜/褋褌褉械谢褟褌褜)
 _byte_ fireshield;  // +32 0x20 // 芯谐薪械薪薪褘泄 褖懈褌

 _byte_ field_21[3];  // +33 0x21  ?
 
 // 袧芯屑械褉 褋褌械泻邪 - 褏芯蟹褟懈薪邪 写邪薪薪芯谐芯 泻谢芯薪邪 (-1 - 薪械褌 褏芯蟹褟懈薪邪).
 _int32_ clone_owner_stack_ix; //+36 
 
 //_int32_ clone_index; // +40 0x28 //薪芯屑械褉 褋褌褝泻邪 泻谢芯薪邪 褝褌芯谐芯
 _List_<_int32_>* clones; // 袟邪屑械薪褟械屑 锌芯谢械. 孝械锌械褉褜 褝褌芯 褋锌懈褋芯泻 泻谢芯薪芯胁 褋褌械泻邪.
 
 _byte_ field_2C[4];  // +44 0x2C  ?
 _dword_ field_30;  // +48 0x30  ?

 _int32_ creature_id;    // +52 0x34 // 褌懈锌 屑芯薪褋褌褉邪
 _int32_ hex_ix;   // +56 0x38  //锌芯蟹懈褑懈褟 薪邪 锌芯谢械 斜芯褟 
 _int32_ def_group_ix; // +60 0x3C
 _int32_ def_frame_ix; // +64 0x40

 _dword_ field_44;  // +68 0x44 //(=1) 褋写胁懈谐 胁 褋褌芯褉芯薪褍 胁褌芯褉芯泄 蟹邪薪褟褌芯泄 泻谢械褌泻懈 写谢褟 屑芯薪褋褌褉邪 褋 写胁褍屑褟 泻谢械褌泻邪屑懈
 _dword_ field_48;  // +72 0x48 ?

 _int32_ count_current; // +76 0x4C // 褔懈褋谢芯 屑芯薪褋褌褉芯胁
 _int32_ count_before_attack; // +80 +0x50 // 褔懈褋谢芯 屑芯薪褋褌褉芯胁 写芯 褍写邪褉邪 锌芯 薪懈屑 胁 褌械泻. 邪褌邪泻褍
 
 _dword_ field_54;  // +84 0x54 ?
 
 _int32_ lost_hp;  // +88 0x58 锌芯褌械褉懈 蟹写芯褉芯胁褜褟 锌芯褋谢械写薪械谐芯 屑芯薪褋褌褉邪
 _int32_ army_slot_ix; // +92 0x5C 薪芯屑械褉 褋谢芯褌邪 of _Army_ (0...6), -1 - 斜褍写械褌 褍写邪谢械薪 锌芯褋谢械 斜懈褌胁褘
 _int32_ count_at_start; // +96 0x60 褔懈褋谢芯 屑芯薪褋褌褉芯胁 胁 薪邪褔邪谢械 斜懈褌胁褘
 
 _dword_ field_64;  // +100 0x64 ?
 
 _dword_ anim_value;  // +104 0x68 = cranim.f[15] 锌褉懈 懈薪懈褑懈邪谢懈蟹邪褑懈懈
 _int32_ full_hp;  // +108 0x6C 锌芯谢薪芯械 蟹写芯褉芯胁褜械 (懈褋锌. 泻邪泻 斜邪蟹邪 写谢褟 谢械褔械薪懈褟)
 
 _bool32_ field_70;  // +112 0x70 ?

//////////////////////////////////////////////////////////////////////////////////
 _CreatureInfo_ creature;
//////////////////////////////////////////////////////////////////////////////////
 //_int_ town;  //+116 0x74
 //_int_ level;  //+120 0x78
 //_char_* sound_name;  //+124 0x7C
 //_char_* def_name;  //+128 0x80
 //_int_ flags;  //+132 0x84
 //_char_* name_single;  //+136 0x88
 //_char_* name_plural;  //+140 0x8C
 //_char_* specification_description;  //+144 0x90
 //_int_ cost_wood;  //+148 0x94
 //_int_ cost_mercury;  //+152 0x98
 //_int_ cost_ore;  //+156 0x9C
 //_int_ cost_sulfur;  //+160 0xA0
 //_int_ cost_crystal;  //+164 0xA4
 //_int_ cost_jems;  //+168 0xA8
 //_int_ cost_gold;  //+172 0xAC
 //_int_ fight_value;  //+176 0xB0
 //_int_ AI_value;  //+180 0xB4
 //_int_ growth;  //+184 0xB8
 //_int_ horde_growth;  //+188 0xBC
 //_int_ hit_points;  //+192 0xC0
 //_int_ speed;  //+196 0xC4   
 //_int_ attack;  //+200 0xC8
 //_int_ defence;  //+204 0xCC
 //_int_ damage_min;  //+208 0xD0
 //_int_ damage_max;  //+212 0xD4
 //_int_ shots;  //+216 0xD8
 //_int_ spells_count;  //+220 0xDC
 //_int_ advmap_low;  //+224 0xE0
 //_int_ advmap_high;  //+228 0xE4
///////////////////////////////////////////////////////////////////////////////

 _byte_ field_E8;  // +232 0xE8  ?

 _bool8_ is_1_killed; // +233 0xE9   =1, 械褋谢懈 褍屑懈褉邪谢 褏芯褌褜 芯写懈薪
 _bool8_ is_killed;  // +234 0xEA   =1, 械褋谢懈 斜褘谢 褍斜懈褌 胁械褋褜 褋褌褝泻

 _byte_ field_EB;  // +235 0xEB  ?

 _int32_ current_creatures_spell_id; // +236 0xEC  薪芯屑械褉 蟹邪泻谢懈薪邪薪懈褟 褋褍褖械褋褌胁邪 胁 褌械泻 褉邪褍薪写械 0x50 Acid breath
 
 _int32_ field_F0;  // +240 0xF0  _byte_=1 锌械褉械写 邪褌邪泻芯泄 薪邪 薪械谐芯 441434
 
 _int32_ side;   // +244 0xF4  0 - attacker, 1 - defender
 
 _dword_ index_on_side;    // +248 F8 dd = 薪芯屑械褉 褋褌褝泻邪 褍 褋褌芯褉芯薪褘 薪邪 锌芯谢械 斜芯褟
 _dword_ field_FC;  // +252 FC dd = ? 褔褌芯-褌芯 褋 屑邪谐懈械泄
 _dword_ field_100;  // +256 100 dd 43DEA4
 _dword_ field_104;  // +260 104 dd 43DEAD
 _dword_ field_108;  // +264 108 dd
 _dword_ field_10C;  // +268 10C dd
 
 _CreatureAnim_ cr_anim; // +272 0x110 
 _Def_* def;    // +356 0x164 def 屑芯薪褋褌褉邪, 蟹邪谐褉褍蟹泻邪: 43DA8E
 _Def_* def_shot;  // +360 0x168 def 胁褘褋褌褉械谢邪, 蟹邪谐褉褍蟹泻邪: 43DA8E
 _dword_ field_16C;  // +364 0x16小 ?
 _Wav_* wav_move;  // +368 0x170 蟹胁褍泻 锌械褉械屑械褖械薪懈褟 (move), 蟹邪谐褉褍蟹泻邪: 43DA8E
 _Wav_* wav_attack;  // +372 0x174 蟹胁褍泻 邪褌邪泻懈 (attk/wnce/shot), 蟹邪谐褉褍蟹泻邪: 43DA8E
 _Wav_* wav_wnce;  // +376 0x178 蟹胁褍泻 '泻芯谢写褍械褌' (wnce), 蟹邪谐褉褍蟹泻邪: 43DA8E
 _Wav_* wav_shot;  // +380 0x17C 蟹胁褍泻 胁褘褋褌褉械谢邪 (shot), 蟹邪谐褉褍蟹泻邪: 43DA8E
 _Wav_* wav_kill;  // +384 0x180 蟹胁褍泻 褋屑械褉褌懈 (kill), 蟹邪谐褉褍蟹泻邪: 43DA8E
 _Wav_* wav_defend;  // +388 0x184 蟹胁褍泻 芯斜芯褉芯薪褘 (wnce/dfnd), 蟹邪谐褉褍蟹泻邪: 43DA8E
 _Wav_* wav_ext1;  // +392 0x188 蟹胁褍泻 写芯锌芯谢薪懈褌械谢褜薪褘泄 1 (ext1), 蟹邪谐褉褍蟹泻邪: 43DA8E
 _Wav_* wav_ext2;  // +396 0x18小 蟹胁褍泻 写芯锌芯谢薪懈褌械谢褜薪褘泄 2 (ext2), 蟹邪谐褉褍蟹泻邪: 43DA8E
 
 _dword_ field_190;  // +400 0x190 ?
 
 _int32_ active_spells_count; // +404 0x194 dd = 泻芯谢懈褔械褋褌胁芯 褍卸械 薪邪谢芯卸械薪薪褘褏 蟹邪泻谢懈薪邪薪懈泄
 _int32_ active_spell_duration[81]; // +408 0x198  械褋褌褜 蟹邪泻谢懈薪邪薪懈械 (写谢懈褌械谢褜薪芯褋褌褜) 懈谢懈 薪械褌
 _int32_ active_spells_power[81]; // +732 0x2DC (褋懈谢邪 写械泄褋褌胁懈褟 蟹邪泻谢懈薪邪薪懈褟)
 
 _byte_ field_420[52]; // +1056 0x420 ?
 
 _int32_ retaliations; // +1108 0x454 // 441B17 (泻芯谢-胁芯 芯褌胁械褌芯胁 薪邪 邪褌邪泻褍 0= 薪械 芯褌胁. 薪邪 邪褌邪泻褍)// 薪邪褋褌褉芯泄泻邪 写谢褟 谐褉懈褎芯薪芯胁 46D6A0
 _int32_ bless_value; // +1112 0x458 Bless 写芯斜邪胁泻邪 泻 Max. Damage
 _int32_ curse_value; // +1116 0x45C Curse 褍斜邪胁泻邪 泻 Min. Damage
 _int32_ field_560;  // +1120 0x460 ?
 _int32_ bloodlast_value;// +1124 0x464 Bloodlast 写芯斜邪胁泻邪 泻 袗褌邪泻械 褋 斜芯薪褍褋邪屑懈
 _int32_ precision_value;// +1128 0x468 Precision 写芯斜邪胁泻邪 泻 袗褌邪泻械 褋 斜芯薪褍褋邪屑懈
 
 _byte_ field_46C[32]; // +1132 0x46C ?
 
 _int32_ king_type;  // +1164 0x48C dd KING_123 褌懈锌 (1=KING_1,2=KING_2,3=KING_3) //   懈褋锌 写谢褟 褉邪褋褔械褌邪 Slayer. 袘芯薪褍褋 8 泻 袗褌邪泻械: 0x4421D2     
 _int32_ field_490;  // +1168 0x490 dd 薪芯屑械褉 邪褌邪泻械褉邪 锌芯 锌芯褉褟写泻褍??? 褍卸械 邪褌邪泻芯胁邪谢??? (褋斜褉邪褋褘胁邪械褌褋褟 锌芯褋谢械 锌械褉胁芯谐芯 褍写邪褉邪)
 _int32_ counerstrike_retaliations; // +1172 0x494 dd 泻芯谢. 写芯锌. 芯褌胁械褌芯胁 薪邪 邪褌邪泻褍, 写芯斜邪胁谢械薪薪褘褏 Counerstrike 蟹邪泻谢芯屑
 
 _byte_ field_498[40]; // +1176 0x498 ?
 
 _bool8_ blinded;   // +1216 0x4C0 db Blinded - 褋薪懈蟹懈褌褜 蟹邪褖懈褌褍 (褋斜褉芯褋懈褌褜 锌芯褋谢械?) 锌褉懈 邪褌邪泻械 薪邪 薪械谐芯 (褍褋褌. 锌械褉械写 褍写邪褉芯屑)
 _bool8_ paralized;   // +1217 0x4C1 db Paralized - 褋薪懈蟹懈褌褜 蟹邪褖懈褌褍 (褋斜褉芯褋懈褌褜 锌芯褋谢械?) 锌褉懈 邪褌邪泻械 薪邪 薪械谐芯 (褍褋褌. 锌械褉械写 褍写邪褉芯屑)
 _bool8_ forgetfulness;  // +1218 0x4C2 dd Forgetfulness - 褍褉芯胁械薪褜 (>2 - 薪械 屑芯卸械褌 褋褌褉械谢褟褌褜)
 
 _byte_ field_4C3[25];  // +1219 0x4C3 ?
 
 _int32_ defend_bonus;  // +1244 0x4DC dd = 胁械谢懈褔懈薪邪 斜芯薪褍褋邪 锌褉懈 胁褘斜芯褉械 蟹邪褖懈褌褘
 _int32_ faerie_dragon_spell;// +1248 0x4E0 dd 蟹邪泻谢懈薪邪薪懈械 写谢褟 褋泻邪蟹 写褉邪泻芯薪邪

 _byte_ field_4E4[100];

                     // +4EC dd 44152A
                     // +4F1 db 43DF88

                     // +514 dd
                     // +518 dd -> dd first \ adjusted stacks pointers
                     // +51C dd -> dd last  /

                     // +524 dd
                     // +528 dd -> dd first \ adjusted to wich stacks pointers
                     // +52C dd -> dd last  /


 // normal
 inline _bool_ CanShoot(_BattleStack_* aim = NULL) {return CALL_2(_bool_, __thiscall, 0x442610, this, aim);}
 inline void InitDefsAndWavs() {CALL_1(void, __thiscall, 0x43D710, this);}
 inline void Construct(int creature_id, int count, _Hero_* hero_owner, int side, int index_on_side/*0 - 21*/, int position_hex_ix,  int army_slot_ix)
  {CALL_8(void, __thiscall, 0x43D5D0, this, creature_id, count, hero_owner, side, index_on_side, position_hex_ix, army_slot_ix);}
 
 
 
 // 袩芯写褋褔褢褌 写芯斜邪胁芯泻 泻 薪邪薪芯褋懈屑芯屑褍 褍褉芯薪褍 (胁芯蟹胁褉邪褖邪械褌褋褟 薪芯胁褘泄 褍褉芯薪).
 // Enemy - 褍泻邪蟹邪褌械谢褜 薪邪 邪褌邪泻褍械屑褘泄 褋褌械泻.
 // BaseDamage - 薪邪褔邪谢褜薪褘泄 褍褉芯薪.
 // IsShot - 褟胁谢褟械褌褋褟 谢懈 邪褌邪泻邪 胁褘褋褌褉械谢芯屑 (TRUE - 褟胁谢褟械褌褋褟).
 // Virtual - 褟胁谢褟械褌褋褟 谢懈 锌芯写褋褔褢褌 锌褉芯懈蟹胁芯写懈屑褘屑 袠袠 (TRUE - 褟胁谢褟械褌褋褟).
 // WayLength - 锌褉芯泄写械薪薪褘泄 锌褍褌褜 写芯 褑械谢懈 (写谢褟 褉邪褋褔褢褌邪 泻邪胁邪谢械褉懈泄褋泻芯谐芯 斜芯薪褍褋邪).
 // out_FireshieldDamage - 褍泻邪蟹邪褌械谢褜 薪邪 锌械褉械屑械薪薪褍褞, 胁 泻芯褌芯褉褍褞 胁 褉械蟹褍谢褜褌邪褌械 褉邪斜芯褌褘 褎褍薪泻褑懈懈 蟹邪锌懈褕械褌褋褟 褍褉芯薪 芯褌 芯谐薪械薪薪芯谐芯 褖懈褌邪 (0 - 薪械 锌芯写褋褔懈褌褘胁邪褌褜).
 inline _int32_ Calc_Damage_Bonuses(_BattleStack_* Enemy, _int32_ BaseDamage, _bool8_ IsShot, _bool8_ Virtual, _int32_ WayLength, _int32_* out_FireshieldDamage)
 {
   return CALL_7(_int32_, __thiscall, 0x443C60, this, Enemy, BaseDamage, IsShot, Virtual, WayLength, out_FireshieldDamage);
 }
 
 
 
 
 // 袨褌褉懈褋芯胁泻邪 胁褘褋褌褉械谢邪 褋褌械泻邪 锌芯 锌褉芯褌懈胁薪懈泻褍 懈 锌芯谢褢褌邪 褋薪邪褉褟写邪.
 inline void Draw_Shot(_BattleStack_* Enemy)
 {
   CALL_2(void, __thiscall, 0x43EFE0, this, Enemy);
 }
 
 
 // 袩芯谢褍褔械薪懈械 胁褌芯褉芯谐芯 谐械泻褋邪, 蟹邪薪懈屑邪械屑芯谐芯 褋褌械泻芯屑 (械褋谢懈 褋褌械泻 1-泻谢械褌芯褔薪褘泄, 锌械褉胁芯谐芯).
 inline _int32_ Get_SecondHex_ix()
 {
   return CALL_1(_int32_, __thiscall, 0x4463C0, this);
 }
 
 
 // 校薪懈褔褌芯卸械薪懈械 褋褌械泻邪.
 // dead_itself - 褍屑械褉 谢懈 褋褌械泻 褋邪屑 褋芯斜芯泄 (薪邪锌褉懈屑械褉, 泻邪泻 泻谢芯薪 锌褉懈 谐懈斜械谢懈 褏芯蟹褟懈薪邪 懈谢懈 芯泻芯薪褔邪薪懈懈 写谢懈褌械谢褜薪芯褋褌懈 蟹邪泻谢懈薪邪薪懈褟).
 inline void Die(_bool8_ dead_itself)
 {
   CALL_2(void, __thiscall, 0x443E40, this, dead_itself);
 }
 
 
 
 
 
 // User
 
 // 袩芯谢褍褔械薪懈械 薪芯屑械褉邪 褋褌褉械谢泻芯胁芯泄 斜邪褕薪懈 褋褌械泻邪 (-1 - 褋褌械泻 薪械 褟胁谢褟械褌褋褟 褋褌褉械谢泻芯胁芯泄 斜邪褕薪械泄).
 inline _int32_ Get_ArrowTowerNum()
 {
   // 袙褘斜懈褉邪械屑 薪芯屑械褉 褋褌褉械谢泻芯胁芯泄 斜邪褕薪懈 胁 蟹邪胁懈褋懈屑芯褋褌懈 芯褌 械褢 锌芯蟹懈褑懈懈 (褋褌邪薪写邪褉褌薪褘泄 褋锌芯褋芯斜 懈谐褉褘).
   switch (this->hex_ix)
   {
     case 254:
       return 0;
     case 251:
       return 1;
     case 255:
       return 2;
     default:
       return -1;
   }
 }
 
};




// 小褌褉褍泻褌褍褉邪 褋褌褉械谢泻芯胁芯泄 斜邪褕薪懈 胁 斜芯褞.
NOALIGN struct _ArrowTower_
{
  _int32_ CreatureType; // +0h; 孝懈锌 褋褍褖械褋褌胁邪 斜邪褕薪懈
  _Def_* Def; // +4h; 袟邪谐褉褍卸械薪薪褘泄 def 褋褍褖械褋褌胁邪 斜邪褕薪懈
  _Def_* BulletDef; // +8h; 袟邪谐褉褍卸械薪薪褘泄 def 褋薪邪褉褟写邪 斜邪褕薪懈
  _int32_ X_Position; // +Ch; 袩芯蟹懈褑懈褟 懈蟹芯斜褉邪卸械薪懈褟 褑械薪褌褉邪 褋褍褖械褋褌胁邪 斜邪褕薪懈 锌芯 谐芯褉懈蟹芯薪褌邪谢懈 胁 锌懈泻褋械谢褟褏
  _int32_ Y_Position; // +10h; 袩芯蟹懈褑懈褟 懈蟹芯斜褉邪卸械薪懈褟 薪懈蟹邪 褋褍褖械褋褌胁邪 斜邪褕薪懈 锌芯 胁械褉褌懈泻邪谢懈 胁 锌懈泻褋械谢褟褏
  _int32_ Orientation; // +14h; 袧邪锌褉邪胁谢械薪懈械 (0 - 胁锌褉邪胁芯, 1 - 胁谢械胁芯)
  _int32_ AnimSectionNum; // +18h; 袧芯屑械褉 褋械泻褑懈懈 泻邪写褉芯胁 邪薪懈屑邪褑懈懈 斜邪褕薪懈
  _int32_ AnimFrameNum; // +1Ch; 孝械泻褍褖懈泄 泻邪写褉 褋械泻褑懈懈 邪薪懈屑邪褑懈懈 斜邪褕薪懈
  _int32_ StackNum; // +20h; 袧芯屑械褉 褋褌械泻邪 斜邪褕薪懈 (褋褌芯褉芯薪邪-胁谢邪写械谢械褑 - 胁褋械谐写邪 1)
};






// 小褌褉褍泻褌褍褉邪 斜芯械胁芯谐芯 褝谢械屑械薪褌邪 蟹邪屑泻邪 (屑邪褋褋懈胁 懈蟹 8-屑懈 褝谢械屑械薪褌芯胁 锌芯 0x63BE60).
NOALIGN struct _CastleElement_
{
  _int16_ GexNum; // +0h; 袩芯蟹懈褑懈褟 褝谢械屑械薪褌邪 (懈褋锌芯谢褜蟹褍械褌褋褟 锌褉懈 械谐芯 胁褘斜芯褉械 泻邪泻 褑械谢懈 邪褌邪泻懈)
  _int16_ SecondGex_Row; // +2h; 袪褟写 胁褌芯褉芯泄 锌芯蟹懈褑懈懈 褝谢械屑械薪褌邪 (-1 - 薪械褌)
  _int16_ X_Position; // +4h; 袚芯褉懈蟹芯薪褌邪谢褜薪邪褟 锌芯蟹懈褑懈褟 褝谢械屑械薪褌邪 胁 锌懈泻褋械谢褟褏
  _int16_ Y_Position; // +6h; 袙械褉褌懈泻邪谢褜薪邪褟 锌芯蟹懈褑懈褟 褝谢械屑械薪褌邪 胁 锌懈泻褋械谢褟褏
  _int32_ CastleDrawingPartNum; // +8h; 袧芯屑械褉 褝谢械屑械薪褌邪 蟹邪屑泻邪 褋褉械写懈 胁褋械褏 芯褌褉懈褋芯胁褘胁邪褞褖懈褏褋褟 褔邪褋褌械泄 蟹邪屑泻邪
};











NOALIGN struct _BattleHex_
{
 //_byte_ field_0[112]; //?
 _int16_ X_Position; // +0h; 袩芯蟹懈褑懈褟 褑械薪褌褉邪 谐械泻褋邪 锌芯 谐芯褉懈蟹芯薪褌邪谢懈 胁 锌懈泻褋械谢褟褏
 _int16_ Y_Position; // +2h; 袩芯蟹懈褑懈褟 薪懈蟹邪 谐械泻褋邪 锌芯 胁械褉褌懈泻邪谢懈 胁 锌懈泻褋械谢褟褏
 _int16_ Left; // +4h; X-泻芯芯褉写懈薪邪褌邪 谢械胁芯泄 谐褉邪薪懈褑褘 谐械泻褋邪
 _int16_ Top; // +6h; Y-泻芯芯褉写懈薪邪褌邪 胁械褉褏薪械泄 谐褉邪薪懈褑褘 谐械泻褋邪
 _int16_ Right; // +8h; X-泻芯芯褉写懈薪邪褌邪 锌褉邪胁芯泄 谐褉邪薪懈褑褘 谐械泻褋邪
 _int16_ Bottom; // +Ah; Y-泻芯芯褉写懈薪邪褌邪 薪懈卸薪械泄 谐褉邪薪懈褑褘 谐械泻褋邪
 _byte_ field_C[4]; //?
 _int32_ Flags; // +10h; 肖谢邪谐懈 谐械泻褋邪 (1 - 械褋褌褜 谢懈 锌褉械锌褟褌褋褌胁懈械)
 _int_ ObstacleNum; // +14h; 袧芯屑械褉 锌褉械锌褟褌褋褌胁懈褟, 薪邪褏芯写褟褖械谐芯褋褟 薪邪 褋褌械泻械 (-1 - 薪械褌)
 _byte_ bstack_side;
 _byte_ bstack_index;
 _byte_ field_1A[86]; //?
 
 
 // normal
 _BattleStack_* GetCreature() {return CALL_1(_BattleStack_*, __thiscall, 0x4E7230, this);}
};


// 小褌褉褍泻褌褍褉邪 斜芯械胁芯泄 邪薪懈屑邪褑懈懈.
NOALIGN struct _BattleAnim_
{
  _cstr_ DefName; // 袠屑褟 def`邪 邪薪懈屑邪褑懈懈
  _cstr_ TouchEffect_Name; // 袠屑褟 褌邪泻褌懈谢褜薪芯谐芯 褝褎褎械泻褌邪 邪薪懈屑邪褑懈懈 (写谢褟 械谐芯 胁芯褋锌褉芯懈蟹胁械写械薪懈褟 薪邪 薪械褋褌邪薪写邪褉褌薪褘褏 褝谢械屑械薪褌邪褏 褍锌褉邪胁谢械薪懈褟 褋 锌芯屑芯褖褜褞 IFC20.dll)
  _dword_ Properties; // 小胁芯泄褋褌胁邪 斜芯械胁芯泄 邪薪懈屑邪褑懈懈 (锌芯 薪械褋泻芯谢褜泻芯 斜懈褌芯胁)
  // ***
  // 袧邪褔邪谢芯 芯锌懈褋邪薪懈褟 褋胁芯泄褋褌胁 邪薪懈屑邪褑懈懈
  // ***
    // (褋写胁懈谐 - 褉邪蟹屑械褉 胁 斜懈褌邪褏 - 蟹薪邪褔械薪懈械) 
    // 0 - 4 - 袩芯蟹懈褑懈褟 芯褌芯斜褉邪卸械薪懈褟 (0 - 芯褌 蟹械屑谢懈 薪邪 褋褌械泻械 懈谢懈 谐械泻褋械, 1 - 锌芯褋械褉械写懈薪械 谐械泻褋邪 懈谢懈 褋褌械泻邪, 2 - 胁褘褕械 褋褌械泻邪, 3 - 锌械褉械写 褋褌械泻芯屑, 4 - 褋 薪懈卸薪械泄 懈 谢械胁芯泄 谐褉邪薪懈褑褘 谐械泻褋邪, -1 - 薪械褌 锌芯蟹懈褑懈懈)
    // 4 - 4 - 袧械 懈褋锌芯谢褜蟹褍械褌褋褟
    // 8 - 1 - 袩褉芯蟹褉邪褔薪芯褋褌褜 (0 - 薪械褌, 1 - 械褋褌褜)
    // 9 - 23 - 袧械 懈褋锌芯谢褜蟹褍械褌褋褟
  // ***
  // 袣芯薪械褑 芯锌懈褋邪薪懈褟 褋胁芯泄褋褌胁 邪薪懈屑邪褑懈懈
  // ***
};


NOALIGN struct _BattleMgr_ : _Struct_ 
{
 _byte_ field_0[452]; // + 0 ?
 _BattleHex_ hex[187]; // + 0x1c4 187=17*11
 
 
 _byte_ field_5394[44]; //?
 
 // 孝懈锌 褌械褉褉懈褌芯褉懈懈 (-1 - 薪械褌, 0 - 锌芯斜械褉械卸褜械, 1 - 褉邪胁薪懈薪邪 屑邪谐芯胁, 2 - 锌褉芯泻谢褟褌邪褟 蟹械屑谢褟 懈 褌. 写.)
 _int32_ spec_terr_type;
 
 _byte_ field_53C4[8]; //?

 _Hero_* hero[2]; // + 21452 // 0 - attacker, 1 - defender
 _byte_ field_53D4[212]; // + 21460d褟
 _int32_ owner_id[2]; // + 21672d // 0 - attacker, 1 - defender
 _byte_ field_54B0[12];  // + 21680
 _int32_ stacks_count[2];//+0x54BC  // 0 - attacker, 1 - defender
 _Army_* army[2]; // + 21700 // 0 - attacker, 1 - defender
 //_BattleStack_ stack[42]; //+ 21708
 _BattleStack_ stack[2][21]; //+ 21708

 _byte_ field_1329C[28]; // + 0x1329C
 _int32_ unk_side; // +78520 0x132B8
 _int32_ current_stack_ix; // +78524 0x132BC
 _int32_ current_side; // +78528 0x132C0

 //_byte_ field_132C4[56]; // + 0x132C4
 _byte_ field_132C4[36]; // + 0x132C4
 _Def_* current_spell_def; // + 0x132E8
 _int_  current_spell_id; // + 0x132EC
 _dword_ field_132F0; // + 0x132F0
 _int32_ town_fort_type; // + 0x132F4
 _dword_ field_132F8; // + 0x132F8

 _Dlg_* dlg;    // + 0x132FC
 
 _byte_ f13300[3564]; // +13300h

 // normal
 //inline _Def_* LoadSpellAnimation(int spell_anim_ix)
 inline int GetHexIxAtXY(int x, int y) {return CALL_2(int, __stdcall, 0x464380, x - dlg->x, y - dlg->y);}
 inline void CastSpell(int spell_id, int hex_ix, int cast_type_012, int hex2_ix /*写谢褟 褌械谢械锌芯褉褌邪 懈 卸械褉褌胁褘*/, int skill_level, int spell_power)
  {CALL_7(void, __thiscall, 0x5A0140, 
    this, spell_id, hex_ix, cast_type_012, hex2_ix, skill_level, spell_power);}
 
 
 // 袩褉芯胁械褉泻邪 薪械芯斜褏芯写懈屑芯褋褌懈 芯褌褉懈褋芯胁泻懈 斜懈褌胁褘.
 // 袩褉懈 薪械芯斜褏芯写懈屑芯褋褌懈 芯褌褉懈褋芯胁泻懈 胁芯蟹胁褉邪褖邪械褌 FALSE, 懈薪邪褔械 TRUE.
 inline _bool8_ ShouldNotRenderBattle()
 {
   return CALL_1(_bool8_, __thiscall, 0x46A080, this);
 }
 
 
 
 // 小斜褉芯褋 锌芯谢械泄 薪械芯斜褏芯写懈屑芯褋褌懈 锌械褉械褉懈褋芯胁泻懈.
 inline void ClearRedrawFields()
 {
   return CALL_1(void, __thiscall, 0x493290, this);
 }
 
 
 // 校泻邪蟹邪薪懈械 薪械芯斜褏芯写懈屑芯褋褌懈 锌械褉械褉懈褋芯胁泻懈 锌褉懈 褋谢械写褍褞褖械泄 芯褌褉懈褋芯胁泻械 写谢褟 褋褌械泻邪 - 褋褌褉械谢泻芯胁芯泄 斜邪褕薪懈.
 inline void SetArrowTowerToRedraw(_BattleStack_* Stack)
 {
   return CALL_2(void, __thiscall, 0x46A040, this, Stack);
 }
 
 
 
 // 袨锌褉械写械谢械薪懈械 谐褉邪薪懈褑 锌械褉械褉懈褋芯胁泻懈 写谢褟 泻邪写褉邪 def`邪.
 inline void SetSpecRedrawBorders(_Def_* Def, _int_ DefGroupNum, _int_ FrameNum, _int_ X_Pos, _int_ Y_Pos, _RedrawBorders_* out_Borders, _bool_ Reflected, _bool_ NeedAddToGlobalBorders)
 {
   CALL_9(void, __thiscall, 0x495AD0, this, Def, DefGroupNum, FrameNum, X_Pos, Y_Pos, out_Borders, Reflected, NeedAddToGlobalBorders);
 }
 
 
 
 
 
 // 袙褘褔懈褋谢械薪懈械 谐褉邪薪懈褑 薪械芯斜褏芯写懈屑芯褋褌懈 芯斜薪芯胁谢械薪懈褟 褝泻褉邪薪邪 薪邪 芯褋薪芯胁械 锌芯谢械泄 薪械芯斜褏芯写懈屑芯褋褌懈 锌械褉械褉懈褋芯胁泻懈 斜芯械胁褘褏 褝谢械屑械薪褌芯胁.
 inline void SetRedrawBorders()
 {
   CALL_1(void, __thiscall, 0x495770, this);
 }
 
 
 // 袨褌褉懈褋芯胁泻邪 锌芯谢褟 斜芯褟.
 // Flip - 薪械芯斜褏芯写懈屑芯褋褌褜 芯斜薪芯胁谢械薪懈褟 褝泻褉邪薪邪.
 // SetBattleRedraws - 薪械芯斜褏芯写懈屑芯褋褌褜 薪邪褋褌褉芯泄泻懈 谐褉邪薪懈褑 芯斜薪芯胁谢械薪懈褟 褝泻褉邪薪邪.
 // UseBattleRedraws - 薪械芯斜褏芯写懈屑芯褋褌褜 懈褋锌芯谢褜蟹芯胁邪薪懈褟 谐褉邪薪懈褑 芯斜薪芯胁谢械薪懈褟 褝泻褉邪薪邪 (锌褉懈 SetBattleRedraws = TRUE 懈谐薪芯褉懈褉褍械褌褋褟, 褋褔懈褌邪褟褋褜 TRUE).
 // WaitingTime - 胁褉械屑褟, 薪邪 芯卸懈写邪薪懈械 泻芯褌芯褉芯谐芯 薪邪写芯 薪邪褋褌褉芯懈褌褜 褋谢械写褍褞褖褍褞 芯褌褉懈褋芯胁泻褍 (懈谐薪芯褉懈褉褍械褌褋褟 锌褉懈 Wait = FALSE).
 // RedrawBackground - 薪械芯斜褏芯写懈屑芯褋褌褜 锌械褉械褉懈褋芯胁泻懈 蟹邪写薪械谐芯 锌谢邪薪邪 (懈 褋褌褢褉泻懈 褋褌邪褉芯谐芯 懈蟹芯斜褉邪卸械薪懈褟).
 // Wait - 薪械芯斜褏芯写懈屑芯褋褌褜 芯卸懈写邪薪懈褟. 袙 褋谢褍褔邪械 FALSE 胁褉械屑褟 芯卸懈写邪薪懈褟 写谢褟 褋谢械写褍褞褖械泄 芯褌褉懈褋芯胁泻懈 薪械 屑械薪褟械褌褋褟.
 inline void RedrawBattlefield(_bool8_ Flip, _bool8_ SetBattleRedraws, _bool8_ UseBattleRedraws, _int_ WaitingTime, _bool8_ RedrawBackground, _bool8_ Wait)
 {
   return CALL_7(void, __thiscall, 0x493FC0, this, Flip, SetBattleRedraws, UseBattleRedraws, WaitingTime, RedrawBackground, Wait);
 }
 
 
 // 袨斜薪芯胁谢械薪懈械 胁褋械谐芯 锌芯谢褟 斜芯褟.
 inline void FlipBattlefield()
 {
   CALL_1(void, __fastcall, 0x493300, this);
 }
 
 
 
 
 // 袠薪懈褑懈邪谢懈蟹邪褑懈褟 锌械褉械屑械薪薪褘褏, 褍锌褉邪胁谢褟褞褖懈褏 胁褉械屑械薪械屑 褋谢褍褔邪泄薪褘褏 邪薪懈屑邪褑懈泄.
 inline void InitRandAnimsTimes()
 {
   CALL_1(void, __thiscall, 0x479860, this);
 }
 
 
 // 袩褉芯懈谐褉褘胁邪薪懈械 芯写薪芯谐芯 泻邪写褉邪 邪薪懈屑邪褑懈懈 芯卸懈写邪薪懈褟 锌芯谢褟 斜芯褟.
 // 协褌芯 邪薪懈屑邪褑懈褟 褎谢邪谐芯胁 谐械褉芯械胁, 邪薪懈屑邪褑懈褟 褋邪屑懈褏 谐械褉芯械胁, 褋谢褍褔邪泄薪邪褟 邪薪懈屑邪褑懈褟 褋褍褖械褋褌胁, 屑懈谐邪褞褖邪褟 褉邪屑泻邪 胁芯泻褉褍谐 褋褌械泻芯胁.
 inline void PlayWaitAnim()
 {
   CALL_1(void, __thiscall, 0x495C50, this);
 }
 
 
 // 袩褉芯懈谐褉褘胁邪薪懈械 芯写薪芯谐芯 泻邪写褉邪 邪薪懈屑邪褑懈懈 芯卸懈写邪薪懈褟 锌芯谢褟 斜芯褟 褌芯谢褜泻芯 胁 褋谢褍褔邪械 薪邪褋褌褍锌谢械薪懈褟 胁褉械屑械薪懈.
 inline void PlayWaitAnimOnce()
 {
   CALL_1(void, __thiscall, 0x473970, this);
 }
 
 
 // 袧邪薪械褋械薪懈械 褍褉芯薪邪 褝谢械屑械薪褌褍 蟹邪屑泻邪 锌芯 械谐芯 薪芯屑械褉褍.
 inline void DamageCastleElement(_int_ CastleElementNum, _int_ Damage)
 {
   CALL_3(void, __thiscall, 0x465570, this, CastleElementNum, Damage);
 }
 
 
 
 // 校写邪谢械薪懈械 褋褌械泻邪 褋 谐械泻褋邪, 薪邪 泻芯褌芯褉芯屑 芯薪 褋褌芯懈褌.
 inline void RemoveStackFromGexes(_BattleStack_* Stack)
 {
   CALL_2(void, __thiscall, 0x468310, this, Stack);
 }
 
 
 // 袩芯褋褌邪薪芯胁泻邪 褋褌械泻邪 薪邪 谐械泻褋.
 inline void PutStackToGex(_BattleStack_* Stack, _int_ GexNum)
 {
   CALL_3(void, __thiscall, 0x4683A0, this, Stack, GexNum);
 }
 
 // 校写邪谢械薪懈械 锌褉械锌褟褌褋褌胁懈褟.
 inline void RemoveObstacle(_int_ ObstacleNum)
 {
   CALL_2(void, __thiscall, 0x466710, this, ObstacleNum);
 }
 
 
 
 
 // my
 inline _BattleStack_* GetCurrentStack()
 {
  return &(stack[current_side][current_stack_ix]);
 }

 inline _BattleStack_* GetCreatureAtXY(int x, int y)
 {
  int hex_ix = GetHexIxAtXY(x, y);
  if (hex_ix != ID_NONE) 
   return hex[hex_ix].GetCreature();
  else
   return NULL;
 }
 
 
 
 
  // 校褋褌邪薪芯胁泻邪 锌芯谢褟 锌械褉械褉懈褋芯胁泻懈 写谢褟 褋褌械泻邪.
 inline void Set_Stack_Redrawable(_BattleStack_* Stack)
 {
   // 小锌械褑懈邪谢褜薪邪褟 褎褍薪泻褑懈褟 写谢褟 褋褌褉械谢泻芯胁芯泄 斜邪褕薪懈.
   if (Stack->creature_id == CID_ARROW_TOWER)
   {
     this->SetArrowTowerToRedraw(Stack);
   }
   // 小锌械褑懈邪谢褜薪芯械 锌芯谢械 写谢褟 褋褌械泻芯胁.
   else
   {
     *(_bool8_*)((_dword_)this + 81920 + Stack->side*20 + Stack->index_on_side) = TRUE;
   }
 }
 
 
 
 
 
 
 // 袛芯斜邪胁谢械薪懈械 芯斜谢邪褋褌懈 泻 谐褉邪薪懈褑邪屑 锌械褉械褉懈褋芯胁泻懈. 袙芯蟹胁褉邪褌 薪械芯斜褏芯写懈屑芯褋褌懈 芯褌褉懈褋芯胁泻懈 懈蟹芯斜褉邪卸械薪懈褟 (锌芯 薪邪褋褌褉芯泄泻邪屑).
 // 袙芯蟹胁褉邪褖械薪懈械 薪械芯斜褏芯写懈屑芯褋褌懈 锌械褉械褉懈褋芯胁泻懈.
 inline _bool_ AddUpdateArea(_int_ X_Pos, _int_ Y_Pos, _int_ Width, _int_ Height)
 {
   
   // 袚褉邪薪懈褑褘 锌械褉械褉懈褋芯胁泻懈.
   _RedrawBorders_ Brd;
   
   
   if (*(_bool8_*)((_ptr_)this + 81196) || *(_bool32_*)((_ptr_)this + 81200))
   {
     // 袥械胁邪褟 谐褉邪薪懈褑邪 锌械褉械褉懈褋芯胁泻懈.
     Brd.Left = max(X_Pos, BattleRedraw_Borders.Left);
     // 袙械褉褏薪褟褟 谐褉邪薪懈褑邪 锌械褉械褉懈褋芯胁泻懈.
     Brd.High = max(Y_Pos, BattleRedraw_Borders.High);
     // 袩褉邪胁邪褟 谐褉邪薪懈褑邪 锌械褉械褉懈褋芯胁泻懈.
     Brd.Right = min(X_Pos + Width - 1, BattleRedraw_Borders.Right);
     // 袧懈卸薪褟褟 谐褉邪薪懈褑邪 锌械褉械褉懈褋芯胁泻懈.
     Brd.Low = min(Y_Pos + Height - 1, BattleRedraw_Borders.Low);
     
     if (*(_bool8_*)((_ptr_)this + 81196))
     {
       // 袧邪褋褌褉芯泄泻邪 谐谢芯斜邪谢褜薪褘褏 谐褉邪薪懈褑 锌械褉械褉懈褋芯胁泻懈.
       (*(_int_*)((_ptr_)this + 81208)) = min(*(_int_*)((_ptr_)this + 81208), Brd.Left);
       (*(_int_*)((_ptr_)this + 81212)) = min(*(_int_*)((_ptr_)this + 81212), Brd.High);
       (*(_int_*)((_ptr_)this + 81216)) = max(*(_int_*)((_ptr_)this + 81216), Brd.Right);
       (*(_int_*)((_ptr_)this + 81220)) = max(*(_int_*)((_ptr_)this + 81220), Brd.Low);
     }
     
     if (*(_bool32_*)((_ptr_)this + 81204)) return FALSE;
   }
   
   
   // 袙芯蟹胁褉邪褖邪械屑 薪械芯斜褏芯写懈屑芯褋褌褜 芯褌褉懈褋芯胁泻懈 (械褋谢懈 褏芯褌褜 褔邪褋褌懈褔薪芯 懈蟹芯斜褉邪卸械薪懈械 锌芯锌邪谢芯 胁 谐褉邪薪懈褑褘 锌械褉械褉懈褋芯胁泻懈).
   if (*(_bool32_*)((_ptr_)this + 81200)
       && (Brd.Left > ((_RedrawBorders_*)((_ptr_)this + 81208))->Right || Brd.Right < ((_RedrawBorders_*)((_ptr_)this + 81208))->Left
           || Brd.High > ((_RedrawBorders_*)((_ptr_)this + 81208))->Low || Brd.Low < ((_RedrawBorders_*)((_ptr_)this + 81208))->High))
   {
     return FALSE;
   }
   else
   {
     return TRUE;
   }
 }
 
 
 // 袛芯斜邪胁谢械薪懈械 芯斜谢邪褋褌懈 泻 谐褉邪薪懈褑褘屑 锌械褉械褉懈褋芯胁泻懈 褋锌芯褋芯斜芯屑 褋褌械泻邪.
 // 袙芯蟹胁褉邪褖械薪懈械 薪械芯斜褏芯写懈屑芯褋褌懈 锌械褉械褉懈褋芯胁泻懈.
 inline _bool_ AddSpecUpdateArea(_Def_* Def, _int_ DefGroupNum, _int_ FrameNum, _int_ X_Pos, _int_ Y_Pos, _bool_ Reflected)
 {
   // 袚褉邪薪懈褑褘 锌械褉械褉懈褋芯胁泻懈.
   _RedrawBorders_ Brd;
   
   if (*(_bool8_*)((_ptr_)this + 81196) || *(_bool32_*)((_ptr_)this + 81200))
   {
     this->SetSpecRedrawBorders(Def, DefGroupNum, FrameNum, X_Pos, Y_Pos, &Brd, Reflected, *(_bool8_*)((_ptr_)this + 81196));
     if (*(_bool32_*)((_ptr_)this + 81204)) return FALSE;
   }
   // 袙芯蟹胁褉邪褖邪械屑 薪械芯斜褏芯写懈屑芯褋褌褜 芯褌褉懈褋芯胁泻懈 (械褋谢懈 褏芯褌褜 褔邪褋褌懈褔薪芯 懈蟹芯斜褉邪卸械薪懈械 锌芯锌邪谢芯 胁 谐褉邪薪懈褑褘 锌械褉械褉懈褋芯胁泻懈).
   if (*(_bool32_*)((_ptr_)this + 81200)
       && (Brd.Left > ((_RedrawBorders_*)((_ptr_)this + 81208))->Right || Brd.Right < ((_RedrawBorders_*)((_ptr_)this + 81208))->Left
           || Brd.High > ((_RedrawBorders_*)((_ptr_)this + 81208))->Low || Brd.Low < ((_RedrawBorders_*)((_ptr_)this + 81208))->High))
   {
     return FALSE;
   }
   else
   {
     return TRUE;
   }
 }
 
 
 
 
};

NOALIGN struct _TownStartInfo_ //size = 0x88
{
 _int_ id; //+0
 _byte_ owner_id;//+4
 _byte_ field_5[19];//+5
 _bool8_ has_fort; //+0x18
 _byte_ field_19[3];//+0x19
 _Army_ army;//+0x1C
 _byte_ field_54[20];//+0x54
 _dword_ type;//+0x68
 _byte_ field_6C[28];//+0x54
};

NOALIGN struct _ArmyStartInfo_
{
 _int32_ type[7];
 _int16_ count[7];
};

NOALIGN struct _HeroStartInfo_ //size = 0x334 bytes
{
 _int8_ owner_id;   //! = 褏芯蟹褟懈薪 (褑胁械褌) ff - 薪懈褔械泄
 _byte_ _u1[3];
 _dword_ id;  // = 薪芯屑械褉 锌芯写褌懈锌邪 (泻芯薪泻褉械褌薪褘泄 谐械褉芯泄)
 _dword_ id_wtf;      // = id
 _bool8_ has_name;    // = 1-械褋褌褜 懈屑褟
 _char_ name[13];//! = 懈屑褟,0
 _byte_ has_exp;    // = 1-械褋褌褜 芯锌褘褌
 _byte_ _u2;
 _int_  exp;     //   +1c  dd   = 芯锌褘褌
 _bool8_   has_picture;    //   +20  db   = 1-械褋褌褜 泻邪褉褌懈薪泻邪
 _byte_    picture_id;     //   +21  db   = 薪芯屑械褉 泻邪褉褌懈薪泻懈
 _bool8_   has_second_skills;   //   +22  db   = 1-械褋褌褜 2-械 褋泻懈谢褘
 _byte_ _u3;
 _dword_ second_skills_count;   //!   +24  dd   = 泻芯谢. 胁褌芯褉褘褏 褋泻懈谢芯胁
 _byte_ second_skill[8];//  +28  dd*8 = 薪芯屑械褉邪 胁褌芯褉褘褏 褋泻懈谢芯胁
 _byte_ second_skill_level[8];//   +30  db*8 = 褍褉芯胁薪懈 胁褌芯褉褘褏 褋泻懈谢芯胁
 _bool8_ has_army;    //   +38  db   = 1-械褋褌褜 褋褍褖械褋褌胁邪
 _byte_ _u4[3];

 _ArmyStartInfo_ army; //+3c
 _bool8_ army_is_group;   //   +66  db   = 谐褉褍锌锌邪/褉邪蟹斜褉芯褋

 _bool8_ has_arts;    //   +67  db   = 1-械褋褌褜 邪褉褌懈褎邪泻褌褘
 _Artifact_ doll_art[19];//+68  dd*2*13 = 邪褉褌懈褎邪泻褌褘 dd-薪芯屑械褉,dd-(ff) +e8 -泻薪懈谐邪(3,ff)
 _Artifact_ backpack_art[64];//+100 dd*2*40 = 邪褉褌 胁 褉褞泻蟹邪泻械 dd-薪芯屑械褉, dd-(ff)
 _byte_ backpack_arts_count;   //   +300 db   = 褔懈褋谢芯 邪褉褌懈褎邪泻褌芯胁 胁 褉褞泻蟹邪泻械
 _dword_ xyz;   //   +301 2*dw = 薪邪褔. 锌芯蟹懈褑懈褟 薪邪 泻邪褉褌械
 _byte_ run_radius;     //!   +305 db   = 褉邪写懈褍褋 芯斜械谐邪薪懈褟
 _bool8_ has_biography;    //   +306 db   = 1-械褋褌褜 斜懈芯谐褉邪褎懈褟
 _byte_ _u6;   //+307
 _HStringF_ biography;      //   +308 dd   = 1-胁褘写械谢械薪邪 锌邪屑褟褌褜 锌芯写 斜懈芯谐褉邪褎懈褞
 _int8_ sex;     //   +318 dd   = 0-屑,1-卸,ff-褍屑芯谢褔邪薪懈械
 _byte_ _u9[3];
 _bool8_ has_spells;   //   +31c db   = 1-械褋褌褜 蟹邪泻谢懈薪邪薪懈褟
 _byte_ _u10[3];
 _byte_ spell[10];//  +320 db*a = 蟹邪泻谢懈薪邪薪懈褟
 _word_ _u11;
 _byte_ has_primary_skills;   //   +32c db   = 1-械褋褌褜 锌械褉胁懈褔薪褘械 褍屑械薪懈褟
 _byte_ primary_skill[4];//  +32d db*4 = 4-褉械 锌械褉胁懈褔薪褘褏 褍屑械薪懈褟
 _byte_ _u12[3];
};

#define GAME_HEROES_AVAILABILITY_OFFSET (*(_ptr_*)0x412F1C)
#define GAME_PLAYERS_AVAILABILITY_OFFSET (*(_ptr_*)0x4868FB)

#define GAME_HEROES_OFFSET (*(_ptr_*)0x41C6B5)






// ******************************




// 小锌懈褋芯泻 谐械褉芯械胁.
NOALIGN struct _HeroesList_: public _List_<_Hero_>
{
  // 袧械褌 写芯锌芯谢薪懈褌械谢褜薪褘褏 锌芯谢械泄, 褌芯谢褜泻芯 屑械褌芯写褘.
  
  // 校写邪谢械薪懈械 褋锌懈褋泻邪 谐械褉芯械胁.
  inline void Delete()
  {
    CALL_1(void, __thiscall, 0x45F830, this);
  }
};




// 小褌褉褍泻褌褍褉邪 斜懈褌芯胁芯泄 屑邪褋泻懈 锌褉芯褏芯写懈屑芯褋褌懈 懈 褌褉懈谐谐械褉芯胁 褕邪斜谢芯薪邪.
NOALIGN struct _TmplPosMsk_
{
  // 袩械褉胁褘械 32 斜懈褌邪.
  _dword_ bits0; // +0
  // 袩芯褋谢械写薪懈械 32 斜懈褌邪 (懈褋锌芯谢褜蟹褍褞褌褋褟 褌芯谢褜泻芯 锌械褉胁褘械 16).
  _dword_ bits32; // +4
  
  
  // 校褋褌邪薪芯胁泻邪 胁褋械褏 斜懈褌芯胁 屑邪褋泻懈.
  void SetAll(_dword_ value)
  {
    CALL_2(void, __thiscall, 0x4E6770, this, value);
  }
  
  
  // 校褋褌邪薪芯胁泻邪 褍泻邪蟹邪薪薪芯谐芯 斜懈褌邪 屑邪褋泻懈.
  void SetBit(_int_ bit_ix, _bool8_ value)
  {
    CALL_3(void, __thiscall, 0x506DD0, this, bit_ix, value);
  }
  
  
  // 袩芯谢褍褔械薪懈械 褍泻邪蟹邪薪薪芯谐芯 斜懈褌邪 屑邪褋泻懈.
  _bool8_ GetBit(_int_ bit_ix)
  {
    return CALL_2(_bool8_, __thiscall, 0x506E30, this, bit_ix);
  }
  
};





// 小褌褉褍泻褌褍褉邪 斜懈褌芯胁芯泄 屑邪褋泻懈 写芯褋褌褍锌薪芯褋褌懈 褌械褉褉懈褌芯褉懈泄 褕邪斜谢芯薪邪.
NOALIGN struct _TmplTerrMsk_
{
  // 袩械褉胁褘械 32 斜懈褌邪.
  _dword_ bits0; // +0
  
  
  // 校褋褌邪薪芯胁泻邪 胁褋械褏 斜懈褌芯胁 屑邪褋泻懈.
  void SetAll(_dword_ value)
  {
    CALL_2(void, __thiscall, 0x506ED0, this, value);
  }
  
  
  // 校褋褌邪薪芯胁泻邪 褍泻邪蟹邪薪薪芯谐芯 斜懈褌邪 屑邪褋泻懈.
  void SetBit(_int_ bit_ix, _bool8_ value)
  {
    return CALL_3(void, __thiscall, 0x506E70, this, bit_ix, value);
  }
  
  
  
  // user
  
  // 袩芯谢褍褔械薪懈械 褍泻邪蟹邪薪薪芯谐芯 斜懈褌邪 屑邪褋泻懈.
  _bool8_ GetBit(_int_ bit_ix)
  {
    return (((1 << (bit_ix & 0x1F)) & *(&this->bits0 + (bit_ix >> 5))) != 0);
  }
  
};





// 楔邪斜谢芯薪 芯斜褗械泻褌邪 薪邪 泻邪褉褌械.
// 袨褌胁械褔邪械褌 蟹邪 褌懈锌 芯斜褗械泻褌邪 懈 胁褋械胁芯蟹屑芯卸薪褘械 褋胁芯泄褋褌胁邪, 泻芯褌芯褉褘械 屑芯谐褍褌 斜褘褌褜 褉邪蟹薪褘屑懈 褍 芯写薪芯谐芯 褌锌锌邪 - 锌褉芯褏芯写懈屑芯褋褌褜 懈 褌. 锌.
NOALIGN struct _Template_
{
  // 袠屑褟 def`邪 褕邪斜谢芯薪邪.
  _HStringF_ DefName; // + 0
  // 袪邪蟹屑械褉 褕邪斜谢芯薪邪 锌芯-谐芯褉懈蟹芯薪褌邪谢懈 (胁 泻谢械褌泻邪褏 泻邪褉褌褘).
  _byte_ Size_x; // +16
  // 袪邪蟹屑械褉 褕邪斜谢芯薪邪 锌芯-胁械褉褌懈泻邪谢懈 (胁 泻谢械褌泻邪褏 泻邪褉褌褘).
  _byte_ Size_y; // +17
  _byte_ f12[10]; // +18
  // 袘懈褌芯胁邪褟 屑邪褋泻邪 锌褉芯褏芯写懈屑褘褏 泻谢械褌芯泻 (6*6, 2 斜懈褌邪 胁 泻邪卸写芯屑 斜邪泄褌械 懈 2 斜邪泄褌邪 锌芯谢薪芯褋褌褜褞 薪械 懈褋锌芯谢褜蟹褍褞褌褋褟).
  _TmplPosMsk_ ImpassBitMask; // +28
  _byte_ f24[8]; // +36
  // 袘懈褌芯胁邪褟 屑邪褋泻邪 邪泻褌懈胁懈褉褍械屑褘褏 泻谢械褌芯泻 (6*6, 2 斜懈褌邪 胁 泻邪卸写芯屑 斜邪泄褌械 懈 2 斜邪泄褌邪 锌芯谢薪芯褋褌褜褞 薪械 懈褋锌芯谢褜蟹褍褞褌褋褟).
  _TmplPosMsk_ TriggerBitMask; // +44
  _TmplTerrMsk_ terrs; // +52
  // 孝懈锌 芯斜褗械泻褌邪 褕邪斜谢芯薪邪.
  _int_ ObjType; // +56
  // 袩芯写褌懈锌 芯斜褗械泻褌邪 褕邪斜芯薪邪.
  _int_ ObjSubtype; // +60
  _byte_ f40; // +64
  _byte_ f41[3]; // +65
};



// 袨斜褗械泻褌 薪邪 泻邪褉褌械 锌褉懈泻谢褞褔械薪懈泄.
NOALIGN struct _Object_
{
  _byte_ f0[4]; // +0h
  // X-泻芯芯褉写懈薪邪褌邪 锌芯谢芯卸械薪懈褟 薪邪 泻邪褉褌械
  _byte_ x; // +4h
  // Y-泻芯芯褉写懈薪邪褌邪 锌芯谢芯卸械薪懈褟 薪邪 泻邪褉褌械
  _byte_ y; // +5h
  // Z-泻芯芯褉写懈薪邪褌邪 锌芯谢芯卸械薪懈褟 薪邪 泻邪褉褌械
  _byte_ z; // +6h
  // 袪械蟹褍谢褜褌邪褌 胁褘褉邪胁薪懈胁邪薪懈褟, 薪械 懈褋锌芯谢褜蟹褍械褌褋褟.
  _byte_ dummy_f7[1]; // +7h
  // 袧芯屑械褉 褕邪斜谢芯薪邪 芯斜褗械泻褌邪.
  _int16_ template_id; // +8h
  _byte_ dummy_fA[2]; // +Ah
};



// 袨斜褗械泻褌 - 谢邪谐械褉褜 谐械褉芯褟.
NOALIGN struct _PlaceHolder_
{
  // 袗写褉械褋 芯斜褖械泄 褋褌褉褍泻褌褍褉褘 芯斜褗械泻褌邪 谢邪谐械褉褟.
  _Object_* object; // +0h
  // 袧芯屑械褉 懈谐褉芯泻邪 - 褏芯蟹褟懈薪邪 谢邪谐械褉褟.
  _byte_ player_ix; // +4h
  // 袪械蟹褍谢褜褌邪褌 胁褘褉邪胁薪懈胁邪薪懈褟, 薪械 懈褋锌芯谢褜蟹褍械褌褋褟.
  _byte_ dummy_f5[3]; // +5h
  // 袧芯屑械褉 谐械褉芯褟 谢邪谐械褉褟 (-1 - 锌褉芯懈蟹胁芯谢褜薪褘泄).
  _int_ hero_id; // +8h
  // 校褋谢芯胁薪邪褟 褋懈谢邪 谐械褉芯褟 胁 谢邪谐械褉械 写谢褟 锌褉芯懈蟹胁芯谢褜薪芯谐芯 谐械褉芯褟.
  _byte_ hero_power; // +Ch
  // 袪械蟹褍谢褜褌邪褌 胁褘褉邪胁薪懈胁邪薪懈褟, 薪械 懈褋锌芯谢褜蟹褍械褌褋褟.
  _byte_ dummy_fD[3]; // +Dh
};





// 袣邪褉褌邪 懈谐褉褘 (褉邪蟹屑械褉 3932 懈谢懈 3936 - 薪械懈蟹胁械褋褌薪芯, 芯褌薪芯褋懈褌褋褟 谢懈 锌芯褋谢械写薪械械 dd 泻 泻邪褉褌械 懈谢懈 锌褉芯褋褌芯 泻 GameMgr).
NOALIGN struct _GameMap_
{
  // 小锌懈褋芯泻 褕邪斜谢芯薪芯胁 芯斜褗械泻褌芯胁 泻邪褉褌褘.
  _List_<_Template_> Templates; // +0
  // 小锌懈褋芯泻 芯斜褗械泻褌芯胁 薪邪 泻邪褉褌械.
  _List_<_Object_> Objects; // +16
  
  _byte_ f20[128]; // +32
  
  // 小锌懈褋芯泻 谢邪谐械褉械泄 谐械褉芯褟 薪邪 泻邪褉褌械.
  _List_<_PlaceHolder_> PlaceHolders; // +160
  
  _byte_ fB0[32]; // +176
  
  // 袗写褉械褋 3-屑械褉薪芯谐芯 屑邪褋褋懈胁邪 [L][Y][X], 褏褉邪薪褟褖械谐芯 褋胁芯泄褋褌胁邪 芯斜褗械泻褌邪 泻邪卸写芯泄 泻谢械褌泻懈 泻邪褉褌褘.
  _MapItem_* items; // +208
  // 袪邪蟹屑械褉 泻邪褉褌褘 (锌芯-谐芯褉懈蟹芯薪褌邪谢懈 懈 锌芯-胁械褉褌懈泻邪谢懈).
  _int_ size; // +212
  // 袝褋褌褜 谢懈 褍 泻邪褉褌褘 锌芯写蟹械屑薪褘泄 褍褉芯胁械薪褜.
  _bool8_ has_underground; // +216
  
  _byte_ fD9[3715]; // +217
  
  
  //normal
  // 袩芯谢褍褔械薪懈械 芯斜褗械泻褌邪 泻邪褉褌褘 锌芯 泻芯芯褉写懈薪邪褌邪屑 (懈蟹 屑邪褋褋懈胁邪 items).
  inline _MapItem_* GetItem(_int_ x, _int_ y, _int_ z)
  {
     return CALL_4(_MapItem_*, __thiscall, 0x4086D0, this, x, y, z);
  }
};


// 袟邪谐芯谢芯胁芯褔薪邪褟 懈薪褎芯褉屑邪褑懈褟 泻邪褉褌褘. 袪邪蟹屑械褉: 720 斜邪泄褌.
NOALIGN struct _MapHeader_
{
  // +0.
  _byte_ f0[772];
};




NOALIGN struct _GameMgr_: _Struct_
{
 _dword_ field_0;//+0 ???
 _byte_ disabled_shrines[70]; //+4 //??? //泻邪泻懈械 褋胁褟褌褘薪懈 械褖械 屑芯卸薪芯 锌芯褋褌邪胁懈褌褜 薪邪 泻邪褉褌褍 (0)
 _byte_ disabled_spells[70];//+0x4A //褉邪蟹褉械褕械薪芯 蟹邪泻谢 (0) 薪邪 泻邪褉褌械 懈谢懈 蟹邪锌褉械褖械薪芯 (1)
 LPCRITICAL_SECTION cs_bink;//+0x90 //CriticalSection Object 写谢褟 蟹邪锌褍褋泻邪/芯褋褌邪薪芯胁泻懈 胁懈写械芯 BINKW32.DLL
 _List_<_TownStartInfo_> town_start_info;//+0x94
 _HeroStartInfo_ hero_start_info[156];//+0xA4
 _dword_ field_1F454;//+0x1F454
 _bool8_ is_cheater;//+0x1F458
 
 _byte_ f1F459[1]; // +1F459h
 
 // 袧芯屑械褉 褋褑械薪邪褉懈褟 胁 泻邪屑锌邪薪懈懈 (褋 1).
 _byte_ campaing_scenario_ix; // +1F45Ah
 
 _byte_ f1F45B[1]; // +1F45Bh
 
 // 袧芯屑械褉 泻邪屑锌邪薪懈懈 (芯锌褉械写械谢褟褞褖懈泄 械褢 泻邪褉褌褍 懈 锌褉.)
 _dword_ campaing_ix;  // +1F45Ch
 
 
 _byte_ f1F460[52]; // +1F460h
 
 
 // 小锌懈褋泻懈 褋芯褏褉邪薪褢薪薪褘褏 谐械褉芯械胁 胁 泻邪屑锌邪薪懈懈 写谢褟 锌械褉械褏芯写邪 胁 褋谢械写褍褞褖懈械 褋褑械薪邪褉懈懈.
 _List_<_HeroesList_> saved_heroes_lists; // +1F494h
 
 
 _byte_ f1F4A4[410]; // +1F4A4h
 
 
 // 袧芯屑械褉 褌械泻褍褖械谐芯 写薪褟 (1-7).
 _word_ curr_day_ix; // +1F63Eh
 
 // 袧芯屑械褉 褌械泻褍褖械泄 薪械写械谢懈 (1-4).
 _word_ curr_week_ix; // +1F640h
 
 // 袧芯屑械褉 褌械泻褍褖械谐芯 屑械褋褟褑邪.
 _word_ curr_month_ix; // +1F642h
 
 
 _byte_ f1F644[84]; // +1F644h
 
 
 // 袙械褉褋懈褟 泻邪褉褌褘 (0 - RoE).
 _dword_ map_version; // +1F698h
 
 _byte_ f1F69C[1]; // +1F69Ch
 
 // 携胁谢褟械褌褋褟 谢懈 褌械泻褍褖邪褟 懈谐褉邪 芯斜褍褔械薪懈械屑.
 _bool8_ is_tutorial; // +1F69Dh
 
 _byte_ f1F69E[59]; // +1F69Eh
 
 // 袧邪蟹胁邪薪懈械 褎邪泄谢邪 泻邪褉褌褘.
 char map_name[248]; // +1F6D9h
 
 _byte_ f1F7D1[3]; // +1F6D1h
 
 // 袩褍褌褜 泻 褎邪泄谢褍 泻邪褉褌褘.
 char map_path[100]; // +1F7D4h
 
 
  _byte_ f1F838[52]; // +1F838h
  
  // 袟邪谐芯谢芯胁芯褔薪邪褟 懈薪褎芯褉屑邪褑懈褟 泻邪褉褌褘 懈谐褉褘.
  _MapHeader_ map_header; // +1F86Ch
  
  // 袣邪褉褌邪 懈谐褉褘.
  _GameMap_ Map; // +1FB70h
 
  _byte_ f20ACC[2900]; // +20ACCh
  
  // 袚械褉芯懈 (锌械褉械薪械褋械薪芯).
  _Hero_ hero[156]; // +21620h
  
  // 袩芯谢芯卸械薪懈褟 谐械褉芯械胁 (锌械褉械薪械褋械薪芯).
  _byte_ heroes_aval_abyte4DF18[156]; // +4DF18h
  
  // 袛芯褋褌褍锌薪芯褋褌懈 谐械褉芯械胁 懈谐褉芯泻邪屑 (锌械褉械薪械褋械薪芯).
  _dword_ hero_player_aval_f4DFBD[156]; // +4DFBDh
  
  _byte_ f4E22D[144]; // +4E22Dh
  
  _byte_ arts_aval_abyte4E2BD[144]; // +4E2BDh
  
  _byte_ f4E34D[1164]; // +4E34Dh
  
 
 inline _Player_* GetMe() {return CALL_1(_Player_*, __thiscall, 0x4CE670, this);}
 inline _int_  GetMeID() {return CALL_1(_int_, __thiscall, 0x4CE6E0, this);}
 inline char*  GetPlayerName(_int_ player_id) {return (char*)( ((_ptr_)this) + 0x20AD0 + player_id*0x168 + 0xCC );}

 inline _int_  FindTownIdByXYZ(_int_ x, _int_ y, _int_ z) {return CALL_4(_int_, __thiscall, 0x4BB530,this, x, y, z);}

 inline _Hero_*  GetHero(_int_ hero_id) {return ((_Hero_ *)(((_ptr_)this) + GAME_HEROES_OFFSET /*0x21620*/ + 1170 * hero_id));}
 inline _Player_* GetPlayer(_int_ player_id) {return ((_Player_ *)(((_ptr_)this) + 0x20AD0 + 360 * player_id));}
 inline _Town_*  GetTown(_int_ town_id) {return ((_Town_*)(*(_ptr_*)(((_ptr_)this) + 0x21614) + 360 * town_id));}
 inline _int_  GetTownsCount() {return ((_int_)((*(_dword_*)(((_ptr_)this) + 0x21618) - *(_dword_*)(((_ptr_)this) + 0x21614)) / 360));}
 inline _GlobalEvent_* GetGlobalEvent(_int_ index) {return ((_GlobalEvent_*)(*(_ptr_*)(((_ptr_)this) + 0x1fbf4) + 52 * index));}
 inline _int_  GetGlobalEventsCount() {return ((_int_)((*(_dword_*)(((_ptr_)this) + 0x1fbf8) - *(_dword_*)(((_ptr_)this) + 0x1fbf4)) / 52));}
 inline _int_  GetMapType() {return ( *(_dword_*)(((_ptr_)this) + 0x1f698) );}
 inline char*  GetScenarioName() {return *(char**)((_ptr_)this +  0x1F86C + 0x2D4);}
 inline _word_  GetDay() {return *(_word_*)((_ptr_)this + 0x01F63E);}
 inline _word_  GetWeek() {return *(_word_*)((_ptr_)this + 0x01F640);}
 inline _word_  GetMonth() {return *(_word_*)((_ptr_)this + 0x01F642);}
 inline _int_*  GetMerchantsArts() {return (_int_*)((_ptr_)this + 0x01F664);}
 
 // 锌芯谢褍褔懈褌褜 褌懈锌 褋锌械褑懈邪谢褜薪芯褋褌懈 谐械褉芯褟
// inline _int_  GetHero_SpecInfo(_int_ hero_id, _int_ type) {return *(int*)(*(int*)0x679C80 + hero_id *40 + type);}


 inline _dword_  GetMapWidth() {return *(_dword_*)((_ptr_)this + 0x1FC44);}
 inline _byte_  GetMapDepth() {return *(_byte_*)((_ptr_)this + 0x1FC48);}

 inline _bool_  IsPlayerIngame(_int_ player_id) { return (_bool_)(1 - *(_byte_*)(((_ptr_)this) + 0x1F636 + player_id)); }
 inline _bool_  IsPlayerOutgame(_int_ player_id) { return (_bool_)(*(_byte_*)(((_ptr_)this) + 0x1F636 + player_id)); }

 inline void ReplayOpponentTurn() {CALL_1(void, __thiscall, 0x49D410, this);}
 inline void ShowScenarioInfo() {CALL_1(void, __thiscall, 0x513950, this);}

 inline _byte_ PlayerIsInGameHuman(_int_ player_id) {return CALL_2(_byte_, __thiscall, 0x4CE630, this, player_id);}

 inline void  ShowFullCreatureInfoDlg(_Army_* army, _int_ index, _Hero_* hero, _int_ e0, _int_ x, _int_ y, _int8_ can_fired, _int8_ right_click)
  { CALL_9(void, __thiscall, 0x4C6910, this, army, index, hero, e0, x, y, can_fired, right_click); }

 // my
 inline void ShowFullCreatureInfoDlg(_Army_* army, _int_ index, _Hero_* hero, _int_ x, _int_ y, _bool8_ right_click)
 {

  if (hero)
   CALL_9(void, __thiscall, 0x4C6910, this, army, index, hero, 0, x, y, hero->army.GetStacksCount() > 1, right_click);
  else
   CALL_9(void, __thiscall, 0x4C6910, this, army, index, hero, 0, x, y, TRUE, right_click);
 }
 
  
  
  // user
  
  // 袩芯谢褍褔械薪懈械 谢芯写泻懈 薪邪 泻芯芯褉写懈薪邪褌邪褏.
  _Struct_* GetBoatAtCoords(_int_ x, _int_ y, _int_ z)
  {
    // 袩褉芯褏芯写懈屑 锌芯 胁褋械屑 褋褍褖械褋褌胁褍褞褖懈屑 谢芯写泻邪屑.
    if (this->Field<_List_<_byte_>>(320440).Data)
    {
      for (_ptr_ i = (_ptr_)this->Field<_List_<_byte_>>(320440).Data; i < (_ptr_)this->Field<_List_<_byte_>>(320440).EndData; i += 40)
      {
        // 袥芯写泻邪 褋褍褖械褋褌胁褍械褌 懈 薪械 懈屑械械褌 谐械褉芯褟.
        if (((_Struct_*)i)->Field<_bool8_>(24) && !((_Struct_*)i)->Field<_bool8_>(36))
        {
           // 袥芯写泻邪 - 薪邪 褌械泻褍褖懈褏 泻芯芯褉写懈薪邪褌邪褏.
           if (((_Struct_*)i)->Field<_int16_>(0) == x && ((_Struct_*)i)->Field<_int16_>(2) == y && ((_Struct_*)i)->Field<_int16_>(4) == z)
           {
             return (_Struct_*)i;
           }
        }
      }
    }
    
    // 袧械 薪邪褕谢懈.
    return NULL;
  }
  
  
  // 袩芯褋邪写泻邪 谐械褉芯褟 胁 谢芯写泻褍 薪邪 褌芯屑 屑械褋褌械, 谐写械 芯薪 褋褌芯懈褌 (谐械褉芯泄 写芯谢卸械薪 斜褘褌褜 薪邪 泻邪褉褌械 懈 薪械 胁 谢芯写泻械, 械褋谢懈 谢芯写泻懈 褌邪屑 卸械 薪械褌, 芯薪邪 褋芯蟹写邪褢褌褋褟, 械褋谢懈 械褋褌褜 - 芯薪邪 写芯谢卸薪邪 褌邪屑 褋褌芯褟褌褜 褋 薪邪褔邪谢邪 懈谐褉褘).
  _bool32_ HeroPlaceToBoat(_Hero_* hero, _int_ boat_subtype)
  {
    
    // 袥芯写泻邪.
    _Struct_* boat;
    
    // 小芯蟹写邪褢屑 谢芯写泻褍.
    _int_ boat_ix = CALL_7(_int_, __thiscall, 0x4BAF10, this, hero->x, hero->y, hero->z, hero->owner_id, FALSE, boat_subtype);
    
    // 袧械 褍写邪谢褋褜 褋芯蟹写邪褌褜 谢芯写泻褍.
    if (boat_ix < 0)
    {
      return FALSE;
    }
    // 小谐械薪械褉懈褉芯胁邪谢懈 谢芯写泻褍.
    else
    {
      boat = (_Struct_*)(this->Field<_List_<_byte_>>(320440).Data + 40*boat_ix);
    }
    
    
    
    // 小邪卸邪械屑 谐械褉芯褟 胁 谢芯写泻褍.
    
    
    // 校斜懈褉邪械屑 谢芯写泻褍 懈蟹 懈薪褎芯褉屑邪褑懈懈 泻谢械褌泻懈.
    CALL_1(void, __thiscall, 0x4D7950, boat);
    
    // 袧邪褋褌褉邪懈胁邪械屑 谐械褉芯褟.
    hero->temp_mod_flags |= 0x40000;
    hero->field_112 = -1;
    *(_int32_*)&hero->d_morale = -1;
    
    // 袩械褉械褋褔懈褌褘胁邪械屑 褏芯写褜斜褍 谐械褉芯褟 胁 胁芯写薪褍褞 (new_mp = old_mp*new_max/old_max).
    if (!(hero->temp_mod_flags & 0x1000000))
    {
      _int_ new_max = CALL_2(_int32_, __thiscall, 0x4E4C00, hero, TRUE);
      hero->movement_points = hero->movement_points*new_max/hero->movement_points_max;
      hero->movement_points_max = new_max;
    }
    
    // 袧邪褋褌褉邪懈胁邪械屑 谢芯写泻褍.
    boat->Field<_int32_>(32) = hero->id;
    boat->Field<_bool8_>(36) = TRUE;
    boat->Field<_int8_>(28) = hero->owner_id;
    
    return TRUE;
  }
 
 
};



// ******************************






// *************************************


#define o_GetTime() CALL_0(_dword_, __cdecl, 0x4F8970)

typedef void (__thiscall *_func_MouseMan_SetCursor)(_ptr_ this_, _int_ frame, _int_ type);
#define b_MouseMan_SetCursor(frame, type) ((_func_MouseMan_SetCursor)0x50CEA0)(o_MouseMgr,(_int_)(frame),(_int_)(type))

#define o_GetMapCellVisability(x,y,z) CALL_3(_dword_, __fastcall, 0x4F8040, x, y, z)


// 袦邪泻褋懈屑邪谢褜薪芯械 褋谢褍褔邪泄薪芯械 褔懈褋谢芯.
#define RandMax 0x7FFF

// 小谢褍褔邪泄薪芯械 褔懈褋谢芯 斜械蟹 写懈邪锌邪蟹芯薪邪.
#define Rand() CALL_0(_dword_, __cdecl, 0x61842C)

// 袩芯谢褍褔械薪懈褟 褋谢褍褔邪泄薪芯谐芯 double.
inline double DoubleRand(double low, double high)
{
  return low + (double)Rand()/(double)RandMax*(high - low);
}


// 袩芯谢褍胁褉械屑褟蟹邪胁懈褋懈屑褘泄 褉邪薪芯写芯屑.
// 袙 蟹邪胁懈褋懈芯褋褌懈 芯褌 蟹薪褔械薪懈褟 褋胁芯械泄 褍锌褉邪胁谢褟褞褖械泄 锌械褉械屑械薪薪芯泄 谐械薪械褉懈褉褍械褌 褋谢褍褔邪泄薪芯械 褑械谢芯械 褔懈褋谢芯 胁 褍泻邪蟹邪薪薪褘褏 锌褉械写械谢邪褏 锌芯 seed 懈谢懈 褌械泻褍褖械屑褍 胁褉械屑械薪懈.
#define TRandint(Low, High) CALL_2(_int_, __fastcall, 0x50B3C0, (_int_)Low, (_int_)High)


// 小谢褍褔邪泄薪芯械 褑械谢芯械 褔懈褋谢芯 胁 写懈邪锌邪蟹芯薪械.
#define Randint(Low, High) CALL_2(_int_, __fastcall, 0x50C7C0, (_int_)Low, (_int_)High)


// 袨卸懈写邪薪懈械 写芯 褍泻邪蟹邪薪薪芯谐芯 胁褉械屑械薪懈 (懈谢懈 胁褉械屑械薪懈, 锌褉械胁褘褕邪褞褖械谐芯 褍泻邪蟹邪薪薪芯械).
#define WaitTill(Time) CALL_1(void, __fastcall, 0x4F8980, (_dword_)Time);


// 袧邪褔邪谢芯 褌邪泻褌懈谢褜薪芯谐芯 褝褎褎械泻褌邪 (IFC20.dll, 薪械 锌褉芯褟胁谢褟械褌褋褟 锌褉懈 褋褌邪薪写邪褉褌薪褘褏 褋褉械写褋褌胁邪褏 褍锌褉邪胁谢械薪懈褟).
#define TouchEffectStart(Name, a2) CALL_2(void, __fastcall, 0x4B6750, (_cstr_)Name, (_dword_)a2)

// 袩芯谢褍褔械薪懈械 懈屑械薪懈 褋褍褖械褋褌胁邪 锌芯 械谐芯 薪芯屑械褉褍 懈 泻芯谢懈褔械褋褌胁褍.
#define GetCreatureName(Type, Count) CALL_2(_cstr_, __fastcall, 0x43FE20, (_int_)Type, (_int_)Count)

// 袩芯谢褍褔械薪懈械 谐褉械泄写邪 褋褍褖械褋褌胁邪 (-1 - 薪械褌 谐褉械泄写邪).
#define GetCreatureGrade(Type) CALL_1(_int_, __fastcall, 0x47AAD0, (_int_)Type)


// *************************************








NOALIGN struct _GarrisonBar_
{
 _byte_ field_0[28];
 _int_ x; //+28
 _int_ y; //+32
 _bool_ is_down_bar; //+36
 _int_ owner_id; //+40
 _int_ sel_slot_index;
 _byte_ field_2C[56];
 _Dlg_* parent_dlg;
 _Army_* army; //+108
 _int_ hero_pic; //+112
 _Hero_* hero; //+116

 // normal
 inline void Update(_bool_ a2, _int_ a3) { CALL_3(void, __thiscall, 0x5AA0C0, this, a2, a3); }
 inline void UpdateRedraw(_int_ a2) { CALL_2(void, __thiscall, 0x5AA090, this, a2); }
};

NOALIGN struct _TownMgr_
{
 _byte_ field_0[56];
 
 _Town_* town; //+56
 _byte_ field_48[220];
 _Dlg_* dlg; // +280
 _GarrisonBar_* garribar_up; //+284
 _GarrisonBar_* garribar_down; //+288

 _GarrisonBar_* garribar_sel; //+292
 _int_ garribar_slot_index_sel; //+296

 _GarrisonBar_* garribar_src; //+300
 _int_ garribar_slot_index_src; // +304
 _GarrisonBar_* garribar_dst; //+308
 _int_ garribar_slot_index_dst; //+312

 _ptr_ resources_bar;//+316

 _dword_ field_140;//+320

 _char_ statusbar_text[88]; // +324

 _int_ command_code; //+412
 
 _byte_ f1A0[56]; // +1A0h


 // normal

 void CreateNewGarriBars() {CALL_1(void, __thiscall, 0x5C7210, this);}
 void MoveHeroUp() {CALL_1(void, __thiscall, 0x5D5550, this);}
 void MoveHeroDown() {CALL_1(void, __thiscall, 0x5D5620, this);}

 // my 

 inline void DeleteGarriBars()
 {
  if (this->garribar_up) o_Delete(this->garribar_up); this->garribar_up = NULL;
  if (this->garribar_up) o_Delete(this->garribar_down); this->garribar_down = NULL;
 }

 inline void SwapHeroes() {this->town->SwapHeroes(); DeleteGarriBars(); CreateNewGarriBars();}

};


typedef void (__thiscall * _func_AdvMgr_ActivateHero)(_ptr_ this_, int hero_id, int a3, char a4, char a5);
#define o_AdvMgr_ActivateHero(advmgr, hero_id, a3, a4, a5) ((_func_AdvMgr_ActivateHero)0x417A80)((_ptr_)(advmgr), (int)(hero_id), (int)(a3), (char)(a4), (char)(a5))

typedef _MapItem_* (__thiscall * _func_GetMapItem)(_ptr_ this_, int x, int y, int z);
#define b_GetMapItem(x,y,z) ((_func_GetMapItem)0x4086D0)(*(_ptr_*)(o_AdvMgr + 92),(int)(x),(int)(y),(int)(z))



NOALIGN struct _AdvMgr_
{
 _byte_ field_0[68]; //+0
 _Dlg_* dlg; //+68
 _byte_ field_48[20]; //+72
 _GameMap_* map; //+92
 _byte_ field_60[488]; //+96
 // 肖芯薪芯胁褘械 蟹胁褍泻懈 (褋褋褘谢泻邪 薪邪 蟹胁褍泻 懈谢懈 0, 械褋谢懈 薪械 锌褉芯懈谐褉褘胁邪械褌褋褟).
 _Wav_* loop_sounds[70]; // +584
 _byte_ field_360[52]; //+864
 _int_ current_info_panel_id;//+916
 
 _byte_ f398[32]; // +398h
 
 
 //inline _Dlg_* GetDlg() {return *(_Dlg_**)((_ptr_)this + 68);}
 //inline _int_ GetCurrentInfoPanelID() {return *(_int_*)((_ptr_)this + 916);}
 inline _dword_ FullUpdate(_bool_ redraw_screen) {return CALL_3(_dword_, __thiscall, 0x417380, this, redraw_screen, 0/*not used*/);}
 inline _dword_ RebuildHeroInfoPanel(_bool_ even_if_on_top) {return CALL_2(_dword_, __thiscall, 0x4163B0, this, even_if_on_top);}
 inline _dword_ RebuildTownInfoPanel(_bool_ even_if_on_top) {return CALL_2(_dword_, __thiscall, 0x416450, this, even_if_on_top);}
 inline _dword_ UpdateInfoPanel(_bool_ even_if_on_top, _bool_ redraw, _bool_ redraw_screen)
  {return CALL_4(_dword_, __thiscall, 0x415D40, this, even_if_on_top, redraw, redraw_screen);}
 inline _dword_ RedrawInfoPanel(_bool_ redraw_screen) {return CALL_2(_dword_, __thiscall, 0x402BC0, dlg, redraw_screen);}
 inline _dword_ ViewWorld(_int_ a2, _int_ a3) {return CALL_3(_dword_, __thiscall, 0x5FC340, this, a2, a3);}
 inline _dword_ ShowPuzzleMap() {return CALL_1(_dword_, __thiscall, 0x41A750, this);}
 inline _dword_ DrawMap(_int_ x, _int_ y, _int_ z, _int_ a5, _bool_ update_info_panel)
  { return CALL_6(_dword_, __thiscall, 0x40F350, this, x,y,z, a5, update_info_panel);}
 inline _dword_ DrawMap(_dword_ xyz, _int_ a5, _bool_ update_info_panel)
  { return DrawMap(b_unpack_x(xyz), b_unpack_y(xyz), b_unpack_z(xyz), a5, update_info_panel);}
 inline _dword_ Dig(_int_ x, _int_ y, _int_ z) { return CALL_4(_dword_, __thiscall, 0x40EBF0, this, x,y,z); }
 inline _dword_ Dig() { return Dig(-1,0,0); }
 
 
};


#define o_SwapMan_SplitArmyStack (*(_bool_*)0x6A3D68)
NOALIGN struct _SwapMan_
{
 _byte_ field_0[56];
 _Dlg_* dlg; //+56
 _Pcx8_* pcx8_sel_rect; //+60
 _Hero_* hero[2]; //+64
 _int_ src_hero_ix; //+72
 _int_ dst_hero_ix; //+76
 _int_ src_slot_ix; //+80
 _int_ dst_slot_ix; //+84
 _bool_ slot_selected; //+88
};

//////////////////////////////////////////////////////////////////////////////////////////
//typedef _int8_ (__thiscall *_func_AdvMgr_FullUpdate)(_ptr_ this_, _byte_ redraw, _dword_ unused);
//#define b_AdvMgr_FullUpdate(redraw) ((_func_AdvMgr_FullUpdate)0x417380)(o_AdvMgr, (_byte_)(redraw), 0)

//typedef char (__thiscall * _func_AdvMgr_RebuildHeroInfoPanel)(_ptr_ advmgr, _int8_ a2);
//typedef char (__thiscall * _func_AdvManInfoPanel_Redraw)(_ptr_ this_, _int8_ a2);
//#define o_AdvMgr_RebuildHeroInfoPanel(this_, even_if_not_on_top) ((_func_AdvMgr_RebuildHeroInfoPanel)0x4163B0)((_ptr_)(this_),(_int8_)(even_if_not_on_top))
//#define b_AdvMgr_RedrawInfoPanel(this_, redraw_on_primary_buf) ((_func_AdvManInfoPanel_Redraw)0x402BC0)(*(_ptr_*)(this_ + 68), (_int8_)(redraw_on_primary_buf))

//#define b_AdvmanHeroInfoPanel_Update(draw) {((_func_RebuildAdvmanHeroInfoPanel)0x4163B0)(o_AdvMgr, 1); ((_func_RedrawAdvmanInfoPanel)0x402BC0)(*(_ptr_*)(o_AdvMgr + 68), (_int8_)(draw));}
//#define b_AdvMgr_CurrentInfoPanelID (*(_dword_*)(o_AdvMgr + 916))

//typedef void (__thiscall * _func_AdvMgr_ViewWorld)(_ptr_ this_, _int_ a2, _int_ a3);
//#define b_AdvMgr_ViewWorld(a2, a3) ((_func_AdvMgr_ViewWorld)0x5FC340)(o_AdvMgr, (_int_)(a2), (_int_)(a3))
//#define b_AdvMgr_ShowPuzzleMap() ((_func_this)0x41A750)(o_AdvMgr)

//typedef void (__thiscall *_func_AdvMgr_DrawMap)(_ptr_ this_, _int_ x, _int_ y, _int_ z, _bool_ a5, _bool_ a6);
//#define o_AdvMgr_DrawMap(this_,x,y,z,a5,a6) ((_func_AdvMgr_DrawMap)0x40F350)((_ptr_)(this_),(_int_)(x),(_int_)(y),(_int_)(z),(_bool_)(a5),(_bool_)(a6))
//#define b_AdvMgr_DrawMap(this_,xyz,a5,a6) o_AdvMgr_DrawMap(this_, b_unpack_x(xyz), b_unpack_y(xyz), b_unpack_z(xyz),(_bool_)(a5),(_bool_)(a6))


#define o_Terminate(pchar_reason_text) CALL_1(void, __fastcall, 0x4F3D20, pchar_reason_text)

//typedef void (* _func_PrintToScreenLog)(_ptr_ screen_log, char* format, ...);
//#define b_PrintToScreenLog(format, ...) ((_func_PrintToScreenLog)0x553C40)(o_ScreenLogStruct, (char*)(format), __VA_ARGS__)
#define b_PrintToScreenLog(format, ...) ((void (__cdecl *)(_ptr_, char*, ...))0x553C40)(o_ScreenLogStruct, (char*)(format), __VA_ARGS__)

typedef int (__cdecl * _func__beginthread)(_ptr_ func, SIZE_T dwStackSize, _ptr_ arg);
#define o__beginthread(func, stack_size, arg) ((_func__beginthread)0x61A56C)((_ptr_)(func), (SIZE_T)(stack_size), (_ptr_)(arg))




//////typedef LRESULT (CALLBACK *_func_WndProc)(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
//////#define o_WndProc(hWnd, message, wParam, lParam) ((_func_WndProc)0x4F8290)((HWND)(hWnd),(UINT)(message),(WPARAM)(wParam),(LPARAM)(lParam))


NOALIGN struct _InputMgr_
{
 __declspec(noinline) void SendEventMsg(int type, int subtype, int id, int x, int y, int flags, int flags_2, int new_param) // +0h
 {
  if ( (_ptr_)this )
  {
   if ( *((_ptr_ *)(_ptr_)this + 13) == 1 )
   {
    _ptr_ v = 32 * *((_ptr_ *)(_ptr_)this + 527);
    _EventMsg_ * msg = (_EventMsg_ *)((_ptr_)this + v + 56);
    *(_ptr_ *)((_ptr_)this + v + 68) = 0;

    ///
    msg->type = type;
    msg->subtype = subtype;
    msg->item_id = id;
    msg->x_abs = x;
    msg->y_abs = y;
    msg->flags = flags;
    msg->flags_2 = flags_2;
    msg->new_param = new_param;
    ///

    ++*((_ptr_ *)(_ptr_)this + 527);
    *((_ptr_ *)(_ptr_)this + 527) %= 64;
    if ( *((_ptr_ *)(_ptr_)this + 526) == *((_ptr_ *)(_ptr_)this + 527) )
    {
     *((_ptr_ *)(_ptr_)this + 526) += 1;
     *((_ptr_ *)(_ptr_)this + 526) %= 64;
    }
    *((_ptr_ *)(_ptr_)this + 597) = 0;
   }
  }
 }
 
 
 _byte_ f4[48]; // +4h
 
 // 袙芯蟹屑芯卸械薪 谢懈 锌褉懈褢屑 褋芯斜褘褌懈泄.
 _bool32_ CanRecieveMsg; // +34h
 // 袩褉懈薪褟褌褘械 褋芯斜褘褌懈褟.
 // 袩褉懈 芯泻芯薪褔邪薪懈懈 屑邪褋褋懈胁邪 芯薪 薪邪褔懈薪邪械褌 蟹邪锌芯谢薪褟褌褜褋褟 褋薪邪褔邪谢邪 (褌. 械. 斜褍写褍褌 蟹邪褌懈褉邪褌褜褋褟 褋邪屑褘械 褉邪薪薪懈械 褋芯斜褘褌懈褟).
 _EventMsg_ Msg[64]; // +38h
 // 袧芯屑械褉 锌械褉胁芯谐芯 褋芯斜褘褌懈褟 写谢褟 芯斜褉邪斜芯褌泻懈.
 // 袩褉懈 锌械褉械锌芯谢薪械薪懈懈 屑邪褋褋懈胁邪 斜褍写械褌 懈蟹屑械薪褟褌褜褋褟, 褔褌芯斜褘 胁褋械谐写邪 褍泻邪蟹褘胁邪褌褜 薪邪 褋邪屑芯械 褉邪薪薪械械 褋芯芯斜褖械薪懈械.
 _int_ FirstMsg_ix; // +838h
 // 袧芯屑械褉 褋芯斜褘褌懈褟, 胁 泻芯褌芯褉芯械 蟹邪锌懈褕械褌褋褟 褋谢械写褍褞褖械械 锌褉懈薪褟褌芯械.
 _int_ NextMsg_ix; // +83Ch
 
 _byte_ f840[288]; // +840h
 
 
 // 袙蟹褟褌懈械 锌械褉胁芯谐芯 褋芯斜褘褌懈褟 懈蟹 芯褔械褉械写懈.
 // out_event_msg - 邪写褉械褋 褋芯芯斜褖械薪懈褟, 胁 泻芯褌芯褉芯械 蟹邪锌懈褕械褌褋褟 懈薪褎芯褉屑邪褑懈褟.
 inline void Peek_Event(_EventMsg_* out_event_msg)
 {
   CALL_2(void, __thiscall, 0x4EC660, this, out_event_msg);
 }
 
};





// 袦械薪械写卸械褉 蟹胁褍泻邪 (褉邪蟹屑械褉 薪械懈蟹胁械褋褌械薪, 锌芯泻邪 - 写谢褟 芯锌懈褋邪薪懈褟 屑械褌芯写芯胁).
NOALIGN struct _SoundMgr_
{
  _byte_ f0[216]; // +0h
  
  // 小褌邪褉褌 锌褉芯懈谐褉褘胁邪薪懈褟 蟹胁褍泻邪 (胁芯蟹胁褉邪褖械薪懈褟 懈薪写械泻褋邪 褋褉械写懈 锌褉芯懈谐褉褘胁邪械屑褘褏 蟹胁褍泻芯胁).
  inline _dword_ StartSample(_Wav_* Wav)
  {
    return CALL_2(_dword_, __thiscall, 0x59A510, this, Wav);
  }
};





// ********************************************


// 小芯褋褌芯褟薪懈械 斜邪薪泻邪 褋褍褖械褋褌胁.
// 袣邪卸写褘泄 斜邪薪泻 屑芯卸械褌 斜褘褌褜 胁 芯写薪芯屑 懈蟹 褔械褌褘褉褢褏 褋芯褋褌芯褟薪懈泄, 褋谢褍褔邪泄薪芯 胁褘斜懈褉邪褞褖械屑褋褟 胁 薪邪褔邪谢械 懈谐褉褘.
// 小芯褋褌芯褟薪懈械 芯锌褉械写械谢褟械褌 芯褏褉邪薪褍 懈 薪邪谐褉邪写褍 斜邪薪泻邪.
NOALIGN struct _CrBankState_
{
  // 袟邪褖懈褌薪懈泻懈 斜邪薪泻邪.
  _Army_ defenders; // +0h
  
  // 袣芯谢懈褔械褋褌胁邪 褉械褋褍褉褋芯胁, 胁褏芯写褟褖懈褏 胁 褋芯褋褌邪胁械 薪邪谐褉邪写褘.
  _int_ resources_award[7]; // +38h
  
  // 孝懈锌 褋褍褖械褋褌胁邪, 胁褏芯写褟褖械谐芯 胁 褋芯褋褌邪胁 薪邪谐褉邪写褘.
  _int_ creatures_award_ix; // +54h
  // 袣芯谢懈褔械褋褌胁芯 褋褍褖械褋褌胁 褋芯芯褌胁械褌褋褌胁褍褞褖械谐芯 褌懈锌邪, 胁褏芯写褟褖械械 胁 褋芯褋褌邪胁 薪邪谐褉邪写褘.
  _byte_ creatures_award_count; // +58h
  
  // 袗斜褋芯谢褞褌薪芯械 蟹薪邪褔械薪懈械 褕邪薪褋邪 胁褘锌邪写械薪懈褟 写邪薪薪芯谐芯 褋芯褋褌芯褟薪懈褟.
  // 袪械邪谢褜薪褘泄 褕邪薪褋 蟹邪胁懈褋懈褌 芯褌 邪斜褋芯谢褞褌薪褘褏 蟹薪邪褔械薪懈泄 胁褋械褏 褋芯褋褌芯褟薪懈泄, 薪芯 芯斜褘褔薪芯 芯薪懈 胁 褋褍屑屑械 写邪褞褌 100, 褌. 械. 褝褌芯 锌褉芯褑械薪褌褘.
  _byte_ chance; // +59h
  
  // 楔邪薪褋 锌芯褟胁谢械薪懈褟 褍谢褍褔褕械薪薪芯谐芯 褋褌械泻邪 褋褉械写懈 蟹邪褖懈褌薪懈泻芯胁 斜邪薪泻邪 锌褉懈 胁蟹褟褌懈懈 胁 锌褉芯褑械薪褌邪褏.
  _byte_ upgrade_chance; // +5Ah
  
  // 袣芯谢懈褔械褋褌胁芯 邪褉褌械褎邪泻褌芯胁-褋芯泻褉芯胁懈褖, 胁褏芯写褟褖懈褏 胁 褋芯褋褌邪胁 薪邪谐褉邪写褘.
  _byte_ arts_treasure_count; // +5Bh
  // 袣芯谢懈褔械褋褌胁芯 屑邪谢褘褏 邪褉褌械褎邪泻褌芯胁, 胁褏芯写褟褖懈褏 胁 褋芯褋褌邪胁 薪邪谐褉邪写褘.
  _byte_ arts_minor_count; // +5Ch
  // 袣芯谢懈褔械褋褌胁芯 胁械谢懈泻懈褏 邪褉褌械褎邪泻褌芯胁, 胁褏芯写褟褖懈褏 胁 褋芯褋褌邪胁 薪邪谐褉邪写褘.
  _byte_ arts_major_count; // +5Dh
  // 袣芯谢懈褔械褋褌胁芯 邪褉褌械褎邪泻褌芯胁-褉械谢懈泻褌芯胁, 胁褏芯写褟褖懈褏 胁 褋芯褋褌邪胁 薪邪谐褉邪写褘.
  _byte_ arts_relic_count; // +5Eh
  
  // 袪械蟹褍谢褜褌邪褌 胁褘褉邪胁薪懈胁邪薪懈褟, 薪械 懈褋锌芯谢褜蟹褍械褌褋褟.
  _byte_ dummy_f5F[1]; // +5Fh
};



// 孝懈锌 斜邪薪泻邪 褋褍褖械褋褌胁 泻邪泻 芯斜褗械泻褌邪 薪邪 泻邪褉褌械.
// 啸褉邪薪懈褌 胁 褋械斜械 胁芯蟹屑芯卸薪褘械 褋芯褋褌芯褟薪懈褟 斜邪薪泻邪 褋褍褖械褋褌胁 (褌. 械. 械谐芯 芯褏褉邪薪褍 懈 薪邪谐褉邪写褍).
NOALIGN struct _CrBankType_
{
  // 袙褋械谐写邪 1.
  _byte_ setup; // +0h
  
  // 袪械蟹褍谢褜褌邪褌 胁褘褉邪胁薪懈胁邪薪懈褟, 薪械 懈褋锌芯谢褜蟹褍械褌褋褟.
  _byte_ dummy_f1[3]; // +1h
  
  // 袠屑褟 斜邪薪泻邪.
  _HStringA_ name; // +4h
  
  // 袙芯蟹屑芯卸薪褘械 褋芯褋褌芯褟薪懈褟 斜邪薪泻邪.
  _CrBankState_ States[4]; // +Ch
  
  
  
  
  
  
  // 袣芯薪褋褌褉褍泻褌芯褉.
  inline _CrBankType_* Contruct()
  {
    return CALL_1(_CrBankType_*, __thiscall, 0x47A400, this);
  }
};



// ********************************************


// 袙薪械褕薪械械 卸懈谢懈褖械 薪邪 泻芯褉褌械.
NOALIGN struct _Dwelling_
{
  // 孝懈锌 卸懈谢懈褖邪 泻邪泻 芯斜褗械泻褌邪 (17 - 芯斜褘褔薪芯械, 20 - 褋 4 褋褍褖械褋褌胁邪屑懈).
  _byte_ type;
  // 袩芯写褌懈锌 卸懈谢懈褖邪 泻邪泻 芯斜褗械泻褌邪.
  _byte_ subtype;
  _byte_ f2;
  _byte_ f3;
  // 孝懈锌褘 褋褍褖械褋褌胁, 写芯褋褌褍锌薪褘褏 写谢褟 薪邪泄屑邪 (-1 - 薪械褌).
  _int_  creature_types[4];
  // 袣芯谢懈褔械褋褌胁邪 褋褍褖械褋褌胁, 写芯褋褌褍锌薪褘褏 写谢褟 薪邪泄屑邪.
  _word_ creature_counts[4];
  // 袟邪褖懈褌薪懈泻懈 卸懈谢懈褖邪.
  _Army_ defenders;
  // X-泻芯芯褉写懈薪邪褌邪 薪邪 泻邪褉褌械.
  _byte_ x;           // +54 db (3)
  // Y-泻芯芯褉写懈薪邪褌邪 薪邪 泻邪褉褌械.
  _byte_ y;           // +55 db
  // 袧邪褏芯写懈褌褋褟 谢懈 胁 锌芯写蟹械屑械谢褜械.
  _bool8_ l;
  // 袠谐褉芯泻-褏芯蟹褟懈薪 (-1 - 薪械褌).
  _int8_ owner_ix;
  _byte_ f58;
  _byte_ f59;
  _byte_ f5A;
  _byte_ f5B;
  
  // 袣芯薪褋褌褉褍泻褌芯褉.
  inline _Dwelling_* Contruct()
  {
    return CALL_1(_Dwelling_*, __thiscall, 0x4B8250, this);
  }
};

// ********************************************



















// 12 bytes. 小芯泻褉芯胁懈褖械 蟹芯薪褘 谐械薪械褉邪褌芯褉邪 褋谢褍褔泄薪褘褏 泻邪褉褌.
NOALIGN struct _ZoneTreasure_
{
  // +0. 袦懈薪懈屑邪谢褜薪邪褟 褑械薪薪芯褋褌褜.
  _int32_ min_value;
  
  // +4. 袦懈薪懈屑邪谢褜薪邪褟 褑械薪薪芯褋褌褜.
  _int32_ max_value;
  
  // +8. 效邪褋褌芯褌邪 锌芯褟胁谢械薪懈褟.
  _int32_ density;
};


// 28 bytes. 小胁褟蟹褜 蟹芯薪褘  谐械薪械褉邪褌芯褉邪 褋谢褍褔泄薪褘褏 泻邪褉褌 褋 写褉褍谐芯泄.
NOALIGN struct _ZoneConnection_
{
  // +0. 袧邪褋褌褉芯泄泻懈 蟹芯薪褘, 褋 泻芯褌芯褉芯泄 褋胁褟蟹邪薪邪 褌械泻褍褖邪褟.
  _ZoneSettings_ *another_zone_settings;
  
  // +4. 笑械薪薪芯褋褌褜 锌褉芯褏芯写邪.
  _int32_ value;
  
  // +8. 楔懈褉芯泻懈泄 谢懈 锌褉芯褏芯写.
  _bool8_ is_wide;
  
  // +9. 袨褏褉邪薪褟械褌褋褟 谢懈 褋褌褉邪卸械屑 谐褉邪薪懈褑褘.
  _bool8_ has_border_guard;
  
  // +10. 袘褘谢邪 谢懈 褍卸械 褋芯蟹写邪薪邪 薪邪 蟹邪谐芯褌芯胁泻械 泻邪褉褌褘.
  _bool8_ is_created;
  
  // +11. 袪械蟹褍谢褜褌邪褌 胁褘褉邪胁薪懈胁邪薪懈褟, 薪械 懈褋锌芯谢褜蟹褍械褌褋褟.
  _byte_ dummy_f11[1];
  
  // +12. 袦懈薪懈屑邪谢褜薪芯械 泻芯谢懈褔械褋褌胁芯 蟹芯薪 褔械谢芯胁械泻邪, 薪械芯斜褏芯写懈屑芯械 写谢褟 锌芯褟胁谢械薪懈褟 褋胁褟蟹懈.
  _int32_ min_human_pos;
  
  // +16. 袦邪泻褋懈屑邪谢褜薪芯械 泻芯谢懈褔械褋褌胁芯 蟹芯薪 褔械谢芯胁械泻邪, 锌芯写褏芯写褟褖械械 写谢褟 锌芯褟胁谢械薪懈褟 褋胁褟蟹懈.
  _int32_ max_human_pos;
  
  // +20. 袦懈薪懈屑邪谢褜薪芯械 泻芯谢懈褔械褋褌胁芯 蟹芯薪 懈谐褉芯泻芯胁, 薪械芯斜褏芯写懈屑芯械 写谢褟 锌芯褟胁谢械薪懈褟 褋胁褟蟹懈.
  _int32_ min_total_pos;
  
  // +24. 袦邪泻褋懈屑邪谢褜薪芯械 泻芯谢懈褔械褋褌胁芯 蟹芯薪 懈谐褉芯泻芯胁, 锌芯写褏芯写褟褖械械 写谢褟 锌芯褟胁谢械薪懈褟 褋胁褟蟹懈.
  _int32_ max_total_pos;
};


// 212 bytes. 袧邪褋褌褉芯泄泻懈 蟹芯薪褘 谐械薪械褉邪褌芯褉邪 褋谢褍褔泄薪褘褏 泻邪褉褌.
NOALIGN struct _ZoneSettings_
{
  // +0. 袧芯屑械褉 蟹芯薪褘.
  _int32_ id;
  
  // +4. 孝懈锌 蟹芯薪褘 (0 - 蟹芯薪邪 褔械谢芯胁械泻邪, 1 - 蟹芯薪邪 袠袠, 2 - 褋芯泻褉芯胁懈褖薪懈褑褘, 3 - 锌褍褋褌邪褟).
  _int32_ type;
  
  // +8. 袘邪蟹芯胁褘泄 褉邪蟹屑械褉 蟹芯薪褘.
  _int32_ base_size;
  
  // +12. 袦懈薪懈屑邪谢褜薪芯械 泻芯谢懈褔械褋褌胁芯 蟹芯薪 褔械谢芯胁械泻邪, 薪械芯斜褏芯写懈屑芯械 写谢褟 锌芯褟胁谢械薪懈褟 蟹芯薪褘.
  _int32_ min_human_pos;
  
  // +16. 袦邪泻褋懈屑邪谢褜薪芯械 泻芯谢懈褔械褋褌胁芯 蟹芯薪 褔械谢芯胁械泻邪, 锌芯写褏芯写褟褖械械 写谢褟 锌芯褟胁谢械薪懈褟 蟹芯薪褘.
  _int32_ max_human_pos;
  
  // +20. 袦懈薪懈屑邪谢褜薪芯械 泻芯谢懈褔械褋褌胁芯 蟹芯薪 懈谐褉芯泻芯胁, 薪械芯斜褏芯写懈屑芯械 写谢褟 锌芯褟胁谢械薪懈褟 蟹芯薪褘
  _int32_ min_ai_pos;
  
  // +24. 袦邪泻褋懈屑邪谢褜薪芯械 泻芯谢懈褔械褋褌胁芯 蟹芯薪 懈谐褉芯泻芯胁, 锌芯写褏芯写褟褖械械 写谢褟 锌芯褟胁谢械薪懈褟 蟹芯薪褘.
  _int32_ max_ai_pos;
  
  // +28. 袠谐褉芯泻 - 胁谢邪写械谢械褑 蟹芯薪褘.
  _int32_ owner;
  
  // +32. 袦懈薪懈屑邪谢褜薪芯械 泻芯谢懈褔械褋褌胁芯 谐芯褉芯写芯胁 斜械蟹 褎芯褉褌邪 懈谐褉芯泻邪.
  _int32_ min_player_towns;
  
  // +36. 袦懈薪懈屑邪谢褜薪芯械 泻芯谢懈褔械褋褌胁芯 谐芯褉芯写芯胁 褋 褎芯褉褌芯屑 懈谐褉芯泻邪.
  _int32_ min_player_castles;
  
  // +40. 效邪褋褌芯褌邪 锌芯褟胁谢械薪懈褟 谐芯褉芯写芯胁 斜械蟹 褎芯褉褌邪 懈谐褉芯泻邪.
  _int32_ player_towns_density;
  
  // +44. 效邪褋褌芯褌邪 锌芯褟胁谢械薪懈褟 谐芯褉芯写芯胁 褋 褎芯褉褌芯屑 懈谐褉芯泻邪.
  _int32_ player_castles_density;
  
  // +48. 袦懈薪懈屑邪谢褜薪芯械 泻芯谢懈褔械褋褌胁芯 薪械泄褌褉邪谢褜薪褘褏 谐芯褉芯写芯胁 斜械蟹 褎芯褉褌邪.
  _int32_ min_neutral_towns;
  
  // +52. 袦懈薪懈屑邪谢褜薪芯械 泻芯谢懈褔械褋褌胁芯 薪械泄褌褉邪谢褜薪褘褏 谐芯褉芯写芯胁 褋 褎芯褉褌芯屑.
  _int32_ min_neutral_castles;
  
  // +56. 效邪褋褌芯褌邪 锌芯褟胁谢械薪懈褟 薪械泄褌褉邪谢褜薪褘褏 谐芯褉芯写芯胁 斜械蟹 褎芯褉褌邪.
  _int32_ neutral_towns_density;
  
  // +60. 效邪褋褌芯褌邪 锌芯褟胁谢械薪懈褟 薪械泄褌褉邪谢褜薪褘褏 谐芯褉芯写芯胁 褋 褎芯褉褌芯屑.
  _int32_ neutral_castles_density;
  
  // +64. 袛芯谢卸薪褘 谢懈 胁褋械 谐芯褉芯写邪 蟹芯薪褘 锌褉懈薪邪写谢械卸邪褌褜 芯写薪芯屑褍 褌懈锌褍.
  _bool8_ towns_are_the_same_type;
  
  // +65. 袛芯褋褌褍锌薪芯褋褌褜 谐芯褉芯写芯胁.
  _bool8_ towns_aval[9];
  
  // +74. 袪械蟹褍谢褜褌邪褌 胁褘褉邪胁薪懈胁邪薪懈褟, 薪械 懈褋锌芯谢褜蟹褍械褌褋褟.
  _byte_ dummy_f4A[2];
  
  // +76. 袦懈薪懈屑邪谢褜薪芯械 泻芯谢懈褔械褋褌胁芯 褕邪褏褌 泻邪卸写芯谐芯 褌懈锌邪.
  _int32_ min_mines[7];
  
  // +104. 效邪褋褌芯褌邪 锌芯褟胁谢械薪懈褟 褕邪褏褌 泻邪卸写芯谐芯 褌懈锌邪.
  _int32_ mines_density[7];
  
  // +132. 小芯芯褌胁械褌褋褌胁褍械褌 谢懈 褌懈锌 褌械褉褉懈褌芯褉懈懈 褉芯写薪芯泄 蟹械屑谢械 谐芯褉芯写邪.
  _bool8_ terr_match_to_town;
  
  // +133. 袛芯褋褌褍锌薪芯褋褌懈 褌懈锌芯胁 褌械褉褉懈褌芯褉懈泄.
  _bool8_ terrs_aval[8];
  
  // +141. 袪械蟹褍谢褜褌邪褌 胁褘褉邪胁薪懈胁邪薪懈褟, 薪械 懈褋锌芯谢褜蟹褍械褌褋褟.
  _byte_ dummy_f8D[3];
  
  // +144. 小懈谢邪 屑芯薪褋褌褉芯胁 (0 - 薪械褌 屑芯薪褋褌褉芯胁, 1 - 褋谢邪斜褘械, 2 - 褋褉械写薪懈械, 3 - 褋懈谢褜薪褘械).
  _int32_ monsters_strength;
  
  // +148. 小芯芯褌胁械褌褋褌胁褍褞褌 谢懈 褌懈锌褘 屑芯薪褋褌褉芯胁 褌懈锌褍 谐芯褉芯写邪.
  _bool8_ monsters_match_to_town;
  
  // +149. 袛芯褋褌褍锌薪芯褋褌懈 屑芯薪褋褌褉芯胁 懈蟹 谐芯褉芯写芯胁.
  _bool8_ monsters_towns_aval[9];
  
  // +158. 袪械蟹褍谢褜褌邪褌 胁褘褉邪胁薪懈胁邪薪懈褟, 薪械 懈褋锌芯谢褜蟹褍械褌褋褟.
  _byte_ dummy_f9E[2];
  
  // +160. 小芯泻褉芯胁懈褖邪 蟹芯薪褘.
  _ZoneTreasure_ treasure[3];
  
  // +196. 小胁褟蟹懈 褋 写褉褍谐懈屑懈 蟹芯薪邪屑懈.
  _List_<_ZoneConnection_> connections;
};







// ********************************************// ********************************************

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//typedef _ptr_ (__thiscall * _func_GetNetMessage)(_ptr_ this_, _int8_ a2, _int_ a3);
//#define b_GetNetMessage() ((_func_GetNetMessage)0x553440)(o_DirectPlayCOMObject, 0, 0);

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




// 袩械褉械锌懈褋邪薪薪邪褟 谐械褉芯泄褋泻邪褟 褎褍薪泻褑懈褟 蟹邪谐褉褍蟹泻懈 懈 锌褉芯懈谐褉褘胁邪薪懈褟 蟹胁褍泻邪.
_Sample_ __fastcall rwr_Load_And_Start_Sample(_cstr_ WavName);




//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
