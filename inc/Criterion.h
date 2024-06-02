#ifndef __CRITERION_H
#define __CRITERION_H

#include "memoryAllocatedItem.hpp"

/**
 * @brief Model class to define how the MMU access the decision criterion
*/
class Criterion
{
public:
	static MemoryAllocatedItem * choose_slot(
		MemoryAllocatedItem * free_mem_list_head[],
		unsigned int mem_size
		);
};

/**
 * @brief Best fit criterion implementation class
*/
class BestFit
{
public:
	static MemoryAllocatedItem * choose_slot(
		MemoryAllocatedItem * free_mem_list_head[],
		unsigned int mem_size
		);
};

/**
 * @brief First fit criterion implementation class
*/
class FirstFit
{
public:
	static MemoryAllocatedItem * choose_slot(
		MemoryAllocatedItem * free_mem_list_head[],
		unsigned int mem_size
		);
};


#endif