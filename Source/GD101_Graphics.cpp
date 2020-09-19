#include "GD101_DEF.h"

struct DrawVertex
{
	FLOAT2 pos;
};


#if defined(_WINDOWS) || defined(WIN32) || defined(_WIN32)
    #include "Platform\Windows\Graphics.h"
	#include "Settings.h"

	DrawVertex vertices[2] ;

	int DrawLine(int x0, int y0, int x1, int y1)
	{
		//DrawVertex lineVertices[] = {
		//FLOAT2( 0.0f, 0.5f),
		//FLOAT2( 0.5f, -0.5f)	}; 

		// Error disini, mau keluar dulu jalan2
		FLOAT2 pos0;
		pos0.x = x0/rc.
		vertices[0] = ( 0.0f, 0.5f);
		vertices[1] = FLOAT2( 0.0f, 0.5f);
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