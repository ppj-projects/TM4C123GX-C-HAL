#ifndef SYS_CTRL_COMP_H
#define SYS_CTRL_COMP_H

#include <stdint.h>

#define HWREG32_RW(x) 	(*((uint32_t volatile *)(x)))
#define HRREG32_RO(x) 	(*((uint32_t volatile const *)(x)))

#define SYSCTR32_RW(x) 	HWREG32_RW((SYSCTR_BASE) + (x))
#define SYSCTR32_RO(x) 	HWREG32_RO((SYSCTR_BASE) + (x))

// System Control base address
#define SYSCTR_BASE		0x400F'E000UL

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



/* System Control Base Address */
#define SYSCTRL_BASE    0x400F'E000UL

/* System Control Base Pointer */
uint32_t volatile * const SysCtrl_base = (uint32_t volatile *)SYSCTRL_BASE;

/* System Control Register Pointers */
uint32_t volatile * const SysCtrl_DID0 = &SysCtrl_base[DID0 / sizeof(uint32_t)];
uint32_t volatile * const SysCtrl_DID1 = &SysCtrl_base[DID1 / sizeof(uint32_t)];
uint32_t volatile * const SysCtrl_PBORCTL = &SysCtrl_base[PBORCTL / sizeof(uint32_t)];
uint32_t volatile * const SysCtrl_RIS = &SysCtrl_base[RIS / sizeof(uint32_t)];
uint32_t volatile * const SysCtrl_IMC = &SysCtrl_base[IMC / sizeof(uint32_t)];
uint32_t volatile * const SysCtrl_MISC = &SysCtrl_base[MISC / sizeof(uint32_t)];
uint32_t volatile * const SysCtrl_RESC = &SysCtrl_base[RESC / sizeof(uint32_t)];
uint32_t volatile * const SysCtrl_RCC = &SysCtrl_base[RCC / sizeof(uint32_t)];
uint32_t volatile * const SysCtrl_GPIOHBCTL = &SysCtrl_base[GPIOHBCTL / sizeof(uint32_t)];
uint32_t volatile * const SysCtrl_RCC2 = &SysCtrl_base[RCC2 / sizeof(uint32_t)];
uint32_t volatile * const SysCtrl_MOSCCTL = &SysCtrl_base[MOSCCTL / sizeof(uint32_t)];
uint32_t volatile * const SysCtrl_DSLPCLKCFG = &SysCtrl_base[DSLPCLKCFG  sizeof(uint32_t)];
uint32_t volatile * const SysCtrl_SYSPROP = &SysCtrl_base[SYSPROP / sizeof(uint32_t)];
uint32_t volatile * const SysCtrl_PIOSCCAL = &SysCtrl_base[PIOSCCAL / sizeof(uint32_t)];
uint32_t volatile * const SysCtrl_PIOSCSTAT = &SysCtrl_base[PIOSCSTAT / sizeof(uint32_t)];
uint32_t volatile * const SysCtrl_PLLFREQ0 = &SysCtrl_base[PLLFREQ0 / sizeof(uint32_t)];
uint32_t volatile * const SysCtrl_PLLFREQ1 = &SysCtrl_base[PLLFREQ1 / sizeof(uint32_t)];
uint32_t volatile * const SysCtrl_PLLSTAT = &SysCtrl_base[PLLSTAT / sizeof(uint32_t)];
uint32_t volatile * const SysCtrl_SLPPWRCFG = &SysCtrl_base[SLPPWRCFG / sizeof(uint32_t)];
uint32_t volatile * const SysCtrl_DSLPPWRCFG = &SysCtrl_base[DSLPPWRCFG / sizeof(uint32_t)];
uint32_t volatile * const SysCtrl_LDOSPCTL = &SysCtrl_base[LDOSPCTL / sizeof(uint32_t)];
uint32_t volatile * const SysCtrl_LDOSPCAL = &SysCtrl_base[LDOSPCAL / sizeof(uint32_t)];
uint32_t volatile * const SysCtrl_LDODPCTL = &SysCtrl_base[LDODPCTL / sizeof(uint32_t)];
uint32_t volatile * const SysCtrl_LDODPCAL = &SysCtrl_base[LDODPCAL / sizeof(uint32_t)];
uint32_t volatile * const SysCtrl_SDPMST = &SysCtrl_base[SDPMST / sizeof(uint32_t)];

/* Run Mode Clock Gating Registers */
uint32_t volatile * const SysCtrl_RCGCWD = &SysCtrl_base[RCGCWD / sizeof(uint32_t)];
uint32_t volatile * const SysCtrl_RCGCTIMER = &SysCtrl_base[RCGCTIMER / sizeof(uint32_t)];
uint32_t volatile * const SysCtrl_RCGCGPIO = &SysCtrl_base[RCGCGPIO / sizeof(uint32_t)];
uint32_t volatile * const SysCtrl_RCGCDMA = &SysCtrl_base[RCGCDMA / sizeof(uint32_t)];
uint32_t volatile * const SysCtrl_RCGCHIB = &SysCtrl_base[RCGCHIB / sizeof(uint32_t)];
uint32_t volatile * const SysCtrl_RCGCUART = &SysCtrl_base[RCGCUART / sizeof(uint32_t)];
uint32_t volatile * const SysCtrl_RCGCSSI = &SysCtrl_base[RCGCSSI / sizeof(uint32_t)];
uint32_t volatile * const SysCtrl_RCGCI2C = &SysCtrl_base[RCGCI2C / sizeof(uint32_t)];
uint32_t volatile * const SysCtrl_RCGCUSB = &SysCtrl_base[RCGCUSB / sizeof(uint32_t)];
uint32_t volatile * const SysCtrl_RCGCCAN = &SysCtrl_base[RCGCCAN / sizeof(uint32_t)];
uint32_t volatile * const SysCtrl_RCGCADC = &SysCtrl_base[RCGCADC / sizeof(uint32_t)];
uint32_t volatile * const SysCtrl_RCGCACMP = &SysCtrl_base[RCGCACMP / sizeof(uint32_t)];
uint32_t volatile * const SysCtrl_RCGCPWM = &SysCtrl_base[RCGCPWM / sizeof(uint32_t)];
uint32_t volatile * const SysCtrl_RCGCQEI = &SysCtrl_base[RCGCQEI / sizeof(uint32_t)];
uint32_t volatile * const SysCtrl_RCGCEEPROM = &SysCtrl_base[RCGCEEPROM / sizeof(uint32_t)];
uint32_t volatile * const SysCtrl_RCGCWTIMER = &SysCtrl_base[RCGCWTIMER / sizeof(uint32_t)];


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

typedef enum
{
	GPIOA,
	GPIOB,
	GPIOC,
	GPIOD,
	GPIOE,
	GPIOF
}Sysctrl_GpioPort_t;

// API calls. Limited for this project
void Sysctrl_configure_gpio_port(Sysctrl_GpioPort_t gpio_port, bool enable);

#endif
