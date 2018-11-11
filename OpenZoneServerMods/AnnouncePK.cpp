#include "stdafx.h"
#include "AnnouncePK.h"

oKilledByPC KilledByPC;

int __fastcall HookedKilledByPC(void* pThis, DWORD EDX, void *a2)
{
	std::string killer((char *)a2 + 32), killed((char *)pThis + 32);
	std::string pkShout = killer + " killed " + killed + " at map " + std::to_string(*((WORD *)pThis + 42));
	InGameShout("[PK-Shout]", pkShout.c_str());
	return KilledByPC(pThis, a2);
}

void HookKilledByPC()
{
	static bool once = true;
	if (once)
	{
		ZoneServerPrint("Hooking KilledByPC function");
		once = false;
		KilledByPC = (oKilledByPC)(0x004E9890);
		DetourTransactionBegin();
		DetourUpdateThread(GetCurrentThread());
		DetourAttach(&(PVOID&)KilledByPC, HookedKilledByPC);
		DetourTransactionCommit();
	}
}
