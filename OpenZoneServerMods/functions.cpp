#include "stdafx.h"

struct MainServerShoutPacket
{
	unsigned short type;
	unsigned short PCID;
	char header[5];
	char padding;
	char strName[20];
	char strUnk[22];
	char strMessage[64];
};

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

void InGameShout(const char *name, const char *msg)
{
	struct MainServerShoutPacket myPkt;
	void *MainServer = (void *)0x0072BF10;
	myPkt.type = 0xA101u;
	myPkt.PCID = 0x0074u;
	int bytes[5] = { 241, 173, 32, 0, 0 };
	memcpy(&myPkt.header, &bytes, 5);
	myPkt.padding = 0;
	strcpy(myPkt.strName, name);
	myPkt.strUnk[0] = 0;
	strncpy(myPkt.strMessage, msg, 64u);
	((int(__thiscall*)(void *baseServer, void *packet, size_t size))0x004057CC)(MainServer, &myPkt, sizeof(struct MainServerShoutPacket));
}
