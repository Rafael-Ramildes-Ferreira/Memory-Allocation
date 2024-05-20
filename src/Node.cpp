#include "MemoryAllocatedItem.h"
#include "Node.h"

Node::Node(T *item){
	this->item = &item;
    	this->next = null;
    	this->prev = null;
}
