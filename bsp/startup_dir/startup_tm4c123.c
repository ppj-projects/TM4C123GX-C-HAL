#include <stdint.h>

// Placing forward declarations for these
void init_bss();
void init_static_data();
void init_init_array();
void init_ctors();

void startup()
{
	// Initialize oscillators. Here?
	cpu_clock_init()

	// Initialize non-initialized variables
	init_bss();

	// Initialize statics and globals
	init_static_data();

	// Initialize constructor
	init_preinit_array();
	init_init_array();
	init_ctors();

	// Start main
	main();
}


// 32 bit memory access guaranteed to be safe by AAPCS's 4 byte address alignment
// in linker script
extern uint32_t _bss_start;
extern uint32_t _bss_end;

void init_bss()
{
	// Zero-ize the bss section
	for(uint32_t* bss_entry = &_bss_start; bss_entry < &_bss_end; bss_entry++)
	{
		*bss_entry = 0;
	}
}


extern uint32_t _data_sram_start;
extern uint32_t _data_sram_end;
extern uint32_t _data_flash_start;

void init_static_data()
{
	uint32_t* data_sram_entry = &_data_sram_start;
	uint32_t* data_flash_entry = &_data_flash_start;
	while( data_sram_entry < &_data_sram_end)
	{
		*data_sram_entry++ = *data_flash_entry++;
	}
}

typedef void (*Preinit_array_t)(void);
extern Preinit_array_t _preinit_start;
extern Preinit_array_t _preinit_end;

void init_preinit_array()
{
	for(Preinit_array_t* preinit_entry = &_preinit_start ; preinit_entry < &_preinit_end; preinit_entry++)
	{
		(*preinit_entry)();
	}
}

typedef void (*Init_array_t)(void);
extern Init_array_t _init_array_start;
extern Init_array_t _init_array_end;

void init_init_array()
{
	for(Init_array_t* init_array_entry = &_init_array_start; init_array_entry < &_init_array_end; init_array_entry++)
	{
		(*init_array_entry)();
	}
}

typedef void (*Ctors_t)(void);
extern Ctors_t _ctors_start;
extern Ctors_t _ctors_end;

void init_ctors()
{
	for(Ctors_t* ctor_entry = &_ctors_start; ctor_entry < &_ctors_end; ctor_entry++)
	{
		(*ctor_entry)();
	}
}


