#include "Settings.h"
		
//-----------------------------------------------------------------------------------------------------------
//		FOR WINDOWS PLATFORM
//-----------------------------------------------------------------------------------------------------------
#if defined(_WINDOWS) || defined(WIN32) || defined(_WIN32)

#include <string>
#include "Platform\Windows\DX\PxShaderYellow.h"
#include "Platform\Windows\DX\VShaderNormal.h"

	bool GD101_InitWindow(const char * windowName, int height, int width)
	{
		#if defined(UNICODE)
			tempUnicode= new wchar_t[strlen(windowName) + 1];
			mbstowcs_s(NULL, tempUnicode, strlen(windowName) + 1, windowName, strlen(windowName));

			if( !InitWindow(tempUnicode, height, width)  )
			return false;
		#else
			if( !InitWindow(windowName, height, width)  )
			return false;
		#endif
			
		if( !InitDevice() )
		{
			CleanupDevice();
			return false;
		}

		ShowWindow( g_hWnd, _nCmdShow );
	
		return true;
	}

	bool EndLoop()
	{
			if( PeekMessage( &msg, NULL, 0, 0, PM_REMOVE ) )
			{
				TranslateMessage( &msg );
				DispatchMessage( &msg );
			}
			if(WM_QUIT == msg.message){
				CleanupDevice();

				delete tempUnicode;
				delete tempName;
				return true;
			}
 
		return false;
	}
	HRESULT InitWindow(LPCWSTR windowName , int height,int width)
	{
		 // Register class
		WNDCLASSEX wcex;
		wcex.cbSize = sizeof( WNDCLASSEX );
		wcex.style = CS_HREDRAW | CS_VREDRAW;
		wcex.lpfnWndProc = WndProc;
		wcex.cbClsExtra = 0;
		wcex.cbWndExtra = 0;
		wcex.hInstance = g_hInst;
		wcex.hIcon = LoadIcon( g_hInst, ( LPCTSTR )IDI_GD101_LIB );
		wcex.hCursor = LoadCursor( NULL, IDC_ARROW );
		wcex.hbrBackground = ( HBRUSH )( COLOR_WINDOW + 1 );
		wcex.lpszMenuName = NULL;
		wcex.lpszClassName = windowName;///TEXT("");
		wcex.hIconSm = LoadIcon( wcex.hInstance, ( LPCTSTR )IDI_GD101_LIB );
		if( !RegisterClassEx( &wcex ) )
			return E_FAIL;

		// Create window
		// Error disini, mau keluar dulu jalan2 
		//rc = { 0, 0, width, height };
		rc.left = 0;
		rc.top =  0;
		rc.right = width;
		rc.bottom = height;
		AdjustWindowRect( &rc, WS_OVERLAPPEDWINDOW, FALSE );
		g_hWnd = CreateWindow( windowName/*TEXT("")*/, windowName /*TEXT("")*/,
							   WS_OVERLAPPED | WS_MINIMIZEBOX | WS_SYSMENU, // Ini untuk FIXED Size Window
							   CW_USEDEFAULT, CW_USEDEFAULT, rc.right - rc.left, rc.bottom - rc.top, NULL, NULL, g_hInst,
							   NULL );
		if( !g_hWnd )
			return E_FAIL;
		
		return 1;
	}
	LRESULT CALLBACK    WndProc( HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam )
	{
		PAINTSTRUCT ps;
		HDC hdc;

		switch( message )
		{
			case WM_PAINT:
				hdc = BeginPaint( hWnd, &ps );
				EndPaint( hWnd, &ps );
				break;

			case WM_DESTROY:
				PostQuitMessage( 0 );
				break;

			default:
				return DefWindowProc( hWnd, message, wParam, lParam );
		}
		return 0;
	}

	int InitStandartShader()
	{
		int hr = 0;
		// Compile the vertex shader
		#if defined(DIRECTX)
		ID3DBlob* pVSBlob = NULL;
		std::string vert = "float4 VS( float4 Pos : POSITION ) : SV_POSITION  { return Pos; }";

		std::string pix = "float4 PS( float4 Pos : SV_POSITION ) : SV_Target {  return float4( 1.0f, 1.0f, 1.0f, 1.0f );   }";

		hr = D3DCompile( vert.c_str(), vert.length(), nullptr, nullptr, nullptr, "VS", "vs_4_0", 0, 0, &pVSBlob, nullptr);
			if( FAILED( hr ) )
			{
				MessageBox( NULL,
							L"The FX1 file cannot be compiled.  Please run this executable from the directory that contains the FX file.", L"Error", MB_OK );
				return hr;
			}

			//SIZE_T size = 436;
			// Create the vertex shader
			hr = g_pd3dDevice->CreateVertexShader( pVSBlob->GetBufferPointer(), pVSBlob->GetBufferSize(), NULL, &g_pVertexShader );
			if( FAILED( hr ) )
			{	
				pVSBlob->Release();
				return hr;
			}

			// Define the input layout
			D3D11_INPUT_ELEMENT_DESC layout[] =
			{
				{ "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
			};
			UINT numElements = ARRAYSIZE( layout );

			// Create the input layout
			hr = g_pd3dDevice->CreateInputLayout( layout, numElements, pVSBlob->GetBufferPointer(), pVSBlob->GetBufferSize() , &g_pVertexLayout );
			pVSBlob->Release();
			if( FAILED( hr ) )
				return hr;

			// Set the input layout
			g_pImmediateContext->IASetInputLayout( g_pVertexLayout );

			// Compile the pixel shader
			ID3DBlob* pPSBlob = NULL;
			hr =  D3DCompile( pix.c_str(), pix.length(), nullptr, nullptr, nullptr, "PS", "ps_4_0", D3DCOMPILE_ENABLE_STRICTNESS, 0, &pPSBlob, nullptr);
			if( FAILED( hr ) )
			{
				MessageBox( NULL,
							L"The FX2 file cannot be compiled.  Please run this executable from the directory that contains the FX file.", L"Error", MB_OK );
				return hr;
			}

			// Create the pixel shader
			hr = g_pd3dDevice->CreatePixelShader( pPSBlob->GetBufferPointer(), pPSBlob->GetBufferSize(), NULL, &g_pPixelShader );
			pPSBlob->Release();
			if( FAILED( hr ) )
				return hr;
			
		#elif defined(OPENGL)
	
			  int vertexShader = glCreateShader(GL_VERTEX_SHADER);
			 glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
			 glCompileShader(vertexShader);
			   check for shader compile errors
			 int success;
			 char infoLog[512];
			 glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
			 if (!success)
			 {
				 glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
				  std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
			 }
		#endif
		isShaderLoaded= true;

		return 0;
	}

	int LoadShaderFile(const char * pFileName)
	{

		int hr = 0;
		#if defined(UNICODE)
			tempName = new wchar_t[strlen(pFileName) + 1];
			mbstowcs_s(NULL, tempName, strlen(pFileName) + 1, pFileName, strlen(pFileName));

		#endif
		// Compile the vertex shader
		#if defined(DIRECTX)
		ID3DBlob* pVSBlob = NULL;
		std::string vert = "float4 VS( float4 Pos : POSITION ) : SV_POSITION  { return Pos; }";

		std::string pix = "float4 PS( float4 Pos : SV_POSITION ) : SV_Target {  return float4( 1.0f, 1.0f, 1.0f, 1.0f );   }";

		hr = D3DCompile( vert.c_str(), vert.length(), nullptr, nullptr, nullptr, "VS", "vs_4_0", 0, 0, &pVSBlob, nullptr);
			if( FAILED( hr ) )
			{
				MessageBox( NULL,
							L"The FX1 file cannot be compiled.  Please run this executable from the directory that contains the FX file.", L"Error", MB_OK );
				return hr;
			}

			//SIZE_T size = 436;
			// Create the vertex shader
			hr = g_pd3dDevice->CreateVertexShader( pVSBlob->GetBufferPointer(), pVSBlob->GetBufferSize(), NULL, &g_pVertexShader );
			if( FAILED( hr ) )
			{	
				pVSBlob->Release();
				return hr;
			}

			// Define the input layout
			D3D11_INPUT_ELEMENT_DESC layout[] =
			{
				{ "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
			};
			UINT numElements = ARRAYSIZE( layout );

			// Create the input layout
			hr = g_pd3dDevice->CreateInputLayout( layout, numElements, pVSBlob->GetBufferPointer(), pVSBlob->GetBufferSize() , &g_pVertexLayout );
			pVSBlob->Release();
			if( FAILED( hr ) )
				return hr;

			// Set the input layout
			g_pImmediateContext->IASetInputLayout( g_pVertexLayout );

			// Compile the pixel shader
			ID3DBlob* pPSBlob = NULL;
			hr =  D3DCompile( pix.c_str(), pix.length(), nullptr, nullptr, nullptr, "PS", "ps_4_0", D3DCOMPILE_ENABLE_STRICTNESS, 0, &pPSBlob, nullptr);
			if( FAILED( hr ) )
			{
				MessageBox( NULL,
							L"The FX2 file cannot be compiled.  Please run this executable from the directory that contains the FX file.", L"Error", MB_OK );
				return hr;
			}

			// Create the pixel shader
			hr = g_pd3dDevice->CreatePixelShader( pPSBlob->GetBufferPointer(), pPSBlob->GetBufferSize(), NULL, &g_pPixelShader );
			pPSBlob->Release();
			if( FAILED( hr ) )
				return hr;
			
		#elif defined(OPENGL)
	
			  int vertexShader = glCreateShader(GL_VERTEX_SHADER);
			 glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
			 glCompileShader(vertexShader);
			   check for shader compile errors
			 int success;
			 char infoLog[512];
			 glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
			 if (!success)
			 {
				 glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
				  std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
			 }
		#endif
		isShaderLoaded= true;
		//SetShader();
		return 1;
	}
	int ActivateShader()
	{
		int hr = 0;

		#if defined(DIRECTX)
			 SimpleVertex vertices[] =
			{
				XMFLOAT3( 0.0f, 0.5f, 0.5f ),
				XMFLOAT3( 0.5f, -0.5f, 0.5f ),
				XMFLOAT3( -0.5f, -0.5f, 0.5f ),
			};
			D3D11_BUFFER_DESC bd;
			ZeroMemory( &bd, sizeof(bd) );
			bd.Usage = D3D11_USAGE_DEFAULT;
			bd.ByteWidth = sizeof( SimpleVertex ) * 3;
			bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
			bd.CPUAccessFlags = 0;
			D3D11_SUBRESOURCE_DATA InitData;
			ZeroMemory( &InitData, sizeof(InitData) );
			InitData.pSysMem = vertices;
			hr = g_pd3dDevice->CreateBuffer( &bd, &InitData, &g_pVertexBuffer );
			if( FAILED( hr ) )
				return hr;

			// Set vertex buffer
			UINT stride = sizeof( SimpleVertex );
			UINT offset = 0;
			g_pImmediateContext->IASetVertexBuffers( 0, 1, &g_pVertexBuffer, &stride, &offset );

			// Set primitive topology
			g_pImmediateContext->IASetPrimitiveTopology( D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST );

		#elif defined(OPENGL)
    
		#endif
		return 1;
	}

	#if defined(DIRECTX)
	//--------------------------------------------------------------------------------------
	// Helper for compiling shaders with D3DX11
	//--------------------------------------------------------------------------------------

	//HRESULT CompileShaderDirectX( const char* data)
	//{

	//}
	HRESULT CompileShaderFromFile( WCHAR* szFileName, LPCSTR szEntryPoint, LPCSTR szShaderModel, ID3DBlob** ppBlobOut )
	{
		HRESULT hr = S_OK;

		DWORD dwShaderFlags = D3DCOMPILE_ENABLE_STRICTNESS;
	#if defined( DEBUG ) || defined( _DEBUG )
		// Set the D3DCOMPILE_DEBUG flag to embed debug information in the shaders.
		// Setting this flag improves the shader debugging experience, but still allows 
		// the shaders to be optimized and to run exactly the way they will run in 
		// the release configuration of this program.
		dwShaderFlags |= D3DCOMPILE_DEBUG;
	#endif

		ID3DBlob* pErrorBlob;
		hr = D3DX11CompileFromFile( szFileName, NULL, NULL, szEntryPoint, szShaderModel, 
			dwShaderFlags, 0, NULL, ppBlobOut, &pErrorBlob, NULL );
		
		if( FAILED(hr) )
		{
			if( pErrorBlob != NULL )
				OutputDebugStringA( (char*)pErrorBlob->GetBufferPointer() );
			if( pErrorBlob ) pErrorBlob->Release();
			return hr;
		}
		if( pErrorBlob ) pErrorBlob->Release();

		return S_OK;
	}
	//--------------------------------------------------------------------------------------
	// Create Direct3D device and swap chain for DIRECTX
	//--------------------------------------------------------------------------------------
	HRESULT InitDevice()
	{
		HRESULT hr = S_OK;

		RECT rc;
		GetClientRect( g_hWnd, &rc );
		UINT width = rc.right - rc.left;
		UINT height = rc.bottom - rc.top;

		UINT createDeviceFlags = 0;
	#ifdef _DEBUG
		createDeviceFlags |= D3D11_CREATE_DEVICE_DEBUG;
	#endif

		D3D_DRIVER_TYPE driverTypes[] =
		{
			D3D_DRIVER_TYPE_HARDWARE,
			D3D_DRIVER_TYPE_WARP,
			D3D_DRIVER_TYPE_REFERENCE,
		};
		UINT numDriverTypes = ARRAYSIZE( driverTypes );

		D3D_FEATURE_LEVEL featureLevels[] =
		{
			D3D_FEATURE_LEVEL_11_0,
			D3D_FEATURE_LEVEL_10_1,
			D3D_FEATURE_LEVEL_10_0,
		};
		UINT numFeatureLevels = ARRAYSIZE( featureLevels );

		DXGI_SWAP_CHAIN_DESC sd;
		ZeroMemory( &sd, sizeof( sd ) );
		sd.BufferCount = 1;
		sd.BufferDesc.Width = width;
		sd.BufferDesc.Height = height;
		sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
		sd.BufferDesc.RefreshRate.Numerator = 60;
		sd.BufferDesc.RefreshRate.Denominator = 1;
		sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
		sd.OutputWindow = g_hWnd;
		sd.SampleDesc.Count = 1;
		sd.SampleDesc.Quality = 0;
		sd.Windowed = TRUE;

		for( UINT driverTypeIndex = 0; driverTypeIndex < numDriverTypes; driverTypeIndex++ )
		{
			g_driverType = driverTypes[driverTypeIndex];
			hr = D3D11CreateDeviceAndSwapChain( NULL, g_driverType, NULL, createDeviceFlags, featureLevels, numFeatureLevels,
												D3D11_SDK_VERSION, &sd, &g_pSwapChain, &g_pd3dDevice, &g_featureLevel, &g_pImmediateContext );
			if( SUCCEEDED( hr ) )
				break;
		}
		if( FAILED( hr ) )
			return hr;

		// Create a render target view
		ID3D11Texture2D* pBackBuffer = NULL;
		hr = g_pSwapChain->GetBuffer( 0, __uuidof( ID3D11Texture2D ), ( LPVOID* )&pBackBuffer );
		if( FAILED( hr ) )
			return hr;

		hr = g_pd3dDevice->CreateRenderTargetView( pBackBuffer, NULL, &g_pRenderTargetView );
		pBackBuffer->Release();
		if( FAILED( hr ) )
			return hr;

		g_pImmediateContext->OMSetRenderTargets( 1, &g_pRenderTargetView, NULL );

		// Setup the viewport
		D3D11_VIEWPORT vp;
		vp.Width = (FLOAT)width;
		vp.Height = (FLOAT)height;
		vp.MinDepth = 0.0f;
		vp.MaxDepth = 1.0f;
		vp.TopLeftX = 0;
		vp.TopLeftY = 0;
		g_pImmediateContext->RSSetViewports( 1, &vp );

		InitStandartShader();

		return 1;
	}
	//--------------------------------------------------------------------------------------
	// Clean up the objects we've created for DIRECTX
	//--------------------------------------------------------------------------------------
	void CleanupDevice()
	{
		if( g_pImmediateContext ) g_pImmediateContext->ClearState();

		if( g_pVertexBuffer ) g_pVertexBuffer->Release();
		if( g_pVertexLayout ) g_pVertexLayout->Release();
		if( g_pVertexShader ) g_pVertexShader->Release();
		if( g_pPixelShader ) g_pPixelShader->Release();
		if( g_pRenderTargetView ) g_pRenderTargetView->Release();
		if( g_pSwapChain ) g_pSwapChain->Release();
		if( g_pImmediateContext ) g_pImmediateContext->Release();
		if( g_pd3dDevice ) g_pd3dDevice->Release();
	}
	#endif // DIRECTX

	int ClearScreen()
	{
		// Clear the back buffer 
		#if defined(DIRECTX)
		float ClearColor[4] = { 0.0f, 0.125f, 0.3f, 1.0f }; // red,green,blue,alpha
		g_pImmediateContext->ClearRenderTargetView( g_pRenderTargetView, ClearColor );

		#elif defined(OPENGL)
				glClear(GL_COLOR_BUFFER_BIT);
		#endif
	
		return 1;
	}
	void ExecuteShader()
	{
		#if defined(DIRECTX)
		g_pImmediateContext->VSSetShader( g_pVertexShader, NULL, 0 );
		g_pImmediateContext->PSSetShader( g_pPixelShader, NULL, 0 );
		g_pImmediateContext->Draw( 3, 0 );

		#elif defined(OPENGL)
		glBegin(GL_TRIANGLES);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2i(0,  1);
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex2i(-1, -1);
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex2i(1, -1);
		glEnd();
		#endif

	}
	int ScreenFlip()
	{
		// Flip Screen
		#if defined(DIRECTX)
			g_pSwapChain->Present( 0, 0 );
		#elif defined(OPENGL)
			glFlush();
		#endif
    
		return 1;
	}
	//  ENTRYPOINT
	int WINAPI wWinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow )
	{
		g_hInst = hInstance;
		_nCmdShow= nCmdShow;

		return Main();
	}
//-----------------------------------------------------------------------------------------------------------
//		FOR ANDROID PLATFORM
//-----------------------------------------------------------------------------------------------------------
#elif defined(ANDROID)


//-----------------------------------------------------------------------------------------------------------
//		FOR PLAYSTATION_1 PLATFORM
//-----------------------------------------------------------------------------------------------------------
#elif defined(PLAYSTATION_1)

//-----------------------------------------------------------------------------------------------------------
//		FOR PLAYSTATION_2 PLATFORM
//-----------------------------------------------------------------------------------------------------------
#elif defined(PLAYSTATION_2)
#include <iostream>
void InitGS()
{
	// Enable the zbuffer.
	z.enable = DRAW_ENABLE;
	z.mask = 0;
	z.method = ZTEST_METHOD_GREATER_EQUAL;
	z.zsm = GS_ZBUF_32;
	z.address = graph_vram_allocate( frame.width, frame.height, z.zsm, GRAPH_ALIGN_PAGE);

	// Initialize the screen and tie the first framebuffer to the read circuits.
	graph_initialize(frame.address, frame.width, frame.height, frame.psm, 0, 0);
}
void InitDrawingEnvironment()
{
    packet_t *packet = packet_init(16,PACKET_NORMAL);
	// This is our generic qword pointer.
	qword_t *q = packet->data;
	// This will setup a default drawing environment.
	q = draw_setup_environment(q,0, &frame, &z);
	// Now reset the primitive origin to 2048-width/2,2048-height/2.
	q = draw_primitive_xyoffset(q,0,(2048-320),(2048-256));
	// Finish setting up the environment.
	q = draw_finish(q);
	// Now send the packet, no need to wait since it's the first.
	dma_channel_send_normal(DMA_CHANNEL_GIF,packet->data,q - packet->data, 0, 0);
	dma_wait_fast();

	packet_free(packet);   
}
bool EndLoop()
{
    //
    return false;
}

int ScreenFlip()
{      
    		// Define our dmatag for the dma chain.
		DMATAG_END(dmatag,(q-current->data)-1,0,0,0);

		// Now send our current dma chain.
		dma_wait_fast();
		dma_channel_send_chain(DMA_CHANNEL_GIF,current->data, q - current->data, 0, 0);
		// Now switch our packets so we can process data while the DMAC is working.
		context ^= 1;
		// Wait for scene to finish drawing
		draw_wait_finish();
		graph_wait_vsync();
        
        return 0;
}
int ClearScreen()
{
    current = packets[context];
    // Grab our dmatag pointer for the dma chain.
    dmatag = current->data;
   
    q = dmatag;
    q++;

    // Clear framebuffer but don't update zbuffer.
    q = draw_disable_tests(q,0,&z);
    q = draw_clear(q,0,2048.0f-320.0f,2048.0f-256.0f, frame.width, frame.height,0x00,0x20,0x4C);
    q = draw_enable_tests(q,0,&z);
    
    return 0;
}

bool GD101_InitWindow(const char * windowName, int height, int width)
{
    // 32-bit 640x512 framebuffer, kita gunakan fixed size windows
	frame.width = 640;
	frame.height = 512;
	frame.mask = 0;
	frame.psm = GS_PSM_32;
	frame.address = graph_vram_allocate(frame.width, frame.height, frame.psm, GRAPH_ALIGN_PAGE);
    
    InitGS();
    InitDrawingEnvironment();
    
    printf("PACKETS!\n");
    packets[0] = packet_init(100,PACKET_NORMAL);
	packets[1] = packet_init(100,PACKET_NORMAL);

    printf("CREATE VIEW!\n");
	// Create the view_screen matrix.
	create_view_screen(view_screen, graph_aspect_ratio(), -3.00f, 3.00f, -3.00f, 3.00f, 1.00f, 2000.00f);
    	// Wait for any previous dma transfers to finish before starting.
	dma_wait_fast();
    
    return true;
}

// EntryPoint
int main(int argc, char **argv)
{
    printf("INITTTT!\n");
    	// Init GIF dma channel.
	dma_channel_initialize(DMA_CHANNEL_GIF,NULL,0);
	dma_channel_fast_waits(DMA_CHANNEL_GIF);
    
    Main();   
    packet_free(packets[0]);
	packet_free(packets[1]);
	// Sleep
	SleepThread();
    return 0;
}
//-----------------------------------------------------------------------------------------------------------
//		FOR WEBGL PLATFORM
//-----------------------------------------------------------------------------------------------------------
#elif defined(WEBGL)
#include <iostream>

#include <stdio.h>
#include <stdlib.h>
#include <emscripten/emscripten.h>
#include <emscripten/html5.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <GLES2/gl2.h>

bool isInitialized = true;
GLuint compile_shader(GLenum shaderType, const char *src)
{
  GLuint shader = glCreateShader(shaderType);
  glShaderSource(shader, 1, &src, NULL);
  glCompileShader(shader);

  GLint isCompiled = 0;
  glGetShaderiv(shader, GL_COMPILE_STATUS, &isCompiled);
  if (!isCompiled)
  {
    GLint maxLength = 0;
    glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &maxLength);
    char *buf = (char*)malloc(maxLength);
    glGetShaderInfoLog(shader, maxLength, NULL, buf);
    printf("%s\n", buf);
    free(buf);
    return 0;
  }

   return shader;
}

GLuint create_program(GLuint vertexShader, GLuint fragmentShader)
{
   GLuint program = glCreateProgram();
   glAttachShader(program, vertexShader);
   glAttachShader(program, fragmentShader);
   glBindAttribLocation(program, 0, "apos");
   glBindAttribLocation(program, 1, "acolor");
   glLinkProgram(program);
   return program;
}

// ini buat mencegah infinity loop, karena kita butuh 1 kali process saja
bool firstEndLoop = true;//false;
int ScreenFlip()
{
    #ifdef EXPLICIT_SWAP
      emscripten_webgl_commit_frame();
    #endif
  
  return 0;
}

bool EndLoop()
{
    if(!firstEndLoop){
        firstEndLoop = true;
        return false;
    }
    else{
        return true;
    }
}

int ClearScreen()
{
    std::cout << "ClearScreen \n";
  glClearColor(0.0f, 0.125f, 0.3f,1);
  glClear(GL_COLOR_BUFFER_BIT);
  
  return 0;
}

bool GD101_InitWindow(const char * windowName, int height, int width)
{
        EmscriptenWebGLContextAttributes attr;
      emscripten_webgl_init_context_attributes(&attr);
    #ifdef EXPLICIT_SWAP
      attr.explicitSwapControl = 1;
    #endif
    #ifdef DRAW_FROM_CLIENT_MEMORY
      // This test verifies that drawing from client-side memory when enableExtensionsByDefault==false works.
      attr.enableExtensionsByDefault = 0;
    #endif

      EMSCRIPTEN_WEBGL_CONTEXT_HANDLE ctx = emscripten_webgl_create_context("#canvas", &attr);
      emscripten_webgl_make_context_current(ctx);

    emscripten_set_canvas_element_size("#canvas", (int)width, (int)height);
    glViewport(0, 0, (int)width, (int)height);
      static const char vertex_shader[] =
        "attribute vec4 apos;"
        "attribute vec4 acolor;"
        "varying vec4 color;"
        "void main() {"
          "color = acolor;"
          "gl_Position = apos;"
        "}";
      GLuint vs = compile_shader(GL_VERTEX_SHADER, vertex_shader);

      static const char fragment_shader[] =
        "precision lowp float;"
        "varying vec4 color;"
        "void main() {"
          "gl_FragColor = color;"
        "}";
      GLuint fs = compile_shader(GL_FRAGMENT_SHADER, fragment_shader);

      GLuint program = create_program(vs, fs);
      glUseProgram(program);
      
        glEnableVertexAttribArray(0);
      glEnableVertexAttribArray(1);
      std::cout << "Main Loop \n";

    
    return true;
}

int InitStandartShader()
{
 return 0;
}

EMSCRIPTEN_KEEPALIVE extern "C" void Entry() {
    std::cout << "Entry 1 \n";
}

EM_JS(int, GetCanvasWidth, (), {
    var canvas = document.getElementById('canvas');
    
    return canvas.width;
});
EM_JS(int, GetCanvasHeight, (), {
        var canvas = document.getElementById('canvas');
    
    return canvas.height;
});

int GetCvsWidth()
{
    return GetCanvasWidth();
}
int GetCvsHeight()
{
    return GetCanvasHeight();
}
// ENTRYPOINT
int main()
{
  std::cout << "Main \n";
  //InitStandartShader();
   
    EM_ASM({
    requestAnimationFrame = function() {
      Module._Entry();
    };
  });
  
  Main();
  //emscripten_set_main_loop(Main, 30, 1);
  std::cout << "End Main 1 \n";
    return 0;
}

#endif // ALL PLATFORM


