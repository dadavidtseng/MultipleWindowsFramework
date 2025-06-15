//----------------------------------------------------------------------------------------------------
// WindowEx.hpp
//----------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------
#pragma once
#include <chrono>
#include <random>

//----------------------------------------------------------------------------------------------------
struct sDriftParams
{
    float velocityX      = 0;            // X方向速度 (像素/秒)
    float velocityY      = 0;            // Y方向速度 (像素/秒)
    float acceleration   = 50.0f;         // 加速度係數
    float drag           = 0.98f;                 // 阻力係數 (0.95-0.99)
    float bounceEnergy   = 0.8f;         // 反彈能量保留係數 (0.7-0.9)
    float wanderStrength = 2000.0f;       // 隨機漂移強度
    float targetVelocity = 100.0f;       // 目標速度
    bool  enableGravity  = true;        // 是否啟用重力
    bool  enableWander   = true;         // 是否啟用隨機漂移
};

//----------------------------------------------------------------------------------------------------
class WindowEx
{
public:
    WindowEx();
    void*  m_windowHandle   = nullptr;
    void*   m_displayContext = nullptr;
    int   x                = 0, y         = 0, width         = 0, height         = 0;
    float viewportX        = 0, viewportY = 0, viewportWidth = 0, viewportHeight = 0;
    RECT  lastRect{};
    bool  needsUpdate = true;

    // 漂移相關
    sDriftParams                           drift;
    std::mt19937                          rng;
    std::uniform_real_distribution<float> wanderDist{-1.0f, 1.0f};
    std::chrono::steady_clock::time_point lastUpdateTime;
    bool                                  isDragging = false;          // 是否正在被拖拽
    POINT                                 dragOffset{};         // 拖拽偏移
};

LRESULT CALLBACK WindowsMessageHandlingProcedure(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
