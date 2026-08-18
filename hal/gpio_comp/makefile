# Path to syscall.o. syscall.o must be built first
#VPATH = ../clib/newlib_syscall
vpath %.o ../clib
vpath %.h include
vpath %.c src

# Set target device path
hal_target ?= ../device/tm4c123gh6pm/include
hal_target := ../device/$(TARGET)/include

#.PHONY: gpio1 $(path_hal)

#gpio1: gpio1.o syscall.o
#	/home/practice/x-tools/arm-bare_newlib_cortex_m3_nommu-eabihf/bin/arm-bare_newlib_cortex_m3_nommu-eabihf-gcc \
#	$^ -o $@

gpio1.o: gpio1.c gpio1.h $(hal_target)/gpio_isr.h
	/home/practice/x-tools/arm-bare_newlib_cortex_m3_nommu-eabihf/bin/arm-bare_newlib_cortex_m3_nommu-eabihf-gcc \
	-c -I include -I $(hal_target) $< -o $@
