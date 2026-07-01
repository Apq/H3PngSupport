////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// 铚楀鍔虫壈.
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// 瀹嬭悓褰㈠悤鑵?
//
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#define _byte_ unsigned __int8
#define _word_ unsigned __int16
#define _dword_ unsigned __int32


#define CALL_0(return_type, call_type, address) \
 ((return_type (call_type *)(void))address)()
#define CALL_1(return_type, call_type, address, a1) \
 ((return_type (call_type *)(_dword_))(address))((_dword_)(a1))
#define CALL_2(return_type, call_type, address, a1, a2) \
 ((return_type (call_type *)(_dword_,_dword_))(address))((_dword_)(a1),(_dword_)(a2))
#define CALL_3(return_type, call_type, address, a1, a2, a3) \
 ((return_type (call_type *)(_dword_,_dword_,_dword_))(address))((_dword_)(a1),(_dword_)(a2),(_dword_)(a3))
#define CALL_4(return_type, call_type, address, a1, a2, a3, a4) \
 ((return_type (call_type *)(_dword_,_dword_,_dword_,_dword_))(address))((_dword_)(a1),(_dword_)(a2),(_dword_)(a3),(_dword_)(a4))
#define CALL_5(return_type, call_type, address, a1, a2, a3, a4, a5) \
 ((return_type (call_type *)(_dword_,_dword_,_dword_,_dword_,_dword_))(address))((_dword_)(a1),(_dword_)(a2),(_dword_)(a3),(_dword_)(a4),(_dword_)(a5))
#define CALL_6(return_type, call_type, address, a1, a2, a3, a4, a5, a6) \
 ((return_type (call_type *)(_dword_,_dword_,_dword_,_dword_,_dword_,_dword_))(address))((_dword_)(a1),(_dword_)(a2),(_dword_)(a3),(_dword_)(a4),(_dword_)(a5),(_dword_)(a6))
#define CALL_7(return_type, call_type, address, a1, a2, a3, a4, a5, a6, a7) \
 ((return_type (call_type *)(_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_))(address))((_dword_)(a1),(_dword_)(a2),(_dword_)(a3),(_dword_)(a4),(_dword_)(a5),(_dword_)(a6),(_dword_)(a7))
#define CALL_8(return_type, call_type, address, a1, a2, a3, a4, a5, a6, a7, a8) \
 ((return_type (call_type *)(_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_))(address))((_dword_)(a1),(_dword_)(a2),(_dword_)(a3),(_dword_)(a4),(_dword_)(a5),(_dword_)(a6),(_dword_)(a7),(_dword_)(a8))
#define CALL_9(return_type, call_type, address, a1, a2, a3, a4, a5, a6, a7, a8, a9) \
 ((return_type (call_type *)(_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_))(address))((_dword_)(a1),(_dword_)(a2),(_dword_)(a3),(_dword_)(a4),(_dword_)(a5),(_dword_)(a6),(_dword_)(a7),(_dword_)(a8),(_dword_)(a9))
#define CALL_10(return_type, call_type, address, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10) \
 ((return_type (call_type *)(_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_))(address))((_dword_)(a1),(_dword_)(a2),(_dword_)(a3),(_dword_)(a4),(_dword_)(a5),(_dword_)(a6),(_dword_)(a7),(_dword_)(a8),(_dword_)(a9),(_dword_)(a10))
#define CALL_11(return_type, call_type, address, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11) \
 ((return_type (call_type *)(_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_))(address))((_dword_)(a1),(_dword_)(a2),(_dword_)(a3),(_dword_)(a4),(_dword_)(a5),(_dword_)(a6),(_dword_)(a7),(_dword_)(a8),(_dword_)(a9),(_dword_)(a10),(_dword_)(a11))
#define CALL_12(return_type, call_type, address, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12) \
 ((return_type (call_type *)(_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_))(address))((_dword_)(a1),(_dword_)(a2),(_dword_)(a3),(_dword_)(a4),(_dword_)(a5),(_dword_)(a6),(_dword_)(a7),(_dword_)(a8),(_dword_)(a9),(_dword_)(a10),(_dword_)(a11),(_dword_)(a12))
#define CALL_13(return_type, call_type, address, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13) \
 ((return_type (call_type *)(_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_))(address))((_dword_)(a1),(_dword_)(a2),(_dword_)(a3),(_dword_)(a4),(_dword_)(a5),(_dword_)(a6),(_dword_)(a7),(_dword_)(a8),(_dword_)(a9),(_dword_)(a10),(_dword_)(a11),(_dword_)(a12),(_dword_)(a13))
#define CALL_14(return_type, call_type, address, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14) \
 ((return_type (call_type *)(_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_))(address))((_dword_)(a1),(_dword_)(a2),(_dword_)(a3),(_dword_)(a4),(_dword_)(a5),(_dword_)(a6),(_dword_)(a7),(_dword_)(a8),(_dword_)(a9),(_dword_)(a10),(_dword_)(a11),(_dword_)(a12),(_dword_)(a13),(_dword_)(a14))
#define CALL_15(return_type, call_type, address, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15) \
 ((return_type (call_type *)(_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_))(address))((_dword_)(a1),(_dword_)(a2),(_dword_)(a3),(_dword_)(a4),(_dword_)(a5),(_dword_)(a6),(_dword_)(a7),(_dword_)(a8),(_dword_)(a9),(_dword_)(a10),(_dword_)(a11),(_dword_)(a12),(_dword_)(a13),(_dword_)(a14),(_dword_)(a15))
#define CALL_16(return_type, call_type, address, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16) \
 ((return_type (call_type *)(_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_))(address))((_dword_)(a1),(_dword_)(a2),(_dword_)(a3),(_dword_)(a4),(_dword_)(a5),(_dword_)(a6),(_dword_)(a7),(_dword_)(a8),(_dword_)(a9),(_dword_)(a10),(_dword_)(a11),(_dword_)(a12),(_dword_)(a13),(_dword_)(a14),(_dword_)(a15),(_dword_)(a16))
#define CALL_17(return_type, call_type, address, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17) \
 ((return_type (call_type *)(_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_,_dword_))(address))((_dword_)(a1),(_dword_)(a2),(_dword_)(a3),(_dword_)(a4),(_dword_)(a5),(_dword_)(a6),(_dword_)(a7),(_dword_)(a8),(_dword_)(a9),(_dword_)(a10),(_dword_)(a11),(_dword_)(a12),(_dword_)(a13),(_dword_)(a14),(_dword_)(a15),(_dword_)(a16),(_dword_)(a17))

#define CALL_VA(return_type, adress, a1, ...) \
 ((return_type (__cdecl *)(_dword_, ...))(adress))((_dword_)(a1), __VA_ARGS__)


// _bool_ - 4-?寰夎降閽碱帠 鑵╂报楹囪€滄牆 铚? 璧?BOOL ?Win32 API
#define _bool_ __int32

typedef _dword_ _ptr_;



#pragma pack(push, 4)


class Variable
{
public:
	virtual _dword_ __stdcall GetValue() = 0;
	virtual void __stdcall SetValue(_dword_ value) = 0;
	virtual _dword_* __stdcall GetPValue() = 0;
};

struct FlagsRegister
{
	_dword_ CF			: 1; //0
	_dword_ reserved_1	: 1; //1
	_dword_ PF			: 1; //2
	_dword_ reserved_3	: 1; //3
	_dword_ AF			: 1; //4
	_dword_ reserved_5	: 1; //5
	_dword_ ZF			: 1; //6
	_dword_ SF			: 1; //7
	_dword_ TF			: 1; //8
	_dword_ IF			: 1; //9
	_dword_ DF			: 1; //10
	_dword_ OF			: 1; //11
	_dword_ IOPL		: 2; //12-13
	_dword_ NT			: 1; //14
	_dword_ reserved_15	: 1; //15
	_dword_ RF			: 1; //16
	_dword_ VM			: 1; //17
	_dword_ AC			: 1; //18
	_dword_ VIF			: 1; //19
	_dword_ VIP			: 1; //20
	_dword_ ID			: 1; //21
	_dword_ reserved_22	: 1; //22
	_dword_ reserved_23	: 1; //23
	_dword_ reserved_24	: 1; //24
	_dword_ reserved_25	: 1; //25
	_dword_ reserved_26	: 1; //26
	_dword_ reserved_27	: 1; //27
	_dword_ reserved_28	: 1; //28
	_dword_ reserved_29	: 1; //29
	_dword_ reserved_30	: 1; //30
	_dword_ reserved_31	: 1; //31
};

// 缇婄椉鐗濈?HookContext
struct HookContext
{
 int eax;
 int ecx;
 int edx;
 int ebx;
 int esp;
 int ebp;
 int esi;
 int edi;

 _ptr_ return_address;

 FlagsRegister flags;


 inline void Push(int v)
 {
	 esp -= 4;
	 *(int*)(esp) = v;
 }

 inline int Pop()
 {
	 int r = *(int*)(esp);
	 esp += 4;
	 return r;
 }
};



#define EXEC_DEFAULT 1
#define NO_EXEC_DEFAULT 0
#define SKIP_DEFAULT 0


#define PATCH_  0
#define LOHOOK_ 1
#define HIHOOK_ 2


#define DATA_ 0
#define CODE_ 1


// 娉€辩枺鐗濈潎?瑙屽洬?Patch
class Patch
{
public:
 virtual _ptr_ __stdcall GetAddress() = 0; 

 virtual _dword_ __stdcall GetSize() = 0; 

 virtual char* __stdcall GetOwner() = 0;

 virtual int  __stdcall GetType() = 0;

 virtual _bool_ __stdcall IsApplied() = 0;

 virtual _bool_ __stdcall Apply() = 0;

 virtual _bool_ __stdcall ApplyInsert(int zorder) = 0;

 /////////////////////////////////////////////////////////////////////////////////////////////////////
 // 浣撹澗?Undo
 virtual _bool_ __stdcall Undo() = 0;


 /////////////////////////////////////////////////////////////////////////////////////////////////////
 // 浣撹澗?Destroy
 // 鑵昏€辩椉鐗濋摃
 virtual _bool_ __stdcall Destroy() = 0;

 /////////////////////////////////////////////////////////////////////////////////////////////////////
 // 浣撹澗?GetAppliedBefore
 virtual Patch* __stdcall GetAppliedBefore() = 0;

 /////////////////////////////////////////////////////////////////////////////////////////////////////
 // 浣撹澗?GetAppliedAfter
 virtual Patch* __stdcall GetAppliedAfter() = 0;

};


class LoHook : public Patch
{
};


typedef int(__stdcall *_LoHookFunc_)(LoHook*, HookContext*);


#define CALL_ 0
#define SPLICE_ 1
#define FUNCPTR_ 2

#define DIRECT_  0
#define EXTENDED_ 1
#define SAFE_  2

#define ANY_  0
#define STDCALL_ 0
#define THISCALL_ 1
#define FASTCALL_ 2 
#define CDECL_  3
#define FASTCALL_1 1 

class HiHook : public Patch
{
public:
 virtual _ptr_ __stdcall GetDefaultFunc() = 0;

 virtual _ptr_ __stdcall GetOriginalFunc() = 0;

 virtual _ptr_ __stdcall GetReturnAddress() = 0;


 //# ver 2.1
 virtual void __stdcall SetUserData(_dword_ data) = 0;
 virtual _dword_ __stdcall GetUserData() = 0;
};


// 娉€辩枺鐗濈潎?瑙屽洬?PatcherInstance
class PatcherInstance
{
public:
 ////////////////////////////////////////////////////////////
 // 浣撹澗?WriteByte
 virtual Patch* __stdcall WriteByte(_ptr_ address, int value) = 0;
 
 ////////////////////////////////////////////////////////////
 // 浣撹澗?WriteWord
 virtual Patch* __stdcall WriteWord(_ptr_ address, int value) = 0;
 
 ////////////////////////////////////////////////////////////
 // 浣撹澗?WriteDword
 virtual Patch* __stdcall WriteDword(_ptr_ address, int value) = 0;
 
 ////////////////////////////////////////////////////////////
 // 浣撹澗?WriteJmp
 virtual Patch* __stdcall WriteJmp(_ptr_ address, _ptr_ to) = 0;
 
 ////////////////////////////////////////////////////////////
 // 浣撹澗?WriteHexPatch
 /* 闀虫灞?
   pi->WriteHexPatch(0x57b521, "6A 01  6A 00");
 */
 virtual Patch* __stdcall WriteHexPatch(_ptr_ address, char* hex_str) = 0;
 
 ////////////////////////////////////////////////////////////
 // 浣撹澗?WriteCodePatchVA
 virtual Patch* __stdcall WriteCodePatchVA(_ptr_ address, char* format, _dword_* va_args) = 0;
 
 ////////////////////////////////////////////////////////////
 // 浣撹澗?WriteLoHook
 //
 // 宄﹀繊鍔虫壈! 
 virtual LoHook* __stdcall WriteLoHook(_ptr_ address, _LoHookFunc_ func) = 0;
 
 ////////////////////////////////////////////////////////////
 // 浣撹澗?WriteHiHook
 //
 //
 //
 //        __fastcall f(this_, no_used_edx, ...) 
 //
 //
 //
 //
 //  STDCALL_
 //  THISCALL_
 //  FASTCALL_
 //  CDECL_
 //
 //
 virtual HiHook* __stdcall WriteHiHook(_ptr_ address, int hooktype, int subtype, int calltype, void* new_func) = 0;

 ///////////////////////////////////////////////////////////////////
 virtual Patch* __stdcall CreateBytePatch(_ptr_ address, int value) = 0;
 virtual Patch* __stdcall CreateWordPatch(_ptr_ address, int value) = 0;
 virtual Patch* __stdcall CreateDwordPatch(_ptr_ address, int value) = 0;
 virtual Patch* __stdcall CreateJmpPatch(_ptr_ address, _ptr_ to) = 0;
 virtual Patch* __stdcall CreateHexPatch(_ptr_ address, char* hex_str) = 0;
 virtual Patch* __stdcall CreateCodePatchVA(_ptr_ address, char* format, _dword_* va_args) = 0;
 virtual LoHook* __stdcall CreateLoHook(_ptr_ address, void* func) = 0;
 virtual HiHook* __stdcall CreateHiHook(_ptr_ address, int hooktype, int subtype, int calltype, void* new_func) = 0;
 
 ////////////////////////////////////////////////////////////
 // 浣撹澗?ApplyAll
 // (鑰? Patch::Apply)
 virtual _bool_ __stdcall ApplyAll() = 0;

 ////////////////////////////////////////////////////////////
 // 浣撹澗?UndoAll
 // (鑰? Patch::Undo)
 virtual _bool_ __stdcall UndoAll() = 0;

 ////////////////////////////////////////////////////////////
 // 浣撹澗?DestroyAll
 // (鑰? Patch::Destroy)
 virtual _bool_ __stdcall DestroyAll() = 0;

 virtual Patch* __stdcall WriteDataPatchVA(_ptr_ address, char* format, _dword_* va_args);
 virtual Patch* __stdcall CreateDataPatchVA(_ptr_ address, char* format, _dword_* va_args);


 // 浣撹澗?GetLastPatchAt
 virtual Patch* __stdcall GetLastPatchAt(_ptr_ address) = 0;

 // 浣撹澗?UndoAllAt
 // (鑰? Patch::Undo)
 virtual _bool_ __stdcall UndoAllAt(_ptr_ address) = 0;

 // 浣撹澗?GetFirstPatchAt
 virtual Patch* __stdcall GetFirstPatchAt(_ptr_ address) = 0;


 ////////////////////////////////////////////////////////////
 // 浣撹澗?Write
 virtual Patch* __stdcall Write(_ptr_ address, _ptr_ data, _dword_ size, _bool_ is_code = 0) = 0;
 ///////////////////////////////////////////////////////////////////
 // 浣撹澗?CreatePatch
 virtual Patch* __stdcall CreatePatch(_ptr_ address, _ptr_ data, _dword_ size, _bool_ is_code = 0) = 0;


 //## ver 2.1
  ////////////////////////////////////////////////////////////
 // 浣撹澗?WriteLoHookEx
 //
 virtual LoHook* __stdcall WriteLoHookEx(_ptr_ address, void* func, _dword_ stack_delta) = 0;
 // 浣撹澗?CreateLoHookEx
 virtual LoHook* __stdcall CreateLoHookEx(_ptr_ address, void* func, _dword_ stack_delta) = 0;


 virtual LoHook* __stdcall WriteHexHookVA(_ptr_ address, _bool_ exec_default, char* hex_str, _dword_* va_args) = 0;
 virtual LoHook* __stdcall CreateHexHookVA(_ptr_ address, _bool_ exec_default, char* hex_str, _dword_* va_args) = 0;



 virtual void __stdcall BlockAt(_ptr_ address) = 0;

 //## ver 2.6

 virtual void __stdcall BlockAllExceptVA(_dword_ *va_args) = 0;


 //## ver 4.0
 virtual Patch* __stdcall WriteAsmPatchVA(_ptr_ address, _dword_* va_args) = 0;

 virtual Patch* __stdcall CreateAsmPatchVA(_ptr_ address, _dword_* va_args) = 0;

 virtual LoHook* __stdcall WriteAsmHookVA(_ptr_ address, _dword_* va_args) = 0;

 virtual LoHook* __stdcall CreateAsmHookVA(_ptr_ address, _dword_* va_args) = 0;


 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 inline Patch* WriteAsmPatch(_ptr_ address, ...)
 {
	 return WriteAsmPatchVA(address, (_dword_*)((_ptr_)&address + 4));
 }
 ////////////////////////////////////////////////////////////
 // 浣撹澗?CreateAsmPatch
 inline Patch* CreateAsmPatch(_ptr_ address, ...)
 {
	 return CreateAsmPatchVA(address, (_dword_*)((_ptr_)&address + 4));
 }

 ////////////////////////////////////////////////////////////
 inline LoHook* WriteAsmHook(_ptr_ address, ...)
 {
	 return WriteAsmHookVA(address, (_dword_*)((_ptr_)&address + 4));
 }

 ////////////////////////////////////////////////////////////
 // 浣撹澗?CreateAsmHook
 inline LoHook* CreateAsmHook(_ptr_ address, ...)
 {
	 return CreateAsmHookVA(address, (_dword_*)((_ptr_)&address + 4));
 }



//
 inline LoHook* WriteHexHook(_ptr_ address, _bool_ exec_default, char* format, ...)
 {
  return WriteHexHookVA(address, exec_default, format, (_dword_*)((_ptr_)&format + 4));
 }
 // 浣撹澗?CreateHexHook
 inline LoHook* CreateHexHook(_ptr_ address, _bool_ exec_default, char* format, ...)
 {
  return CreateHexHookVA(address, exec_default, format, (_dword_*)((_ptr_)&format + 4));
 }


 ////////////////////////////////////////////////////////////
 // 浣撹澗?WriteCodePatch
 // #0 -  #9  -闀壐?閾楃湇鑰卞挮顝割帠 鍣ょ柋?闀辫€?閾掕婕?EB, 70 - 7F, E8, E9, 0F80 - 0F8F
 // Patch* p = pi->WriteCodePatch(address,
 //  "#0: %%",
 //  "B9 %d %%", this,     // mov ecx, this  // 
 //  "BA %d %%", this->context,   // mov edx, context  // 
 //  "%c %%", func,      // call func  // 
 //  "83 F8 01 %%",      // cmp eax, 1
 //  "0F 85 #7 %%",       // jne long to label 7 (if func returns 0)
 //  "83 F8 02 %%",      // cmp eax, 2
 //  "0F 85 ~d %%", 0x445544,   // jne long to 0x445544 (if func returns 0)
 //  "EB #0 %%",       // jmp short to label 0
 //  "%m %%", address2, size,   // exec  code copy from address2
 //  "#7: FF 25 %d %.", &return_address); // jmp [&return_address]
 inline Patch* WriteCodePatch(_ptr_ address, char* format, ...)
 {
  return WriteCodePatchVA(address, format, (_dword_*)((_ptr_)&format + 4));
 }
 
 ////////////////////////////////////////////////////////////
 // 浣撹澗?CreateCodePatch
 inline Patch* CreateCodePatch(_ptr_ address, char* format, ...)
 {
  return CreateCodePatchVA(address, format, (_dword_*)((_ptr_)&format + 4));
 }


 ////////////////////////////////////////////////////////////
 // 浣撹澗?WriteDataPatch
 // Patch* p = pi->WriteDataPatch(address,
 //  "FF FF FF %d %%", var, 
 //  "%m %%", address2, size, 
 //  "AE %.");
 inline Patch* WriteDataPatch(_ptr_ address, char* format, ...)
 {
  return WriteDataPatchVA(address, format, (_dword_*)((_ptr_)&format + 4));
 }
 
 ////////////////////////////////////////////////////////////
 // 浣撹澗?CreateDataPatch
 inline Patch* CreateDataPatch(_ptr_ address, char* format, ...)
 {
  return CreateDataPatchVA(address, format, (_dword_*)((_ptr_)&format + 4));
 }
 
 inline Patch* __stdcall WriteDword(_ptr_ address, const char* value)
 {
  return WriteDword(address, (int)value);
 }

};

// 瀛板洬?Patcher
class Patcher
{
public:

 ///////////////////////////////////////////////////
 // 浣撹澗?CreateInstance
 virtual PatcherInstance* __stdcall CreateInstance(char* owner) = 0;
 
 ///////////////////////////////////////////////////
 // 浣撹澗?GetInstance
 virtual PatcherInstance*  __stdcall GetInstance(char* owner) = 0;
 
 ///////////////////////////////////////////////////
 // 浣撹澗?GetLastPatchAt
 virtual Patch* __stdcall GetLastPatchAt(_ptr_ address);
 
 ///////////////////////////////////////////////////
 // 浣撹澗?UndoAllAt
 virtual Patch* __stdcall UndoAllAt(_ptr_ address);
 
 ///////////////////////////////////////////////////
 // 浣撹澗?SaveDump
 virtual void __stdcall SaveDump(char* file_name) = 0;
 
 ///////////////////////////////////////////////////
 // 浣撹澗?SaveLog
 virtual void __stdcall SaveLog(char* file_name) = 0;
 
 ///////////////////////////////////////////////////
 // 浣撹澗?GetMaxPatchSize
 virtual int __stdcall GetMaxPatchSize() = 0;
 

 ///////////////////////////////////////////////////
 // 浣撹澗?WriteComplexDataVA
 virtual int __stdcall WriteComplexDataVA(_ptr_ address, char* format, _dword_* args) = 0;
 
 ///////////////////////////////////////////////////
 virtual int __stdcall GetOpcodeLength(_ptr_ p_opcode) = 0;
 
 ///////////////////////////////////////////////////
 // 
 virtual int __stdcall MemCopyCode(_ptr_ dst, _ptr_ src, _dword_ size) = 0;
 
 ///////////////////////////////////////////////////
 // 浣撹澗?GetFirstPatchAt
 virtual Patch* __stdcall GetFirstPatchAt(_ptr_ address);
 
 ///////////////////////////////////////////////////
 // 鐘锋湨顗?瑙愰暔鐥煎睈閽?
 virtual int __stdcall MemCopyCodeEx(_ptr_ dst, _ptr_ src, _dword_ size) = 0;
 
 
 // ver 2.3
 // 浣撹澗?VarInit
 virtual Variable* __stdcall VarInit(char* name, _dword_ value) = 0;
 // 浣撹澗?VarFind
 virtual Variable* __stdcall VarFind(char* name) = 0;


 // ver 2.6
 // 浣撹澗?PreCreateInstance
 virtual PatcherInstance* __stdcall PreCreateInstance(char* name) = 0;


 // ver 4.1
 virtual int __stdcall WriteAsmCodeVA(_ptr_ address, _dword_* args) = 0;
 virtual _ptr_ __stdcall CreateCodeBlockVA(_dword_* args) = 0;

 
 template<typename ValueType>
 inline ValueType VarGetValue(char* name, ValueType default_value)
 {
	 if (sizeof(ValueType) > 4) return default_value;
	 Variable* v = VarFind(name);
	 if (v == NULL) return default_value;
	 return (ValueType)v->GetValue();
 }

 template<typename ValueType>
 inline ValueType& VarValue(char* name)
 {
	 if (sizeof(ValueType) > 4) __asm{__asm int 3};
	 
	 Variable* v = VarFind(name);
	 if (v == NULL) v = VarInit(name, 0);
	 
	 if (v == NULL) __asm{__asm int 3};
	 
	 return (ValueType&)*v->GetPValue();
 }



 ////////////////////////////////////////////////////////////////////
 // 宄﹀繊鍔虫壈!
 // PatcherInstance::WriteCodePatch
 //
 inline _ptr_ WriteComplexData(_ptr_ address, char* format, ...)
 {
  return WriteComplexDataVA(address, format, (_dword_*)((_ptr_)&format + 4));
 }



inline HiHook* GetFirstHiHookAt(_ptr_ address)
{
	Patch* p = GetFirstPatchAt(address);
	while (true)
	{
		if (p == 0) return 0;
		if (p->GetType() == HIHOOK_) return (HiHook*)p;
		p = p->GetAppliedAfter();
	}
}

inline HiHook* GetLastHiHookAt(_ptr_ address)
{
	Patch* p = GetLastPatchAt(address);
	while (true)
	{
		if (p == 0) return 0;
		if (p->GetType() == HIHOOK_) return (HiHook*)p;
		p = p->GetAppliedBefore();
	}
}


};





#pragma pack(pop)

//////////////////////////////////////////////////////////////////

#include <windows.h>
inline Patcher* GetPatcher()
{
static int calls_count = 0;
 if (calls_count > 0) return NULL;
 calls_count++;
 HMODULE pl = LoadLibraryA("patcher_x86.dll");
 if (pl)
 {
  FARPROC f = GetProcAddress(pl, "_GetPatcherX86@0");
  if (f) return CALL_0(Patcher*, __stdcall, f);
 }
 return NULL;
}