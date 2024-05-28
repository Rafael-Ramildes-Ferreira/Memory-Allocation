#ifndef _LINKEDLIST_CLASS_H
#define _LINKEDLIST_CLASS_H
#include "Node.h"
#include <cstdint>

template<typename T>
class LinkedList {
	private:				
		Node<T> *first, *last;
	public:
		int size;

		LinkedList(){

			this->first = nullptr;
			this->last = nullptr;
			this->size = 0;
		}
		bool isEmpty();
		void addFirst(T *item);
		void insert(int index, T *item);
		int find(int id);
		T* remove(int id);
		T* get_item(unsigned int index);
		Node<T> *get_first();
		Node<T> *get_last();
};

#include "LinkedList.tpp"
#endif