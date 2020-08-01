#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <hlib.h>
#include <string>


using namespace hlib;
using namespace std;

// HE
//S4_Main.exe+18CC86 - 8B C6                   - mov eax,esi
//S4_Main.exe+18CC88 - C7 86 AC000000 00000000 - mov [esi+000000AC],00000000
//S4_Main.exe+18CC92 - C7 86 B0000000 00000000 - mov [esi+000000B0],00000000
//S4_Main.exe+18CC9C - C7 86 B4000000 0F000000 - mov [esi+000000B4],0000000F <====== patch here
//S4_Main.exe+18CCA6 - C7 86 B8000000 00000000 - mov [esi+000000B8],00000000
//S4_Main.exe+18CCB0 - 5E                      - pop esi
//S4_Main.exe+18CCB1 - 8B E5                   - mov esp,ebp
//S4_Main.exe+18CCB3 - 5D                      - pop ebp
//S4_Main.exe+18CCB4 - C2 1C00                 - ret 001C

// GE
//S4_Main.exe+64E9B - 89 86 BC000000        - mov [esi+000000BC],eax
//S4_Main.exe+64EA1 - 8A 56 67              - mov dl,[esi+67]
//S4_Main.exe+64EA4 - 89 86 C0000000        - mov [esi+000000C0],eax
//S4_Main.exe+64EAA - 89 86 C4000000        - mov [esi+000000C4],eax
//S4_Main.exe+64EB0 - 89 86 CC000000        - mov [esi+000000CC],eax
//S4_Main.exe+64EB6 - C7 86 C8000000 0F000000 - mov [esi+000000C8],0000000F <====== patch here
//S4_Main.exe+64EC0 - 89 96 D0000000        - mov [esi+000000D0],edx


#define PATTERN_FERRY_CONSTRUCTOR_HE "8B C6 C7 86 AC 00 00 00 00 00 00 00 C7 86 B0 00 00 00 00 00 00 00 C7 86 B4 00 00 00 ? ? ? ? C7 86 B8 00 00 00 00 00 00 00 5E 8B E5 5D C2 1C 00"
#define PATTERN_FERRY_CONSTRUCTOR_GE "00 8A 56 67 89 86 C0 00 00 00 89 86 C4 00 00 00 89 86 CC 00 00 00 C7 86 C8 00 00 00 ? ? ? ? 89 96 D0 00 00 00"

static const DWORD DefaultNewFerryLimit = 45;

static LPWSTR filenameOf(LPWSTR str) {
	if (str == NULL) return str;
	for (WCHAR* c = str; *c != 0; c++) {
		if (*c == L'/' || *c == L'\\') { str = c; ++str; }
	}
	return str;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved) {
	static Patch FerryCapacityPatch;
	static HANDLE hProcess = GetCurrentProcess();

    switch (ul_reason_for_call) {
	case DLL_PROCESS_ATTACH: {
		const DWORD S4_Main = (DWORD)GetModuleHandleA(NULL);
		const bool isGE = GetModuleHandleA("GfxEngine.dll"); // if this module is present, we assume gold edition
		const DWORD FerryConstructorPattern = (DWORD)FindPattern(hProcess, S4_Main,
			StringPattern(isGE ? PATTERN_FERRY_CONSTRUCTOR_GE : PATTERN_FERRY_CONSTRUCTOR_HE));

		if (!FerryConstructorPattern) {
			MessageBox(NULL, "Sorry, your game version is not supported by the Ferry Capacity Customizer plugin. Please open a ticket here: https://github.com/nyfrk/FerryLimitCustomizer/issues", "S4 Ferry Limit Customizer", MB_ICONWARNING | MB_OK);
		}
		else {
			DWORD newFerryLimit = DefaultNewFerryLimit;

			WCHAR buf[MAX_PATH+1];
			auto length = GetModuleFileNameW(hModule, buf, _countof(buf)-1);
			buf[length] = '\0'; // xp compatibility

			if (length >= 0) { // we got a valid file name
				LPWSTR fn = filenameOf(buf);
				wcscpy_s(fn, _countof(buf) - (fn - buf), L"FerryCustomizer.ini");
				newFerryLimit = (DWORD)max(0,GetPrivateProfileIntW(L"Ferry", L"Capacity", DefaultNewFerryLimit, buf));
			}
			
			FerryCapacityPatch = Patch(FerryConstructorPattern + 28, newFerryLimit);
			FerryCapacityPatch.patch(hProcess);
		}
		break;
	}
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
		break;
    case DLL_PROCESS_DETACH:
		FerryCapacityPatch.unpatch(hProcess);
        break;
    }
    return TRUE;
}

