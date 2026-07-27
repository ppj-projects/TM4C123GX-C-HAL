#include <stdint.h>

// GPIO base addresses
#define GPIOA_BASE	0x4000'4000U
#define GPIOB_BASE	0x4000'5000U
#define GPIOC_BASE	0x4000'6000U
#define GPIOD_BASE	0x4000'7000U
#define GPIOE_BASE	0x4000'8000U
#define GPIOF_BASE	0x4000'9000U

// Array constants
#define MAX_GPIO_PORTS 6 // 6 GPIO ports

//Post-CMSIS Pointer array memory mapping
typedef struct __atribte__((packed))
{
	// Already 4 bytes apart
	uint32_t GPIODATA;
	// 0x400 - 0x004 = 0x3FC => 1,020
	// 1020 bytes / 4 bytes = 255 indexes
	uint32_t RESERVED1[255];
	uint32_t GPIODIR;
	uint32_t GPIOIS;
	uint32_t GPIOIBE;
	uint32_t GPIOIEV;
	uint32_t GPIOIM;
	uint32_t GPIORIS;
	uint32_t GPIOMIS;
	uint32_t GPIOICR;
	uint32_t GPIOAFSEL;
	// 0x424 ~ 0x500
	// 0x500 - 0x424 = 0xDC => 220
	// 220 bytes / 4 bytes = 55 indexes
	uint32_t RESERVED2[55];
	uint32_t GPIODR2R;
	uint32_t GPIODR4R;
	uint32_t GPIODR8R;
	uint32_t GPIOODR;
	uint32_t GPIOPUR;
	uint32_t GPIOPDR;
	uint32_t GPIOSLR;
	uint32_t GPIOLOCK;
	uint32_t GPIOCR;
	uint32_t GPIOAMSEL;
	uint32_t GPIOPCTL;
	uint32_t GPIOADCCTL;
	uint32_t GPIODMACTL;
}volatile * const Gpio_MapPtr;

static Gpio_MapPtr volatile * const Gpio_port_map[MAX_GPIO_PORTS] = 
{
	(Gpio_MapPtr)(GPIOA_BASE),
	(Gpio_MapPtr)(GPIOB_BASE),
	(Gpio_MapPtr)(GPIOC_BASE),
	(Gpio_MapPtr)(GPIOD_BASE),
	(Gpio_MapPtr)(GPIOE_BASE),
	(Gpio_MapPtr)(GPIOF_BASE)
};

// ...
