/* Map memory regions */
MEMORY
{
	FLASH (rx) : ORIGIN = 0x00000000, LENGTH = 256K

	/* No x unless there is a .ramfunc section */
	SRAM (rw) : ORIGIN = 0x20000000, LENGTH = 32K
}

/* Map sections to executable */
SECTIONS
{
	/* FLASH sections */
	.isr_vector : 
	{
		KEEP(*(.isr_vector))
	} > FLASH

	.text :
	{
		KEEP(*(.text))
	} > FLASH

	.rodata :
	{
		KEEP(*(.rodata))
	} > FLASH

	.preinit_array :
	{
		/* Modern C++ sections */
		KEEP(*(SORT(.preinit_array.*))
		KEEP(*(.preinit_array))
	} > FLASH

	.init_array :
	{
		/* Modern C++ sections */
		KEEP(*(SORT(.init_array.*)))
		KEEP(*(.init_array))
	} > FLASH

	.fini_array :
	{
		/* Modern C++ sections */
		KEEP(*(SORT(.fini_array.*))
		KEEP(*(.fini_array))
	} > FLASH

	.ctors :
	{
		/* Older C++ sections */
		KEEP(*(SORT(.ctors.*)))
		KEEP(*(.ctors))
	} > FLASH

	.dtors :
	{
		/* Older C++ sections */
		KEEP(*(SORT(.dtors.*))
		KEEP(*(.dtors))
	} > FLASH

	/* SRAM sections */
	.data (NOLOAD):
	{
		/* Pointer to start of data*/
		_data_start = .;
		
		KEEP(*(.data))
		
		/* Pointer to end of data */
		_data_end = .;
	} > SRAM AT > FLASH

	.bss :
	{
		/* Pointer to start of bss*/
		_bss_start = .;
		KEEP(*(.bss))
		
		/* Older section */
		KEEP(*(COMMON))

		/* Pointer to end of bss*/
		_bss_end = .;
	} > SRAM
}
