// Direct Memory Mapping
#define HWREG32_RW(x) (*((uint32_t volatile *)(x)))
#define HWREG32_RO(x) (*((uint32_t volatile const *)(x)))

// GPIO base addresses
#define GPIOA_BASE	0x4000'4000U
#define GPIOB_BASE	0x4000'5000U
#define GPIOC_BASE	0x4000'6000U
#define GPIOD_BASE	0x4000'7000U
#define GPIOE_BASE	0x4000'8000U
#define GPIOF_BASE	0x4000'9000U

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
