#pragma once
#include "LinkedListNode.h"
#include "LinkedListIterator.h"
#include "LinkedListType.h"


// Making Shorthand for Node
template<typename T> using Node = LinkedListNode<T>;

// Inherits Data and Functions from LinkedListType
template<typename T>
class UnorderedLinkedList : public LinkedListType<T> {
	// Function Overriding
public:
	// Search for Specific Value in LinkedList without editing the list
	bool search(const T& key) const;

	// Inserts Node at the Beginning of LinkedList
	void insertFirst(const T& val);

	// Inserts Node at the End of LinkedList
	void insertLast(const T& val);

	// Removes Node Having the given value
	void deleteNode(const T& val);
};

template<typename T>
bool UnorderedLinkedList<T>::search(const T& key) const {
	for (typename LinkedListType<T>::iterator it = LinkedListType<T>::begin(); it != LinkedListType<T>::end(); ++it) {
		if (*it == key) return true;
	}
	return false;
}
template<typename T>
void UnorderedLinkedList<T>::insertFirst(const T& val) {
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

template<typename T>
void UnorderedLinkedList<T>::insertLast(const T& val) {
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

template<typename T>
void UnorderedLinkedList<T>::deleteNode(const T& val) {
	assert(LinkedListType<T>::begin() != LinkedListType<T>::end());
	Node<T>* curr = LinkedListType<T>::first;
	while (curr->next != nullptr) {
		if (curr->next->data == val) {
			Node<T>* temp = curr->next;
			curr->next = temp->next;
			delete temp;
			return;
		}
		curr = curr->next;
	}
}