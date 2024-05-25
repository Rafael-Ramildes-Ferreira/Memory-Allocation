#ifndef _NODE_CLASS_H
#define _NODE_CLASS_H

template <typename T>
class Node {
	public:
		T* item;
		Node *next;
		Node *prev;
		
		Node(T *item);
};

#include "Node.tpp"
#endif