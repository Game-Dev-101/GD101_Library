#ifndef __PLATFORM_ENTRY__
#define __PLATFORM_ENTRY__

#include <sys/types.h>
#include <stdlib.h>
#include <libgte.h>
#include <libgpu.h>
#include <libgs.h>

#define OT_LENGTH 1002 // the ordertable length
#define PACKETMAX 18 // the maximum number of objects on the screen
//SCREEN_WIDTH  320  screen width
//SCREEN_HEIGHT 240  screen height (240 NTSC, 256 PAL)

GsOT myOT[2]; // ordering table header
GsOT_TAG myOT_TAG[2][1<<1]; // ordering table unit
PACKET GPUPacketArea[2][PACKETMAX]; // GPU packet data

/* u_long _ramsize   = 0x00200000; // force 2 megabytes of RAM
u_long _stacksize = 0x00004000; // force 16 kilobytes of stack */

// INTEGERS
// --------
short CurrentBuffer = 0; // holds the current buffer number

u_long ot[1002];

// Method Umum Untuk Semua
bool EndLoop();

int ScreenFlip();
int ClearScreen();

bool GD101_InitWindow(const char * windowName, int height, int width);
extern int Main();


#endif //__PLATFORM_ENTRY__

