#pragma once

typedef void(__thiscall* oAddExp) (void* pThis, unsigned int a2, unsigned int a3, int a4, int a5);

void __fastcall HookedAddExp(void* pThis, DWORD EDX, unsigned int a2, unsigned int a3, int a4, int a5);
void HookAddExp();

