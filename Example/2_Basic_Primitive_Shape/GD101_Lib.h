/**********************************************************************************************
*   LICENSE: MIT
*
*
*   Copyright (c) 2020-2020 Imandana Rahimaswara - Imandana
*
*   This software is provided "as-is", without any express or implied warranty. In no event
*   will the authors be held liable for any damages arising from the use of this software.
*
*   Permission is granted to anyone to use this software for any purpose, including commercial
*   applications, and to alter it and redistribute it freely, subject to the following restrictions:
*
*     1. The origin of this software must not be misrepresented; you must not claim that you
*     wrote the original software. If you use this software in a product, an acknowledgment
*     in the product documentation would be appreciated but is not required.
*
*     2. Altered source versions must be plainly marked as such, and must not be misrepresented
*     as being the original software.
*
*     3. This notice may not be removed or altered from any source distribution.
*
**********************************************************************************************/



#ifndef __GD_101_LIB__
#define __GD_101_LIB__


#include "GD101_DEF.h"
//--------- Core ---------------//////////////////////////////////////
extern bool GD101_InitWindow(const char* windowName, int height, int width);
extern int ScreenFlip();
extern int ClearScreen();
extern bool EndLoop();

//---------- Graphics ----------/////////////////////////////////////
extern int LoadShaderFile(const char * pFileName);
extern void ExecuteShader();
//extern int DrawLine(int x0, int y0, int x1, int y1);
extern int DrawLine(float x0, float y0, float x1, float y1, COLOR4 color);
extern int DrawBox(float x0, float y0, float width, float height, COLOR4 color);

// Ini sementara tersedia untuk android saja, kalai ada waktu di rapikan lagi
extern int screenHeight;
extern int screenWidth;
/////////////////////////////////////////
//------------- Inputs ----------/////////////////////////////////////

#endif //__GD_101_LIB__
