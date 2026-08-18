# Paths to the directory for this HAL
path_clib := clib
path_gpiocomp := gpio_comp
path_sysctrlcomp := sys_ctrl_comp
path_nviccomp := nvic_comp

path_hal := $(path_clib) $(path_gpiocomp) $(path_sysctrlcomp) $(path_nviccomp)

.PHONY: gpio1 $(path_hal)
gpio1: $(path_hal)

# Recursively call make in each directory. Start with clib
$(path_hal):
	$(MAKE) --directory=$@
