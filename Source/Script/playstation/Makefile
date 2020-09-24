# _____     ___ ____     ___ ____
#  ____|   |    ____|   |        | |____|
# |     ___|   |____ ___|    ____| |    \    PS2DEV Open Source Project.
#-----------------------------------------------------------------------
# Copyright 2001-2004, ps2dev - http://www.ps2dev.org
# Licenced under Academic Free License version 2.0
# Review ps2sdk README & LICENSE files for further details.

### Definisi Object Kita
LOCAL_PATH := ./

PS2_INCLUDE_DIR = ../../Platform/Playstation_2/
SOURCE_DIR = ../../
BUILD_DIR = ../../BuildLib/Playstation_2/

PS2_DEFINE = -DPLAYSTATION_2

### Nama file dan library dependencys
EE_LIB = GD101_LIB.a
EE_OBJS += $(BUILD_DIR)GD101_Core.o $(BUILD_DIR)GD101_Graphics.o
EE_LIBS = -ldraw -lgraph -lmath3d -lmf -lpacket -ldma

### Rule Compile all
all: $(EE_LIB)
	$(EE_STRIP) --strip-all $(EE_LIB)
    
### Clean all compiled data
clean:
	rm -f $(BUILD_DIR)$(EE_LIB) $(BUILD_DIR)$(EE_OBJS)

## Tambahkan file extra untuk definisi dan command compile yand ada dalam direktori yang sama
include Makefile.pref
include Makefile.ee
