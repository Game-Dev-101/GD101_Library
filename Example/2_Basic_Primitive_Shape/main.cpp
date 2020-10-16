#include "GD101_Lib.h"

#if defined(WEBGL)
    #include <emscripten/emscripten.h>
    #include <emscripten/html5.h>
#endif

struct Rect
{
	float x;
	float y;
	float width;
	float height;

	Rect(float _x, float _y, float _width, float _height)
		: x(_x), y(_y), width(_width), height(_height) {}
};

#if defined(WEBGL)
	float x =0;
	float y =0;
	bool isRight = false;

	Rect boxRect(20, 20, 50, 50);
	float xVelo = 5.0f;
	float yVelo = 5.0f;
    void While()
    {
            ClearScreen();

            // Untuk Garis
            if(x <= 0  ) isRight =true;
            else if( x >= 800) isRight = false;

            if(isRight) x += 5.0f;
            else x -= 5.0f;
            
                    boxRect.x += xVelo;
            boxRect.y += yVelo;
            // Untuk Box
            if(boxRect.x + boxRect.width >= 800  || boxRect.x <= 0)
                xVelo *= -1;
            if(boxRect.y + boxRect.height >= 500 || boxRect.y <= 0)
                yVelo *= -1;

            DrawLine(x, 0, 780, 500, COLOR4(0.0,0.0,0.0,1.0));
            DrawBox(boxRect.x, boxRect.y, boxRect.width, boxRect.height,  COLOR4(0.0,0.0,0.0,1.0));

            //emscripten_webgl_commit_frame();
            ScreenFlip();
    }
#endif  // WEBGL

int Main()
{
	if(!GD101_InitWindow("Apa Kabar GD101",500,800))
		return 0;

    #if defined(WEBGL)
        emscripten_set_main_loop(While, 30, 1);
    #endif
    
	float x =0;
	float y =0;
	bool isRight = false;

	Rect boxRect(20, 20, 80, 80);
	float xVelo = 6.3f;
	float yVelo = 6.6f;

	// Main message loop
	while(!EndLoop())
	{
		ClearScreen();

		// Untuk Garis
		if(x <= 0  ) isRight =true;
		else if( x >= 1200) isRight = false;

		if(isRight) x += 6.5f;
		else x -= 6.5f;

		boxRect.x += xVelo;
		boxRect.y += yVelo;
		// Untuk Box
		if(boxRect.x + boxRect.width >= 1250  || boxRect.x <= 0)
			xVelo *= -1;
		if(boxRect.y + boxRect.height >= 700 || boxRect.y <= 0)
			yVelo *= -1;

		DrawLine(x, 0, 1200, 700, COLOR4(0.0,0.0,0.0,1.0));
		DrawBox(boxRect.x, boxRect.y, boxRect.width, boxRect.height,  COLOR4(0.0,0.0,0.0,1.0));

		ScreenFlip();
	}

    return 0;
}

