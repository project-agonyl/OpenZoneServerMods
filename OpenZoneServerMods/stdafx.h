// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files
#include <windows.h>
#include <string>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <tchar.h>

#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")

// reference additional headers your program requires here
#pragma comment (lib, "detours.lib")
#include "detours/detours.h"
#include "functions.h"
#include "MercenaryLevelUp.h";
#include "RemoveShueRestrictions.h"
