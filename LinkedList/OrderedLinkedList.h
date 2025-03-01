#pragma once
#include "LinkedListNode.h"
#include "LinkedListIterator.h"
#include "LinkedListType.h"


// Making Shorthand for Node
template<typename T> using Node = LinkedListNode<T>;


// Inherits Data and Functions from LinkedListType
template<typename T>
class OrderedLinkedList : public LinkedListType<T> {
	// Function Overriding
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
};

template<typename T>
bool OrderedLinkedList<T>::search(const T& key) const {
	Node<T>* curr = first;
	while (curr != nullptr) {
		if (curr->data == key) return true;
		curr = curr->next;
	}
	return false;
}

template<typename T>
void OrderedLinkedList<T>::insert(const T& val) {
	Node<T>* curr;
	Node<T>* newNode = new Node<T>(val);

	if (first == nullptr) {
		first = newNode;
		last = first;
		++count;
		return;
	}
	if (first->data <= val) {
		insertFirst(val);
		return;
	}
	while (curr->next != nullptr && curr->next->data < key) {
		curr = curr->next;
	}
	if (curr->next == nullptr) {
		insertLast(val);
		return;
	}
	newNode->next = curr->next;
	curr->next = newNode;
	++count;
}

template<typename T>
void OrderedLinkedList<T>::insertFirst(const T& val) {
	Node<T>* newNode = new Node<T>(val);
	++count;
	if (first == nullptr) {
		first = newNode;
		last = first;
		return;
	}
	newNode->next = first;
	first = newNode;
}

template<typename T>
void OrderedLinkedList<T>::insertLast(const T& val) {
	Node<T>* newNode = new Node<T>(val);
	++count;
	if (last == nullptr) {
		first = newNode;
		last = first;
		return;
	}
	last->next = newNode;
	last = last->next;
}

template<typename T>
void OrderedLinkedList<T>::deleteNode(const T& val) {
	assert(first != nullptr);
	Node<T>* curr = first;
	while (curr->next != nullptr) {
		if (curr->next->data == val) {
			Node<T>* temp = curr->next;
			curr->next = temp->next;
			delete temp;
			return;
		}
	}

}
