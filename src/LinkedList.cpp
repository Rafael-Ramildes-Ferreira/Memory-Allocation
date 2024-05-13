#include "MemoryAllocatedItem.h"
#include "Node.h"
#include "LinkedList.h"

LinkedList::LinkedList(){

	this->head = null;
  this->tail = null;
  this->size = 0;
}
LinkedList::bool isEmpty(){
	this->size == 0 ? return 1: return 0;
}
LinkedList::void addFirst(T *item){
    Node newNode = new Node(item);
        
    if (isEmpty()) {
			this->head = &newNode;
			this->tail = &newNode;
    } else {
			newNode->next = &this->head;
			this->head.prev = &newNode;
			this->head = &newNode;
    }
	
    size += 1;
}
LinkedList::void add(int index, T *item){
	if (index < 0 || index >= this->size){
		cout << "[ERRO] Index not exist";
		return
	}
        	
        
    Node newNode = new Node(item);
        
    if (index == 0) {
        this->addFirst(item);
    }  else {
        Node aux = this->head;
            
        for (int i = 0; i < index - 1; i++)
            aux = &aux->next;
            
        newNode->next = &aux->next;
        aux->next = &newNode;
        newNode->next.prev = &newNode;
        newNode->prev = &aux;
            
        size += 1;
    }
}
LinkedList::T* get_AllocatedItem(int id){
		
    Node aux = &this.head;
      
    for (int i = 0; i < this->size; i++){
    	aux = &aux->next;
    	if(aux->item.id == id){
    		return &aux->item;
    	}
    }
        
    cout << "[ERRO] Item not exist";   
    return;

}
LinkedList::T* remove(int id){

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
    
    cout << "[ERRO] Item not exist";    
    return;
}












