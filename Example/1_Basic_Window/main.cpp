#include <iostream>
#include "GD101_Lib.h"

int Main()
{
	if(!GD101_InitWindow("Apa Kabar GD101",500,800))
		return 0;

	// Main message loop
	while(!EndLoop())
	{
		ClearScreen();

		ScreenFlip();
	}

    return 0;
}

