#include "mmu.hpp"
#include "memoryAllocatedItem.hpp"

MMU::MMU(unsigned int minBlock, Algorithm algorithm, AllocationMap allocationMap)
{
    // TODO Verificar se o minBlock usa no método de LinkedList, pois não estou usando...
    this->minBlock = minBlock;
    this->algorithm = algorithm;
    this->allocationMap = allocationMap;
}

unsigned int MMU::getMinBlock()
{
    return this->minBlock;
}

Algorithm MMU::getAlgorithm()
{
    return this->algorithm;
}

AllocationMap MMU::getAllocationMap()
{
    return this->allocationMap;
}

void MMU::setMinBlock(unsigned int minBlock)
{
    this->minBlock = minBlock;
}

void MMU::setAlgorithm(Algorithm algorithm)
{
    this->algorithm = algorithm;
}

void MMU::setAllocationMap(AllocationMap allocationMap)
{
    this->allocationMap = allocationMap;
}

bool MMU::allocate(unsigned int sizeBytes, unsigned int id)
{
    if (this->algorithm != circular)
    {
        this->allocationMap.setCurrentIndex(0);
    }
    MemoryAllocatedItem *freeSpaceToAllocate = nullptr;
    while (true)
    {
        auto freeSpace = this->allocationMap.findNextFreeMemory();
        if (freeSpace == nullptr)
        {
            break;
        }
        else if (freeSpace->getSizeBytes() == sizeBytes)
        {
            freeSpaceToAllocate = freeSpace;
            break;
        }
        else if (freeSpace->getSizeBytes() > sizeBytes)
        {
            switch (this->algorithm)
            {
            case firstFit:
            case circular:
                freeSpaceToAllocate = freeSpace;
                goto returnFreeSpaceToAllocate;
            case bestFit:
                if (freeSpaceToAllocate == nullptr || freeSpaceToAllocate->getSizeBytes() > freeSpace->getSizeBytes())
                {
                    freeSpaceToAllocate = freeSpace;
                }
                break;
            case worstFit:
                if (freeSpaceToAllocate == nullptr || freeSpaceToAllocate->getSizeBytes() < freeSpace->getSizeBytes())
                {
                    freeSpaceToAllocate = freeSpace;
                }
                break;
            }
        }
    }
returnFreeSpaceToAllocate:
    if (freeSpaceToAllocate == nullptr)
    {
        return false;
    }
    else
    {
        // TODO Ver se está correto isso aqui: freeSpaceToAllocate->getStartAddr()
        auto memoryToAllocate = new MemoryAllocatedItem(id, true, freeSpaceToAllocate->getStartAddr(), sizeBytes);
        this->allocationMap.allocateInFreeSpace(memoryToAllocate, freeSpaceToAllocate);
        return true;
    }
}

void MMU::deallocate(unsigned int id)
{
    this->allocationMap.deallocate(id);
}
