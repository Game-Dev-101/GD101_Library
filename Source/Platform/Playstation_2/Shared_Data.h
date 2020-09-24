#ifndef __SHARED_DATA__
#define __SHARED_DATA__

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


extern framebuffer_t frame;
extern zbuffer_t z;

extern VECTOR object_position ;
extern VECTOR object_rotation ;

extern VECTOR camera_position ;
extern VECTOR camera_rotation ;

extern int i;
extern int context;

extern MATRIX local_world;
extern MATRIX world_view;
extern MATRIX view_screen;
extern MATRIX local_screen;

//extern VECTOR *temp_vertices;

extern prim_t prim;
extern color_t color;

extern xyz_t   *verts;
extern color_t *colors;

// The data packets for double buffering dma sends.
extern packet_t *packets[2];
extern packet_t *current;
extern qword_t *q;
extern qword_t *dmatag;


#endif // __SHARED_DATA__

