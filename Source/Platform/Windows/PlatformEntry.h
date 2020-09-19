#ifndef __PLATFORM_ENTRY__
#define __PLATFORM_ENTRY__

// Standart Windows set to DirectX
#ifndef OPENGL
#define DIRECTX
    #if defined(DIRECTX)
        #include <d3d11.h>
        #include <d3dx11.h>
        #include <d3dcompiler.h>
        #include <xnamath.h>

        //--------------------------------------------------------------------------------------
        // Global Variables
        //--------------------------------------------------------------------------------------
        HINSTANCE               g_hInst = NULL;
        HWND                    g_hWnd = NULL;
        D3D_DRIVER_TYPE         g_driverType = D3D_DRIVER_TYPE_NULL;
        D3D_FEATURE_LEVEL       g_featureLevel = D3D_FEATURE_LEVEL_11_0;
        ID3D11Device*           g_pd3dDevice = NULL;
        ID3D11DeviceContext*    g_pImmediateContext = NULL;
        IDXGISwapChain*         g_pSwapChain = NULL;
        ID3D11RenderTargetView* g_pRenderTargetView = NULL;
        ID3D11VertexShader*     g_pVertexShader = NULL;
        ID3D11PixelShader*      g_pPixelShader = NULL;
        ID3D11InputLayout*      g_pVertexLayout = NULL;
        ID3D11Buffer*           g_pVertexBuffer = NULL;

        HRESULT InitDevice();

        void CleanupDevice();
        void Render();

        void Execute();

        HRESULT CompileShaderFromFile( WCHAR* szFileName, LPCSTR szEntryPoint, LPCSTR szShaderModel, ID3DBlob** ppBlobOut );
        //--------------------------------------------------------------------------------------
        // Structures
        //--------------------------------------------------------------------------------------
        struct SimpleVertex
        {
            XMFLOAT3 Pos;
        };

		// Windows Size
		RECT rc;

    #elif defined(OPENGL)

#endif // DIRECTX
#endif // OPENGL

HRESULT InitWindow(LPCWSTR , int,int);
LRESULT CALLBACK    WndProc( HWND, UINT, WPARAM, LPARAM );
int _nCmdShow;

int WINAPI wWinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow );
bool EndLoop();

bool isShaderLoaded;
int LoadShaderFile(wchar_t *);

void UnLoadShaderFIle();
int SetShader();

int ScreenFlip();
void ExecuteShader();
int ClearScreen();

bool GD101_InitWindow(const char * windowName, int height, int width);
extern int Main();
MSG msg = {0};

wchar_t * tempUnicode;


#endif //__PLATFORM_ENTRY__