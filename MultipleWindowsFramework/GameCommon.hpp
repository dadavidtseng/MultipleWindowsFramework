//----------------------------------------------------------------------------------------------------
// GameCommon.h
//----------------------------------------------------------------------------------------------------

#pragma once
#include <vector>
#include <windows.h>

#include "RendererEx.hpp"

extern RendererEx* g_theRenderer;
// extern std::vector<HWND> g_gameWindows;

void CreateAndRegisterMultipleWindows(HINSTANCE hInstance, int windowCount);
HWND CreateGameWindow(HINSTANCE hInstance, const wchar_t* title, int x, int y, int width, int height);
