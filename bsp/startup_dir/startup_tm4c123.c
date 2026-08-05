#include <stdint.h>

// Import sp and heap pointer
extern uint32_t* _stack_start;
extern uint32_t* _heap_start;

// I guess these are only needed by older compilers
// __attribute__((interrupt));
void Unused_ISR()
{
	while(1);
	return;
}

void Reset_ISR()
{
	startup();
	return; 
}

void Nmi_ISR
{
	// This should not happen
	while(1) ;
	return; 
}

void Hardfault_ISR
{
	// This should not happen
	while(1) ;
	return; 
}

void MemMan_ISR()
{
	// This should not happen
	while(1) ;
	return; 
}

void Busfault_ISR()
{
	// This should not happen
	while(1) ;
	return; 
}

void Usagefault_ISR()
{
	// This should not happen
	while(1) ;
	return; 
}

void Svc_ISR()
{
	// Not using SVC for this implementation
	while(1) ;
	return; 
}

void Debugmon_ISR()
{
	// Not using SVC for this implementation
	while(1) ;
	return; 
}

void Pendsv_ISR()
{
	// Not using SVC for this implementation
	while(1) ;
	return; 
}

void Systick_ISR()
{
	// To be implemented later
	return; 
}


void GpioA_ISR()
{
	return; 
}

void GpioB_ISR()
{
	return; 
}

void GpioC_ISR()
{
	return; 
}

void GpioD_ISR()
{
	return; 
}

void GpioE_ISR()
{
	return; 
}

void GpioF_ISR()
{
	return; 
}


void Uart0_ISR()
{
	return; 
}

void Uart1_ISR()
{
	return; 
}

void Uart2_ISR()
{
	return; 
}

void Uart3_ISR()
{
	return; 
}

void Uart4_ISR()
{
	return; 
}

void Uart5_ISR()
{
	return; 
}

void Uart6_ISR()
{
	return; 
}

void Uart7_ISR()
{
	return; 
}


void Ssi0_ISR()
{
	return; 
}

void Ssi1_ISR()
{
	return; 
}

void Ssi2_ISR()
{
	return; 
}

void Ssi3_ISR()
{
	return; 
}


void Can0_ISR()
{
	return; 
}

void Can1_ISR()
{
	return; 
}



void I2c0_ISR()
{
	return; 
}

void I2c1_ISR()
{
	return; 
}

void I2c2_ISR()
{
	return; 
}

void I2c3_ISR()
{
	return; 
}


// CMSIS
typedef void (*isr_t)(void);

__attribute__((section(".isr_vectors")));
const volatile isr_t vector_table[155] =
{
    (isr_t)&_stack_start, // sp // stack pointer defined in linker script. At top of SRAM

	/* system exceptions */
    Reset_ISR, // RESET
    Nmi_ISR// NON-MASKABLE INTERRUPT NMI
    Hardfault_ISR// HARD FAULT
    MemMan_ISR// MEMORY MANAGEMENT
    Busfault_ISR // BUS FAULT
    Usagefault_ISR// USAGE FAULT
    0, // RESERVED (0)
    Svc_ISR, // SVCALL
    Debugmon_ISR, // DEBUG MONITOR
    0, // RESERVED (0)
    Pendsv_ISR, // PENDSV
    Systick_ISR, // SYSTICK

	/* interrupts */
    GpioA_ISR, // GPIOA
    GpioB_ISR, // GPIOB
    GpioC_ISR, // GPIOC
    GpioD_ISR, // GPIOD
    GpioE_ISR, // GPIOE
    Uart0_ISR, // UART0
    Uart1_ISR, // UART1
    Ssi0_ISR, // SSI0
    I2c0_ISR, // I2C0
    Unused_ISR, // PWM0 FAULT
    Unused_ISR, // PWM0 GENERATOR 0
    Unused_ISR, // PWM0 GENERATOR 1
    Unused_ISR, // PWM0 GENERATOR 2
    Unused_ISR, // QEI0
    Unused_ISR, // ADC0 SEQUENCE 0
    Unused_ISR, // ADC0 SEQUENCE 1
    Unused_ISR, // ADC0 SEQUENCE 2
    Unused_ISR, // ADC0 SEQUENCE 3
    Unused_ISR, // WATCHDOG TIMER 0 AND 1
    Unused_ISR, // TIMER 0A
    Unused_ISR, // TIMER 0B
    Unused_ISR, // TIMER 1A
    Unused_ISR, // TIMER 1B
    Unused_ISR, // TIMER 2A
    Unused_ISR, // TIMER 2B
    Unused_ISR, // ANALOG COMPARATOR 0
    Unused_ISR, // ANALOG COMPARATOR 1
    0, // RESERVED[1]
    Unused_ISR, // SYSTEM CONTROL
    Unused_ISR, // FLASH MEMORY CONTROL AND EEPROM CONTROL
    GpioF_ISR, // GPIOF
    0, 0, // RESERVED[2]
    Uart2_ISR, // UART2
    Ssi1_ISR, // SSI1
    Unused_ISR, // TIMER 3A
    Unused_ISR, // TIMER 3B
    I2c1_ISR, // I2C1
    Unused_ISR, // QEI1
    Can0_ISR, // CAN0
    Can1_ISR, // CAN1
    0, 0, // RESERVED[2]
    Unused_ISR, // HIBERNATION MODULE
    Usb_ISR, // USB
    Unused_ISR, // PWM GENERATOR 3
    Unused_ISR, // uDMA SOFTWARE
    Unused_ISR, // uDMA ERROR
    Unused_ISR, // ADC1 SEQUENCE 0
    Unused_ISR, // ADC1 SEQUENCE 1
    Unused_ISR, // ADC1 SEQUENCE 2
    Unused_ISR, // ADC1 SEQUENCE 3
    0, 0, 0, 0, 0,// RESERVED[5]
    Ssi2_ISR, // SSI2
    Ssi3_ISR, // SSI3
    Uart3_ISR, // UART3
    Uart4_ISR, // UART4
    Uart5_ISR, // UART5
    Uart6_ISR, // UART6
    Uart7_ISR, // UART7
    0, 0, 0, 0, // RESERVED[4]
    I2c2_ISR, // I2C2
    I2c3_ISR, // I2C3
    Unused_ISR, // TIMER 4A
    Unused_ISR, // TIMER 4B
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, // RESERVED[20]
    Unused_ISR, // TIMER 5A
    Unused_ISR, // TIMER 5B
    Unused_ISR, // TIMER 0A (32/64-BIT)
    Unused_ISR, // TIMER 0B (32/64-BIT)
    Unused_ISR, // TIMER 1A (32/64-BIT)
    Unused_ISR, // TIMER 1B (32/64-BIT)
    Unused_ISR, // TIMER 2A (32/64-BIT)
    Unused_ISR, // TIMER 2B (32/64-BIT)
    Unused_ISR, // TIMER 3A (32/64-BIT)
    Unused_ISR, // TIMER 3B (32/64-BIT)
    Unused_ISR, // TIMER 4A (32/64-BIT)
    Unused_ISR, // TIMER 4B (32/64-BIT)
    Unused_ISR, // TIMER 5A (32/64-BIT)
    Unused_ISR, // TIMER 5B (32/64-BIT)
    Unused_ISR, // SYSTEM EXCEPTION (IMPRECISE)
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, // RESERVED[27]
    Unused_ISR, // PWM1 GENERATOR 0
    Unused_ISR, // PWM1 GENERATOR 1
    Unused_ISR, // PWM1 GENERATOR 2
    Unused_ISR, // PWM1 GENERATOR 3
    Unused_ISR  // PWM1 FAULT
}



// CPU initialization
// zero clear RAM initialization
// ROM to RAM initialization
// Static constructor initialization

void startup()
{
	// Initialize oscillators. Here?
	cpu_clock_init()

	// Initialize non-initialized variables
	init_bss()

	// Initialize statics and globals
	init_static_data()

	// Initialize constructor... but this is C?
	init_static_ctors()

	// Start main
	main();
}


extern uint32_t* _bss_start;
extern uint32_t* _bss_end;

void init_bss()
{
	// Zero-ize the bss section
	for(uint32_t* bss_entry = &_bss_start; bss_entry < &_bss_end; bss_entry++)
	{
		*bss_entry = 0;
	}
}


extern uint32_t* _data_sram_start;
extern uint32_t* _data_sram_end;
extern uint32_t* _data_flash_start;

void init_static_data()
{
	uint32_t* data_sram_entry = &_data_sram_start;
	uint32_t* data_flash_entry = &_data_flash_start;
	while( data_sram_entry < &_data_sram_end)
	{
		*data_sram_entry++ = *data_flash_entry++;
	}
}


// Need pointers to ctors and init_array
void init_static_ctors()
{

}

