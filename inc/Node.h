#ifndef _NODE_CLASS_H
#define _NODE_CLASS_H
template <typename T>

class Node {
	private:
    		T* item;
    		Node *next;
    		Node *prev;
    	public:
    		Node(T *item);
};
#endif
