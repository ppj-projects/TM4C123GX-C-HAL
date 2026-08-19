vpath %.c $(TARGET)/src
vpath %.h $(TARGET)/include

isr1.o: isr.c $(TARGET)/include/*.h
	arm-bare_newlib_cortex_m3_nommu-eabihf-gcc -c -I$(TARGET)/include $< -o $@
	mv $@ ../bin
