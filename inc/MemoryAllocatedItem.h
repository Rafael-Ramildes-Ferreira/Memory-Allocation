#ifndef _MEMORYALLOCATEDITEM_CLASS_H
#define _MEMORYALLOCATEDITEM_CLASS_H
#include <cstdint>


class MemoryAllocatedItem {
	private:
    		unsigned int id;
    		bool allcocated_memory;
    		unsigned int start_addr;
    		unsigned int size_bytes;
	public:
		MemoryAllocatedItem(unsigned int id, bool allcocated_memory, unsigned int start_addr, unsigned int size_bytes);
		
		~MemoryAllocatedItem();
			
		unsigned int get_id(void);
		bool get_allcocatedMemory(void);
		unsigned int get_startAddr(void);
		unsigned int get_sizeBytes(void);
};
#endif
