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
	if(!GD101_InitWindow("Apa Kabar GD101",500,800))
		return 0;

	float x =0;
	float y =0;
	bool isRight = false;

	Rect boxRect(20, 20, 50, 50);
	float xVelo = 0.3f;
	float yVelo = 0.6f;

	// Main message loop
	while(!EndLoop())
	{
		ClearScreen();

		// Untuk Garis
		if(x <= 0  ) isRight =true;
		else if( x >= 800) isRight = false;

		if(isRight) x += 0.5f;
		else x -= 0.5f;

		boxRect.x += xVelo;
		boxRect.y += yVelo;
		// Untuk Box
		if(boxRect.x + boxRect.width >= 800  || boxRect.x <= 0)
			xVelo *= -1;
		if(boxRect.y + boxRect.height >= 500 || boxRect.y <= 0)
			yVelo *= -1;

		DrawLine(x, 0, 600, 500, COLOR4(0.0,0.0,0.0,1.0));
		DrawBox(boxRect.x, boxRect.y, boxRect.width, boxRect.height,  COLOR4(0.0,0.0,0.0,1.0));

		ScreenFlip();
	}

    return 0;
}

