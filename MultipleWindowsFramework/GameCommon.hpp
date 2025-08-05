//----------------------------------------------------------------------------------------------------
// GameCommon.h
//----------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------
#pragma once
#include <windows.h>

//-Forward-Declaration--------------------------------------------------------------------------------
class Renderer;

//----------------------------------------------------------------------------------------------------
extern Renderer* g_renderer;

void CreateAndRegisterMultipleWindows(HINSTANCE hInstance, int windowCount);
HWND CreateGameWindow(HINSTANCE hInstance,  wchar_t const* title, int x, int y, int width, int height);
