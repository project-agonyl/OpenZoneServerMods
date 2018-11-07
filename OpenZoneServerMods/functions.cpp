#include "stdafx.h"

void ZoneServerPrint(const char *msg)
{
	// Calling original Print function from the ZoneServer
	((int(__cdecl*)(const char* string))0x00435EC0)(msg);
}

void ServerAnnouncement(const char *msg)
{
	// Calling original ShoutNotice function from the ZoneServer
	((int(__cdecl*)(const char* string))0x0047A6A0)(msg);
}

void InGameShout(void *pThis, char *msg)
{
	((int(__thiscall*)(void *pThis, void *packet, size_t size))0x0041C3F0)(pThis, msg, 0x74u);
}