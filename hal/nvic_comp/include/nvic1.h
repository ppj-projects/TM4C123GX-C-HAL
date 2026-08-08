#ifndef NVIC_COMP_H
#define NVIC_COMP_H

#include <stdint.h>

// Reg access
#define HWREG32_RW(x) (*((uint32_t volatile *)(x)))
#define HWREG32_RO(x) (*((uint32_t volatile const *)(x)))

// NVIC base address
#define NVICCTRL_BASE	0xE000E000UL

// NVIC registers
#define EN0		0x100U
#define EN1		0x104U
#define EN2		0x108U
#define EN3		0x10CU
#define EN4		0x110U
#define DIS0		0x180U
#define DIS1		0x184U
#define DIS2		0x188U
#define DIS3		0x18CU
#define DIS4		0x190U
#define PEND0		0x200U
#define PEND1		0x204U
#define PEND2		0x208U
#define PEND3		0x20CU
#define PEND4		0x210U
#define UNPEND0	0x280U
#define UNPEND1	0x284U
#define UNPEND2	0x288U
#define UNPEND3	0x28CU
#define UNPEND4	0x290U
#define ACTIVE0	0x300U	//RO
#define ACTIVE1	0x304U	//RO
#define ACTIVE2	0x308U	//RO
#define ACTIVE3	0x30CU	//RO
#define ACTIVE4	0x310U	//RO
#define PRI0		0x400U
#define PRI1		0x404U
#define PRI2		0x408U
#define PRI3		0x40CU
#define PRI4		0x410U
#define PRI5		0x414U
#define PRI6		0x418U
#define PRI7		0x41CU
#define PRI8		0x420U
#define PRI9		0x424U
#define PRI10		0x428U
#define PRI11		0x42CU
#define PRI12		0x430U
#define PRI13		0x434U
#define PRI14		0x438U
#define PRI15		0x43CU
#define PRI16		0x440U
#define PRI17		0x444U
#define PRI18		0x448U
#define PRI19		0x44CU
#define PRI20		0x450U
#define PRI21		0x454U
#define PRI22		0x458U
#define PRI23		0x45CU
#define PRI24		0x460U
#define PRI25		0x464U
#define PRI26		0x468U
#define PRI27		0x46CU
#define PRI28		0x470U
#define PRI29		0x474U
#define PRI30		0x478U
#define PRI31		0x47CU
#define PRI32		0x480U
#define PRI33		0x484U
#define PRI34		0x488U
#define SWTRIG		0xF00U

// NVIC ccess
#define NVIC32_RW(x)	HWREG32_RW((NVIC_BASE) + (x))
#define NVIC32_RO(x)	HWREG32_RO((NVIC_BASE) + (x))

// Interrupt number enums
typedef enum
{
	GPIOA_nvic_int,
	GPIOB_nvic_int,
	GPIOC_nvic_int,
	GPIOD_nvic_int,
	GPIOE_nvic_int,
	UART0_nvic_int,
	UART1_nvic_int,
	SSI0_nvic_int,
	I2C0_nvic_int,
	PWM0_FAULT_nvic_int,
	PWM0_GEN0_nvic_int,
	PWM0_GEN1_nvic_int,
	PWM0_GEN2_nvic_int,
	QEI0_nvic_int,
	ADC0_SEQ0_nvic_int,
	ADC0_SEQ1_nvic_int,
	ADC0_SEQ2_nvic_int,
	ADC0_SEQ3_nvic_int,
	WDT0_1_nvic_int,
	TIMER0A_16_32_nvic_int,
	TIMER0B_16_32_nvic_int,
	TIMER1A_16_32_nvic_int,
	TIMER1B_16_32_nvic_int,
	TIMER2A_16_32_nvic_int,
	TIMER2B_16_32_nvic_int,
	COMP0_nvic_int,
	COMP1_nvic_int,
	
	// Interrupt 27 is reserved
	SYSCTL_nvic_int = 28,
	FLASH_EEPROM_nvic_int,
	GPIOF_nvic_int,

	// Interrupts 31-32 are reserved
	UART2_nvic_int = 33,
	SSI1_nvic_int,
	TIMER3A_16_32_nvic_int,
	TIMER3B_16_32_nvic_int,
	I2C1_nvic_int,
	QEI1_nvic_int,
	CAN0_nvic_int,
	CAN1_nvic_int,
	
	// Interrupts 41-42 are reserved
	HIB_nvic_int = 43,
	USB_nvic_int,
	PWM0_GEN3_nvic_int,
	UDMA_SW_nvic_int,
	UDMA_ERROR_nvic_int,
	ADC1_SEQ0_nvic_int,
	ADC1_SEQ1_nvic_int,
	ADC1_SEQ2_nvic_int,
	ADC1_SEQ3_nvic_int,
	
	// Interrupts 52-56 are reserved
	SSI2_nvic_int = 57,
	SSI3_nvic_int,
	UART3_nvic_int,
	UART4_nvic_int,
	UART5_nvic_int,
	UART6_nvic_int,
  	  UART7_nvic_int,
  	  
	// *nterrupts 64-67 are reserved
	I2C2_nvic_int = 68,
	I2C3_nvic_int,
	TIMER4A_16_32_nvic_int,
	TIMER4B_16_32_nvic_int,
	
	// Interrupts 72-91 are reserved
	TIMER5A_16_32_nvic_int = 92,
	TIMER5B_16_32_nvic_int,
	TIMER0A_32_64_nvic_int,
	TIMER0B_32_64_nvic_int,
	TIMER1A_32_64_nvic_int,
	TIMER1B_32_64_nvic_int,
	TIMER2A_32_64_nvic_int,
	TIMER2B_32_64_nvic_int,
	TIMER3A_32_64_nvic_int,
	TIMER3B_32_64_nvic_int,
	TIMER4A_32_64_nvic_int,
	TIMER4B_32_64_nvic_int,
	TIMER5A_32_64_nvic_int,
	TIMER5B_32_64_nvic_int,
	SYSTEM_EXCEPTION_nvic_int,
	
	// Interrupts 107-133 are reserved
	PWM1_GEN0_nvic_int = 134,
	PWM1_GEN1_nvic_int,
	PWM1_GEN2_nvic_int,
	PWM1_GEN3_nvic_int,
	PWM1_FAULT_nvic_int
} Nvic_interrupt_numb_t;

// NVIC priority levels
typedef enum
{
	PRI0,
	PRI1,
	PRI2,
	PRI3,
	PRI4,
	PRI5,
	PRI6,
	PRI7
}Nvic_priority_t;

// NVIC API
void Nvic_enable_interrupt(Nvic_interrupt_numb_t int_num, Nvic_priority_t priority, bool en);
void Nvic_set_interrupt_pending(int_num, bool set);
bool Nvic_is_interrupt_active(int_num);

#endif
