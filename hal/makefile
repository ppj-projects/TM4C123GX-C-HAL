# Paths to the directory for this HAL
path_clib := clib
path_gpiocomp := gpio_comp
path_sysctrlcomp := sys_ctrl_comp
path_nviccomp := nvic_comp
path_device := device

path_hal := $(path_device) $(path_clib) $(path_sysctrlcomp) $(path_nviccomp) $(path_gpiocomp)

# Set target device path
hal_target ?= tm4c123gh6pm
hal_target := $(DEVICE)

.PHONY: gpio1 $(path_hal)
gpio1: $(path_hal)

# Recursively call make in each directory. Start with clib
$(path_hal):
	$(MAKE) --directory=$@ TARGET=$(hal_target)
