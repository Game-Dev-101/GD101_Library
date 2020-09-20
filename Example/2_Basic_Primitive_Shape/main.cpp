#include <iostream>

#include "GD101_Lib.h"

int Main()
{
	if(!GD101_InitWindow("Apa Kabar",500,800))
		return 0;

	LoadShaderFile("SHAPE.fx");

	// Main message loop
	while(!EndLoop())
	{
		ClearScreen();

		DrawLine(20,100,0,0);
		//ExecuteShader();

		ScreenFlip();
	}

    return 0;
}

