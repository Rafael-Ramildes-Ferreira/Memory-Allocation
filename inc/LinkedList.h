#ifndef _LINKEDLIST_CLASS_H
#define _LINKEDLIST_CLASS_H
#include "Node.h"
#include <cstdint>

template<typename T>
class LinkedList {
	private:				
    		Node<T> *first, *last;
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
