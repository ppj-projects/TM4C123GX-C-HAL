#include <stdint.h>

// GPIO register offsets
#define GPIODATA	0x000U  // rw
#define GPIODIR		0x400U 	// rw
#define GPIOIS 		0x404U 	// rw
#define GPIOIBE 	0x408U 	// rw
#define GPIOIEV 	0x40cU	// rw
#define GPIOIM 		0x410U 	// rw
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
#define GPIOLOCK 	0x520U	// rw
#define GPIOCR 		0x524U	// ro //-- means read only. It only reads back a set of register values once "set"
#define GPIOAMSEL 	0x528U	// rw
#define GPIOPCTL 	0x52cU	// rw
#define GPIOADCCTL 	0x530U  // rw
#define GPIODMACTL 	0x534U  // rw

// Pointer memory mapping
// GPIO base addresses
uint32_t volatile * const GpioA_base = (uint32_t volatile *)0x4000'4000UL;
uint32_t volatile * const GpioB_base = (uint32_t volatile *)0x4000'5000UL;
uint32_t volatile * const GpioC_base = (uint32_t volatile *)0x4000'6000UL;
uint32_t volatile * const GpioD_base = (uint32_t volatile *)0x4000'7000UL;
uint32_t volatile * const GpioE_base = (uint32_t volatile *)0x4000'8000UL;
uint32_t volatile * const GpioF_base = (uint32_t volatile *)0x4000'9000UL;
uint32_t volatile * const GpioG_base = (uint32_t volatile *)0x4000'A000UL;
uint32_t volatile * const GpioH_base = (uint32_t volatile *)0x4000'B000UL;
uint32_t volatile * const GpioH_base = (uint32_t volatile *)0x4000'C000UL;

// GPIO register addres
// Two styles used, just for demonstration. Use either
uint32_t volatile * const GpioA_Gpiodata1 = &GpioA_base[GPIODATA / sizeof(uint32_t)];
uint32_t volatile * const GpioA_Gpiodata2 = (GpioA_base + (GPIODATA / sizeof(uint32_t)));

uint32_t volatile * const GpioA_Gpiodir1 = &GpioA_base[GPIODIR / sizeof(uint32_t)];
uint32_t volatile * const GpioA_Gpiodir2 = (GpioA_base + (GPIODIR / size(uint32_t)));

uint32_t volatile * const GpioA_Gpiois1 = &GpioA_base[GPIOIS / sizeof(uint32_t)];
uint32_t volatile * const GpioA_Gpiois2 = (GpioA_base + (GPIOIS / sizeof(uint32_t)));

uint32_t volatile * const GpioA_Gpioibe1 = &GpioA_base[GPIOIBE / sizeof(uint32_t)];
uint32_t volatile * const GpioA_Gpioibe2 = (GpioA_base + (GPIOIBE / sizeof(uint32_t)));

uint32_t volatile * const GpioA_Gpioiev1 = &GpioA_base[GPIOIVE / sizeof(uint32_t)];
uint32_t volatile * const GpioA_Gpioiev2 = (GpioA_base + (GPIOIVE / sizeof(uint32_t)));

uint32_t volatile * const GpioA_Gpioim1 = &GpioA_base[GPIOIM / sizeof(uint32_t)];
uint32_t volatile * const GpioA_Gpioim2 = (GpioA_base + (GPIOIM / sizeof(uint32_t)));

uint32_t volatile * const GpioA_Gpioirs1 = &GpioA_base[GPIOIRS / sizeof(uint32_t)];
uint32_t volatile * const GpioA_Gpioirs2 = (GpioA_base + (GPIOIRS / sizeof(uint32_t)));

uint32_t volatile * const GpioA_Gpiomis1 = &GpioA_base[GPIOIMS / sizeof(uint32_t)];
uint32_t volatile * const GpioA_Gpiomis2 = (GpioA_base + (GPIOMIS / sizeof(uint32_t)));
//....

