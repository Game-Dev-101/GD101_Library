#include <iostream>
#include "GD101_Lib.h"

int main()
{
	if(!GD101_InitWindow("Apa Kabar",500,500))
		return 0;

	LoadShaderFile(L"Tutorial02.glsl");

	// Main message loop
	while(!EndLoop())
	{
		ClearScreen();

		ExecuteShader();

		ScreenFlip();
	}

    return 0;
}

