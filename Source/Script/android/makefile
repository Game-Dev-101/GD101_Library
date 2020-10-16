LOCAL_PATH := ./
NAME_LIB :=libGD101_LIB.a
SRC_FILES +=../../GD101_core.cpp ../../GD101_Graphics.cpp

CFLAGS = -march=armv7-a -mfloat-abi=softfp -mfpu=vfpv3-d16
# Compilation functions attributes options
CFLAGS += -ffunction-sections -funwind-tables -fstack-protector-strong -fPIC
# Compiler options for the linker
CFLAGS += -Wall -Wa,--noexecstack -Wformat -Werror=format-security -no-canonical-prefixes
# Preprocessor macro definitions
CFLAGS += -DANDROID -DPLATFORM_ANDROID -D__ANDROID_API__=19 -u ANativeActivity_onCreate

LIBRARY += -lm -llog -landroid
INCLUDE += -I.

OBJ_FILES +=GD101_core.o GD101_Graphics.o

all: $(OBJ_FILES)
	llvm-ar rcs $(NAME_LIB) $(OBJ_FILES)
	
$(OBJ_FILES): 
	clang -c $(SRC_FILES) $(INCLUDE) $(CFLAGS) -v

    
clean:
	rm $(CURDIR)/$(OBJ_FILES)
	rm $(CURDIR)/$(NAME_LIB)
