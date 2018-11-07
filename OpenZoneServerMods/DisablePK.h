#pragma once

typedef int(__thiscall* oIsEnabled2PK) (void* pThis, USHORT mapId, int unknown);

int __fastcall HookedIsEnabled2PK(void* pThis, DWORD EDX, USHORT level, int unknown);
void HookIsEnabled2PK();