#ifndef __LINKED_LIST_MMU_H
#define __LINKED_LIST_MMU_H

#include "LinkedList.h"
#include "memoryAllocatedItem.hpp"
#include "allocationMap.hpp"


#define MAXIMUM_FREE_SLOTS 1000

class LinkedListMMU : public AllocationMap
{
private:
    LinkedList<MemoryAllocatedItem> *list;
    unsigned int memSize;
    unsigned int minBlockSize;
    
public:
    LinkedListMMU(unsigned int memSize, unsigned int minBlockSize);
    LinkedListMMU(LinkedList<MemoryAllocatedItem> *list);

    MemoryAllocatedItem *findNextFreeMemory() override;
    MemoryAllocatedItem *allocateInFreeSpace(MemoryAllocatedItem *memoryToAllocate, MemoryAllocatedItem *freeSpaceToAllocate) override;
    MemoryAllocatedItem *deallocate(unsigned int id) override;
    MemoryAllocatedItem **find_free_memory(void) override;

    LinkedList<MemoryAllocatedItem> *getList();
    void setList(LinkedList<MemoryAllocatedItem> *list);

    void print(void) override;
};

#endif