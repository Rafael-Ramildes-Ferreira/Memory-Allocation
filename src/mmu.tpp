#include "mmu.hpp"
#include "memoryAllocatedItem.hpp"
#include "MemorySlot.h"
#include <iostream>

template<typename T>
MMU<T>::MMU(unsigned int minBlock, allocation_algorithm algorithm, AllocationMap *allocationMap)
{
    // TODO Verificar se o minBlock usa no método de LinkedList, pois não estou usando...
    this->minBlock = minBlock;
    this->algorithm = algorithm;
    this->allocationMap = allocationMap;

    std::cout << "MMU Construída!!" << std::endl;
}

template<typename T>
unsigned int MMU<T>::getMinBlock()
{
    return this->minBlock;
}

template<typename T>
allocation_algorithm MMU<T>::getAlgorithm()
{
    return this->algorithm;
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
void MMU<T>::setAlgorithm(allocation_algorithm algorithm)
{
    this->algorithm = algorithm;
}

template<typename T>
void MMU<T>::setAllocationMap(AllocationMap allocationMap)
{
    this->allocationMap = allocationMap;
}

template<typename T>
bool MMU<T>::allocate(unsigned int sizeBytes, unsigned int id)
{
    std::cout << "MMU<T>::allocate" << std::endl;
    MemoryAllocatedItem **mem_slot_list = allocationMap->find_free_memory();
    std::cout << "received free_memory_list == nullptr: " << (mem_slot_list == nullptr) << std::endl;
    if(mem_slot_list == nullptr){
    std::cout << "return false; 1" << std::endl;
        // Empty list, no free space
        return false;
    }

    MemoryAllocatedItem *freeSpaceToAllocate = criterion.choose_slot(mem_slot_list,sizeBytes);
    if(freeSpaceToAllocate == nullptr){
    std::cout << "return false; 2" << std::endl;
        // No slot large enough
        return false;
    }

    std::cout << "Passou" << std::endl;
    MemoryAllocatedItem *memoryToAllocate = new MemoryAllocatedItem(id,1,freeSpaceToAllocate->getStartAddr(), sizeBytes);
    std::cout << "Antes de AllocationMap::allocateInFreeSpac" << std::endl;
    this->allocationMap->allocateInFreeSpace(memoryToAllocate, freeSpaceToAllocate);
    return true;

//     if (this->algorithm != circular)
//     {
//         this->allocationMap->setCurrentIndex(0);
//     }
//     MemoryAllocatedItem *freeSpaceToAllocate = nullptr;
//     while (true)
//     {
//         auto freeSpace = this->allocationMap->findNextFreeMemory();
//         if (freeSpace == nullptr)
//         {
//             break;
//         }
//         else if (this->algorithm != worstFit && freeSpace->getSizeBytes() == sizeBytes)
//         {
//             freeSpaceToAllocate = freeSpace;
//             break;
//         }
//         else if (freeSpace->getSizeBytes() > sizeBytes)
//         {
//             switch (this->algorithm)
//             {
//             case firstFit:
//             case circular:
//                 freeSpaceToAllocate = freeSpace;
//                 goto returnFreeSpaceToAllocate;
//             case bestFit:
//                 if (freeSpaceToAllocate == nullptr || freeSpaceToAllocate->getSizeBytes() > freeSpace->getSizeBytes())
//                 {
//                     freeSpaceToAllocate = freeSpace;
//                 }
//                 break;
//             case worstFit:
//                 if (freeSpaceToAllocate == nullptr || freeSpaceToAllocate->getSizeBytes() < freeSpace->getSizeBytes())
//                 {
//                     freeSpaceToAllocate = freeSpace;
//                 }
//                 break;
//             }
//         }
//     }
// returnFreeSpaceToAllocate:
//     if (freeSpaceToAllocate == nullptr)
//     {
//         return false;
//     }
//     else
//     {
//         // TODO Ver se está correto isso aqui: freeSpaceToAllocate->getStartAddr()
//         auto memoryToAllocate = new MemoryAllocatedItem(id, true, freeSpaceToAllocate->getStartAddr(), sizeBytes);
//         this->allocationMap->allocateInFreeSpace(memoryToAllocate, freeSpaceToAllocate);
//         return true;
//     }
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