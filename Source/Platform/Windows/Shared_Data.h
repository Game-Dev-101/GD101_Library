#ifndef __SHARED_DATA__
#define __SHARED_DATA__


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
        extern HINSTANCE               g_hInst ;
        extern HWND                    g_hWnd ;
        extern D3D_DRIVER_TYPE         g_driverType;
        extern D3D_FEATURE_LEVEL       g_featureLevel ;
        extern ID3D11Device*           g_pd3dDevice ;
        extern ID3D11DeviceContext*    g_pImmediateContext;
        extern IDXGISwapChain*         g_pSwapChain ;
        extern ID3D11RenderTargetView* g_pRenderTargetView ;
        extern ID3D11VertexShader*     g_pVertexShader;
        extern ID3D11PixelShader*      g_pPixelShader ;
        extern ID3D11InputLayout*      g_pVertexLayout ;
        extern ID3D11Buffer*           g_pVertexBuffer ;

		// Windows Size
		extern RECT rc;

    #elif defined(OPENGL)

#endif // DIRECTX
#endif // OPENGL


#endif // __SHARED_DATA__