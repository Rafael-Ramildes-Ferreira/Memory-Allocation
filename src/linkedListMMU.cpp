#include "linkedListMMU.hpp"
#include "LinkedList.h"

MemoryAllocatedItem *LinkedListMMU::findNextFreeMemory()
{
    unsigned int listSize = this->list->size;
    unsigned int index = (this->currentIndex + 1) % listSize;
    while (index != currentIndex)
    {
        auto memoryAllocatedItem = this->list->get_item(index);
        if (!memoryAllocatedItem->getAllocatedMemory())
        {
            this->currentIndex = index;
            return memoryAllocatedItem;
        }
        index = (index + 1) % listSize;
    }
    return nullptr;
}

MemoryAllocatedItem *LinkedListMMU::allocateInFreeSpace(MemoryAllocatedItem *memoryToAllocate, MemoryAllocatedItem *freeSpaceToAllocate)
{
    auto index = this->list->find(freeSpaceToAllocate->getId());
    this->list->insert(index, memoryToAllocate);

    if (memoryToAllocate->getSizeBytes() == freeSpaceToAllocate->getSizeBytes())
    {
        this->list->remove(freeSpaceToAllocate->getId());
        return nullptr;
    }
    else
    {
        freeSpaceToAllocate->setSizeBytes(freeSpaceToAllocate->getSizeBytes() - memoryToAllocate->getSizeBytes());
        // TODO Ver se está correto isso aqui
        freeSpaceToAllocate->setStartAddr(freeSpaceToAllocate->getStartAddr() + memoryToAllocate->getSizeBytes());
        return freeSpaceToAllocate;
    }
}

MemoryAllocatedItem *LinkedListMMU::deallocate(unsigned int id)
{
    for (int i = 0; i++; i < this->list->size)
    {
        auto memoryAllocatedItem = this->list->get_item(i);
        if (memoryAllocatedItem->getId() == id && memoryAllocatedItem->getAllocatedMemory())
        {
            auto totalMemoryFree = memoryAllocatedItem->getSizeBytes();
            auto fixedIndex = i;
            // TODO Verificar se está recalculando o startAddr de maneira certa
            auto startAddr = memoryAllocatedItem->getStartAddr();
            if (i > 0)
            {
                auto before = this->list->get_item(i - 1);
                if (!before->getAllocatedMemory())
                {
                    totalMemoryFree += before->getSizeBytes();
                    startAddr -= before->getSizeBytes();
                    this->list->remove(this->list->get_item(i + 1)->getId());
                    fixedIndex--;
                }
            }
            if (i < this->list->size - 1)
            {
                auto after = this->list->get_item(fixedIndex + 1);
                if (!after->getAllocatedMemory())
                {
                    totalMemoryFree += after->getSizeBytes();
                    this->list->remove(this->list->get_item(fixedIndex + 1)->getId());
                }
            }
            memoryAllocatedItem->setAllocatedMemory(false);
            memoryAllocatedItem->setSizeBytes(totalMemoryFree);
            memoryAllocatedItem->setStartAddr(startAddr);
            return memoryAllocatedItem;
        }
    }
    return nullptr;
}

LinkedListMMU::LinkedListMMU()
{
    this->list = new LinkedList<MemoryAllocatedItem>;
}

LinkedListMMU::LinkedListMMU(LinkedList<MemoryAllocatedItem> *list)
{
    this->list = list;
}

LinkedList<MemoryAllocatedItem> *LinkedListMMU::getList()
{
    return this->list;
}

void LinkedListMMU::setList(LinkedList<MemoryAllocatedItem> *list)
{
    this->list = list;
}
