#include "linkedListMMU.hpp"
#include "LinkedList.h"
#include <functional>
#include <iostream>

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
    // auto index = this->list->findBy(freeSpaceToAllocate->getId());
    // auto toBeFound = [freeSpaceToAllocate](MemoryAllocatedItem *item) -> bool {return item->getStartAddr() == freeSpaceToAllocate->getStartAddr();};
    auto toBeFound = [](MemoryAllocatedItem *free) -> std::function<bool(MemoryAllocatedItem *item)> {
        return [=](MemoryAllocatedItem *item) { return item->getStartAddr() == free->getStartAddr(); };
    };

    auto index = this->list->findBy(toBeFound(freeSpaceToAllocate));
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

LinkedListMMU::LinkedListMMU(unsigned int memSize)
{
    this->list = new LinkedList<MemoryAllocatedItem>;
    MemoryAllocatedItem *emptyMemory = new MemoryAllocatedItem(0,false,0,memSize);
    this->list->addFirst(emptyMemory);
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

MemoryAllocatedItem **LinkedListMMU::find_free_memory(void)
{
    // MemoryAllocatedItem *free_memory_list[MAXIMUM_FREE_SLOTS];
    unsigned int index = 0;
    for(int i = 0; i < this->list->size; i++)
    {
        MemoryAllocatedItem *mem_slot = this->list->get_item(i);
        if(mem_slot != nullptr){
            if(!mem_slot->getAllocatedMemory()){
                this->free_memory_list[index] = mem_slot;
                index++;
            }
        }
    }

    return this->free_memory_list;
}

void LinkedListMMU::print(void)
{
    Node<MemoryAllocatedItem> *node = this->list->get_first();
    while (node != nullptr)
    {
        MemoryAllocatedItem *item = node->item;
        std::cout << item->getSizeBytes() << "\t" << item->getAllocatedMemory() << std::endl;
        node = node->next;
    }
}