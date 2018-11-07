#pragma once

typedef int(__thiscall* oKilledByPC) (void* pThis, void *a2);

int __fastcall HookedKilledByPC(void* pThis, DWORD EDX, void *a2);
void HookKilledByPC();

