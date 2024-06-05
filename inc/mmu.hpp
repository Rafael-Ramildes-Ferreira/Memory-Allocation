#ifndef __MMU_H
#define __MMU_H

#include "allocationMap.hpp"

template<typename T>
class MMU
{
private:
    unsigned int minBlock;
    AllocationMap *allocationMap;
    T criterion;

public:
    MMU(unsigned int minBlock, AllocationMap *allocationMap);

    unsigned int getMinBlock();
    AllocationMap *getAllocationMap();

    void setMinBlock(unsigned int minBlock);
    void setAllocationMap(AllocationMap allocationMap);

    bool allocate(unsigned int sizeBytes, unsigned int id);
    void deallocate(unsigned int id);

    void printMemory();
};

#include "mmu.tpp"

#endif