#ifndef _LINKEDLIST_CLASS_H
#define _LINKEDLIST_CLASS_H
#include "Node"
#include <stdint>

class LinkedList {
	private:				
    		Node *first, *last;
    		int size;
	public:
		LinkedList();
		bool isEmpty();
		void addFirst(T *item);
		void insert(int index, T *item);
		int find(int id);
		T* remove(int id);
};
#endif
