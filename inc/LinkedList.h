#ifndef _LINKEDLIST_CLASS_H
#define _LINKEDLIST_CLASS_H
#include "Node"
#include <stdint>
template <typename T>

class LinkedList {
	private:
				T *allocatedItem;				
    		Node *head, *tail;
    		int size;
	public:
		LinkedList();
		bool isEmpty();
		void addFirst(T *item);
		void add(int index, T *item);
		T* get_AllocatedItem(int id);
		T* remove(int id);
};
#endif
