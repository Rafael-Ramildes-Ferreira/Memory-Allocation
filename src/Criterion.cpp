#include "Criterion.h"


/* Model Criterion class -----------------------------------------------------*/
/**
 * @brief Example function implementation. This function should walk through a
 * MemorySlot list to the choosen one based on a given criterion
 * @param free_mem_list_head: Pointer to the first MemorySlot object
 * @returns Choosen MemorySlot
*/
MemorySlot * Criterion::choose_slot(
		MemorySlot * free_mem_list_head, 
		unsigned int list_size, 
		unsigned int mem_size
		)
{
	return nullptr;
}

/* Best Fit Criterion class -----------------------------------------------------*/
/**
 * @brief Walk through a MemorySlot list to the choosen the best fit
 * @param free_mem_list_head: Pointer to the first MemorySlot object
 * @returns Choosen MemorySlot
*/
MemorySlot * BestFit::choose_slot(
		MemorySlot * free_mem_list_head, 
		unsigned int list_size, 
		unsigned int mem_size
		)
{
	MemorySlot * bestfit = nullptr;
	for(int i = 0; i < list_size; i++){
		if(	free_mem_list_head[i].get_size() >= mem_size)
		{
			if (bestfit == nullptr)
			{
				bestfit = &free_mem_list_head[i];
			}
			else if(free_mem_list_head[i].get_size() < bestfit->get_size())
			{
				bestfit = &free_mem_list_head[i];
			}
		}
	}
	return bestfit;
}

/* First Fit Criterion class -----------------------------------------------------*/
/**
 * @brief Walk through a MemorySlot list to the choosen the first fit
 * @param free_mem_list_head: Pointer to the first MemorySlot object
 * @returns Choosen MemorySlot
*/
MemorySlot * FirstFit::choose_slot(
		MemorySlot * free_mem_list_head, 
		unsigned int list_size, 
		unsigned int mem_size
		)
{
	for(int i = 0; i < list_size; i++){
		if(free_mem_list_head[i].get_size() >= mem_size) return &free_mem_list_head[i];
	}
	return nullptr;  // No available memory slot
}