/*
# _____     ___ ____     ___ ____
#  ____|   |    ____|   |        | |____|
# |     ___|   |____ ___|    ____| |    \    PS2DEV Open Source Project.
#-----------------------------------------------------------------------
# (c) 2005 Naomi Peori <naomi@peori.ca>
# Licenced under Academic Free License version 2.0
# Review ps2sdk README & LICENSE files for further details.
#
*/
#ifndef __MESH_DATA__
#define __MESH_DATA__

 int points_count = 3;

 int points[3] = {
   0,  1,  2
 };

 int vertex_count = 3;

 VECTOR vertices[3] = {
  {  0.00f,  30.00f,  10.00f, 1.00f },
  {  0.00f,  -30.00f, -10.00f, 1.00f },
  {  -10.00f, 0.00f,  10.00f, 1.00f }
 };

 VECTOR colours[3] = {
  { 1.00f, 1.00f, 1.00f, 1.00f },
  { 1.00f, 1.00f, 1.00f, 1.00f },
  { 1.00f, 1.00f, 1.00f, 1.00f },

 };

 #endif // __MESH_DATA__
 
 