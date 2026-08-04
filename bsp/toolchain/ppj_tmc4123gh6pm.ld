/* Followed syntax here: https://home.cs.colorado.edu/~main/cs1300/doc/gnu/ld_3.html */
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
		*(.text)
	} > FLASH

	.rodata :
	{
		*(.rodata)
	} > FLASH

	.preinit_array :
	{
		/* Modern C++ sections */
		KEEP(*(SORT(.preinit_array.*)))
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
		KEEP(*(SORT(.fini_array.*)))
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
	.data :
	{
		/* Pointer to start of data in SRAM*/
		_data_sram_start = .;
		
		*(.data)
		
		/* Pointer to end of data in SRAM*/
		_data_sram_end = .;
	} > SRAM AT > FLASH

	/*  Pointer to .data in FLASH */
	_data_flash_start = LOADADDR(.data);

	.bss (NOLOAD) :
	{
		/* Pointer to start of bss*/
		_bss_start = .;
		*(.bss)
		
		/* Older section */
		*(COMMON)

		/* Pointer to end of bss*/
		_bss_end = .;
	} > SRAM

	/* Start of heap after SRAM sections. Grows upward */
	_heap_start = .;

	/* Start of stack at the end of SRAM. Grows downard */
	_stack_start = ORIGIN(SRAM) + LENGTH(SRAM);

	/* Metadata that isn't required */
	/DISCARD/ :
	{
		*(.comment)
	}
}
