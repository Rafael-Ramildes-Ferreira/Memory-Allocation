#include "Criterion.h"


/* Model Criterion class -----------------------------------------------------*/
/**
 * @brief Example function implementation. This function should walk through a
 * MemorySlot list to the choosen one based on a given criterion
 * @param free_mem_list_head: Pointer to the first MemorySlot object
 * @returns Choosen MemorySlot
*/
MemorySlot * Criterion::choose_slot(MemorySlot * free_mem_list_head, unsigned int size)
{
	return nullptr;
}

/* Best Fit Criterion class -----------------------------------------------------*/
/**
 * @brief Walk through a MemorySlot list to the choosen the best fit
 * @param free_mem_list_head: Pointer to the first MemorySlot object
 * @returns Choosen MemorySlot
*/
MemorySlot * BestFit::choose_slot(MemorySlot * free_mem_list_head, unsigned int size)
{
	return nullptr;
}

/* First Fit Criterion class -----------------------------------------------------*/
/**
 * @brief Walk through a MemorySlot list to the choosen the first fit
 * @param free_mem_list_head: Pointer to the first MemorySlot object
 * @returns Choosen MemorySlot
*/
MemorySlot * FirstFit::choose_slot(MemorySlot * free_mem_list_head, unsigned int size)
{
	return nullptr;
}