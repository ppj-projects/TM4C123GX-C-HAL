# Path to syscall.o. syscall.o must be built first
#VPATH = ../clib/newlib_syscall
vpath %.o ../clib
vpath %.h include
vpath %.c src

sys_ctrl1: syscall.o sys_ctrl1.o
	/home/practice/x-tools/arm-bare_newlib_cortex_m3_nommu-eabihf/bin/arm-bare_newlib_cortex_m3_nommu-eabihf-gcc \
	$^ -o $@

sys_ctrl1.o: sys_ctrl1.c sys_ctrl1.h
	/home/practice/x-tools/arm-bare_newlib_cortex_m3_nommu-eabihf/bin/arm-bare_newlib_cortex_m3_nommu-eabihf-gcc \
	-c -I include $< -o $@
