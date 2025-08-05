#include <windows.h>
#include "Window.hpp"

#include "GameCommon.hpp"

Window::Window()
{
    // 初始化隨機數生成器
    rng.seed(std::chrono::steady_clock::now().time_since_epoch().count());
    lastUpdateTime = std::chrono::steady_clock::now();

    // 隨機初始速度
    std::uniform_real_distribution<float> velDist(-50.0f, 50.0f);
    drift.velocityX = velDist(rng);
    drift.velocityY = velDist(rng);
}

// 窗口程序
LRESULT CALLBACK WindowsMessageHandlingProcedure(HWND const   hwnd,
                            UINT const   uMsg,
                            WPARAM const wParam,
                            LPARAM const lParam)
{
    switch (uMsg)
    {
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC         hdc = BeginPaint(hwnd, &ps);
            // 渲染由 WindowKillRenderer 處理
            EndPaint(hwnd, &ps);
            return 0;
        }
    case WM_MOVE:
    case WM_SIZE:
        // 窗口移動或大小改變時，標記需要更新
        if (g_renderer)
        {
            // 在下一次渲染時會自動檢測位置變化
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}
