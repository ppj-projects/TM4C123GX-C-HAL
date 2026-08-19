# Set target device path
hal_target ?= ../device/tm4c123gh6pm/include
hal_target := ../device/$(TARGET)/include

vpath %.h include $(hal_target)
vpath %.c src

#gpio1: gpio1.o syscall.o
#	/home/practice/x-tools/arm-bare_newlib_cortex_m3_nommu-eabihf/bin/arm-bare_newlib_cortex_m3_nommu-eabihf-gcc \
#	$^ -o $@

gpio1.o: gpio1.c $(hal_target)/*.h
	arm-bare_newlib_cortex_m3_nommu-eabihf-gcc -c -I include -I $(hal_target) $< -o $@
	mv $@ ../bin
