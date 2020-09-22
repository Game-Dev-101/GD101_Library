

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
	struct DrawVertex
	{
		FLOAT3 pos;
	};
	DrawVertex vertices[5] ;

	void GraphicsInit()
	{

	}

	int DrawLine(int x0, int y0, int x1, int y1 , COLOR4 color)
	{
		// Anchor pointnya ditengah
		float midX = (float)rc.right/2.0f;
		float midY = (float)rc.bottom/2.0f;

		float xx0 = x0 <= (rc.right/2) ? ( (float)x0/midX ) - 1.0f : (float)(x0-midX) / midX ;
		float yy0 = y0 <= (rc.bottom/2) ? ( ((float)y0/midY ) - 1.0f)*(-1) : ( (float)(y0-midY) / midY ) *(-1);

		float xx1 = x1 <= (rc.right/2) ? ( (float)x1/midX ) - 1.0f : (float)(x1-midX) / midX ;
		float yy1 = y1 <= (rc.bottom/2) ? ( ((float)y1/midY ) - 1.0f)*(-1) : ( (float)(y1-midY) / midY ) *(-1);

		FLOAT3 pos0( xx0,  yy0, 0.0f);
		FLOAT3 pos1( xx1, yy1, 0.0f);

		vertices[0].pos = pos0;
		vertices[1].pos = pos1;
		vertices[2].pos = pos1;


		D3D11_BUFFER_DESC bd;
		ZeroMemory( &bd, sizeof(bd) );
		bd.Usage = D3D11_USAGE_DEFAULT;
		bd.ByteWidth = sizeof( DrawVertex ) * 3;
		bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
		bd.CPUAccessFlags = 0;
		D3D11_SUBRESOURCE_DATA InitData;
		ZeroMemory( &InitData, sizeof(InitData) );
		InitData.pSysMem = vertices;
	
		if(g_pVertexBuffer) g_pVertexBuffer->Release();
		if( g_pImmediateContext ) g_pImmediateContext->Release();

		g_pd3dDevice->CreateBuffer( &bd, &InitData, &g_pVertexBuffer );

		// Set vertex buffer
		UINT stride = sizeof( DrawVertex );
		UINT offset = 0;
		g_pImmediateContext->IASetVertexBuffers( 0, 1, &g_pVertexBuffer, &stride, &offset );

		// Set primitive topology
		g_pImmediateContext->IASetPrimitiveTopology( D3D11_PRIMITIVE_TOPOLOGY_LINELIST );

		g_pImmediateContext->VSSetShader( g_pVertexShader, NULL, 0 );
		g_pImmediateContext->PSSetShader( g_pPixelShader, NULL, 0 );
		g_pImmediateContext->Draw( 2, 0 );

		return 0;
	}

	int DrawBox(int x0, int y0, int width, int height, COLOR4 color)
	{
		float midX = (float)rc.right/2.0f;
		float midY = (float)rc.bottom/2.0f;

		float tWidth = x0 + width ;
		float tHheight = y0 + height;

		float xx0 = x0 <= midX ? ( (float)x0/midX ) - 1.0f : (float)(x0-midX) / midX ;
		float yy0 = y0 <= midY ? ( ((float)y0/midY ) - 1.0f)*(-1) : ( (float)(y0-midY) / midY ) *(-1);

		tWidth = tWidth <= midX ? ( (float)tWidth/midX ) - 1.0f : (float)(tWidth-midX) / midX ;
		tHheight = tHheight <= midY ? ( ((float)tHheight/midY ) - 1.0f)*(-1) : ( (float)(tHheight-midY) / midY ) *(-1);


		FLOAT3 pos0(  xx0, yy0, 0.0f);
		FLOAT3 pos1(  tWidth, yy0, 0.0f);
		FLOAT3 pos2( tWidth, tHheight, 0.0f);

		FLOAT3 pos3(  xx0, tHheight, 0.0f);
		FLOAT3 pos4(  xx0, yy0, 0.0f);

		vertices[0].pos = pos0;
		vertices[1].pos = pos1;
		vertices[2].pos = pos2;

		vertices[3].pos = pos3;
		vertices[4].pos = pos4;

		D3D11_BUFFER_DESC bd;
		ZeroMemory( &bd, sizeof(bd) );
		bd.Usage = D3D11_USAGE_DEFAULT;
		bd.ByteWidth = sizeof( DrawVertex ) * 5;
		bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
		bd.CPUAccessFlags = 0;
		D3D11_SUBRESOURCE_DATA InitData;
		ZeroMemory( &InitData, sizeof(InitData) );
		InitData.pSysMem = vertices;

		if(g_pVertexBuffer) g_pVertexBuffer->Release();
		if( g_pImmediateContext ) g_pImmediateContext->Release();

		g_pd3dDevice->CreateBuffer( &bd, &InitData, &g_pVertexBuffer );

		// Set vertex buffer
		UINT stride = sizeof( DrawVertex );
		UINT offset = 0;
		g_pImmediateContext->IASetVertexBuffers( 0, 1, &g_pVertexBuffer, &stride, &offset );

		// Set primitive topology
		g_pImmediateContext->IASetPrimitiveTopology( D3D11_PRIMITIVE_TOPOLOGY_LINESTRIP );

		g_pImmediateContext->VSSetShader( g_pVertexShader, NULL, 0 );
		g_pImmediateContext->PSSetShader( g_pPixelShader, NULL, 0 );
		g_pImmediateContext->Draw( 5, 0 );

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