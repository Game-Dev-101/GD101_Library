#include <iostream>

#include "GD101_Lib.h"

int Main()
{
	if(!GD101_InitWindow("Apa Kabar",500,800))
		return 0;

	LoadShaderFile("SHAPE.fx");

	float x =0;
	float y =0;
	bool isRight = false;
	// Main message loop
	while(!EndLoop())
	{
		ClearScreen();

		if(x <= 0  ) isRight =true;
		else if( x >= 800) isRight = false;

		if(isRight) x += 0.5f;
		else x -= 0.5f;

		//y+= 0.2f;
		DrawLine(x, 0, 600, 500, COLOR4(12,12,12,1));

		DrawBox(100, 50, 200, 50,  COLOR4(12,12,12,1));
		//ExecuteShader();

		ScreenFlip();
	}

    return 0;
}

