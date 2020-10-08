
NAME = 2_BPrim
LDFLAGS	= -O3 -Xn512
TADDR	= -Xo$80100000
GDLIB = ..\..\Library\Playstation_1\GD101_LIB.LIB

CPE =2_BPrim.cpe

OBJ0 = main.obj
all: 
	ccpsx -O3 -c main.cpp
	ccpsx $(LDFLAGS) $(TADDR) -o$(CPE) $(OBJ0) -l$(GDLIB)
	cpe2x $(CPE)

