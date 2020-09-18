#ifndef __GD_101_LIB__
#define __GD_101_LIB__

extern bool GD101_InitWindow(const char* windowName, int height, int width);

extern int ScreenFlip();
extern void ExecuteShader();
extern int ClearScreen();

extern int LoadShaderFile(wchar_t * pFileName);


extern bool EndLoop();

#endif //__GD_101_LIB__
