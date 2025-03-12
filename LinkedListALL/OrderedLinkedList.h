#pragma once
#include "LinkedListNode.h"
#include "LinkedListIterator.h"
#include "LinkedListType.h"
#include <cassert>
#include <algorithm>
#include <functional>

// Making Shorthand for Node
template<typename T> using Node = LinkedListNode<T>;


// Inherits Data and Functions from LinkedListType
template<typename T, class Compare = less_equal<T>>
class OrderedLinkedList : public LinkedListType<T> {
	// Function Overriding
	Compare comp;
public:
	// Search for Specific Value in LinkedList without editing the list
	bool search(const T& key) const;

	// Inserts Node at its right position acscending
	void insert(const T& val);

	// Inserts Node at the Beginning of LinkedList
	void insertFirst(const T& val);

	// Inserts Node at the End of LinkedList
	void insertLast(const T& val);

	// Removes Node Having the given value
	void deleteNode(const T& val);

	void remDuplicate();
};

template<typename T, class Compare>
bool OrderedLinkedList<T,Compare>::search(const T& key) const {
	for(typename LinkedListType<T>::iterator it = LinkedListType<T>::begin(); it != LinkedListType<T>::end(); ++it) {
    if(*it >= key) return *it == key;
	}
	return false;
}

template<typename T, class Compare>
void OrderedLinkedList<T, Compare>::insert(const T& val) {
	Node<T>* curr = LinkedListType<T>::first;
	Node<T>* newNode = new Node<T>(val);

	if (LinkedListType<T>::begin() == LinkedListType<T>::end()) {
		LinkedListType<T>::first = newNode;
		LinkedListType<T>::last = LinkedListType<T>::first;
		++LinkedListType<T>::count;
		return;
	}
	if (comp(val, *LinkedListType<T>::begin())) {
		insertFirst(val);
		return;
	}
	while (curr->next != nullptr && comp(curr->next->data, val)) {
		curr = curr->next;
	}
	if (curr->next == nullptr) {
		insertLast(val);
		return;
	}
	newNode->next = curr->next;
	curr->next = newNode;
	++LinkedListType<T>::count;
}

template<typename T, class Compare>
void OrderedLinkedList<T, Compare>::insertFirst(const T& val) {
	Node<T>* newNode = new Node<T>(val);
	++LinkedListType<T>::count;
	if (LinkedListType<T>::begin() == LinkedListType<T>::end()) {
		LinkedListType<T>::first = newNode;
		LinkedListType<T>::last = LinkedListType<T>::first;
		return;
	}
	newNode->next = LinkedListType<T>::first;
	LinkedListType<T>::first = newNode;
}

template<typename T, class Compare>
void OrderedLinkedList<T, Compare>::insertLast(const T& val) {
	Node<T>* newNode = new Node<T>(val);
	++LinkedListType<T>::count;
	if (LinkedListType<T>::last == nullptr) {
		LinkedListType<T>::first = newNode;
		LinkedListType<T>::last = LinkedListType<T>::first;
		return;
	}
	LinkedListType<T>::last->next = newNode;
	LinkedListType<T>::last = LinkedListType<T>::last->next;
}

template<typename T, class Compare>
void OrderedLinkedList<T, Compare>::deleteNode(const T& val) {
	assert(LinkedListType<T>::begin() != LinkedListType<T>::end());
	Node<T>* curr = LinkedListType<T>::first;
	if (curr->data == val) {
		LinkedListType<T>::first = LinkedListType<T>::first->next;
		delete curr;
		return;
	}
	while (curr->next != nullptr && comp(curr->next->data, val)) {
		if (curr->next->data == val) {
			Node<T>* temp = curr->next;
			curr->next = temp->next;
			delete temp;
			return;
		}
		curr = curr->next;
	}
}

template<typename T, class Compare>
void OrderedLinkedList<T, Compare>::remDuplicate() {
	OrderedLinkedList<int>::iterator it = LinkedListType<T>::begin();
	int prev = *it;
	for (++it; it != LinkedListType<T>::end(); ++it) {
		if (prev == *it) {
			deleteNode(prev);
		}
		prev = *it;
	}
}
