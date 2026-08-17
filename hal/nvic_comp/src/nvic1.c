#include <stdint.h>
#include "nvic1.h"

static inline uint32_t get_reg_offset(Nvic_interrupt_numb_t int_num)
{
	return (int_num >> NVIC_REG_SIZE_DIV);
}

static inline uint32_t get_bit_offset(Nvic_interrupt_numb_t int_num)
{
	return int_num & NVIC_REG_SIZE_MOD;
}

static inline uint32_t get_pri_reg_offset(Nvic_interrupt_numb_t int_num)
{
	return int_num >> NVIC_PRI_REG_SIZE_DIV;
}

static inline uint32_t get_pri_bit_offset(Nvic_interrupt_numb_t int_num)
{
	return ((int_num & NVIC_PRI_REG_SIZE_MOD) << NVIC_PRI_REG_SIZE_MOD_OFFSET);
}

void Nvic_enable_interrupt(Nvic_interrupt_numb_t int_num, Nvic_priority_t priority, bool en)
{
	// NVIC registers are a concatenation of 32-bit fields for each interrupt
	// Divide by 32 to get proper reg offset
	uint32_t reg_offset = get_reg_offset(int_num);
	
	// Find mod 32 to find correct bit offset
	uint32_t bit_offset = get_bit_offset(int_num);

	uint32_t pri_reg_offset = get_pri_reg_offset(int_num);
	uint32_t pri_bit_offset = get_pri_bit_offset(int_num);

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

void Nvic_set_interrupt_pending(Nvic_interrupt_numb_t int_num, bool set)
{
	uint32_t reg_offset = get_reg_offset(int_num);
	uint32_t bit_offset = get_bit_offset(int_num);

	uint32_t pri_reg_offset = get_pri_reg_offset(int_num);
	uint32_t pri_bit_offset = get_pri_bit_offset(int_num);

	if(set)
	{
		NVIC32_RW(PEND0 + reg_offset) |= 1 << bit_offset;
	}
	else
	{
		NVIC32_RW(UNPEND0 + reg_offset) |= 1 << bit_offset;
	}

	return;
}

bool Nvic_is_interrupt_active(Nvic_interrupt_numb_t int_num)
{
	uint32_t reg_offset = get_reg_offset(int_num);
	uint32_t bit_offset = get_bit_offset(int_num);
	uint32_t active_val = (NVIC32_RO(ACTIVE0 + reg_offset) >> bit_offset);
	
	// Use a mask, get the active bit
	active_val &= 1;

	return (active_val == 1 ? true : false);
}
