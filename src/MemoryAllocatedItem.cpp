#include "MemoryAllocatedItem.h"

MemoryAllocatedItem::MemoryAllocatedItem(unsigned int id, bool allcocated_memory, unsigned int start_addr, unsigned int size_bytes){
	this->id  = id;
	this->allcocated_memory = allcocated_memory;
	this->start_addr = start_addr;
	this->size_bytes = size_bytes;
}
		
MemoryAllocatedItem::~MemoryAllocatedItem(){}
	
MemoryAllocatedItem::unsigned int get_id(void){
	return  this->id;
}
MemoryAllocatedItem::bool get_allcocatedMemory(void){
	return this->allcocated_memory;
}
MemoryAllocatedItem::unsigned int get_startAddr(void){
	return this->start_addr;
}
MemoryAllocatedItem::unsigned int get_sizeBytes(void){
	return this->size_bytes;
}
