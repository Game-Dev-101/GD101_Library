#include "GD101_Lib.h"

struct Rect
{
	float x;
	float y;
	float width;
	float height;

	Rect(float _x, float _y, float _width, float _height)
		: x(_x), y(_y), width(_width), height(_height) {}
};

int Main()
{
    // Untuk Playstation 1 dan 2, size windownya fixed size 640x512
	if(!GD101_InitWindow("Apa Kabar GD101",500,800))
		return 0;

	float x =0;
	float y =0;
	bool isRight = false;

	Rect boxRect(20.0f, 20.0f, 50.0f, 50.0f);
	float xVelo = 4.3f;
	float yVelo = 4.6f;

	// Main message loop
	while(!EndLoop())
	{
		ClearScreen();

		// Untuk Garis
		if(x <= 0  ) isRight =true;
		else if( x >= 640) isRight = false;

		if(isRight) x += 4.5f;
		else x -= 4.5f;

		boxRect.x += xVelo;
		boxRect.y += yVelo;
		// Untuk Box
		if(boxRect.x + boxRect.width >= 640  || boxRect.x <= 0)
			xVelo *= -1;
		if(boxRect.y + boxRect.height >= 512 || boxRect.y <= 0)
			yVelo *= -1;

        DrawLine(x, 0, 20, 500, COLOR4(0.0,0.0,0.0,1.0));
		DrawLine(x, 0, 600, 500, COLOR4(0.0,0.0,0.0,1.0));
		DrawBox(boxRect.x, boxRect.y, boxRect.width, boxRect.height,  COLOR4(0.0,0.0,0.0,1.0));

		ScreenFlip();
	}

    return 0;
}

