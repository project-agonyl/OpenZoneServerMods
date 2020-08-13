#include "stdafx.h"

DWORD mercenaryLevelUpBackAddy;
void __declspec(naked) MercenaryLevelUp()
{
	__asm
	{
		add cx, 0x28
		mov edx, dword ptr ss : [ebp - 0x4]
		mov word ptr ds : [edx + 0x60] , cx
		mov eax, dword ptr ss : [ebp - 0x4]
		mov cx, word ptr ds : [eax + 0x6C]
		add cx, 0x3
		jmp[mercenaryLevelUpBackAddy]
	}
}

void HookMercenaryLevelUp()
{
	ZoneServerPrint("Hooking MercenaryLevelUp function");
	int hookLength = 22;
	DWORD hookAddress = 0x004612BC;
	mercenaryLevelUpBackAddy = hookAddress + hookLength;
	Hook((void*)hookAddress, MercenaryLevelUp, hookLength);
}
