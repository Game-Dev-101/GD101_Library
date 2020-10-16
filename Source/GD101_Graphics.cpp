

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

	int DrawLine(float x0, float y0, float x1, float y1 , COLOR4 color)
	{
		// Anchor pointnya ditengah

		// Algoritma Pertama
		float midX = (float)rc.right/2.0f;
		float midY = (float)rc.bottom/2.0f;

		float xx0 = x0 <= midX ? ( (float)x0/midX ) - 1.0f : (float)(x0-midX) / midX ;
		float yy0 = y0 <= midY ? ( ((float)y0/midY ) - 1.0f)*(-1) : ( (float)(y0-midY) / midY ) *(-1);

		float xx1 = x1 <= midX ? ( (float)x1/midX ) - 1.0f : (float)(x1-midX) / midX ;
		float yy1 = y1 <= midY ? ( ((float)y1/midY ) - 1.0f)*(-1) : ( (float)(y1-midY) / midY ) *(-1);

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

	int DrawBox(float x0, float y0, float width, float height, COLOR4 color)
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

    // sementara aku taruh height sama witdh disini ya
    int screenHeight    =  gdEngine.height;
    int screenWidth     =  gdEngine.width;
    extern GLuint vPosition;
    int DrawLine(float x0, float y0, float x1, float y1, COLOR4 pColor)
    { 
        float midX = gdEngine.width/2;
		float midY = gdEngine.height/2;

		float xx0 = ((x0 - midX)/midX) ;
		float yy0 = ((y0 - midY)/midY) * -1.0f;

		float xx1 = ((x1 - midX)/midX) ;
		float yy1 = ((y1 - midY)/midY) * -1.0f;
        
            float pos_and_color[] = {
          //     x,     y, r, g, b
             xx0, yy0, 1, 1, 1,
              xx1, yy1, 1, 1, 1,
          };

          glBufferData(GL_ARRAY_BUFFER, sizeof(pos_and_color), pos_and_color, GL_STATIC_DRAW);
             
          glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 20, 0);
          glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 20, (void*)8);

          glDrawArrays(GL_LINE_STRIP, 0, 2);
        return 0;
    }
    
  	int DrawBox(float x0, float y0, float width, float height, COLOR4 pColor)
    {         
        float tWidth = x0 + width ;
		float tHheight = y0 + height;

        float midX = gdEngine.width/2;
		float midY = gdEngine.height/2;
    
		float xx0 = ((x0 - midX)/midX);
		float yy0 = ((y0 - midY)/midY) * -1.0f;

		tWidth = ((tWidth - midX)/midX) ;
		tHheight = ((tHheight - midY)/midY) * -1.0f;
        
           float pos_and_color[] = {
          //     x,     y, r, g, b
             xx0, yy0, 1, 1, 1,
             tWidth, yy0, 1, 1, 1,
             tWidth, tHheight, 1, 1, 1,
             
             xx0, tHheight, 1, 1, 1,
             xx0, yy0, 1, 1, 1,
              
          };

          glBufferData(GL_ARRAY_BUFFER, sizeof(pos_and_color), pos_and_color, GL_STATIC_DRAW);
             
          glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 20, 0);
          glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 20, (void*)8);

          glDrawArrays(GL_LINE_STRIP, 0, 5);
        return 0;
    }
//-----------------------------------------------------------------------------------------------------------
//		FOR WEBGL PLATFORM
//-----------------------------------------------------------------------------------------------------------
#elif defined(WEBGL)
    #include "Platform\WebGl\Graphics.h"
    //#include <iostream>
    
    int DrawLine(float x0, float y0, float x1, float y1, COLOR4 pColor)
    {     
        float midX = GetCvsWidth()/2;
		float midY = GetCvsHeight()/2;

		float xx0 = ((x0 - midX)/midX) ;
		float yy0 = ((y0 - midY)/midY) * -1.0f;

		float xx1 = ((x1 - midX)/midX) ;
		float yy1 = ((y1 - midY)/midY) * -1.0f;
         
            float pos_and_color[] = {
          //     x,     y, r, g, b
             xx0, yy0, 1, 1, 1,
              xx1, yy1, 1, 1, 1,
          };

          // Ini kyknya 
          GLuint vbo;
          glGenBuffers(1, &vbo);
          glBindBuffer(GL_ARRAY_BUFFER, vbo);
          //
          glBufferData(GL_ARRAY_BUFFER, sizeof(pos_and_color), pos_and_color, GL_STATIC_DRAW);
             
          glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 20, 0);
          glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 20, (void*)8);

          glDrawArrays(GL_LINE_STRIP, 0, 2);
          
        return 0;
    }
    
   	int DrawBox(float x0, float y0, float width, float height, COLOR4 pColor)
    {
                
        float tWidth = x0 + width ;
		float tHheight = y0 + height;

        float midX = GetCvsWidth()/2;
		float midY = GetCvsHeight()/2;

         
		float xx0 = ((x0 - midX)/midX);
		float yy0 = ((y0 - midY)/midY) * -1.0f;

		tWidth = ((tWidth - midX)/midX) ;
		tHheight = ((tHheight - midY)/midY) * -1.0f;
        
            float pos_and_color[] = {
          //     x,     y, r, g, b
             xx0, yy0, 1, 1, 1,
             tWidth, yy0, 1, 1, 1,
             tWidth, tHheight, 1, 1, 1,
             
             xx0, tHheight, 1, 1, 1,
             xx0, yy0, 1, 1, 1,
              
          };
          
          // INi bahaya
          GLuint vbo;
          glGenBuffers(1, &vbo);
          glBindBuffer(GL_ARRAY_BUFFER, vbo);
          // wkwkw
          glBufferData(GL_ARRAY_BUFFER, sizeof(pos_and_color), pos_and_color, GL_STATIC_DRAW);
             
          glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 20, 0);
          glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 20, (void*)8);

          glDrawArrays(GL_LINE_STRIP, 0, 5);
        return 0;
    }

//-----------------------------------------------------------------------------------------------------------
//		FOR PLAYSTATION_1 PLATFORM
//-----------------------------------------------------------------------------------------------------------
#elif defined(PLAYSTATION_1)
    #include "Platform\PlayStation_1\Graphics.h"
#include <stdlib.h>
#include <libgte.h>
#include <libgpu.h>
#include <libgs.h>

LINE_F2 myLineF2;
LINE_F4 myLineF4;
    	int DrawLine(float x0, float y0, float x1, float y1, COLOR4 pColor)
        {
            myLineF2.r0 = 255;
            myLineF2.g0 = 255;
            myLineF2.b0 = 255;
            
            myLineF2.x0 = x0;
            myLineF2.y0 = y0;
            
            myLineF2.x1 = x1;
            myLineF2.y1 = y1;

            SetLineF2(&myLineF2);
            DrawPrim(&myLineF2);
            //AddPrim(ot+1,&myLineF2);

            return 0;
        }
        
        int DrawBox(float x0, float y0, float width, float height, COLOR4 color)
        {
            myLineF2.r0 = 255;
            myLineF2.g0 = 255;
            myLineF2.b0 = 255;
            
            myLineF4.r0 = 255;
            myLineF4.g0 = 255;
            myLineF4.b0 = 255;
            
            myLineF2.x0 = x0;
            myLineF2.y0 = y0;
            myLineF2.x1 = x0 + width;
            myLineF2.y1 = y0;
            
            myLineF4.x0 = x0 + width;
            myLineF4.y0 = y0;
            myLineF4.x1 = x0 + width;
            myLineF4.y1 = y0 + height;
            myLineF4.x2 = x0;
            myLineF4.y2 = y0 + height;
            myLineF4.x3 = x0;
            myLineF4.y3 = y0;
            
            SetLineF2(&myLineF2);
            DrawPrim(&myLineF2);
            
            SetLineF4(&myLineF4);
            DrawPrim(&myLineF4);
            return 0;
        }    

//-----------------------------------------------------------------------------------------------------------
//		FOR PLAYSTATION_2 PLATFORM
//-----------------------------------------------------------------------------------------------------------
#elif defined(PLAYSTATION_2)
    #include "Platform/PlayStation_2/Graphics.h"
    #include <iostream>
    
     int points_count = 5;
     int vertex_count = 5;
    // Allocate calculation space.
	VECTOR* temp_vertices = (VECTOR*)memalign(128, sizeof(VECTOR) * vertex_count);
	// Allocate register space.
	xyz_t* verts  = (xyz_t*)memalign(128, sizeof(vertex_t) * vertex_count);
	color_t * colors = (color_t *)memalign(128, sizeof(color_t)  * vertex_count);
    
     int points[5] = {
       0,  1,  2, 3, 4
     };

     VECTOR colours[5] = {
      { 1.00f, 1.00f, 1.00f, 1.00f },
      { 1.00f, 1.00f, 1.00f, 1.00f },
      { 1.00f, 1.00f, 1.00f, 1.00f },
      
      { 1.00f, 1.00f, 1.00f, 1.00f },
      { 1.00f, 1.00f, 1.00f, 1.00f }
      };
    
    int DrawLine(float x0, float y0, float x1, float y1, COLOR4 pColor)
    {
        printf("DRAWLINES\n");
        
        // Mid dari 640x512
        float midX = 320.0f;
		float midY = 256.0f;
        
        printf("midX = %f\n", midX);
        printf("midY = %f\n", midY);
        // masih belum tau gmn panjang lebarnya... sementara pake ini hardcoded
        // x = 45.00f
        // y = 33.50f
        
        // Algo ketiga
	/* 	float xx0 = x0 <= midX ? (( x0/midX )*(45.00f)) - 45.00f:  ((x0-midX) / midX) *45.00f ;
		float yy0 = y0 <= midY ? ( ( y0/midY ) - 33.50f)*(-1.0f) : (  (y0-midY) / midY ) *(-33.50f);

		float xx1 = x1 <= midX ? (( x1/midX )*(45.00f)) - 45.00f :  ((x1-midX) / midX) *45.00f ;
		float yy1 = y1 <= midY ? ( ( y1/midY ) - 33.50f)*(-1.0f) : (  (y1-midY) / midY ) *(-33.50f); */
        
		float xx0 = ((x0 - midX)/midX) * 45.00f;
		float yy0 = ((y0 - midY)/midY) * -33.50f;

		float xx1 = ((x1 - midX)/midX) * 45.00f;
		float yy1 = ((y1 - midY)/midY) * -33.50f;
        
/*         VECTOR vertices[3] = {
          {  0.00f,  33.50f,  10.00f, 1.00f },
          {  0.00f,  -33.50f, 10.00f, 1.00f },
          {  -45.00f, 0.00f,  10.00f, 1.00f }
         }; */
          VECTOR vertices[2] = {
          {  xx0,  yy0,  10.00f, 1.00f },
          {  xx1,  yy1, 10.00f, 1.00f }
         };
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

        
		// Draw the triangles using triangle primitive type.
		q = draw_prim_start(q,0,&prim, &color);

		for(i = 0; i < 2 /*points_count*/; i++)
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
	int DrawBox(float x0, float y0, float width, float height, COLOR4 pColor)
    {
        
        float midX = 320.0f;
		float midY = 256.0f;
        
        float tWidth = x0 + width ;
		float tHheight = y0 + height;

/* 		float xx0 = x0 <= midX ? (( x0/midX )*(45.00f)) - 45.00f:  ((x0-midX) / midX) *45.00f ;
		float yy0 = y0 <= midY ? ( ( y0/midY ) - 33.50f)*(-1.0f) : (  (y0-midY) / midY ) *(-33.50f);

		tWidth = tWidth <= midX ? (( tWidth/midX )*(45.00f)) - 45.00f:  ((tWidth-midX) / midX) *45.00f ;
		tHheight = tHheight <= midY ? ( ( tHheight/midY ) - 33.50f)*(-1.0f) : (  (tHheight-midY) / midY ) *(-33.50f);
 */
         
		float xx0 = ((x0 - midX)/midX) * 45.00f;
		float yy0 = ((y0 - midY)/midY) * -33.50f;

		tWidth = ((tWidth - midX)/midX) * 45.00f;
		tHheight = ((tHheight - midY)/midY) * -33.50f;
        
         VECTOR vertices[5] = {
          {  xx0,  yy0,  10.00f, 1.00f },
          {  tWidth,  yy0, 10.00f, 1.00f },
          { tWidth, tHheight,  10.00f, 1.00f },
          
           {  xx0,  tHheight, 10.00f, 1.00f },
           {  xx0,  yy0,  10.00f, 1.00f }
         };

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

		// Draw the triangles using triangle primitive type.
		q = draw_prim_start(q,0,&prim, &color);

		for(i = 0; i < 5 /*points_count*/; i++)
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

#endif


