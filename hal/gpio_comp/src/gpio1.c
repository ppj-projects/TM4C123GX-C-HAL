#include <stdint.h>
#include <stddef.h>
#include "gpio1.h"
#include "gpio_isr.h"

// Gpio ISRs
void Gpio_signal_handler(GpioPort_t port, GpioPinChannel_t pin)
{
	return;
}

void GpioA_ISR()
{
	//Gpio_signal_handler();
	return; 
}

void GpioB_ISR()
{
	//Gpio_signal_handler();
	return; 
}

void GpioC_ISR()
{
	//Gpio_signal_handler();
	return; 
}

void GpioD_ISR()
{
	//Gpio_signal_handler();
	return; 
}

void GpioE_ISR()
{
	//Gpio_signal_handler();
	return; 
}

void GpioF_ISR()
{
	//Gpio_signal_handler();
	return; 
}


// Disconnecting components and creating a contract
// Comments will explain the order of API calls
// Users need to determine these from the top level component
// Ex: Using UART comp will explain calling gpio API, and gpio API
// will explain calling sys control API
//// This couples sys_ctrl with gpio
//#include "sys_ctrl1.h"

// GPIO Port Control (GPIOPCTL) values
// CAN
static const GpioPctl_t GPIOPCTL_CAN0PB[] =
{
	{GPIOB, PIN4, 8}, // PB4 (CAN0Rx)
	{GPIOB, PIN5, 8}, // PB5 (CAN0Tx)
};

static const GpioPctl_t GPIOPCTL_CAN0PE[] =
{
	{GPIOE, PIN4, 8}, // PE4 (CAN0Rx)
	{GPIOE, PIN5, 8}, // PE5 (CAN0Tx)
};

static const GpioPctl_t GPIOPCTL_CAN0PF[] =
{
	{GPIOF, PIN0, 3}, // PF0 (CAN0Rx)
	{GPIOF, PIN3, 3}, // PF3 (CAN0Tx)
};

static const GpioPctl_t GPIOPCTL_CAN1[] =
{
	{GPIOA, PIN0, 8}, // PA0 (CAN1Rx)
	{GPIOA, PIN1, 8}, // PA1 (CAN1Tx)
};

static const GpioPctl_t * GPIOPCTL_CAN_PERIPHERAL_PINS[4] = 
{
	GPIOPCTL_CAN0PB, GPIOPCTL_CAN0PE, GPIOPCTL_CAN0PF, GPIOPCTL_CAN1
};

// UART
static const GpioPctl_t GPIOPCTL_UART0[] = 
{
	{GPIOA, PIN0, 1}, // PA0 (U0Rx)
	{GPIOA, PIN1, 1}  // PA1 (U0Tx)
};

static const GpioPctl_t GPIOPCTL_UART1A[] = 
{
	{GPIOB, PIN0, 1}, // PB0 (U1Rx)
	{GPIOB, PIN1, 1}, // PB1 (U1Tx)
	{GPIOC, PIN4, 14}, // PC4 (U1RTS)
	{GPIOC, PIN5, 14} // PC5 (U1CTS)
};

static const GpioPctl_t GPIOPCTL_UART1B[] = 
{
	{GPIOC, PIN4, 2}, // PC4 (U1Rx)
	{GPIOC, PIN5, 2}, // PC5 (U1Tx)
	{GPIOF, PIN0, 1}, // PF0 (U1RTS)
	{GPIOF, PIN1, 1} // PF1 (U1CTS)
};

static const GpioPctl_t GPIOPCTL_UART2[] = 
{
	{GPIOD, PIN6, 1}, // PD6 (U2Rx)
	{GPIOD, PIN7, 1}, // PD7 (U2Tx)
};

static const GpioPctl_t GPIOPCTL_UART3[] = 
{
	{GPIOC, PIN6, 1}, // PC6 (U3Rx)
	{GPIOC, PIN7, 1}, // PC7 (U3Tx)
};

static const GpioPctl_t GPIOPCTL_UART4[] = 
{
	{GPIOC, PIN4, 1}, // PC4 (U4Rx)
	{GPIOC, PIN5, 1}, // PC5 (U4Tx)
};

static const GpioPctl_t GPIOPCTL_UART5[] = 
{
	{GPIOE, PIN4, 1}, // PE4 (U5Rx)
	{GPIOE, PIN5, 1}, // PE5 (U5Tx)
};

static const GpioPctl_t GPIOPCTL_UART6[] = 
{
	{GPIOD, PIN4, 1}, // PD4 (U6Rx)
	{GPIOD, PIN5, 1}, // PD5 (U6Tx)
};

static const GpioPctl_t GPIOPCTL_UART7[] = 
{
	{GPIOE, PIN0, 1}, // PE0 (U7Rx)
	{GPIOE, PIN1, 1}, // PE1 (U7Tx)
};

static const GpioPctl_t * GPIOPCTL_UART_PERIPHERAL_PINS[9] = 
{
	GPIOPCTL_UART0, GPIOPCTL_UART1A, GPIOPCTL_UART1B, GPIOPCTL_UART2, GPIOPCTL_UART3, 
	GPIOPCTL_UART4, GPIOPCTL_UART5, GPIOPCTL_UART6, GPIOPCTL_UART7
};

// I2C
static const GpioPctl_t GPIOPCTL_I2C0[] =
{
	{GPIOB, PIN2, 3}, // PB2 (I2C0SCL)
	{GPIOB, PIN3, 3}, // PB3 (I2C0SDA)
};

static const GpioPctl_t GPIOPCTL_I2C1[] =
{
	{GPIOA, PIN6, 3}, // PA6 (I2C1SCL)
	{GPIOA, PIN7, 3}, // PA7 (I2C1SDA)
};

static const GpioPctl_t GPIOPCTL_I2C2[] =
{
	{GPIOE, PIN4, 3}, // PE4 (I2C2SCL)
	{GPIOE, PIN5, 3}, // PE5 (I2C2SDA)
};

static const GpioPctl_t GPIOPCTL_I2C3[] =
{
	{GPIOD, PIN0, 3}, // PD0 (I2C3SCL)
	{GPIOD, PIN1, 3}, // PD1 (I2C3SDA)
};

static const GpioPctl_t * GPIOPCTL_I2C_PERIPHERAL_PINS[4] = 
{
	GPIOPCTL_I2C0, GPIOPCTL_I2C1, GPIOPCTL_I2C3, GPIOPCTL_I2C3
};

// SSI
static const GpioPctl_t GPIOPCTL_SSI0[] =
{
	{GPIOA, PIN2, 2}, // PA2 (SSI0Clk)
	{GPIOA, PIN3, 2}, // PA3 (SSI0Fss)
	{GPIOA, PIN4, 2}, // PA4 (SSI0Rx)
	{GPIOA, PIN5, 2}, // PA5 (SSI0Tx)
};

static const GpioPctl_t GPIOPCTL_SSI1[] =
{
	{GPIOD, PIN0, 2}, // PD0 (SSI1Clk)
	{GPIOD, PIN1, 2}, // PD1 (SSI1Fss)
	{GPIOD, PIN2, 2}, // PD2 (SSI1Rx)
	{GPIOD, PIN3, 2}, // PD3 (SSI1Tx)

	{GPIOF, PIN0, 2}, // PF0 (SSI1Rx)
	{GPIOF, PIN1, 2}, // PF1 (SSI1Tx)
	{GPIOF, PIN2, 2}, // PF2 (SSI1Clk)
	{GPIOF, PIN3, 2}, // PF3 (SSI1Fss)
};

static const GpioPctl_t GPIOPCTL_SSI2[] =
{
	{GPIOB, PIN4, 2}, // PB4 (SSI2Clk)
	{GPIOB, PIN5, 2}, // PB5 (SSI2Fss)
	{GPIOB, PIN6, 2}, // PB6 (SSI2Rx)
	{GPIOB, PIN7, 2}, // PB7 (SSI2Tx)
};

static const GpioPctl_t GPIOPCTL_SSI3[] =
{
	{GPIOD, PIN0, 1}, // PD0 (SSI3Clk)
	{GPIOD, PIN1, 1}, // PD1 (SSI3Fss)
	{GPIOD, PIN2, 1}, // PD2 (SSI3Rx)
	{GPIOD, PIN3, 1}, // PD3 (SSI3Tx)
};

static const GpioPctl_t * GPIOPCTL_SSI_PERIPHERAL_PINS[4] = 
{
	GPIOPCTL_SSI0, GPIOPCTL_SSI1, GPIOPCTL_SSI2, GPIOPCTL_SSI3
};

// USB
static const GpioPctl_t GPIOPCTL_USB0[] =
{
	{GPIOB, PIN0, 1}, // PB0 (USB0ID)
	{GPIOB, PIN1, 1}, // PB1 (USB0VBUS)
	{GPIOD, PIN4, 1}, // PD4 (USB0DM)
	{GPIOD, PIN5, 1}, // PD5 (USB0DP)

	{GPIOC, PIN6, 9}, // PC6 (USB0EPEN)
	{GPIOD, PIN2, 9}, // PD2 (USB0EPEN)
	{GPIOF, PIN4, 9}, // PF4 (USB0EPEN)

	{GPIOC, PIN7, 9}, // PC7 (USB0PFLT)
	{GPIOD, PIN3, 9}, // PD3 (USB0PFLT)
};


// Going to remove this function and create a contract
// User needs to call these APIs themselves, and the comments will explain this
// This will prevent dependencies between components and decouple them
// GPIO config functions
void Gpio_configure(GpioPort_t port)
{
	// Set GPIO bus. Just comment for demonstration. Default will always be APB
	// Sysctrl_configure_gpio_bus((Sysctrl_GpioPort_t)port, Sysctrl_bus_t::APB);

	// Enable port
	// Check if already enabled. Need getter
	//Sysctrl_configure_gpio_port((Sysctrl_GpioPort_t)port, true);

	return;
}

void Gpio_configure_io(GpioPort_t port, GpioPinChannel_t pin, GpioDirection_t dir)
{
	uint32_t dir_val = ((dir == INPUT)? 1 : 0 ) << pin;
	uint32_t afsel_val = 0 << pin;
	uint32_t drive_val = 1 << pin;
	uint32_t den_val = 1 << pin;
	Gpio_configure(port);
	
	HWREG32_RW((GPIOA_BASE + (GPIO_BASE_OFFSET * port)) + GPIODIR) &= ~(1 << pin);
	HWREG32_RW((GPIOA_BASE + (GPIO_BASE_OFFSET * port)) + GPIODIR) |= dir_val;
	
	HWREG32_RW((GPIOA_BASE + (GPIO_BASE_OFFSET * port)) + GPIOAFSEL) &= ~(1 << pin);
	HWREG32_RW((GPIOA_BASE + (GPIO_BASE_OFFSET * port)) + GPIOAFSEL) |= afsel_val
	
	HWREG32_RW((GPIOA_BASE + (GPIO_BASE_OFFSET * port)) + GPIODR4R) &= ~(1 << pin);
	HWREG32_RW((GPIOA_BASE + (GPIO_BASE_OFFSET * port)) + GPIODR4R) |= drive_val;
	
	HWREG32_RW((GPIOA_BASE + (GPIO_BASE_OFFSET * port)) + GPIODEN) &= ~(1 << pin);
	HWREG32_RW((GPIOA_BASE + (GPIO_BASE_OFFSET * port)) + GPIODEN) |= den_val;

	return;
}


static void Gpio_configure_af_peripheral(const GpioPctl_t periph_setting)
{
	uint32_t afsel_val = 1 << periph_setting.pin;
	uint32_t pctl_val = periph_setting.pctl_val << (4 * periph_setting.pin);
	Gpio_configure(periph_setting.port);
	
	
	HWREG32_RW((GPIOA_BASE + (GPIO_BASE_OFFSET * periph_setting.port)) + GPIOAFSEL) &=
		~(1 << periph_setting.pin);
	HWREG32_RW((GPIOA_BASE + (GPIO_BASE_OFFSET * periph_setting.port)) + GPIOAFSEL) |=
		afsel_val;
		
	HWREG32_RW((GPIOA_BASE + (GPIO_BASE_OFFSET * periph_setting.port)) + GPIOPCTL) &=
		~(1 << periph_setting.pin);
	HWREG32_RW((GPIOA_BASE + (GPIO_BASE_OFFSET * periph_setting.port)) + GPIOPCTL) |= 
		pctl_val;

	return;
}

void Gpio_configure_can(GpioCan_t can_periph)
{
    const GpioPctl_t * periph_array = GPIOPCTL_CAN_PERIPHERAL_PINS[can_periph];
    for(size_t periph_entry = 0; periph_entry < sizeof(periph_array); periph_entry++)
    {
	    Gpio_configure_af_peripheral(*(periph_array + periph_entry));
    }
	return;
}

void Gpio_configure_uart(GpioUart_t uart_periph)
{
    const GpioPctl_t * periph_array = GPIOPCTL_UART_PERIPHERAL_PINS[uart_periph];
    for(size_t periph_entry = 0; periph_entry < sizeof(periph_array); periph_entry++)
    {
	    Gpio_configure_af_peripheral(*(periph_array + periph_entry));
    }
	return;
}

void Gpio_configure_i2c(GpioI2c_t i2c_periph)
{
    const GpioPctl_t * periph_array = GPIOPCTL_I2C_PERIPHERAL_PINS[i2c_periph];
    for(size_t periph_entry = 0; periph_entry < sizeof(periph_array); periph_entry++)
    {
	    Gpio_configure_af_peripheral(*(periph_array + periph_entry));
    }
	return;
}

void Gpio_configure_ssi(GpioSsi_t ssi_periph)
{
    const GpioPctl_t * periph_array = GPIOPCTL_SSI_PERIPHERAL_PINS[ssi_periph];
    for(size_t periph_entry = 0; periph_entry < sizeof(periph_array); periph_entry++)
    {
	    Gpio_configure_af_peripheral(*(periph_array + periph_entry));
    }
	return;
}

void Gpio_configure_timer(GpioTimer_t timer_periph)
{
    Gpio_configure_af_peripheral(GPIOPCTL_USB0[timer_periph]);
	return;
}

