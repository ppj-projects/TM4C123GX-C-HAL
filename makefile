# Add path to toolchain bin directory to PATH environment variable, and export
PATH += ~/x-tools/x-tools/arm-bare_newlib_cortex_m3_nommu-eabihf/bin/
export PATH

# Paths to the directory for this project
path_hal_clib := hal/clib
path_hal_gpiocomp := hal/gpio_comp
path_hal_sys_ctrlcomp := hal/sys_ctrl_comp
path_bsp := bsp

path_hal := $(path_hal_clib) $(path_hal_gpiocomp) $(path_hal_sys_ctrlcomp)

.PHONY: gpio1 $(path_hal)
gpio1: $(path_hal)

# Recursively call make in each directory. Start with clib
$(path_hal):
	$(MAKE) --directory=$@
