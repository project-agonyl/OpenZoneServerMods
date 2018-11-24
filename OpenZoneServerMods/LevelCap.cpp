#include "stdafx.h"
#include "LevelCap.h"

oAddExp AddExp;

void __fastcall HookedAddExp(void* pThis, DWORD EDX, unsigned int a2, unsigned int a3, int a4, int a5)
{
	int EnableLevelCap = GetPrivateProfileInt(L"MODULES", L"EnableLevelCap", 0, L".\\OpenZoneServerMods.ini");
	if (EnableLevelCap == 1) {
		int levelCap = GetPrivateProfileInt(L"LEVELCAP", L"LevelCap", 165, L".\\OpenZoneServerMods.ini");
		WORD level = *((WORD *)pThis + 43);
		if (level >= levelCap) {
			return;
		}
	}
	AddExp(pThis, a2, a3, a4, a5);
}

void HookAddExp()
{
	static bool once = true;
	if (once)
	{
		ZoneServerPrint("Hooking AddExp function");
		once = false;
		AddExp = (oAddExp)(0x004E2560);
		DetourTransactionBegin();
		DetourUpdateThread(GetCurrentThread());
		DetourAttach(&(PVOID&)AddExp, HookedAddExp);
		DetourTransactionCommit();
	}
}
