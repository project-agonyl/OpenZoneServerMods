# Opensource Modifications for A3 Online ZoneServer.exe

We all know how hard it is to implement a feature into the exisiting ZoneServer.exe for which we do not have the source. 
This project aims to make modifying ZoneServer.exe a bit less of a hassle. 

Most of the ZoneServer.exe modifications guide released are based on opening ZoneServer.exe in a debugger like Ollydbg and updating assembly code in it. 
It is hard to write assembly language in order to modify ZoneServer.exe. This project was born so that ZoneServe.exe could be modified by writing C++ code rather than assembly.

Though it might have drawbacks like code not being as optimized as it would be if assembly code was injected into ZoneServe.exe directly, 
the drawbacks are overshadowed by the ease by which anyone with a little knowledge of reverse engineering as well as good C++ skills can implement/modify features.

Using a technique called function hotpatching at runtime, a function behaviour can be modified to fit your needs. This project compiles into a DLL which can then be injected into 
ZoneServer.exe to modify it's behaviour.

This project uses Microsoft Detours 3.0 to make function hooking less of a nightmare for beginners!

### Warning

This is project has not been tested in a server having more than 3 players. Hence it is not recommended to go live with it before extensive testing and optimization!

## Usage

* Clone/Download the project.
* Build the solution using Visual Studio 2017.
* Copy ``OpenZoneServerMods.ini`` into your ZoneServer.exe folder and enable required modules by updating the file.
* Inject OpenZoneServerMods.dll into your ZoneServer.exe process using your favourite DLL injection tool such as DLLInjector or Extreme Injector.
* On successful injection you should be able to see debug messages in your ZoneServer from the DLL.

## Feature List

* Disabling PK in a particular map.
* Announcing player kills.
* Adding level cap(Once the level cap has been reached the player stops receiving hunting exp from monsters)

## Pre-compiled DLL

Pre-compiled DLL is under the release section of this project.
