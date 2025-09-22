#include "Render/Render.h"

DWORD WINAPI MainThread(LPVOID lpReserved) {
    bool init_hook = false;
    do
    {
        if (kiero::init(kiero::RenderType::D3D11) == kiero::Status::Success)
        {
            kiero::bind(8, (void**)&oPresent, hkPresent);
            init_hook = true;
        }
    } while (!init_hook);
    return TRUE;
}

void cacheThread() {
    HoldFast::cache.PlayerThread();
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    if (ul_reason_for_call == DLL_PROCESS_ATTACH)
    {
        DisableThreadLibraryCalls(hModule);
        AllocConsole();
        freopen_s(reinterpret_cast<FILE**>(stdin), "CONIN$", "r", stdin);
        freopen_s(reinterpret_cast<FILE**>(stdout), "CONOUT$", "w", stdout);
        printf("[/] Loading HoldFast Legend Hack\n");
        CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)cacheThread, 0, 0, nullptr);
        CreateThread(nullptr, 0, MainThread, hModule, 0, nullptr);
    }
    return TRUE;
}

