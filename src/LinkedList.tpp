#include "memoryAllocatedItem.hpp"
#include "Node.h"
#include "LinkedList.h"
#include <cassert>
#include <iostream>


template<typename T>
bool LinkedList<T>::isEmpty(){
	return this->size == 0;
}

template<typename T>
void LinkedList<T>::addFirst(T *item){
    Node<T> *newNode = new Node(item);
        
    if (isEmpty()) {
			this->first = newNode;
			this->last = newNode;
    } else {
			newNode->next = this->first;
			this->first->prev = newNode;
			this->first = newNode;
    }
	
    size += 1;
}

template<typename T>
void LinkedList<T>::insert(int index, T *item){
	assert(!(index < 0 || index >= this->size));
        	
        
    Node<T> *newNode = new Node(item);
    Node<T> *aux = this->get_node(index);

    if(aux == nullptr) {
        return;
    }
        
    if(aux->prev != nullptr){
        aux->prev->next = newNode;
    } else {
        this->first = newNode;
    }

    newNode->prev = aux->prev;
    newNode->next = aux;
    aux->prev = newNode;
        
    this->size += 1;
}

template<typename T>
int LinkedList<T>::findBy(std::function<bool(MemoryAllocatedItem*)> func)
{
    Node<T> *node = this->first;
    int index = 0;
    while (node != nullptr)
    {
        if(func(node->item)) return index;
        
        node = node->next;
        index++;
    }
    
    return -1;
}

template<typename T>
int LinkedList<T>::remove(unsigned int index)
{  
    // Seek
    Node<T> *node = this->get_node(index);
    if(node == nullptr) return -1;

    // 'n Destroy
    node->prev->next = node->next;
    if(node->next != nullptr){
        node->next->prev = node->prev;
    } else {
        this->last = node->prev;
    }

    return 0;
}

template<typename T>
T* LinkedList<T>::get_item(unsigned int index)
{
    Node<T> *node = this->get_node(index);
    
    if(node == nullptr) return nullptr;
    else return node->item;
}

template<typename T>
Node<T> *LinkedList<T>::get_first()
{
    return this->first;
}

template<typename T>
Node<T> *LinkedList<T>::get_last()
{
    return this->last;
}

template<typename T>
Node<T> *LinkedList<T>::get_node(unsigned int index)
{
    if(index >= this->size) return nullptr;

	Node<T> *node = this->first;
	unsigned int count = 0;
	while(node != nullptr && count++ < index)
	{
		node = node->next;
	}

	return node;
}