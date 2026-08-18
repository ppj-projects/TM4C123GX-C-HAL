VPATH = $(TARGET)/src $(TARGET)/include

isr1.o: isr.c isr.h can_isr.h gpio_isr.h i2c_isr.h ssi_isr.h uart_isr.h
	/home/practice/x-tools/arm-bare_newlib_cortex_m3_nommu-eabihf/bin/arm-bare_newlib_cortex_m3_nommu-eabihf-gcc \
	-c -I $(TARGET)/include $< -o $@
	mv $@ ../bin
