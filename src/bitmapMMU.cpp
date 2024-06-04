#include "bitmapMMU.hpp"
#include "LinkedList.h"
#include <functional>
#include <iostream>

BitmapMMU::BitmapMMU(unsigned int memSize, unsigned int minBlockSize)
{
    this->list = new LinkedList<MemoryAllocatedItem>;
    this->bitmap = new bool[this->memSize / this->minBlockSize];
    for (int i = 0; i < this->memSize / this->minBlockSize; i++)
    {
        this->bitmap[i] = false;
    }
}

BitmapMMU::BitmapMMU(LinkedList<MemoryAllocatedItem> *list, bool *bitmap)
{
    this->bitmap = bitmap;
    this->list = list;
}

MemoryAllocatedItem *BitmapMMU::findNextFreeMemory()
{
    unsigned int bitmapSize = sizeof(this->bitmap) / sizeof(*this->bitmap);
    auto index = currentIndex;
    auto totalFree = 0;
    auto searching = -1;
    do
    {
        if (this->bitmap[index])
        {
            if (searching != -1)
            {
                MemoryAllocatedItem *emptyMemory = new MemoryAllocatedItem(0, false, searching * this->minBlockSize, totalFree * this->minBlockSize);
                this->currentIndex = (index + 1) % bitmapSize;
                return emptyMemory;
            }
        }
        else
        {

            totalFree += 1;
            if (searching == -1)
            {
                searching = index;
            }
            if (index == bitmapSize - 1)
            {
                MemoryAllocatedItem *emptyMemory = new MemoryAllocatedItem(0, false, searching * this->minBlockSize, totalFree * this->minBlockSize);
                this->currentIndex = 0;
                return emptyMemory;
            }
        }
        index = (index + 1) % bitmapSize;
    } while (index != currentIndex);
    return nullptr;
}

MemoryAllocatedItem **BitmapMMU::find_free_memory(void)
{
    auto free_memory_list = new MemoryAllocatedItem *[this->memSize / this->minBlockSize / 2];
    auto cont = 0;
    while (true)
    {
        auto emptySpace = this->findNextFreeMemory();
        if (emptySpace == nullptr)
        {
            return free_memory_list;
        }
        else
        {
            free_memory_list[cont] = emptySpace;
        }
        cont++;
    }
}

MemoryAllocatedItem *BitmapMMU::allocateInFreeSpace(MemoryAllocatedItem *memoryToAllocate, MemoryAllocatedItem *freeSpaceToAllocate)
{
    auto startAddrBitmap = memoryToAllocate->getStartAddr() / this->minBlockSize;
    for (int i = 0; i < memoryToAllocate->getSizeBytes() / this->minBlockSize; i++)
    {
        this->bitmap[startAddrBitmap + i] = true;
    }
    this->list->addFirst(memoryToAllocate);
    return memoryToAllocate;
}

MemoryAllocatedItem *BitmapMMU::deallocate(unsigned int id)
{
    auto memoryToDeallocate = this->list->remove(id);
    if (memoryToDeallocate == nullptr)
    {
        return nullptr;
    }
    auto startAddrBitmap = memoryToDeallocate->getStartAddr() / this->minBlockSize;
    for (int i = 0; i < memoryToDeallocate->getSizeBytes() / this->minBlockSize; i++)
    {
        this->bitmap[startAddrBitmap + i] = false;
    }
    return memoryToDeallocate;
}

LinkedList<MemoryAllocatedItem> *BitmapMMU::getList()
{
    return this->list;
}

void BitmapMMU::setList(LinkedList<MemoryAllocatedItem> *list)
{
    this->list = list;
}

void BitmapMMU::print(void)
{
    // TODO
}