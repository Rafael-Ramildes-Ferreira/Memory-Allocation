#include "MemoryAllocatedItem.h"
#include "Node.h"
#include "LinkedList.h"
#include <cassert>

template<typename T>
LinkedList<T>::LinkedList(){

	this->first = nullptr;
  this->last = nullptr;
  this->size = 0;
}

template<typename T>
bool LinkedList<T>::isEmpty(){
	return this->size == 0;
}

template<typename T>
void LinkedList<T>::addFirst(T *item){
    Node newNode = new Node(item);
        
    if (isEmpty()) {
			this->first = &newNode;
			this->last = &newNode;
    } else {
			newNode->next = &this->first;
			this->first.prev = &newNode;
			this->first = &newNode;
    }
	
    size += 1;
}

template<typename T>
void LinkedList<T>::insert(int index, T *item){
	assert(index < 0 || index >= this->size);
        	
        
    Node newNode = new Node(item);
        
    if (index == 0) {
        this->addFirst(item);
    }  else {
        Node aux = this->first;
            
        for (int i = 0; i < index - 1; i++)
            aux = &aux->next;
            
        newNode->next = &aux->next;
        aux->next = &newNode;
        newNode->next.prev = &newNode;
        newNode->prev = &aux;
            
        size += 1;
    }
}

template<typename T>
int LinkedList<T>::find(int id){
		
    Node aux = &this->first;
      
    for (int i = 0; i < this->size; i++){
    	aux = &aux->next;
    	if(aux->item.id == id){
    		return 1;
    	}
    }
        
    assert(false);
}

template<typename T>
T* LinkedList<T>::remove(int id){

    Node aux = this.head;
   
    for (int i = 0; i < this->size; i++){
    	aux = &aux->next;
    	if(aux->item.id == id){
    		aux->prev.next = &aux->next;
				aux->next.prev = &aux->prev;
				size -= 1;  
    		return &aux->item;
    	}
    }
    
    assert(false);
}












