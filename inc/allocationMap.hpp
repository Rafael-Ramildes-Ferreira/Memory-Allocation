#include "memoryAllocatedItem.hpp"
class AllocationMap
{
protected:
    // Variável de instância protegida
    unsigned int currentIndex;

public:
    // Construtor
    AllocationMap() : currentIndex(0) {}

    // Destrutor virtual
    virtual ~AllocationMap() {}

    // Função puramente virtual (método abstrato)
    virtual MemoryAllocatedItem *findNextFreeMemory();

    // Função puramente virtual (método abstrato)
    virtual MemoryAllocatedItem *allocateInFreeSpace(MemoryAllocatedItem *memoryToAllocate, MemoryAllocatedItem *freeSpaceToAllocate);

    // Função puramente virtual (método abstrato)
    virtual MemoryAllocatedItem *deallocate(unsigned int id);

    // Getter para currentIndex
    unsigned int getCurrentIndex() const
    {
        return currentIndex;
    }

    // Setter para currentIndex
    void setCurrentIndex(unsigned int index)
    {
        currentIndex = index;
    }
};