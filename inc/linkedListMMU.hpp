#ifndef __LINKED_LIST_MMU_H
#define __LINKED_LIST_MMU_H

#include "doubly_linked_list.h"
#include "memoryAllocatedItem.hpp"
#include "allocationMap.hpp"

class LinkedListMMU : public AllocationMap
{
private:
    structures::DoublyLinkedList<MemoryAllocatedItem *> *list;

public:
    LinkedListMMU();
    LinkedListMMU(structures::DoublyLinkedList<MemoryAllocatedItem *> *list);

    MemoryAllocatedItem *findNextFreeMemory() override;
    MemoryAllocatedItem *allocateInFreeSpace(MemoryAllocatedItem *memoryToAllocate, MemoryAllocatedItem *freeSpaceToAllocate) override;
    MemoryAllocatedItem *deallocate(unsigned int id) override;

    structures::DoublyLinkedList<MemoryAllocatedItem *> *getList();
    void setList(structures::DoublyLinkedList<MemoryAllocatedItem *> *list);
};

#endif