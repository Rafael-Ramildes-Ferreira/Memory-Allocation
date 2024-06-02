#ifndef __MMU_H
#define __MMU_H

#include "allocationMap.hpp"
enum allocation_algorithm {AA_INVALID, BEST_FIT, FIRST_FIT};

template<typename T>
class MMU
{
private:
    unsigned int minBlock;
    allocation_algorithm algorithm;
    AllocationMap *allocationMap;
    T criterion;

public:
    MMU(unsigned int minBlock, allocation_algorithm algorithm, AllocationMap *allocationMap);

    unsigned int getMinBlock();
    allocation_algorithm getAlgorithm();
    AllocationMap *getAllocationMap();

    void setMinBlock(unsigned int minBlock);
    void setAlgorithm(allocation_algorithm algorithm);
    void setAllocationMap(AllocationMap allocationMap);

    bool allocate(unsigned int sizeBytes, unsigned int id);
    void deallocate(unsigned int id);

    void printMemory();
};

#include "mmu.tpp"

#endif