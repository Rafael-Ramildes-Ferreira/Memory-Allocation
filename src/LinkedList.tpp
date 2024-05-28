#include "memoryAllocatedItem.hpp"
#include "Node.h"
#include "LinkedList.h"
#include <cassert>

// template<typename T>
// LinkedList<T>::LinkedList(){

//     this->first = nullptr;
//     this->last = nullptr;
//     this->size = 0;
// }

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
        
    if (index == 0) {
        this->addFirst(item);
    }  else {
        Node<T> *aux = this->first;
            
        for (int i = 0; i < index - 1; i++)
            aux = aux->next;
            
        newNode->next = aux;
        newNode->prev = aux->prev;
        aux->prev->next = newNode;
        aux->prev = newNode;
            
        size += 1;
    }
}

template<typename T>
int LinkedList<T>::find(int id){
		
    Node<T> *aux = this->first;
      
    for (int i = 0; i < this->size; i++){
    	if(aux->item->getId() == id){
    		return i;
    	}
    	aux = aux->next;
    }
        
    assert(false);
}

template<typename T>
T* LinkedList<T>::remove(int id){

    Node<T> *aux = this->first;
   
    for (int i = 0; i < this->size; i++){
    	if(aux->item->getId() == id){
    		aux->prev->next = aux->next;
            aux->next->prev = aux->prev;
            size -= 1;
            T *mem_allocated = aux->item;
            delete aux; // Should not delete the item but only the Node structure
    		return mem_allocated;
    	}
    	aux = aux->next;
    }
    
    assert(false);
}

template<typename T>
T* LinkedList<T>::get_item(unsigned int index)
{
	Node<T> *node = this->first;
	unsigned int count = 0;
	while(node != nullptr && count < index)
	{
		node = node->next;
	}

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