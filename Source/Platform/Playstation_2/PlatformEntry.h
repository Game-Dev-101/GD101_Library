#ifndef __PLATFORM_ENTRY__
#define __PLATFORM_ENTRY__

#include <kernel.h>
#include <stdlib.h>
#include <tamtypes.h>
#include <math3d.h>

#include <packet.h>

#include <dma_tags.h>
#include <gif_tags.h>
#include <gs_psm.h>

#include <dma.h>

#include <graph.h>

#include <draw.h>
#include <draw3d.h>

framebuffer_t frame;
zbuffer_t z;

void InitGS();
void InitDrawingEnvironment();


VECTOR object_position = { 0.00f, 0.00f, 0.00f, 1.00f };
VECTOR object_rotation = { 0.00f, 0.00f, 0.00f, 1.00f };

VECTOR camera_position = { 0.00f, 0.00f, 100.00f, 1.00f };
VECTOR camera_rotation = { 0.00f, 0.00f,   0.00f, 1.00f };

int i;
int context = 0;

// Matrices to setup the 3D environment and camera
MATRIX local_world;
MATRIX world_view;
MATRIX view_screen;
MATRIX local_screen;

//VECTOR *temp_vertices;

prim_t prim;
color_t color;

/* xyz_t   *verts;
color_t *colors; */

// The data packets for double buffering dma sends.
packet_t *packets[2];
packet_t *current;
qword_t *q;
qword_t *dmatag;

// Method Umum Untuk Semua
bool EndLoop();

int ScreenFlip();
int ClearScreen();

bool GD101_InitWindow(const char * windowName, int height, int width);
extern int Main();


#endif //__PLATFORM_ENTRY__

