# Path to syscall.o. syscall.o must be built first
#VPATH = ../clib/newlib_syscall
vpath %.o ../clib
vpath %.h include
vpath %.c src

gpio1: syscall.o gpio1.o
	/home/practice/x-tools/arm-bare_newlib_cortex_m3_nommu-eabihf/bin/arm-bare_newlib_cortex_m3_nommu-eabihf-gcc \
	../clib/syscall.o gpio1.o -o gpio1

gpio1.o: gpio1.c gpio1.h
	/home/practice/x-tools/arm-bare_newlib_cortex_m3_nommu-eabihf/bin/arm-bare_newlib_cortex_m3_nommu-eabihf-gcc \
	-c -I include src/gpio1.c -o gpio1.o
