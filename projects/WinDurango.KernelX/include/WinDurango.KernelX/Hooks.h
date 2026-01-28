#pragma once
#include <winrt/Windows.ApplicationModel.h>
#include <windows.h>
#include <filesystem>
#include <Shlwapi.h>
#include <winrt/windows.storage.provider.h>
#include <windows.applicationmodel.core.h>
#include <string>
#include <locale>
#include <codecvt>


//Provided by XWine1, all credits to them.
//(This is from the old impl but we can use it just fine).
HRESULT XWineGetImport(_In_opt_ HMODULE Module, _In_ HMODULE ImportModule, _In_ LPCSTR Import,
                       _Out_ PIMAGE_THUNK_DATA *pThunk);
HRESULT XWinePatchImport(_In_opt_ HMODULE Module, _In_ HMODULE ImportModule, _In_ PCSTR Import, _In_ PVOID Function);
HRESULT PatchNeededImports(_In_opt_ HMODULE Module, _In_ HMODULE ImportModule, _In_ PCSTR Import, _In_ PVOID Function);
HMODULE GetRuntimeModule();
inline HRESULT WINAPI EraRoGetActivationFactory(HSTRING classId, REFIID iid, void **factory);
HRESULT WINAPI GetActivationFactoryRedirect(PCWSTR str, REFIID riid, void **ppFactory);