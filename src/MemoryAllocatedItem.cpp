#include "memoryAllocatedItem.hpp"

MemoryAllocatedItem::MemoryAllocatedItem(unsigned int id, bool allocatedMemory, unsigned int startAddr, unsigned int sizeBytes)
{
    this->id = id;
    this->allocatedMemory = allocatedMemory;
    this->startAddr = startAddr;
    this->sizeBytes = sizeBytes;
}

unsigned int MemoryAllocatedItem::getId()
{
    return this->id;
}

bool MemoryAllocatedItem::getAllocatedMemory()
{
    return this->allocatedMemory;
}

unsigned int MemoryAllocatedItem::getStartAddr()
{
    return this->startAddr;
}

unsigned int MemoryAllocatedItem::getSizeBytes()
{
    return this->sizeBytes;
}

void MemoryAllocatedItem::setId(unsigned int id)
{
    this->id = id;
}

void MemoryAllocatedItem::setAllocatedMemory(bool allocatedMemory)
{
    this->allocatedMemory = allocatedMemory;
}

void MemoryAllocatedItem::setStartAddr(unsigned int startAddr)
{
    this->startAddr = startAddr;
}

void MemoryAllocatedItem::setSizeBytes(unsigned int sizeBytes)
{
    this->sizeBytes = sizeBytes;
}
