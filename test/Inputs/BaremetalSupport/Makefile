CC := arm-none-eabi-gcc
CC_FLAGS := -O0 -g -fno-short-enums -march=armv7-m -mthumb -D__NO_SYSTEM_INIT -D__START=_start -D__STACK_SIZE=0x100000 -D__HEAP_SIZE=0x100000 -D__STARTUP_COPY_MULTIPLE


build: build/startup.o build/support.o build/commandline.o
	arm-none-eabi-ar q build/libbaremetalTestsSupport.a build/startup.o build/support.o build/commandline.o
	arm-none-eabi-ranlib build/libbaremetalTestsSupport.a

.PHONY: build

build/%.o : %.c
	mkdir -p build
	$(CC) $(CC_FLAGS) -c $< -o $@

build/%.o : %.cpp
	mkdir -p build
	$(CC) $(CC_FLAGS) -c $< -o $@
