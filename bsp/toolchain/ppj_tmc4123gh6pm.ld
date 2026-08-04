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
		/* Memory is naturally aligned every 4 byte addresses on Cortex-m4 */
		. = ALIGN(4);
		KEEP(*(.isr_vector))
		. = ALIGN(4);
	} > FLASH

	.text :
	{
		. = ALIGN(4);
		*(.text)
		*(.text.*)
		. = ALIGN(4);
	} > FLASH

	.rodata :
	{
		. = ALIGN(4);
		*(.rodata)
		*(.rodata.*)
		. = ALIGN(4);
	} > FLASH

	.preinit_array :
	{
		. = ALIGN(4);

		/* Modern C++ sections */
		KEEP(*(SORT(.preinit_array.*)))
		KEEP(*(.preinit_array))

		. = ALIGN(4);
	} > FLASH

	.init_array :
	{
		. = ALIGN(4);

		/* Modern C++ sections */
		KEEP(*(SORT(.init_array.*)))
		KEEP(*(.init_array))

		. = ALIGN(4);
	} > FLASH

	.fini_array :
	{
		. = ALIGN(4);

		/* Modern C++ sections */
		KEEP(*(SORT(.fini_array.*)))
		KEEP(*(.fini_array))

		. = ALIGN(4);
	} > FLASH

	.ctors :
	{
		. = ALIGN(4);

		/* Older C++ sections */
		KEEP(*(SORT(.ctors.*)))
		KEEP(*(.ctors))

		. = ALIGN(4);
	} > FLASH

	.dtors :
	{
		. = ALIGN(4);

		/* Older C++ sections */
		KEEP(*(SORT(.dtors.*))
		KEEP(*(.dtors))

		. = ALIGN(4);
	} > FLASH

	/* SRAM sections */
	.data :
	{
		. = ALIGN(4);

		/* Pointer to start of data in SRAM*/
		_data_sram_start = .;
		
		*(.data)
		*(.data.*)

		. = ALIGN(4);
		
		/* Pointer to end of data in SRAM*/
		_data_sram_end = .;
	} > SRAM AT > FLASH

	/*  Pointer to .data in FLASH */
	_data_flash_start = LOADADDR(.data);

	.bss (NOLOAD) :
	{
		. = ALIGN(4);

		/* Pointer to start of bss*/
		_bss_start = .;
		*(.bss)
		*(.bss.*)
		
		/* Older section */
		*(COMMON)

		. = ALIGN(4);

		/* Pointer to end of bss*/
		_bss_end = .;
	} > SRAM

	/* AAPCS says procedure calls must be 8 byte aligned */
	. = ALIGN(8);

	/* Start of heap after SRAM sections. Grows upward */
	_heap_start = .;

	. = ALIGN(8);
	/* Start of stack at the end of SRAM. Grows downard */
	_stack_start = ORIGIN(SRAM) + LENGTH(SRAM);

	/* Metadata that isn't required */
	/DISCARD/ :
	{
		*(.comment)
	}
}
