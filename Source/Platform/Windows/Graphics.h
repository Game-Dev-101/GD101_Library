#ifndef __GRAPHICS__
#define __GRAPHICS__

#ifndef OPENGL
#define DIRECTX
    #if defined(DIRECTX)
	
	

	int DrawLine(int x0, int y0, int x1, int y1);

	#endif // DIRECTX

#else // Ini Untuk OPENGL Sementara pake OGL 1.1 dulu ya
	int DrawLine(int x0, int y0, int x1, int y1);
#endif // OPENGL

#endif // __GRAPHICS__