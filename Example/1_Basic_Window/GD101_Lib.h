#ifndef __GD_101_LIB__
#define __GD_101_LIB__

//--------- Core ---------------//////////////////////////////////////
extern bool GD101_InitWindow(const char* windowName, int height, int width);
extern int ScreenFlip();
extern int ClearScreen();
extern bool EndLoop();

//---------- Graphics ----------/////////////////////////////////////
//extern int LoadShaderFile(wchar_t * pFileName);
//extern void ExecuteShader();
extern int DrawLine(int x0, int y0, int x1, int y1);


//------------- Inputs ----------/////////////////////////////////////

#endif //__GD_101_LIB__
