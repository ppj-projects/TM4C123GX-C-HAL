#ifndef SYS_CTRL_COMP_H
#define SYS_CTRL_COMP_H

#include <stdint.h>
#include <stdbool.h>

#define HWREG32_RW(x) 	(*((uint32_t volatile *)(x)))
#define HRREG32_RO(x) 	(*((uint32_t volatile const *)(x)))

#define SYSCTR32_RW(x) HWREG32_RW((SYSCTR_BASE) + (x))
#define SYSCTR32_RO(x) HWREG32_RO((SYSCTR_BASE) + (x))

// System Control base address
#define SYSCTR_BASE		0x400FE000UL

// System Control register offsets
#define DID0            0x000U
#define DID1            0x004U
#define PBORCTL         0x030U
#define RIS             0x050U
#define IMC             0x054U
#define MISC            0x058U
#define RESC            0x05CU
#define RCC             0x060U
#define GPIOHBCTL       0x06CU
#define RCC2            0x070U
#define MOSCCTL         0x07CU
#define DSLPCLKCFG      0x144U
#define SYSPROP         0x14CU
#define PIOSCCAL        0x150U
#define PIOSCSTAT       0x154U
#define PLLFREQ0        0x160U
#define PLLFREQ1        0x164U
#define PLLSTAT         0x168U
#define SLPPWRCFG       0x188U
#define DSLPPWRCFG      0x18CU
#define LDOSPCTL        0x1B4U
#define LDOSPCAL        0x1B8U
#define LDODPCTL        0x1BCU
#define LDODPCAL        0x1C0U
#define SDPMST          0x1CCU

#define RCGCWD          0x600U
#define RCGCTIMER       0x604U
#define RCGCGPIO        0x608U
#define RCGCDMA         0x60CU
#define RCGCHIB         0x614U
#define RCGCUART        0x618U
#define RCGCSSI         0x61CU
#define RCGCI2C         0x620U
#define RCGCUSB         0x628U
#define RCGCCAN         0x634U
#define RCGCADC         0x638U
#define RCGCACMP        0x63CU
#define RCGCPWM         0x640U
#define RCGCQEI         0x644U
#define RCGCEEPROM      0x658U
#define RCGCWTIMER      0x65CU

// Sys Control Base Address 
#define SYSCTRL_BASE    0x400F'E000UL

typedef enum
{
	GPIOA,
	GPIOB,
	GPIOC,
	GPIOD,
	GPIOE,
	GPIOF
}Sysctrl_GpioPort_t;

typedef enum
{
	APB,
	AHB
}Sysctrl_Bus_t;

// API calls. Limited for this project
void Sysctrl_configure_gpio_port(Sysctrl_GpioPort_t gpio_port, bool enable);
void Sysctrl_configure_gpio_bus(Sysctrl_GpioPort_t gpio_port, Sysctrl_Bus_t bus);

#endif
