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
	if(!GD101_InitWindow("Apa Kabar GD101",240,320))
		return 0;

	float x =0;
	float y =0;
	bool isRight = false;

	Rect boxRect(20, 20, 50, 50);
	float xVelo = 2;
	float yVelo = 2;

	// Main message loop
	while(!EndLoop())
	{
		ClearScreen();

		// Untuk Garis
		if(x <= 0  ) isRight =true;
		else if( x >= 320) isRight = false;

		if(isRight) x += 2;
		else x -= 2;

		boxRect.x += xVelo;
		boxRect.y += yVelo;
		// Untuk Box
		if(boxRect.x + boxRect.width >= 320  || boxRect.x <= 0)
			xVelo *= -1;
		if(boxRect.y + boxRect.height >= 240 || boxRect.y <= 0)
			yVelo *= -1;

		DrawLine(x, 0, 300, 240, COLOR4(0.0,0.0,0.0,1.0));
		DrawBox(boxRect.x, boxRect.y, boxRect.width, boxRect.height,  COLOR4(0.0,0.0,0.0,1.0));

		ScreenFlip();
	}

    return 0;
}

