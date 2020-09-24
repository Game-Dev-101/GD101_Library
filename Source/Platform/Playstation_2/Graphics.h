#ifndef __GRAPHICS__
#define __GRAPHICS__

#include "../../GD101_DEF.h"
#include "Shared_Data.h"

	void ColorFilter(COLOR4 data);

	int DrawLine(int x0, int y0, int x1, int y1, COLOR4 color);
	int DrawBox(int x0, int y0, int width, int height, COLOR4 color);



#endif // __GRAPHICS__

