#ifndef __CRITERION_H
#define __CRITERION_H

#include "MemorySlot.h"

/**
 * @brief Abstract class to define how the MMU access the decition criterion
*/
class Criterion
{
public:
	virtual MemorySlot * choose_slot(MemorySlot * free_mem_list_head);
};


#endif