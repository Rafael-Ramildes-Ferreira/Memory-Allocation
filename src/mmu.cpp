#include "mmu.hpp"
#include "memoryAllocatedItem.hpp"
#include "MemorySlot.h"
#include "unit_test.h"
#include <cassert>
#include <iostream>


MMU::MMU(unsigned int minBlock, AllocationMap *allocationMap, Criterion *criterion)
{
    this->minBlock = minBlock;
    this->allocationMap = allocationMap;
    this->criterion = criterion;
}

unsigned int MMU::getMinBlock()
{
    return this->minBlock;
}

AllocationMap *MMU::getAllocationMap()
{
    return this->allocationMap;
}

void MMU::setMinBlock(unsigned int minBlock)
{
    this->minBlock = minBlock;
}

void MMU::setAllocationMap(AllocationMap *allocationMap)
{
    this->allocationMap = allocationMap;
}

bool MMU::allocate(unsigned int sizeBytes, unsigned int id)
{
    MemoryAllocatedItem **mem_slot_list = allocationMap->find_free_memory();
    if(mem_slot_list == nullptr){
        // Empty list, no free space
        std::cout << "Lista de livres vazia" << std::endl;
        return false;
    }

    unsigned int sizeToAllocate = sizeBytes-sizeBytes%this->minBlock + (sizeBytes%this->minBlock!=0)*this->minBlock;
    MemoryAllocatedItem *freeSpaceToAllocate = criterion->choose_slot(mem_slot_list,sizeToAllocate);
    if(freeSpaceToAllocate == nullptr){
        // No slot large enough
        std::cout << "Nenhum slot escolhido" << std::endl;
        return false;
    }
    
    MemoryAllocatedItem *memoryToAllocate = new MemoryAllocatedItem(id,1,freeSpaceToAllocate->getStartAddr(), sizeToAllocate);
    this->allocationMap->allocateInFreeSpace(memoryToAllocate, freeSpaceToAllocate);
    return true;
}

void MMU::deallocate(unsigned int id)
{
    this->allocationMap->deallocate(id);
}

void MMU::printMemory(){
    allocationMap->print();
}