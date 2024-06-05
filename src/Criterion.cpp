#include "Criterion.h"
#include <iostream>


/* Model Criterion class -----------------------------------------------------*/
/**
 * @brief Example function implementation. This function should walk through a
 * MemoryAllocatedItem list to the choosen one based on a given criterion
 * @param free_mem_list_head: Pointer to the first MemoryAllocatedItem object
 * @returns Choosen MemoryAllocatedItem
*/
MemoryAllocatedItem * Criterion::choose_slot(
		MemoryAllocatedItem ** free_mem_list_head,
		unsigned int mem_size
		)
{
	return nullptr;
}

/* Best Fit Criterion class -----------------------------------------------------*/
/**
 * @brief Walk through a MemoryAllocatedItem list to the choosen the best fit
 * @param free_mem_list_head: Pointer to the first MemoryAllocatedItem object
 * @returns Choosen MemoryAllocatedItem
*/
MemoryAllocatedItem * BestFit::choose_slot(
		MemoryAllocatedItem * free_mem_list_head[], 
		unsigned int mem_size
		)
{
	MemoryAllocatedItem * bestfit = nullptr;
	for(int i = 0; free_mem_list_head[i] != nullptr; i++){
		if(	free_mem_list_head[i]->getSizeBytes() >= mem_size)
		{
			if (bestfit == nullptr)
			{
				bestfit = free_mem_list_head[i];
			}
			else if(free_mem_list_head[i]->getSizeBytes() < bestfit->getSizeBytes())
			{
				bestfit = free_mem_list_head[i];
			}
		}
	}
	return bestfit;
}

/* First Fit Criterion class -----------------------------------------------------*/
/**
 * @brief Walk through a MemoryAllocatedItem list to the choosen the first fit
 * @param free_mem_list_head: Pointer to the first MemoryAllocatedItem object
 * @returns Choosen MemoryAllocatedItem
*/
MemoryAllocatedItem * FirstFit::choose_slot(
		MemoryAllocatedItem ** free_mem_list_head,
		unsigned int mem_size
		)
{
	for(int i = 0; free_mem_list_head[i] != nullptr; i++){
		std::cout << "(free_mem_list_head[i] == nullptr): " << (free_mem_list_head[i] == nullptr) << std::endl;
		if(free_mem_list_head[i]->getSizeBytes() >= mem_size) return free_mem_list_head[i];
	}
	return nullptr;  // No available memory slot
}