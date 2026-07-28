#include "sys_ctrl1.h"

// API calls. Limited for this project
void Sysctrl_configure_gpio_port(Sysctrl_GpioPort_t gpio_port, bool enable)
{
	SYSCTR32_RW(RCGCGPIO) = enable << gpio_port;
}

void Sysctrl_configure_gpio_bus(Sysctrl_GpioPort_t gpio_port, Sysctrl_Bus_t bus)
{
	SYSCTR32_RW(GPIOHBCTL) = bus << gpio_port;
}
