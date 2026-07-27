#include <stdint.h>

// Struct Memory Mapping

// GPIO base addresses
#define GPIOA_BASE	0x4000'4000U
#define GPIOB_BASE	0x4000'5000U
#define GPIOC_BASE 	0x4000'6000U
#define GPIOD_BASE	0x4000'7000U
#define GPIOE_BASE	0x4000'8000U
#define GPIOF_BASE	0x4000'9000U

// Gpio register map
typedef struct __attribute__((packed))
{
	uint32_t GPIODATA;
	//0x400 - 0x004 = 0x3FC => 1,020
	// 1020 bytes / 4 bytes = 255 indexes
	uint32_t RESERVED1[255];
	uint32_t GPIODIR;	//0x400U 	// rw
	uint32_t GPIOIS;			//0x404U 	// rw
	uint32_t GPIOIBE; 	//0x408U 	// rw
	uint32_t GPIOIEV; 	//0x40cU	// rw
	uint32_t GPIOIM;	//0x410U 	// rw
	uint32_t GPIORIS; 	//0x414U	// ro
	uint32_t GPIOMIS;	//0x418U	// ro
	uint32_t GPIOICR;	//0x41cU	// rw
	uint32_t GPIOAFSEL; 	//0x420U 	// rw
	// (0x500 - 0x424) / 4 (bytes) => index
	uint32_t RESERVED2[55];	//0x424 ~ 0x4FF
	uint32_t GPIODR2R; 	//0x500U	// rw
	uint32_t GPIODR4R; 	//0x504U	// rw
	uint32_t GPIODR8R; 	//0x508U	// rw
	uint32_t GPIOODR; 	//0x50cU	// rw
	uint32_t GPIOPUR; 	//0x510U	// rw
	uint32_t GPIOPDR; 	//0x514U	// rw
	uint32_t GPIOSLR; 	//0x518U	// rw
	uint32_t GPIOLOCK; 	//0x520U	// rw
	uint32_t GPIOCR; 	//0x524U	// ro //-- means read only. It only reads back a set of register values once "set"
	uint32_t GPIOAMSEL; 	//0x528U	// rw
	uint32_t GPIOPCTL; 	//0x52cU	// rw
	uint32_t GPIOADCCTL; 	//0x530U	// rw
	uint32_t GPIODMACTL; 	//0x534U	// rw
}volatile * const Gpio_MapPtr;

Gpio_MapPtr GpioA = ((Gpio_MapPtr)GPIOA_BASE);
Gpio_MapPtr GpioB = ((Gpio_MapPtr)GPIOB_BASE);
Gpio_MapPtr GpioC = ((Gpio_MapPtr)GPIOC_BASE);
Gpio_MapPtr GpioD = ((Gpio_MapPtr)GPIOD_BASE);
Gpio_MapPtr GpioE = ((Gpio_MapPtr)GPIOE_BASE);
Gpio_MapPtr GpioF = ((Gpio_MapPtr)GPIOF_BASE);
