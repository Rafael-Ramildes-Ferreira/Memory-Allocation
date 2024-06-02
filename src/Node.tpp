#include "memoryAllocatedItem.hpp"
#include "Node.h"

template <typename T>
Node<T>::Node(T *item){
	this->item = item;
    this->next = nullptr;
    this->prev = nullptr;
}