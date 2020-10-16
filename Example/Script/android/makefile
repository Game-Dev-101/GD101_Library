LOCAL_PATH := ./
NAME_LIB :=lib2_Basic_Primitive_Shape.so
SRC_FILES += ../../2_Basic_Primitive_Shape/main.cpp
ARCH =armeabi-v7a

LDFLAGS += -Wl,--build-id -Wl,--no-undefined -Wl,-z,noexecstack -Wl,-z,relro -Wl,-z,now -Wl,--warn-shared-textrel -Wl,--fatal-warnings 
# Force linking of library module to define symbol
LDFLAGS += -u ANativeActivity_onCreate
# Library paths containing required libs

LDFLAGS += -L../../Library/Android/armeabi-v7a/

LIBRARY += -lGD101_LIB -llog -landroid -lEGL -lm -lc -lGLESv2 -lOpenSLES -ldl
INCLUDE += -I. -I../

CFLAGS = -march=armv7-a -mfloat-abi=softfp -mfpu=vfpv3-d16
# Compilation functions attributes options
CFLAGS += -ffunction-sections -funwind-tables -fstack-protector-strong -fPIC
# Compiler options for the linker
CFLAGS += -Wall -Wa,--noexecstack -Wformat -Werror=format-security -no-canonical-prefixes
# Preprocessor macro definitions
CFLAGS += -DANDROID -DPLATFORM_ANDROID -D__ANDROID_API__=19

ARM_MODE =arm
OBJ_FILES +=main.o

all: $(OBJ_FILES)
	clang -o $(NAME_LIB) $(OBJ_FILES) -shared $(LDFLAGS) $(LIBRARY)

$(OBJ_FILES): 
	clang -c $(SRC_FILES) $(INCLUDE) $(CFLAGS)
    
clean:
	rm $(CURDIR)/$(OBJ_FILES)
	rm $(CURDIR)/$(NAME_LIB)
