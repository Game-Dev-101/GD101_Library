#ifndef __GRAPHICS__
#define __GRAPHICS__

#include <string>
#include "GD101_DEF.h"

#ifndef OPENGL
#define DIRECTX
    #if defined(DIRECTX)
		
	void ColorFilter(COLOR4 data);
	void GraphicsInit();

	int DrawLine(int x0, int y0, int x1, int y1, COLOR4 color);
	
	int DrawBox(int x0, int y0, int width, int height, COLOR4 color);

	#endif // DIRECTX

#else // Ini Untuk OPENGL Sementara pake OGL 1.1 dulu ya
	int DrawLine(int x0, int y0, int x1, int y1);
#endif // OPENGL

#endif // __GRAPHICS__