#ifndef __MEMORY_SLOT_H
#define __MEMORY_SLOT_H

#include <cstdint>

/**
 * @brief Holds information on a memory slots so the MMU can decide on which one
 * to allocate
*/
class MemorySlot
{
private:
	uint32_t index;
	unsigned int size;
public:
	MemorySlot(uint32_t index,	unsigned int size);
	~MemorySlot();
	uint32_t get_index();
	unsigned int get_size();
	void set_index(uint32_t _index);
	void set_size(unsigned int _size);
};


#endif