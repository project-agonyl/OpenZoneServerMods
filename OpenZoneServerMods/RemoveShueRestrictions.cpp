#include "stdafx.h"

DWORD shueEatFruitBackAddy;
DWORD shueAddExpBackAddy;

void __declspec(naked) EatFruit()
{
	__asm
	{
		and eax, 0xFF
		cmp eax, 0x96
		jmp[shueEatFruitBackAddy]
	}
}

void __declspec(naked) AddShueExp()
{
	__asm
	{
		and eax, 0xFF
		cmp eax, 0x96
		jmp[shueAddExpBackAddy]
	}
}

void HookEatFruit()
{
	ZoneServerPrint("Hooking shue eat fruit function");
	int hookLength = 8;
	DWORD hookAddress = 0x004DC23C;
	shueEatFruitBackAddy = hookAddress + hookLength;
	Hook((void*)hookAddress, EatFruit, hookLength);
}

void HookAddShueExp()
{
	ZoneServerPrint("Hooking add shue exp function");
	int hookLength = 8;
	DWORD hookAddress = 0x004E2F99;
	shueAddExpBackAddy = hookAddress + hookLength;
	Hook((void*)hookAddress, AddShueExp, hookLength);
}
