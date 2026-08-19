vpath %.h include
vpath %.c src

#nvic1: syscall.o nvic1.o
#	/home/practice/x-tools/arm-bare_newlib_cortex_m3_nommu-eabihf/bin/arm-bare_newlib_cortex_m3_nommu-eabihf-gcc \
#	$^ -o $@

nvic1.o: nvic1.c include/*.h
	arm-bare_newlib_cortex_m3_nommu-eabihf-gcc -c -I include $< -o $@
	mv $@ ../bin
