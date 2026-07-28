#ifndef SYS_CTRL_COMP_H
#define SYS_CTRL_COMP_H

#include <stdint.h>

// System Control base address
#define SYSCTR_BASE	0x400F'E000UL

typedef struct __attribute__((packed))
{
	uint32_t DID0;               // 0x000U
	uint32_t DID1;               // 0x004U

	// 0x008 - 0x02C
	uint32_t UNUSED0[10];
	uint32_t PBORCTL;            // 0x030U

	// 0x034 - 0x04C
	uint32_t UNUSED1[7];
	uint32_t RIS;                // 0x050U
	uint32_t IMC;                // 0x054U
	uint32_t MISC;               // 0x058U
	uint32_t RESC;               // 0x05CU
	uint32_t RCC;                // 0x060U

	// 0x064 - 0x068
	uint32_t UNUSED2[2];
	uint32_t GPIOHBCTL;          // 0x06CU
	uint32_t RCC2;               // 0x070U

	// 0x074 - 0x078
	uint32_t UNUSED3[2];
	uint32_t MOSCCTL;            // 0x07CU

	// 0x080 - 0x140
	uint32_t UNUSED4[49];
	uint32_t DSLPCLKCFG;         // 0x144U

	// 0x148
    	uint32_t UNUSED5[1];
	uint32_t SYSPROP;            // 0x14CU
	uint32_t PIOSCCAL;           // 0x150U
	uint32_t PIOSCSTAT;          // 0x154U

	// 0x158 - 0x15C
	uint32_t UNUSED6[2];
	uint32_t PLLFREQ0;           // 0x160U
	uint32_t PLLFREQ1;           // 0x164U
	uint32_t PLLSTAT;            // 0x168U

	// 0x16C - 0x184
	uint32_t UNUSED7[7];
	uint32_t SLPPWRCFG;          // 0x188U
	uint32_t DSLPPWRCFG;         // 0x18CU

	// 0x190 - 0x1B0
	uint32_t UNUSED8[9];
	uint32_t LDOSPCTL;           // 0x1B4U
	uint32_t LDOSPCAL;           // 0x1B8U
	uint32_t LDODPCTL;           // 0x1BCU
	uint32_t LDODPCAL;           // 0x1C0U

	// 0x1C4 - 0x1C8
	uint32_t UNUSED9[2];
	uint32_t SDPMST;             // 0x1CCU

	// 0x1D0 - 0x5FC 
	uint32_t UNUSED10[269];
	uint32_t RCGCWD;             // 0x600U
	uint32_t RCGCTIMER;          // 0x604U
	uint32_t RCGCGPIO;           // 0x608U
	uint32_t RCGCDMA;            // 0x60CU

	// 0x610
	uint32_t UNUSED11[1];
	uint32_t RCGCHIB;            // 0x614U
	uint32_t RCGCUART;           // 0x618U
	uint32_t RCGCSSI;            // 0x61CU
	uint32_t RCGCI2C;            // 0x620U

	// 0x624
	uint32_t UNUSED12[1];
	uint32_t RCGCUSB;            // 0x628U

	// 0x62C - 0x630
	uint32_t UNUSED13[2];

	uint32_t RCGCCAN;            // 0x634U
	uint32_t RCGCADC;            // 0x638U
	uint32_t RCGCACMP;           // 0x63CU
	uint32_t RCGCPWM;            // 0x640U
	uint32_t RCGCQEI;            // 0x644U

	// 0x648 - 0x654
	uint32_t UNUSED14[4];

	uint32_t RCGCEEPROM;         // 0x658U
	uint32_t RCGCWTIMER;         // 0x65CU

} volatile * const SysCtrl_MapPtr;

const SysCtrl_MapPtr Sysctrl = ((SysCtrl_MapPtr)SYSCTR_BASE);

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
