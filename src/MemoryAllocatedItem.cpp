#include "MemoryAllocatedItem.h"

MemoryAllocatedItem::MemoryAllocatedItem(unsigned int id, bool allcocated_memory, unsigned int start_addr, unsigned int size_bytes){
	this->id  = id;
	this->allcocated_memory = allcocated_memory;
	this->start_addr = start_addr;
	this->size_bytes = size_bytes;
}
		
MemoryAllocatedItem::~MemoryAllocatedItem(){}
	
unsigned int MemoryAllocatedItem::get_id(void){
	return  this->id;
}
bool MemoryAllocatedItem::get_allcocatedMemory(void){
	return this->allcocated_memory;
}
unsigned int MemoryAllocatedItem::get_startAddr(void){
	return this->start_addr;
}
unsigned int MemoryAllocatedItem::get_sizeBytes(void){
	return this->size_bytes;
}
