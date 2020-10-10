#ifndef __PLATFORM_ENTRY__
#define __PLATFORM_ENTRY__

#include <stdio.h>
#include <stdlib.h>
#include <emscripten/emscripten.h>
#include <emscripten/html5.h>
#include <GLES2/gl2.h>


// Method Umum Untuk Semua
bool EndLoop();


int ScreenFlip();
int ClearScreen();

bool GD101_InitWindow(const char * windowName, int height, int width);

// Khusus WEBGL pake void
extern int Main();


#endif //__PLATFORM_ENTRY__

