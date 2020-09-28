# _____     ___ ____     ___ ____
#  ____|   |    ____|   |        | |____|
# |     ___|   |____ ___|    ____| |    \    PS2DEV Open Source Project.
#-----------------------------------------------------------------------
# Copyright 2001-2004, ps2dev - http://www.ps2dev.org
# Licenced under Academic Free License version 2.0
# Review ps2sdk README & LICENSE files for further details.

### Definisi Object Kita
LOCAL_PATH := ./

PROJECT_NAME = 2_Basic_Primitive_Shape

LIB_INCLUDE_DIR = ../../Library/Playstation_2/
SOURCE_DIR = ../../$(PROJECT_NAME)/
BUILD_DIR = ../../$(PROJECT_NAME)/Build/Playstation_2/


### Nama file dan library dependencys
EE_BIN = $(PROJECT_NAME).elf
EE_OBJS += $(BUILD_DIR)main.o
EE_FILES += $(SOURCE_DIR)main.cpp
EE_LIBS = -lGD101_LIB -ldraw -lgraph -lmath3d -lmf -lpacket -ldma 

### Rule Compile all
all: $(EE_BIN)
#	$(EE_STRIP) --strip-all $(EE_BIN)
    
### Clean all compiled data
clean:
	rm -f $(BUILD_DIR)$(EE_BIN) $(EE_OBJS)

## Tambahkan file extra untuk definisi dan command compile yand ada dalam direktori yang sama
include Makefile.pref
include Makefile.ee
