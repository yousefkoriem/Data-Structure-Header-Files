#pragma once
#include "LinkedListNode.h"

// Iterator of LinkedList

// Making Shorthand for Node
template<typename T> using Node = LinkedListNode<T>;



template<typename T>
class LinkedListIterator {	
	// Private pointer for address of node to iterate
	Node<T>* ptr;
public:
	// Default Constructor -> Sets value of pointer to NULL
	LinkedListIterator() : ptr(nullptr) {} // using nullptr to return same type of null pointer

	// Parameterized Constructor
	LinkedListIterator(Node<T>* ptr) : ptr(ptr) {}

	// Copy Constructor
	LinkedListIterator(const LinkedListIterator& it) : ptr(it.ptr) {}


	// Derefrencing operator
	T& operator*() const { return ptr->data; } // returns reference to data -can be edited-

	// Increment operator -> traverse in LinkedList
	LinkedListIterator& operator++() { // Prefix
		ptr = ptr->next;
		return *this;
	}
	LinkedListIterator& operator++(int) { // Postfix
		LinkedListIterator temp = *this;
		ptr = ptr->next;
		return temp;
	}

	// Compare operator -> to check if they point to same node
	bool operator==(const LinkedListIterator& it) const { return ptr == it.ptr; }
	bool operator!=(const LinkedListIterator& it) const { return ptr != it.ptr; }

	// Assignment Operator -> assigns Value from iterator to caller iterator 
	LinkedListIterator& operator=(const LinkedListIterator& it) {
		ptr = it.ptr;
		return *this;
	}
	Node<T>* operator->() { return ptr; }
};