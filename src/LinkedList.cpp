#include "MemoryAllocatedItem.h"
#include "Node.h"
#include "LinkedList.h"

LinkedList::LinkedList(){

	this->first = null;
  this->last = null;
  this->size = 0;
}
LinkedList::bool isEmpty(){
	this->size == 0 ? return 1: return 0;
}
LinkedList::void addFirst(T *item){
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
LinkedList::void insert(int index, T *item){
	if (index < 0 || index >= this->size){
		cout << "[ERRO] Index not exist";
		return
	}
        	
        
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
LinkedList::int find(int id){
		
    Node aux = &this->first;
      
    for (int i = 0; i < this->size; i++){
    	aux = &aux->next;
    	if(aux->item.id == id){
    		return 1;
    	}
    }
        
    cout << "[ERRO] Item not exist";   
    return -1;

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












