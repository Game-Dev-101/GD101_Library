
set NAME=libGD101_LIB.a
set SRC_FILES=../../GD101_core.cpp ../../GD101_Graphics.cpp
set OBJ_FILES= GD101_Graphics.o GD101_core.o

set INTERMEDIATE_FILES../../BuildLib/WebGl/Intermediate/
set BUILD_DIR=../../BuildLib/WebGl/
set INCLUDE_DIR= ../../Platform/WebGl/
set DEFINE= -DWEBGL

call Compile.cmd
call Archieving.cmd
