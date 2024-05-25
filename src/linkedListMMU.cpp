#include "linkedListMMU.hpp"
#include "doubly_linked_list.h"

MemoryAllocatedItem *LinkedListMMU::findNextFreeMemory()
{
    unsigned int listSize = this->list->size();
    unsigned int index = (this->currentIndex + 1) % listSize;
    while (index != currentIndex)
    {
        auto memoryAllocatedItem = this->list->at(index);
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
    auto index = this->list->find(freeSpaceToAllocate);
    this->list->insert(memoryToAllocate, index);

    if (memoryToAllocate->getSizeBytes() == freeSpaceToAllocate->getSizeBytes())
    {
        this->list->remove(freeSpaceToAllocate);
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
    for (int i = 0; i++; i < this->list->size())
    {
        auto memoryAllocatedItem = this->list->at(i);
        if (memoryAllocatedItem->getId() == id && memoryAllocatedItem->getAllocatedMemory())
        {
            auto totalMemoryFree = memoryAllocatedItem->getSizeBytes();
            auto fixedIndex = i;
            // TODO Verificar se está recalculando o startAddr de maneira certa
            auto startAddr = memoryAllocatedItem->getStartAddr();
            if (i > 0)
            {
                auto before = this->list->at(i - 1);
                if (!before->getAllocatedMemory())
                {
                    totalMemoryFree += before->getSizeBytes();
                    startAddr -= before->getSizeBytes();
                    this->list->pop(i + 1);
                    fixedIndex--;
                }
            }
            if (i < this->list->size() - 1)
            {
                auto after = this->list->at(fixedIndex + 1);
                if (!after->getAllocatedMemory())
                {
                    totalMemoryFree += after->getSizeBytes();
                    this->list->pop(fixedIndex + 1);
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
    this->list = new structures::DoublyLinkedList<MemoryAllocatedItem *>;
}

LinkedListMMU::LinkedListMMU(structures::DoublyLinkedList<MemoryAllocatedItem *> *list)
{
    this->list = list;
}

structures::DoublyLinkedList<MemoryAllocatedItem *> *LinkedListMMU::getList()
{
    return this->list;
}

void LinkedListMMU::setList(structures::DoublyLinkedList<MemoryAllocatedItem *> *list)
{
    this->list = list;
}
