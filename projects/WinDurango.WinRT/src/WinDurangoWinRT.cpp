#include "WinDurangoWinRT.h"

std::shared_ptr<wd::common::WinDurango> p_wd;

/*
 * https://learn.microsoft.com/en-us/windows/win32/dlls/dllmain
 */
BOOL WINAPI DllMain(HINSTANCE hinstDLL, // handle to DLL module
                    DWORD fdwReason,    // reason for calling function
                    LPVOID lpvReserved) // reserved
{
    switch (fdwReason)
    {
    case DLL_PROCESS_ATTACH:
        p_wd = wd::common::WinDurango::GetInstance();
        p_wd->log.Log("WinDurango::WinRT", "Initialized");
        break;

    case DLL_THREAD_ATTACH:
        p_wd = wd::common::WinDurango::GetInstance();
        p_wd->log.Log("WinDurango::WinRT", "Initialized");
        break;

    case DLL_THREAD_DETACH:
        p_wd = wd::common::WinDurango::GetInstance();
        p_wd->log.Log("WinDurango::WinRT", "Initialized");
        break;

    case DLL_PROCESS_DETACH:

        if (lpvReserved != nullptr)
        {
            break; // do not do cleanup if process termination scenario
        }

        // Perform any necessary cleanup.
        break;
    }
    return TRUE; // Successful DLL_PROCESS_ATTACH.
}