#ifndef __ALLOCATION_MAP_H
#define __ALLOCATION_MAP_H

#include "memoryAllocatedItem.hpp"
#include "MemorySlot.h"

class AllocationMap
{
protected:
    // Variável de instância protegida
    unsigned int currentIndex;

public:
    // Construtor
    AllocationMap() : currentIndex(0) {}

    // Destrutor virtual
    virtual ~AllocationMap() {}

    // Função puramente virtual (método abstrato)
    virtual MemoryAllocatedItem *findNextFreeMemory() {return nullptr;};

    // Função puramente virtual (método abstrato)
    virtual MemoryAllocatedItem *allocateInFreeSpace(MemoryAllocatedItem *memoryToAllocate, MemoryAllocatedItem *freeSpaceToAllocate) {return nullptr;};

    // Função puramente virtual (método abstrato)
    virtual MemoryAllocatedItem *deallocate(unsigned int id) {return nullptr;};

    virtual MemoryAllocatedItem *allocate(unsigned int sizeBytes,unsigned int id, uint32_t  freeSpaceToAllocate) {return nullptr;};

    // Getter para currentIndex
    unsigned int getCurrentIndex() const
    {
        return currentIndex;
    }

    // Setter para currentIndex
    void setCurrentIndex(unsigned int index)
    {
        currentIndex = index;
    }

    virtual MemorySlot *find_free_memory() {return nullptr;}

    virtual void print(void) {};
};

#endif