//----------------------------------------------------------------------------------------------------
// GameCommon.cpp
//----------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------
#include "GameCommon.hpp"

#include <string>

#include "Renderer.hpp"
#include "Window.hpp"

//----------------------------------------------------------------------------------------------------
Renderer* g_renderer = nullptr;

//----------------------------------------------------------------------------------------------------
void CreateAndRegisterMultipleWindows(HINSTANCE const hInstance,
                                      int const       windowCount)
{
    int const width   = 400;
    int const height  = 300;
    int const startX  = 100;
    int const startY  = 100;
    int const offsetX = 450;
    int const offsetY = 350;

    for (int i = 0; i < windowCount; ++i)
    {
        std::wstring title = L"ChildWindow " + std::to_wstring(i + 1);
        int          x     = startX + (i % 5) * offsetX;       // 每列最多5個視窗
        int          y     = startY + (i / 5) * offsetY;       // 每滿5個換行

        HWND hwnd = CreateGameWindow(hInstance, title.c_str(), x, y, width, height);
        if (hwnd)
        {
            g_renderer->AddWindow(hwnd);
        }
    }
}

//----------------------------------------------------------------------------------------------------
HWND CreateGameWindow(HINSTANCE const hInstance,
                      wchar_t const*  title,
                      int const       x,
                      int const       y,
                      int const       width,
                      int const       height)
{
    WNDCLASS wc      = {};
    wc.lpfnWndProc   = WindowsMessageHandlingProcedure;
    wc.hInstance     = hInstance;
    wc.lpszClassName = L"GameWindow";
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.hCursor       = LoadCursor(nullptr, IDC_ARROW);

    RegisterClass(&wc);

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
    }

    return hwnd;
}
