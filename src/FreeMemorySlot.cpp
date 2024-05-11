#include "FreeMemorySlot.h"

FreeMemorySlot::FreeMemorySlot(uint32_t index,	unsigned int size)
{
		this->index = index;
		this->size = size;
}

FreeMemorySlot::~FreeMemorySlot()
{
}

uint32_t FreeMemorySlot::get_index()
{
	return this->index;
}

unsigned int FreeMemorySlot::get_size()
{
	return this->size;
}

void FreeMemorySlot::set_index(uint32_t index)
{
	this->index = index;
}

void FreeMemorySlot::set_size(unsigned int size)
{
	this->size = size;
}