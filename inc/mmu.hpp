#ifndef __MMU_H
#define __MMU_H

#include "allocationMap.hpp"
enum Algorithm
{
    bestFit,
    firstFit,
    worstFit,
    circular
};

class MMU
{
private:
    unsigned int minBlock;
    Algorithm algorithm;
    AllocationMap allocationMap;

public:
    MMU(unsigned int minBlock, Algorithm algorithm, AllocationMap allocationMap);

    unsigned int getMinBlock();
    Algorithm getAlgorithm();
    AllocationMap getAllocationMap();

    void setMinBlock(unsigned int minBlock);
    void setAlgorithm(Algorithm algorithm);
    void setAllocationMap(AllocationMap allocationMap);

    bool allocate(unsigned int sizeBytes, unsigned int id);
    void deallocate(unsigned int id);
};

#endif