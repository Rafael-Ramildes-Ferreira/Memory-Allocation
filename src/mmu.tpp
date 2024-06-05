#include "mmu.hpp"
#include "memoryAllocatedItem.hpp"
#include "MemorySlot.h"
#include "unit_test.h"
#include <cassert>
#include <iostream>

template<typename T>
MMU<T>::MMU(unsigned int minBlock, AllocationMap *allocationMap)
{
    // Tests if the chosen criterion has choose_slot method
	static_assert(has_choose_slot<T>::value);

    // TODO Verificar se o minBlock usa no método de LinkedList, pois não estou usando...
    this->minBlock = minBlock;
    this->allocationMap = allocationMap;
}

template<typename T>
unsigned int MMU<T>::getMinBlock()
{
    return this->minBlock;
}

template<typename T>
AllocationMap *MMU<T>::getAllocationMap()
{
    return this->allocationMap;
}

template<typename T>
void MMU<T>::setMinBlock(unsigned int minBlock)
{
    this->minBlock = minBlock;
}

template<typename T>
void MMU<T>::setAllocationMap(AllocationMap allocationMap)
{
    this->allocationMap = allocationMap;
}

template<typename T>
bool MMU<T>::allocate(unsigned int sizeBytes, unsigned int id)
{
    MemoryAllocatedItem **mem_slot_list = allocationMap->find_free_memory();
    if(mem_slot_list == nullptr){
        // Empty list, no free space
        return false;
    }

    unsigned int sizeToAllocate = sizeBytes-sizeBytes%this->minBlock + (sizeBytes%this->minBlock!=0)*this->minBlock;
    MemoryAllocatedItem *freeSpaceToAllocate = criterion.choose_slot(mem_slot_list,sizeToAllocate);
    if(freeSpaceToAllocate == nullptr){
        // No slot large enough
        return false;
    }
    
    MemoryAllocatedItem *memoryToAllocate = new MemoryAllocatedItem(id,1,freeSpaceToAllocate->getStartAddr(), sizeToAllocate);
    this->allocationMap->allocateInFreeSpace(memoryToAllocate, freeSpaceToAllocate);
    return true;
}

template<typename T>
void MMU<T>::deallocate(unsigned int id)
{
    this->allocationMap->deallocate(id);
}

template<typename T>
void MMU<T>::printMemory(){
    allocationMap->print();
}