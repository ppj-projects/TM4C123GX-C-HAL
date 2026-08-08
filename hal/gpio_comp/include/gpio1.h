#ifndef GPIO1_COMP_H
#define GPIO1_COMP_H

// Memory access 
// Direct Memory Mapping
#define HWREG32_RW(x) (*((uint32_t volatile *)(x)))
#define HWREG32_RO(x) (*((uint32_t volatile const *)(x)))

// GPIO base addresses
#define GPIO_BASE_OFFSET	0x1000U
#define GPIOA_BASE		0x40004000U
#define GPIOB_BASE		(GPIOA_BASE + GPIO_BASE_OFFSET)
#define GPIOC_BASE		(GPIOB_BASE + GPIO_BASE_OFFSET)
#define GPIOD_BASE		(GPIOB_BASE + GPIO_BASE_OFFSET)
#define GPIOE_BASE		(GPIOB_BASE + GPIO_BASE_OFFSET)
#define GPIOF_BASE		(GPIOB_BASE + GPIO_BASE_OFFSET)

// GPIO register offsets
#define GPIODATA	0x000U  // rw
#define GPIODIR	0x400U 	// rw
#define GPIOIS 	0x404U 	// rw
#define GPIOIBE 	0x408U 	// rw
#define GPIOIEV 	0x40cU	// rw
#define GPIOIM 	0x410U 	// rw
#define GPIORIS 	0x414U	// ro
#define GPIOMIS 	0x418U	// ro
#define GPIOICR 	0x41cU	// rw
#define GPIOAFSEL 	0x420U 	// rw
#define GPIODR2R 	0x500U	// rw
#define GPIODR4R 	0x504U	// rw
#define GPIODR8R 	0x508U	// rw
#define GPIOODR 	0x50cU	// rw
#define GPIOPUR 	0x510U	// rw
#define GPIOPDR 	0x514U	// rw
#define GPIOSLR 	0x518U	// rw
#define GPIODEN     	0x51C   // rw
#define GPIOLOCK 	0x520U	// rw
#define GPIOCR 	0x524U	// ro //-- means read only. It only reads back a set of register values once "set"
#define GPIOAMSEL 	0x528U	// rw
#define GPIOPCTL 	0x52cU	// rw
#define GPIOADCCTL 	0x530U  // rw
#define GPIODMACTL 	0x534U  // rw

// GPIO access
#define GPIOA_RW_REG(x) HWREG32_RW((GPIOA_BASE) + (x))
#define GPIOA_RO_REG(x) HWREG32_RO((GPIOA_BASE) + (x))
#define GPIOB_RW_REG(x) HWREG32_RW((GPIOB_BASE) + (x))
#define GPIOB_RO_REG(x) HWREG32_RO((GPIOB_BASE) + (x))
#define GPIOC_RW_REG(x) HWREG32_RW((GPIOC_BASE) + (x))
#define GPIOC_RO_REG(x) HWREG32_RO((GPIOC_BASE) + (x))
#define GPIOD_RW_REG(x) HWREG32_RW((GPIOD_BASE) + (x))
#define GPIOD_RO_REG(x) HWREG32_RO((GPIOD_BASE) + (x))
#define GPIOE_RW_REG(x) HWREG32_RW((GPIOE_BASE) + (x))
#define GPIOE_RO_REG(x) HWREG32_RO((GPIOE_BASE) + (x))
#define GPIOF_RW_REG(x) HWREG32_RW((GPIOF_BASE) + (x))
#define GPIOF_RO_REG(x) HWREG32_RO((GPIOF_BASE) + (x))

// GPIO Peripheral enums
// Different available AFs
typedef enum
{
	IO,
	CAN,
	UART,
	I2C,
	SSI,
	PWM,
	TIMER,
	USB
}GpioAF_t;

// Different available IOs
typedef enum
{
	GPIOA,
	GPIOB,
	GPIOC,
	GPIOD,
	GPIOE,
	GPIOF,
	MAX_GPIO_PORTS
}GpioPort_t;

typedef enum
{
    PIN0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7,
	MAX_GPIO_PIN_CHANNELS
}GpioPinChannel_t;

typedef enum
{
	INPUT,
	OUTPUT,
}GpioDirection_t;

typedef enum
{
	PULLUP,
	PULLDOWN,
	PUSH,
	PULL,
	OPENDRAIN
}GpioIoPadConfig_t;

typedef enum
{
	TWO,
	FOUR,
	EIGHT
}GpioCurrentStrength_t;

// Different available CANs
typedef enum
{
   	CAN0,
   	CAN1,
   	CAN2
}GpioCan_t;

// Different available UARTs
typedef enum
{
	UART0,
	UART1,
	UART2,
	UART3,
	UART4,
	UART5,
	UART6,
	UART7
}GpioUart_t;

// Different available I2Cs
typedef enum
{
	I2C0,
	I2C1,
	I2C2,
	I2C3
}GpioI2c_t;

// Different available SSIs
typedef enum
{
	SSI0,
	SSI1,
	SSI2,
	SSI3,
}GpioSsi_t;

// Different available Timers
typedef enum
{
	TIMER0,
	TIMER1,
	TIMER2,
	TIMER3,
	TIMER4,
	TIMER5
}GpioTimer_t;

// Port, pin, and pin control information needed for AF
typedef struct  __attribute__((packed))
{
	GpioPort_t port;
	GpioPinChannel_t pin;
	uint8_t pctl_val;
}GpioPctl_t;

// GPIO config functions
void Gpio_configure(GpioPort_t port);

void Gpio_configure_io(GpioPort_t port, GpioPinChannel_t pin, GpioDirection_t dir);
void Gpio_configure_can(GpioCan_t can_periph);
void Gpio_configure_uart(GpioUart_t uart_periph);
void Gpio_configure_i2c(GpioI2c_t i2c_periph);
void Gpio_configure_ssi(GpioSsi_t ssi_periph);
void Gpio_configure_timer(GpioTimer_t timer_periph);

// Application layer ISR callback registration
typedef void* Gpiocb_data;
typedef void (*Gpiocb_t)(void*);
void Gpio_register_callback(GpioPort_t port, GpioPinChannel_t pin, Gpiocb_t callback, Gpiocb_data data);

#endif
