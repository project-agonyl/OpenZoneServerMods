#include "stdafx.h"
#include "DisablePK.h"

#define MAX_PK_DISABLED_MAPS 1

oIsEnabled2PK IsEnabled2PK;
const int PKDisabledMaps[MAX_PK_DISABLED_MAPS] = { 7 };

int __fastcall HookedIsEnabled2PK(void* pThis, DWORD EDX, USHORT level, int unknown)
{
	int EnablePKDisable = GetPrivateProfileInt(L"MODULES", L"EnablePKDisable", 0, L".\\OpenZoneServerMods.ini");
	if (EnablePKDisable == 1) {
		// Retrieve current map ID of the player
		WORD mapID = *((WORD *)pThis + 42);
		for (size_t i = 0; i < MAX_PK_DISABLED_MAPS; i++)
		{
			// If current mapID matches the one that has to be disabled then return 0 to disable PK
			if (PKDisabledMaps[i] == mapID)
			{
				return 0;
			}
		}
	}
	// Call the original function so that PK in other maps work normally
	return IsEnabled2PK(pThis, level, unknown);
}

void HookIsEnabled2PK()
{
	// Used to make sure we hook the function only once
	static bool once = true;
	if (once)
	{
		ZoneServerPrint("Hooking IsEnabled2PK function");
		once = false;
		// Get the original function from the ZoneServer
		IsEnabled2PK = (oIsEnabled2PK)(0x004F7450);
		// Use detour to patch the function
		DetourTransactionBegin();
		DetourUpdateThread(GetCurrentThread());
		DetourAttach(&(PVOID&)IsEnabled2PK, HookedIsEnabled2PK);
		DetourTransactionCommit();
	}
}
