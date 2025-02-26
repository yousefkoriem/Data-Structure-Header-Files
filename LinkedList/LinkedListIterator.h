#pragma once
#include "LinkedListNode.h"

template<typename T>
using Node = LinkedListNode<T>;

template<typename T>
class LinkedListIterator {
	Node<T>* ptr;
public:
	LinkedListIterator() : ptr(nullptr) {}
	LinkedListIterator(Node<T>* ptr) : ptr(ptr) {}
	LinkedListIterator(const LinkedListIterator& it) : ptr(it.ptr) {}



	T operator*() { return ptr->data; }
	LinkedListIterator& operator++() {
		ptr = ptr->next;
		return *this;
	}
	LinkedListIterator operator++(int) {
		LinkedListIterator temp = *this;
		ptr = ptr->next;
		return temp;
	}
	bool operator==(const LinkedListIterator& it) const { return ptr == it.ptr; }
	bool operator!=(const LinkedListIterator& it) const { return ptr != it.ptr; }
	LinkedListIterator& operator=(const LinkedListIterator& it) {
		ptr = it.ptr;
		return *this;
	}
};