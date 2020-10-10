#ifndef __GRAPHICS__
#define __GRAPHICS__

#include <emscripten/emscripten.h>
#include <emscripten/html5.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <GLES2/gl2.h>

#include "../../GD101_DEF.h"
#include "Shared_Data.h"

	void ColorFilter(COLOR4 data);

	int DrawLine(float x0, float y0, float x1, float y1, COLOR4 pColor);
	int DrawBox(float x0, float y0, float width, float height, COLOR4 color);
    
#endif // __GRAPHICS__

