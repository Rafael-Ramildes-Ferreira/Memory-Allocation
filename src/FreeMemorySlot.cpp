#include "MemorySlot.h"

MemorySlot::MemorySlot(uint32_t index,	unsigned int size)
{
		this->index = index;
		this->size = size;
}

MemorySlot::~MemorySlot()
{
}

uint32_t MemorySlot::get_index()
{
	return this->index;
}

unsigned int MemorySlot::get_size()
{
	return this->size;
}

void MemorySlot::set_index(uint32_t index)
{
	this->index = index;
}

void MemorySlot::set_size(unsigned int size)
{
	this->size = size;
}