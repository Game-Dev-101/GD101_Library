

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

		// Algoritma Pertama
		float midX = (float)rc.right/2.0f;
		float midY = (float)rc.bottom/2.0f;

		float xx0 = x0 <= (rc.right/2) ? ( (float)x0/midX ) - 1.0f : (float)(x0-midX) / midX ;
		float yy0 = y0 <= (rc.bottom/2) ? ( ((float)y0/midY ) - 1.0f)*(-1) : ( (float)(y0-midY) / midY ) *(-1);

		float xx1 = x1 <= (rc.right/2) ? ( (float)x1/midX ) - 1.0f : (float)(x1-midX) / midX ;
		float yy1 = y1 <= (rc.bottom/2) ? ( ((float)y1/midY ) - 1.0f)*(-1) : ( (float)(y1-midY) / midY ) *(-1);

		// Algoritma Kedua
		//float xx0 = ((x0*2.0f)/rc.right) - 1.0f;
		//float yy0 = ((y0*2.0f)/rc.bottom) - 1.0f;

		//float xx1 = ((x1*2.0f)/rc.right) - 1.0f;
		//float yy1 = ((y1*2.0f)/rc.bottom) - 1.0f;

		FLOAT3 pos0( xx0,  yy0, 0.0f);
		FLOAT3 pos1( xx1, yy1, 0.0f);

		vertices[0].pos = pos0;
		vertices[1].pos = pos1;
		vertices[2].pos = pos1;


		ZeroMemory( &bd, sizeof(bd) );
		bd.Usage = D3D11_USAGE_DEFAULT;
		bd.ByteWidth = sizeof( DrawVertex ) * 3;
		bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
		bd.CPUAccessFlags = 0;

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
		// Algortima Pertama
		float midX = (float)rc.right/2.0f;
		float midY = (float)rc.bottom/2.0f;

		float tWidth = x0 + width ;
		float tHheight = y0 + height;

		float xx0 = x0 <= midX ? ( (float)x0/midX ) - 1.0f : (float)(x0-midX) / midX ;
		float yy0 = y0 <= midY ? ( ((float)y0/midY ) - 1.0f)*(-1) : ( (float)(y0-midY) / midY ) *(-1);

		tWidth = tWidth <= midX ? ( (float)tWidth/midX ) - 1.0f : (float)(tWidth-midX) / midX ;
		tHheight = tHheight <= midY ? ( ((float)tHheight/midY ) - 1.0f)*(-1) : ( (float)(tHheight-midY) / midY ) *(-1);

		// Algoritma Kedua
		//float xx0 = ((x0*2.0f)/rc.right) - 1.0f;
		//float yy0 = ((y0*2.0f)/rc.bottom) - 1.0f;

		//tWidth = ((tWidth*2.0f)/rc.right) - 1.0f;
		//tHheight = ((tHheight*2.0f)/rc.bottom) - 1.0f;

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

		ZeroMemory( &bd, sizeof(bd) );
		bd.Usage = D3D11_USAGE_DEFAULT;
		bd.ByteWidth = sizeof( DrawVertex ) * 5;
		bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
		bd.CPUAccessFlags = 0;

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
    #include "Platform/PlayStation_2/Graphics.h"
    
     int points_count = 3;
     int vertex_count = 3;
    // Allocate calculation space.
	VECTOR* temp_vertices = (VECTOR*)memalign(128, sizeof(VECTOR) * vertex_count);
	// Allocate register space.
	xyz_t* verts  = (xyz_t*)memalign(128, sizeof(vertex_t) * vertex_count);
	color_t * colors = (color_t *)memalign(128, sizeof(color_t)  * vertex_count);
    
    int DrawLine(int x0, int y0, int x1, int y1, COLOR4 pColor)
    {
        float midX = (float)frame.width/2.0f;
		float midY = (float)frame.height/2.0f;

		float xx0 = x0 <= (midX/2) ? ( (float)x0/midX ) - 1.0f : (float)(x0-midX) / midX ;
		float yy0 = y0 <= (midY/2) ? ( ((float)y0/midY ) - 1.0f)*(-1) : ( (float)(y0-midY) / midY ) *(-1);

		float xx1 = x1 <= (midX/2) ? ( (float)x1/midX ) - 1.0f : (float)(x1-midX) / midX ;
		float yy1 = y1 <= (midY/2) ? ( ((float)y1/midY ) - 1.0f)*(-1) : ( (float)(y1-midY) / midY ) *(-1);

        	// Define the triangle primitive we want to use.
        prim.type = PRIM_LINE_STRIP;
        prim.shading = PRIM_SHADE_GOURAUD;
        prim.mapping = DRAW_DISABLE;
        prim.fogging = DRAW_DISABLE;
        prim.blending = DRAW_DISABLE;
        prim.antialiasing = DRAW_ENABLE;
        prim.mapping_type = PRIM_MAP_ST;
        prim.colorfix = PRIM_UNFIXED;
        
        color.r = 0x80;
        color.g = 0x80;
        color.b = 0x80;
        color.a = 0x80;
        color.q = 1.0f;
        
         int points[3] = {
           0,  1,  2
         };

		 VECTOR vertices[3] = {
          {  0.00f,  30.00f,  10.00f, 1.00f },
          {  0.00f,  -30.00f, -10.00f, 1.00f },
          {  -10.00f, 0.00f,  10.00f, 1.00f }
         };

         VECTOR colours[3] = {
          { 1.00f, 1.00f, 1.00f, 1.00f },
          { 1.00f, 1.00f, 1.00f, 1.00f },
          { 1.00f, 1.00f, 1.00f, 1.00f },

         };
        
        
        // Create the local_world matrix.
		create_local_world(local_world, object_position, object_rotation);

		// Create the world_view matrix.
		create_world_view(world_view, camera_position, camera_rotation);

		// Create the local_screen matrix.
		create_local_screen(local_screen, local_world, world_view, view_screen);

		// Calculate the vertex values.
		calculate_vertices(temp_vertices, vertex_count, vertices, local_screen);

		// Convert floating point vertices to fixed point and translate to center of screen.
		draw_convert_xyz(verts, 2048, 2048, 32, vertex_count, (vertex_f_t*)temp_vertices);

		// Convert floating point colours to fixed point.
		draw_convert_rgbq(colors, vertex_count, (vertex_f_t*)temp_vertices, (color_f_t*)colours, 0x80);

		// Grab our dmatag pointer for the dma chain.
		dmatag = current->data;


		// Draw the triangles using triangle primitive type.
		q = draw_prim_start(q,0,&prim, &color);

		for(i = 0; i < points_count; i++)
		{
			q->dw[0] = colors[points[i]].rgbaq;
			q->dw[1] = verts[points[i]].xyz;
			q++;
		}

		q = draw_prim_end(q,2,DRAW_RGBAQ_REGLIST);

		// Setup a finish event.
		q = draw_finish(q);

        
        return 0;
    }
	int DrawBox(int x0, int y0, int width, int height, COLOR4 color)
    {
        
        return 0;
    }

#endif