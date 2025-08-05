//----------------------------------------------------------------------------------------------------
// Renderer.hpp
//----------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------
#pragma once
#include <vector>
#include <windows.h>

//-Forward-Declaration--------------------------------------------------------------------------------
class Window;
struct sDriftParams;
struct ID3D11Texture2D;
struct ID3D11Device;
struct ID3D11DeviceContext;
struct IDXGISwapChain;
struct ID3D11RenderTargetView;
struct ID3D11VertexShader;
struct ID3D11PixelShader;
struct ID3D11Buffer;
struct ID3D11InputLayout;
struct ID3D11SamplerState;
struct ID3D11ShaderResourceView;
struct IWICImagingFactory;

class Renderer
{
public:
    Renderer();
    ~Renderer();

    HRESULT Initialize(HWND const& hiddenMainWindow);
    HRESULT LoadImageFromFile(wchar_t const* filename, ID3D11Texture2D** texture, ID3D11ShaderResourceView** srv) const;
    void    SetWindowDriftParams(HWND hwnd, const sDriftParams& params);
    void    StartDragging(HWND hwnd, POINT const& mousePos);
    void    StopDragging(HWND hwnd);
    void    UpdateDragging(HWND hwnd, POINT const& mousePos) const;
    void    UpdateWindowDrift(Window& window) const;
    HRESULT AddWindow(HWND const& hwnd);
    void    UpdateWindowPosition(Window& window) const;
    void    Render();
    HRESULT CreateDeviceAndSwapChain();
    HRESULT CreateSceneRenderTexture();
    HRESULT CreateStagingTexture();
    HRESULT CreateTestTexture(const wchar_t* imageFile = nullptr);
    HRESULT CreateShaders();
    HRESULT CreateVertexBuffer();
    HRESULT CreateSampler();

private:
    void RenderTestTexture() const;
    void UpdateWindows();
    void RenderViewportToWindow(Window const& window) const;
    void Cleanup();

    ID3D11Device*             m_device                         = nullptr;
    ID3D11DeviceContext*      m_deviceContext                  = nullptr;
    IDXGISwapChain*           m_mainSwapChain                  = nullptr;
    ID3D11RenderTargetView*   m_mainBackBufferRenderTargetView = nullptr;
    ID3D11Texture2D*          m_sceneTexture                   = nullptr;
    ID3D11RenderTargetView*   m_sceneRenderTargetView          = nullptr;
    ID3D11ShaderResourceView* m_sceneShaderResourceView        = nullptr;
    ID3D11Texture2D*          m_stagingTexture                 = nullptr;
    ID3D11Texture2D*          m_testTexture                    = nullptr;
    ID3D11ShaderResourceView* m_testShaderResourceView         = nullptr;
    ID3D11VertexShader*       m_vertexShader                   = nullptr;
    ID3D11PixelShader*        m_pixelShader                    = nullptr;
    ID3D11Buffer*             m_vertexBuffer                   = nullptr;
    ID3D11Buffer*             m_indexBuffer                    = nullptr;
    ID3D11InputLayout*        m_inputLayout                    = nullptr;
    ID3D11SamplerState*       m_sampler                        = nullptr;

    std::vector<Window> m_windowList;
    UINT                sceneWidth = 1920, sceneHeight = 1080;
    HWND                mainWindow = nullptr;

    BITMAPINFO        bitmapInfo;
    std::vector<BYTE> pixelData;

    int virtualScreenWidth;
    int virtualScreenHeight;

    IWICImagingFactory* m_wicFactory = nullptr;
};
