#pragma once
struct MainServerShoutPacket;

void ZoneServerPrint(const char* msg);
void ServerAnnouncement(const char* msg);
void InGameShout(const char* name, const char* msg);
bool Hook(void* toHook, void* ourFunc, int len);
