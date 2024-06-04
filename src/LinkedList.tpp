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
	
    // Caches new node
    this->cachedNode = newNode;
    this->cachedIndex = 0;

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
      
    newNode->next = aux;
    newNode->prev = aux->prev;  
    if(aux->prev != nullptr){
        aux->prev->next = newNode;
    } else {
        this->first = newNode;
    }

    aux->prev = newNode;

    // Caches new node
    this->cachedNode = newNode;
    this->cachedIndex = index;
        
    this->size += 1;
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

    // Caches changes
    if(index == this->cachedIndex){
        // If cached node is removed, just cache next node
        this->cachedNode = this->cachedNode->next;
    } else if(index < this->cachedIndex){
        // If any node prior to the cached is removed, updates the cache index,
        // since from that point on all indexes will decrement
        this->cachedIndex--;
    }

    return 0;
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
    // Checks boundaries
    if(index >= this->size) return nullptr;

    // Check if requested is imediately accessible
    if(index == 0) return this->first;
    if(index == this->size) return this->last;
    if(index == this->cachedIndex) return this->cachedNode;

    Node<T> *node;
    unsigned int count;

    unsigned int distCached = (cachedIndex > index)?cachedIndex-index:index-cachedIndex;
    
    // Tests if it should go up or down (first case is up)
    if((2*index < this->size && index < distCached) || (index > distCached && cachedIndex < index)) 
    {
        // Setup variables
        if(index <= distCached){
            node = this->first;
            count = 0;
        } else {
            node = this->cachedNode;
            count = this->cachedIndex;
        }

        // Find
        while(node != nullptr && count++ < index)
        {
            node = node->next;
        }

    } else{
        // Setup variables
        if((this->size - index) <= distCached){
            node = this->last;
            count = this->size - 1;
        } else {
            node = this->cachedNode;
            count = this->cachedIndex;
        }

        // Find
        while(node != nullptr && count-- > index)
        {
            node = node->prev;
        }
    }
    
	return node;
}