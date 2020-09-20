#include "GD101_DEF.h"

struct DrawVertex
{
	FLOAT2 pos;
};

// DirectX standart ViewPort
//////////////////////////////////////////////////
// -1.0f, 1.0f						1.0f, 1.0f	//
//												//
//												//
//					0.0f, 0.0f					//
//												//
//												//
// -1.0f, -1.0f						1.0f, -1.0f	//
//////////////////////////////////////////////////
#if defined(_WINDOWS) || defined(WIN32) || defined(_WIN32)
    #include "Platform\Windows\Graphics.h"
	#include "Platform\Windows\Shared_Data.h"

	DrawVertex vertices[2] ;

	int DrawLine(int x0, int y0, int x1, int y1)
	{
		//DrawVertex lineVertices[] = {
		//FLOAT2( 0.0f, 0.5f),
		//FLOAT2( 0.5f, -0.5f)	}; 

		// Anchor pointnya ditengah
		// Sementara Hardcoded
		FLOAT2 pos0( -1.0f,  -1.0f);

		FLOAT2 pos1(0.0f, 0.0f);

		vertices[0].pos = pos0;
		vertices[1].pos = pos1;

		D3D11_BUFFER_DESC bd;
		ZeroMemory( &bd, sizeof(bd) );
		bd.Usage = D3D11_USAGE_DEFAULT;
		bd.ByteWidth = sizeof( DrawVertex ) * 2;
		bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
		bd.CPUAccessFlags = 0;
		D3D11_SUBRESOURCE_DATA InitData;
		ZeroMemory( &InitData, sizeof(InitData) );
		InitData.pSysMem = vertices;

		g_pd3dDevice->CreateBuffer( &bd, &InitData, &g_pVertexBuffer );

		// Set vertex buffer
		UINT stride = sizeof( DrawVertex );
		UINT offset = 0;
		g_pImmediateContext->IASetVertexBuffers( 0, 1, &g_pVertexBuffer, &stride, &offset );

		// Set primitive topology
		g_pImmediateContext->IASetPrimitiveTopology( D3D11_PRIMITIVE_TOPOLOGY_LINELIST );


		g_pImmediateContext->VSSetShader( g_pVertexShader, NULL, 0 );
		g_pImmediateContext->PSSetShader( g_pPixelShader, NULL, 0 );
		g_pImmediateContext->Draw( 3, 0 );

		return 0;
	}
//-----------------------------------------------------------------------------------------------------------
//		FOR ANDROID PLATFORM
//-----------------------------------------------------------------------------------------------------------
#elif defined(ANDROID)
    #include "Platform\Android\Graphics.h"
    

//-----------------------------------------------------------------------------------------------------------
//		FOR WEBGL PLATFORM
//-----------------------------------------------------------------------------------------------------------
#elif defined(WEBGL)
    #include "Platform\WebGl\Graphics.h"
    

//-----------------------------------------------------------------------------------------------------------
//		FOR PLAYSTATION_1 PLATFORM
//-----------------------------------------------------------------------------------------------------------
#elif defined(PLAYSTATION_1)
    #include "Platform\PlayStation_1\Graphics.h"
    

//-----------------------------------------------------------------------------------------------------------
//		FOR PLAYSTATION_2 PLATFORM
//-----------------------------------------------------------------------------------------------------------
#elif defined(PLAYSTATION_2)
    #include "Platform\PlayStation_2\Graphics.h"

#endif