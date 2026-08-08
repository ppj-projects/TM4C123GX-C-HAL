#include <stdint.h>
#include "nvic1.h"

void Nvic_enable_interrupt(Nvic_interrupt_numb_t int_num, Nvic_priority_t priority, bool en)
{
	// NVIC registers are a concatenation of 32-bit fields for each interrupt
	// Divide by 32 to get proper reg offset
	uint32_t reg_offset = int_num >> 5;
	
	// Find mod 32 to find correct bit offset
	uint32_t bit_offset = int_num & 0x1F;

	uint32_t pri_reg_offset = int_num >> 2;
	uint32_t pri_bit_offset = (int_num & 0x3) << 4;

	if(en)
	{
		NVIC32_RW(EN0 + reg_offset) |= 1 << bit_offset;
	}
	else
	{
		NVIC32_RW(DIS0 + reg_offset) |= 1 << bit_offset;
		return;
	}

	NVIC32_RW(PRI0 + pri_reg_offset) |= priority << pri_bit_offset;

	return;
}

void Nvic_set_interrupt_pending(int_num, bool set)
{
	uint32_t reg_offset = int_num >> 5;
	uint32_t bit_offset = int_num & 0x1F;

	uint32_t pri_reg_offset = int_num >> 2;
	uint32_t pri_bit_offset = (int_num & 0x3) << 4;

	if(en)
	{
		NVIC32_RW(PEND0 + reg_offset) |= 1 << bit_offset;
	}
	else
	{
		NVIC32_RW(UNPEND0 + reg_offset) |= 1 << bit_offset;
	}

	return;
}

bool Nvic_is_interrupt_active(int_num)
{
	uint32_t reg_offset = int_num >> 5;
	uint32_t bit_offset = int_num & 0x1F;

	return ((NVIC32_RO(ACTIVE0 + reg_offset) >> bit_offset) == 1 ? true : false);
}
