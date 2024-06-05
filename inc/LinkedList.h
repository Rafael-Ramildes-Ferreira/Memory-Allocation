#ifndef _LINKEDLIST_CLASS_H
#define _LINKEDLIST_CLASS_H
#include "Node.h"
#include <cstdint>
#include <functional>

template<typename T>
class LinkedList {
	private:				
		Node<T> *first, *last;
		Node<T> *cachedNode;
		unsigned int cachedIndex = 0;

		Node<T> *get_node(unsigned int index);
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
		T *remove(unsigned int index);
		int findBy(std::function<bool(MemoryAllocatedItem*)> func);
		T* get_item(unsigned int index);
		Node<T> *get_first();
		Node<T> *get_last();
};

#include "LinkedList.tpp"
#endif