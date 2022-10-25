// mem.h
#ifndef __WIN_MEM_UTILS__
#define __WIN_MEM_UTILS__

#include <windows.h>
#include <TlHelp32.h>
#include <tchar.h>
#include <cstdint>
#include <math.h>

static float M_PI = 3.14159265f;

// --- WINDOW HANDLE ---
/**
 * Get a Window handle using the window title.
 *
 * @param window_title Title of a window
 * @return HWND window_handle
 */
HWND GetWindowHandleByTitle(LPCSTR window_title);

/**
 * Get a Window handle using the class name.
 *
 * @param class_name Name of a class
 * @return HWND window_handle
 */
HWND GetWindowHandleByClass(LPCSTR class_name);

// --- PROCESS ID ---
DWORD GetProcessIdFromWindowHandle(HWND window_handle);
DWORD GetProcessIdByTitle(LPCSTR window_title);
DWORD GetProcessIdByClass(LPCSTR class_name);

// --- PROCESS HANDLE ---
HANDLE GetProcessHandleByProcessId(DWORD process_id, DWORD desired_access);
HANDLE GetProcessHandleByTitle(LPCSTR window_title, DWORD desired_access);
HANDLE GetProcessHandleByClass(LPCSTR class_name, DWORD desired_access);

// BASE ADDRESS
uintptr_t GetModuleBaseAddress(TCHAR* modName, DWORD procId);

// --- READ ---
template <typename T>
T ReadMem(HANDLE pHandle, LPCVOID address) {
    T buffer;
    ReadProcessMemory(pHandle, address, &buffer, sizeof(T), nullptr);
    return buffer;
}

// --- WRITE ---
template <typename T>
void WriteMem(HANDLE pHandle, LPVOID address, T value) {
    WriteProcessMemory(pHandle, address, &value, sizeof(T), nullptr);
}

#endif //MEMORIA_MEMORIA_H
