vpath %.h include
vpath %.c src

#sys_ctrl1: syscall.o sys_ctrl1.o
#	/home/practice/x-tools/arm-bare_newlib_cortex_m3_nommu-eabihf/bin/arm-bare_newlib_cortex_m3_nommu-eabihf-gcc \
#	$^ -o $@

sys_ctrl1.o: sys_ctrl1.c include/*.h
	arm-bare_newlib_cortex_m3_nommu-eabihf-gcc -c -I include $< -o $@
	mv $@ ../bin
