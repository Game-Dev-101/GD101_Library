SRCS = ..\..\GD101_core.cpp ..\..\GD101_Graphics.cpp
OBJS = ..\..\* 
DEFINE =-DPLAYSTATION_1


all:
	ccpsx -O3 -Xo$80010000 -c $(SRCS) $(DEFINE)
	del GD101LIB.lib
	psylib /u GD101LIB.lib $(OBJS)
	
    
clean:
	del *.lib
	del *.obj
    
