#ifndef _NODE_CLASS_H
#define _NODE_CLASS_H
#include "MemoryAllocatedItem"


class Node {
	private:
    		MemoryAllocatedItem *item;
    		Node *next;
    		Node *prev;
    	public:
    		Node(MemoryAllocatedItem *item);
};
#endif
