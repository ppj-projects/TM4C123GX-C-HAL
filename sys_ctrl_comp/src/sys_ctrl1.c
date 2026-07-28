#include "sys_ctrl1.h"

// API calls. Limited for this project
void Sysctrl_configure_gpio_port(Sysctrl_GpioPort_t gpio_port, bool enable)
{
	SYSCTR32_RW(RCGCGPIO) = enable << gpio_port;
}
