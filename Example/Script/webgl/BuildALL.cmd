
set NAME=2_Basic_Primitive_Shape
set SRC_FILES=../../2_Basic_Primitive_Shape/main.cpp
set OBJ_FILES=main.o
set LIB_FILE=GD101_LIB

set DEFINE= -DWEBGL

call Compile.cmd
call Linking.cmd
call Copy.cmd
call Copy2.cmd

