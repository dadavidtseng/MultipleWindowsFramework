//----------------------------------------------------------------------------------------------------
// Window.hpp
//----------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------
#pragma once
#include <chrono>
#include <random>

//----------------------------------------------------------------------------------------------------
struct sDriftParams
{
    float velocityX      = 0;               // X方向速度 (像素/秒)
    float velocityY      = 0;               // Y方向速度 (像素/秒)
    float acceleration   = 50.f;            // 加速度係數
    float drag           = 0.98f;           // 阻力係數 (0.95-0.99)
    float bounceEnergy   = 0.8f;            // 反彈能量保留係數 (0.7-0.9)
    float wanderStrength = 2000.f;          // 隨機漂移強度
    float targetVelocity = 100.f;           // 目標速度
    bool  enableGravity  = true;            // 是否啟用重力
    bool  enableWander   = true;            // 是否啟用隨機漂移
};

//----------------------------------------------------------------------------------------------------
class Window
{
public:
    Window();
    void* m_windowHandle   = nullptr;
    void* m_displayContext = nullptr;
    int   x                = 0;
    int   y                = 0;
    int   width            = 0;
    int   height           = 0;
    float viewportX        = 0;
    float viewportY        = 0;
    float viewportWidth    = 0;
    float viewportHeight   = 0;
    RECT  lastRect{};
    bool  needsUpdate = true;

    // 漂移相關
    sDriftParams                          drift;
    std::mt19937                          rng;
    std::uniform_real_distribution<float> wanderDist{-1.f, 1.f};
    std::chrono::steady_clock::time_point lastUpdateTime;
    bool                                  isDragging = false;          // 是否正在被拖拽
    POINT                                 dragOffset{};         // 拖拽偏移
};

LRESULT CALLBACK WindowsMessageHandlingProcedure(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
