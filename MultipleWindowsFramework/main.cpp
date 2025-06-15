//----------------------------------------------------------------------------------------------------
// main.cpp
//----------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------
#include "GameCommon.hpp"

//----------------------------------------------------------------------------------------------------
int WINAPI WinMain(HINSTANCE const hInstance,
                   HINSTANCE       hPrevInstance,
                   LPSTR           lpCmdLine,
                   int const       nShowCmd)
{
    CoInitialize(nullptr);

    // 創建隱藏的主窗口
    HWND const hiddenWindow = CreateWindowEx(
        NULL,
        L"STATIC",
        L"Hidden",
        WS_POPUP,
        0, 0, 1, 1,
        nullptr,
        nullptr,
        GetModuleHandle(nullptr),
        nullptr
    );

    // 初始化渲染器
    g_theRenderer = new RendererEx();
    if (FAILED(g_theRenderer->Initialize(hiddenWindow)))
    {
        MessageBox(nullptr, L"Failed to initialize renderer", L"Error", MB_OK);
        return -1;
    }

    CreateAndRegisterMultipleWindows(hInstance, 10);


    // 主訊息循環
    MSG  msg     = {};
    bool running = true;

    while (running)
    {
        while (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
        {
            if (msg.message == WM_QUIT)
            {
                running = false;
                break;
            }
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }

        if (running)
        {
            if (g_theRenderer)
            {
                g_theRenderer->Render();
            }
            Sleep(16); // ~60 FPS
        }
    }

    // 清理
    delete g_theRenderer;
    DestroyWindow(hiddenWindow);
    CoUninitialize();
    return 0;
}
