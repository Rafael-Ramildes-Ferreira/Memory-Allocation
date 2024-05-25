#ifndef __LINKED_LIST_MMU_H
#define __LINKED_LIST_MMU_H

#include "LinkedList.h"
#include "memoryAllocatedItem.hpp"
#include "allocationMap.hpp"

class LinkedListMMU : public AllocationMap
{
private:
    LinkedList<MemoryAllocatedItem> *list;

public:
    LinkedListMMU();
    LinkedListMMU(LinkedList<MemoryAllocatedItem> *list);

    MemoryAllocatedItem *findNextFreeMemory() override;
    MemoryAllocatedItem *allocateInFreeSpace(MemoryAllocatedItem *memoryToAllocate, MemoryAllocatedItem *freeSpaceToAllocate) override;
    MemoryAllocatedItem *deallocate(unsigned int id) override;
    MemoryAllocatedItem *allocate(unsigned int sizeBytes,unsigned int id, uint32_t  freeSpaceToAllocate) override {return nullptr;};

    LinkedList<MemoryAllocatedItem> *getList();
    void setList(LinkedList<MemoryAllocatedItem> *list);
};

#endif