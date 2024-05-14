#ifndef __CRITERION_H
#define __CRITERION_H

#include "MemorySlot.h"

/**
 * @brief Model class to define how the MMU access the decision criterion
*/
class Criterion
{
public:
	static MemorySlot * choose_slot(MemorySlot * free_mem_list_head, unsigned int size);
};

/**
 * @brief Best fit criterion implementation class
*/
class BestFit
{
public:
	static MemorySlot * choose_slot(MemorySlot * free_mem_list_head, unsigned int size);
};

/**
 * @brief First fit criterion implementation class
*/
class FirstFit
{
public:
	static MemorySlot * choose_slot(MemorySlot * free_mem_list_head, unsigned int size);
};


#endif