#include <stdint.h>

typedef struct
{
	// For array indexing
	uint32_t GpioPort;
	// For bit shifting for pins into registers
	uint32_t GpioPin;

	// Actual configuration
	uint32_t GpioDirection;
	uint32_t GpioIoPadConfig;
	uint32_t GpioCurrentStrength;
}GpioConfig_t;

// For indexing
typedef enum
{
	GPIOA,
	GPIOB,
	GPIOC,
	GPIOD,
	GPIOE,
	GPIOF,
	MAX_GPIO_PORTS
}GpioPor_t;

// For bit shifting for pins into registers
typedef enum
{
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7,
	MAX_GPIO_PIN_CHANNELS
}GpioPinChannels_t;


// For configuration checking
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

const GpioConfig_t* Gpio_Getconfig1(void);
