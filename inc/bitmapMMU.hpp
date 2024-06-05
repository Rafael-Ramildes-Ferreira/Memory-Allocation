#ifndef __BITMAP_MMU_H
#define __BITMAP_MMU_H

#include "LinkedList.h"
#include "memoryAllocatedItem.hpp"
#include "allocationMap.hpp"

class BitmapMMU : public AllocationMap
{
private:
    LinkedList<MemoryAllocatedItem> *list;
    unsigned int memSize, minBlockSize;
    bool *bitmap;

public:
    BitmapMMU(unsigned int memSize, unsigned int minBlockSize);
    BitmapMMU(LinkedList<MemoryAllocatedItem> *list, bool *bitmap);

    MemoryAllocatedItem *findNextFreeMemory() override;
    MemoryAllocatedItem *allocateInFreeSpace(MemoryAllocatedItem *memoryToAllocate, MemoryAllocatedItem *freeSpaceToAllocate) override;
    MemoryAllocatedItem *deallocate(unsigned int id) override;
    MemoryAllocatedItem **find_free_memory(void) override;

    LinkedList<MemoryAllocatedItem> *getList();
    void setList(LinkedList<MemoryAllocatedItem> *list);

    // bool *getBitmap();
    // void setBitmap(bool *bitmap);

    void print(void) override;
};

#endif