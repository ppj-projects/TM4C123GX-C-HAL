#include "gpio1.h"

// This couples sys_ctrl with gpio
#include "sys_ctrl1.h"

// GPIO Port Control (GPIOPCTL) values
// CAN
static const uint8_t * GPIOPCTL_CAN_PERIPHERAL_PINS[4] = 
{
    CAN0PB, CAN0PE, CAN0PF, CAN1
};

static const uint8_t GPIOPCTL_CAN0PB[] =
{
    8,  // PB4 (CAN0Rx)
    8,  // PB5 (CAN0Tx)
};

static const uint8_t GPIOPCTL_CAN0PE[] =
{
    8,  // PE4 (CAN0Rx)
    8,  // PE5 (CAN0Tx)
};

static const uint8_t GPIOPCTL_CAN0PF[] =
{
    3,  // PF0 (CAN0Rx)
    3,  // PF3 (CAN0Tx)
};

static const uint8_t GPIOPCTL_CAN1[] =
{
    8,  // PA0 (CAN1Rx)
    8,  // PA1 (CAN1Tx)
};

// UART
static const uint8_t * GPIOPCTL_UART_PERIPHERAL_PINS[8] = 
{
    GPIOPCTL_UART0, GPIOPCTL_UART1, GPIOPCTL_UART2, GPIOPCTL_UART3, GPIOPCTL_UART4, GPIOPCTL_UART5, GPIOPCTL_UART6, GPIOPCTL_UART7
};

static const uint8_t GPIOPCTL_UART0[] =
{
    1,  // PA0 (U0Rx)
    1,  // PA1 (U0Tx)
};

static const GpioPctl_t GPIOPCTL_UART0[] = 
{
	{GPIOA, PIN0, 1}, // PA0 (U0Rx)
	{GPIA1, PIN1, 1}  // PA1 (U0Tx)
}

static const uint8_t GPIOPCTL_UART1A[] =
{
    1,  // PB0 (U1Rx)
    1,  // PB1 (U1Tx)
    14, // PC4 (U1RTS)
    14, // PC5 (U1CTS)
};

static const GpioPctl_t GPIOPCTL_UART1A[] = 
{
	{GPIOB, PIN0, 1},
	{GPIOB, PIN1, 1},
	{GPIOC, PIN4, 14},
	{GPIOC, PIN5, 14}
}

static const uint8_t GPIOPCTL_UART1B[] = 
{
    2,  // PC4 (U1Rx)
    2,  // PC5 (U1Tx)
    1,  // PF0 (U1RTS)
    1,  // PF1 (U1CTS)
}

static const GpioPctl_t GPIOPCTL_UART1B[] = 
{
        {GPIOC, PIN4, 2},
        {GPIOC, PIN5, 2},
        {GPIOF, PIN0, 1},
        {GPIOF, PIN1, 1}
}

static const uint8_t GPIOPCTL_UART2[] =
{
    1,  // PD6 (U2Rx)
    1,  // PD7 (U2Tx)
};

static const GpioPctl_t GPIOPCTL_UART2[] = 
{
	{GPIOD, PIN6, 1},
	{GPIOD, PIN7, 1},
}

static const uint8_t GPIOPCTL_UART3[] =
{
    1,  // PC6 (U3Rx)
    1,  // PC7 (U3Tx)
};

static const GpioPctl_t GPIOPCTL_UART2[] = 
{
        {GPIOC, PIN6, 1},
        {GPIOC, PIN7, 1},
}


static const uint8_t GPIOPCTL_UART4[] =
{
    1,  // PC4 (U4Rx)
    1,  // PC5 (U4Tx)
};

static const GpioPctl_t GPIOPCTL_UART2[] = 
{
        {GPIOC, PIN4, 1},
        {GPIOC, PIN5, 1},
}


static const uint8_t GPIOPCTL_UART5[] =
{
    1,  // PE4 (U5Rx)
    1,  // PE5 (U5Tx)
};

static const GpioPctl_t GPIOPCTL_UART2[] = 
{
        {GPIOE, PIN4, 1},
        {GPIOE, PIN5, 1},
}


static const uint8_t GPIOPCTL_UART6[] =
{
    1,  // PD4 (U6Rx)
    1,  // PD5 (U6Tx)
};

static const GpioPctl_t GPIOPCTL_UART2[] = 
{
        {GPIOD, PIN4, 1},
        {GPIOD, PIN5, 1},
}


static const uint8_t GPIOPCTL_UART7[] =
{
    1,  // PE0 (U7Rx)
    1,  // PE1 (U7Tx)
};

static const GpioPctl_t GPIOPCTL_UART2[] = 
{
        {GPIOE, PIN0, 1},
        {GPIOE, PIN1, 1},
}


// I2C
static const uint8_t * GPIOPCTL_I2C_PERIPHERAL_PINS[4] = 
{
    GPIOPCTL_I2C0, GPIOPCTL_I2C1, GPIOPCTL_I2C3, GPIOPCTL_I2C3
};

static const uint8_t GPIOPCTL_I2C0[] =
{
    3,  // PB2 (I2C0SCL)
    3,  // PB3 (I2C0SDA)
};

static const uint8_t GPIOPCTL_I2C1[] =
{
    3,  // PA6 (I2C1SCL)
    3,  // PA7 (I2C1SDA)
};

static const uint8_t GPIOPCTL_I2C2[] =
{
    3,  // PE4 (I2C2SCL)
    3,  // PE5 (I2C2SDA)
};

static const uint8_t GPIOPCTL_I2C3[] =
{
    3,  // PD0 (I2C3SCL)
    3,  // PD1 (I2C3SDA)
};

// SSI
static const uint8_t * GPIOPCTL_SSI_PERIPHERAL_PINS[4] = 
{
    SSI0, SSI1, SSI2, SSI3
}

static const uint8_t GPIOPCTL_SSI0[] =
{
    2,  // PA2 (SSI0Clk)
    2,  // PA3 (SSI0Fss)
    2,  // PA4 (SSI0Rx)
    2,  // PA5 (SSI0Tx)
};

static const uint8_t GPIOPCTL_SSI1[] =
{
    2,  // PD0 (SSI1Clk)
    2,  // PD1 (SSI1Fss)
    2,  // PD2 (SSI1Rx)
    2,  // PD3 (SSI1Tx)
    2,  // PF0 (SSI1Rx)
    2,  // PF1 (SSI1Tx)
    2,  // PF2 (SSI1Clk)
    2,  // PF3 (SSI1Fss)
};

static const uint8_t GPIOPCTL_SSI2[] =
{
    2,  // PB4 (SSI2Clk)
    2,  // PB5 (SSI2Fss)
    2,  // PB6 (SSI2Rx)
    2,  // PB7 (SSI2Tx)
};

static const uint8_t GPIOPCTL_SSI3[] =
{
    1,  // PD0 (SSI3Clk)
    1,  // PD1 (SSI3Fss)
    1,  // PD2 (SSI3Rx)
    1,  // PD3 (SSI3Tx)
};

// USB
static const uint8_t GPIOPCTL_USB0[] =
{
    1,  // PB0 (USB0ID)
    1,  // PB1 (USB0VBUS)
    1,  // PD4 (USB0DM)
    1,  // PD5 (USB0DP)

    9,  // PC6 (USB0EPEN)
    9,  // PD2 (USB0EPEN)
    9,  // PF4 (USB0EPEN)

    9,  // PC7 (USB0PFLT)
    9,  // PD3 (USB0PFLT)
};


// GPIO config functions
void Gpio_configure(GpioPort_t port)
{
	// Set GPIO bus. Just comment for demonstration. Default will always be APB
	// Sysctrl_configure_gpio_bus((Sysctrl_GpioPort_t)port, Sysctrl_bus_t::APB);

	// Enable port
	// Check if already enabled. Need getter
	Sysctrl_configure_gpio_port((Sysctrl_GpioPort_t)port, true);

	return;
}

void Gpio_configure_io(GpioPort_t port, GpioPinChannel_t pin, GpioDirection_t dir)
{
	uint32_t dir_val = ((dir == INPUT)? 1 : 0 ) << pin;
	uint32_t afsel_val = 0 << pin;
	uint32_t drive_val = 1 << pin;
	uint32_t den_val = 1 << pin;
	Gpio_configure(port);

	switch(port)
	{
	case GPIOA:
		GPIOA_RW_REG(GPIODIR) = dir_val;
		GPIOA_RW_REG(GPIOAFSEL) = afsel_val;
		GPIOA_RW_REG(GPIODR4R) = drive_val;
		GPIOA_RW_REG(GPIODEN) = den_val;
		break;
	case GPIOB:
		GPIOB_RW_REG(GPIODIR) = dir_val;
		GPIOB_RW_REG(GPIOAFSEL) = afsel_val;
		GPIOB_RW_REG(GPIODR4R) = drive_val;
                GPIOB_RW_REG(GPIODEN) = den_val;
                break;
	case GPIOC:
		GPIOC_RW_REG(GPIODIR) = dir_val;
		GPIOC_RW_REG(GPIOAFSEL) = afsel_val;
		GPIOC_RW_REG(GPIODR4R) = drive_val;
                GPIOC_RW_REG(GPIODEN) = den_val;
                break;
	case GPIOD:
		GPIOD_RW_REG(GPIODIR) = dir_val;
		GPIOD_RW_REG(GPIOAFSEL) = afsel_val;
		GPIOD_RW_REG(GPIODR4R) = drive_val;
                GPIOD_RW_REG(GPIODEN) = den_val;
                break;
	case GPIOE:
		GPIOE_RW_REG(GPIODIR) = dir_val;
		GPIOE_RW_REG(GPIOAFSEL) = afsel_val;
		GPIOE_RW_REG(GPIODR4R) = drive_val;
                GPIOE_RW_REG(GPIODEN) = den_val;
                break;
	case GPIOF:
		GPIOF_RW_REG(GPIODIR) = dir_val;
		GPIOF_RW_REG(GPIOAFSEL) = afsel_val;
		GPIOF_RW_REG(GPIODR4R) = drive_val;
                GPIOF_RW_REG(GPIODEN) = den_val;
                break;
	}

	return;
}


void Gpio_configure_can(GpioCan_t can_periph);
void Gpio_configure_uart(GpioUart_t uart_periph);
void Gpio_configure_i2c(GpioI2c_t i2c_periph);
void Gpio_configure_ssi(GpioSsi_t ssi_periph);
void Gpio_configure_timer(GpioTimer_t timer_periph);
