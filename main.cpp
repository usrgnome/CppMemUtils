// main.cpp
#include <iostream>
#include <math.h>
#include "mem.h"


int main() {
    // get base address
    char module_name[] = "client.dll"; // ac_client.exe also works?
    uintptr_t ac_client = GetModuleBaseAddress(_T(module_name), GetProcessIdByClass("SDL_app"));
    HANDLE pHandle = GetProcessHandleByClass("SDL_app", PROCESS_ALL_ACCESS);

    // calculate all addresses
    uintptr_t ammo_off = 0x0713FBE0;

    while (true) {
        int ammo = ReadMem<int>(pHandle, (LPVOID)ammo_off);

        std::cout << std::dec << "ammo: " << ammo << "\n";

        if (ammo < 5) {
            WriteMem(pHandle, (LPVOID)ammo_off, (int)999);
        }
    }
}
