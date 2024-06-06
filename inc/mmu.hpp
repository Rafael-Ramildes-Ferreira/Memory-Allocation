#ifndef __MMU_H
#define __MMU_H

#include "allocationMap.hpp"
#include "Criterion.h"


class MMU
{
private:
    unsigned int minBlock;
    AllocationMap *allocationMap;
    Criterion *criterion;

public:
    MMU(unsigned int minBlock, AllocationMap *allocationMap, Criterion *criterion);

    unsigned int getMinBlock();
    AllocationMap *getAllocationMap();

    void setMinBlock(unsigned int minBlock);
    void setAllocationMap(AllocationMap *allocationMap);

    bool allocate(unsigned int sizeBytes, unsigned int id);
    void deallocate(unsigned int id);

    void printMemory();
};


#endif