#ifndef __MEMORY_ALLOCATED_ITEM_H
#define __MEMORY_ALLOCATED_ITEM_H

class MemoryAllocatedItem
{
private:
    unsigned int id;
    bool allocatedMemory;
    unsigned int startAddr;
    unsigned int sizeBytes;

public:
    MemoryAllocatedItem(unsigned int id, bool allocatedMemory, unsigned int startAddr, unsigned int sizeBytes);

    unsigned int getId();

    bool getAllocatedMemory();

    unsigned int getStartAddr();

    unsigned int getSizeBytes();

    void setId(unsigned int id);

    void setAllocatedMemory(bool allocatedMemory);

    void setStartAddr(unsigned int startAddr);

    void setSizeBytes(unsigned int sizeBytes);
};

#endif