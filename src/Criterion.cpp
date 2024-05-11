#include "Criterion.h"


/* Abstract Criterion class --------------------------------------------------*/
/**
 * @brief Virtual function implementation. This function should walk through a
 * MemorySlot list to the choosen one based on a given criterion
 * @param free_mem_list_head: Pointer to the first MemorySlot object
 * @returns Choosen MemorySlot
*/
MemorySlot * Criterion::choose_slot(MemorySlot * free_mem_list_head)
{
	return nullptr;
}