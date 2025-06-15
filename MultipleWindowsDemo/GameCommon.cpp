//----------------------------------------------------------------------------------------------------
// GameCommon.cpp
//----------------------------------------------------------------------------------------------------

#include "GameCommon.hpp"
#include "WindowEx.hpp"

#include <string>

RendererEx*       g_theRenderer = nullptr;
// std::vector<HWND> g_gameWindows;

void CreateAndRegisterMultipleWindows(HINSTANCE hInstance, int windowCount)
{
    const int width   = 400;
    const int height  = 300;
    const int startX  = 100;
    const int startY  = 100;
    const int offsetX = 450;
    const int offsetY = 350;

    for (int i = 0; i < windowCount; ++i)
    {
        std::wstring title = L"ChildWindow " + std::to_wstring(i + 1);
        int          x     = startX + (i % 5) * offsetX;       // 每列最多5個視窗
        int          y     = startY + (i / 5) * offsetY;       // 每滿5個換行

        HWND hwnd = CreateGameWindow(hInstance, title.c_str(), x, y, width, height);
        if (hwnd)
        {
            // g_gameWindows.push_back(hwnd);
            g_theRenderer->AddWindow(hwnd);
        }
    }
}

// 創建窗口
HWND CreateGameWindow(HINSTANCE const hInstance,
                      wchar_t const*  title,
                      int const       x,
                      int const       y,
                      int const       width,
                      int const       height)
{
    // static bool classRegistered = false;
    // if (!classRegistered)
    // {
    WNDCLASS wc      = {};
    wc.lpfnWndProc   = WindowsMessageHandlingProcedure;
    wc.hInstance     = hInstance;
    wc.lpszClassName = L"GameWindow";
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.hCursor       = LoadCursor(nullptr, IDC_ARROW);

    RegisterClass(&wc);
    // classRegistered = true;
    // }

    HWND hwnd = CreateWindowEx(
        0,
        L"GameWindow",
        title,
        WS_OVERLAPPEDWINDOW,
        x, y, width, height,
        nullptr,
        nullptr,
        hInstance,
        nullptr
    );

    if (hwnd)
    {
        ShowWindow(hwnd, SW_SHOW);
        // UpdateWindow(hwnd);
    }

    return hwnd;
}
