#include "MemoryAllocatedItem.h"
#include "Node.h"

Node::Node(MemoryAllocatedItem *item){
	this->item = &item;
    	this->next = null;
    	this->prev = null;
}
