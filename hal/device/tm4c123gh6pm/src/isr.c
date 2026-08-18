#include <stdint.h>
#include "isr.h"
#include "can_isr.h"
#include "i2c_isr.h"
#include "gpio_isr.h"
#include "ssi_isr.h"
#include "uart_isr.h"

__attribute__((weak))
void Unused_ISR()
{
	while(1);
	return;
}

extern void startup();

__attribute((weak))
void Reset_ISR()
{
	startup();
	return; 
}

__attribute((weak))
void Nmi_ISR()
{
	// This should not happen
	while(1) ;
	return; 
}

__attribute__((weak))
void Hardfault_ISR()
{
	// This should not happen
	while(1) ;
	return; 
}

__attribute__((weak))
void MemMan_ISR()
{
	// This should not happen
	while(1) ;
	return; 
}

__attribute__((weak))
void Busfault_ISR()
{
	// This should not happen
	while(1) ;
	return; 
}

__attribute__((weak))
void Usagefault_ISR()
{
	// This should not happen
	while(1) ;
	return; 
}

__attribute__((weak))
void Svc_ISR()
{
	// Not using SVC for this implementation
	while(1) ;
	return; 
}

__attribute__((weak))
void Debugmon_ISR()
{
	// Not using SVC for this implementation
	while(1) ;
	return; 
}

__attribute__((weak))
void Pendsv_ISR()
{
	// Not using SVC for this implementation
	while(1) ;
	return; 
}

__attribute__((weak))
void Systick_ISR()
{
	// To be implemented later
	return; 
}


__attribute__((weak))
void GpioA_ISR()
{
	return; 
}

__attribute__((weak))
void GpioB_ISR()
{
	return; 
}

__attribute__((weak))
void GpioC_ISR()
{
	return; 
}

__attribute__((weak))
void GpioD_ISR()
{
	return; 
}

__attribute__((weak))
void GpioE_ISR()
{
	return; 
}

__attribute__((weak))
void GpioF_ISR()
{
	return; 
}

__attribute__((weak))
void Uart0_ISR()
{
	return; 
}

__attribute__((weak))
void Uart1_ISR()
{
	return; 
}

__attribute__((weak))
void Uart2_ISR()
{
	return; 
}

__attribute__((weak))
void Uart3_ISR()
{
	return; 
}

__attribute__((weak))
void Uart4_ISR()
{
	return; 
}

__attribute__((weak))
void Uart5_ISR()
{
	return; 
}

__attribute__((weak))
void Uart6_ISR()
{
	return; 
}

__attribute__((weak))
void Uart7_ISR()
{
	return; 
}

__attribute__((weak))
void Ssi0_ISR()
{
	return; 
}

__attribute__((weak))
void Ssi1_ISR()
{
	return; 
}

__attribute__((weak))
void Ssi2_ISR()
{
	return; 
}

__attribute__((weak))
void Ssi3_ISR()
{
	return; 
}

__attribute__((weak))
void Can0_ISR()
{
	return; 
}

__attribute__((weak))
void Can1_ISR()
{
	return; 
}

__attribute__((weak))
void I2c0_ISR()
{
	return; 
}

__attribute__((weak))
void I2c1_ISR()
{
	return; 
}

__attribute__((weak))
void I2c2_ISR()
{
	return; 
}

__attribute__((weak))
void I2c3_ISR()
{
	return; 
}

extern uint32_t _stack_start;

// CMSIS style
typedef void (*Isr_t)(void);

__attribute__((section(".isr_vectors")))
const volatile Isr_t vector_table[155] =
{
	// Stack pointer defined in linker script. At top of SRAM
	(Isr_t)&_stack_start,

	/* System exceptions */
	Reset_ISR, 		// RESET
	Nmi_ISR,		// NON-MASKABLE INTERRUPT NMI
	Hardfault_ISR,		// HARD FAULT
	MemMan_ISR,		// MEMORY MANAGEMENT
	Busfault_ISR,		// BUS FAULT
	Usagefault_ISR,	// USAGE FAULT
	0, 			// RESERVED (0)
	Svc_ISR, 		// SVCALL
	Debugmon_ISR, 		// DEBUG MONITOR
	0, 			// RESERVED (0)
	Pendsv_ISR, 		// PENDSV
	Systick_ISR, 		// SYSTICK

	/* Interrupts */
	GpioA_ISR, 		// GPIOA
	GpioB_ISR, 		// GPIOB
	GpioC_ISR, 		// GPIOC
	GpioD_ISR, 		// GPIOD
	GpioE_ISR, 		// GPIOE
	Uart0_ISR, 		// UART0
	Uart1_ISR, 		// UART1
	Ssi0_ISR, 		// SSI0
	I2c0_ISR, 		// I2C0
	Unused_ISR, 		// PWM0 FAULT
	Unused_ISR, 		// PWM0 GENERATOR 0
	Unused_ISR, 		// PWM0 GENERATOR 1
	Unused_ISR,  		// PWM0 GENERATOR 2
	Unused_ISR,  		// QEI0
	Unused_ISR, 		// ADC0 SEQUENCE 0
	Unused_ISR,  		// ADC0 SEQUENCE 1
	Unused_ISR,  		// ADC0 SEQUENCE 2
	Unused_ISR,  		// ADC0 SEQUENCE 3
	Unused_ISR,  		// WATCHDOG TIMER 0 AND 1
	Unused_ISR,  		// TIMER 0A
	Unused_ISR,  		// TIMER 0B
	Unused_ISR,  		// TIMER 1A
	Unused_ISR,  		// TIMER 1B
	Unused_ISR,  		// TIMER 2A
	Unused_ISR,  		// TIMER 2B
	Unused_ISR,  		// ANALOG COMPARATOR 0
	Unused_ISR,  		// ANALOG COMPARATOR 1
	0,  			// RESERVED[1]
	Unused_ISR,  		// SYSTEM CONTROL
	Unused_ISR,  		// FLASH MEMORY CONTROL AND EEPROM CONTROL
	GpioF_ISR,  		// GPIOF
	0, 0,  		// RESERVED[2]
	Uart2_ISR, 		// UART2
	Ssi1_ISR,  		// SSI1
	Unused_ISR,  		// TIMER 3A
	Unused_ISR,  		// TIMER 3B
	I2c1_ISR,  		// I2C1
	Unused_ISR,  		// QEI1
	Can0_ISR, 		// CAN0
	Can1_ISR,  		// CAN1
	0, 0,  		// RESERVED[2]
	Unused_ISR,  		// HIBERNATION MODULE
	Unused_ISR,  		// USB
	Unused_ISR,  		// PWM GENERATOR 3
	Unused_ISR,  		// uDMA SOFTWARE
	Unused_ISR,  		// uDMA ERROR
	Unused_ISR,  		// ADC1 SEQUENCE 0
	Unused_ISR,  		// ADC1 SEQUENCE 1
	Unused_ISR, 		// ADC1 SEQUENCE 2
	Unused_ISR,  		// ADC1 SEQUENCE 3
	0, 0, 0, 0, 0, 	// RESERVED[5]
	Ssi2_ISR,  		// SSI2
	Ssi3_ISR,  		// SSI3
	Uart3_ISR,  		// UART3
	Uart4_ISR,  		// UART4
	Uart5_ISR,  		// UART5
	Uart6_ISR,  		// UART6
	Uart7_ISR,  		// UART7
	0, 0, 0, 0,  		// RESERVED[4]
	I2c2_ISR,  		// I2C2
	I2c3_ISR,  		// I2C3
	Unused_ISR,  		// TIMER 4A
	Unused_ISR,  		// TIMER 4B
	0, 0, 0, 0, 0, 0, 0, 	// RESERVED[20]
	0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 
	Unused_ISR,   		// TIMER 5A
	Unused_ISR,   		// TIMER 5B
	Unused_ISR,   		// TIMER 0A (32/64-BIT)
	Unused_ISR,   		// TIMER 0B (32/64-BIT)
	Unused_ISR,   		// TIMER 1A (32/64-BIT)
	Unused_ISR,   		// TIMER 1B (32/64-BIT)
	Unused_ISR,   		// TIMER 2A (32/64-BIT)
	Unused_ISR,   		// TIMER 2B (32/64-BIT)
	Unused_ISR,   		// TIMER 3A (32/64-BIT)
	Unused_ISR,   		// TIMER 3B (32/64-BIT)
	Unused_ISR,   		// TIMER 4A (32/64-BIT)
	Unused_ISR,   		// TIMER 4B (32/64-BIT)
	Unused_ISR,   		// TIMER 5A (32/64-BIT)
	Unused_ISR,   		// TIMER 5B (32/64-BIT)
	Unused_ISR,   		// SYSTEM EXCEPTION (IMPRECISE)
	0, 0, 0, 0, 0, 0, 0, 	// RESERVED[27]
	0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0,
	Unused_ISR, 		// PWM1 GENERATOR 0
	Unused_ISR, 		// PWM1 GENERATOR 1
	Unused_ISR, 		// PWM1 GENERATOR 2
	Unused_ISR, 		// PWM1 GENERATOR 3
	Unused_ISR 		// PWM1 FAULT
};

