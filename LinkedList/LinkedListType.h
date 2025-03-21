#pragma once

// Building ADT of LinkedList

#include "LinkedListNode.h"
#include "LinkedListIterator.h"
#include <iostream>

// Making Shorthand for Node
template<typename T> using Node = LinkedListNode<T>;

template<typename T>
class LinkedListType {
private:
	// Copying values from one list to another without affecting pointers of the other one
	void copyList(const LinkedListType<T>& lst);
	// Protected Specifier as they are needed in inheritance but not allowing access outside Base or Derived classes
protected:
	// Pointer to first element of LinkedList (Head) and last element
	Node<T>* first;
	Node<T>* last;

	// Counter for the elements in LinkedList
	int count;
public:
	// Calling iterator from LinkedList class
	using iterator = LinkedListIterator<T>;

	// Default Constructor
	LinkedListType() {
		first = nullptr;
		last = nullptr;
		count = 0;
	}

	// Copy Constructor
	LinkedListType(const LinkedListType<T>& lst) {
		copyList(lst);
	}

	// Destructor
	~LinkedListType() {
		destroylist();
	}

	// Assignment operator for LinkedList
	const LinkedListType<T>& operator=(const LinkedListType<T>& lst); // Returning ineditible reference for LinkedList

	// Clears the List for Assigning new Values
	void initailizeList();

	// Checks whether linkedlist is empty or not 
	bool isEmptyList() const { return count == 0; }

	// Prints all Values of list without editing value
	void print() const;

	// returns the value of count -> size of LinkedList
	int length() const { return count; }

	// Deletes all Elements from LinkedList
	void destroylist();

	// Accesses the first element of LinkedList
	T& front() const { 
		assert(first != NULL);
		return first->data;
	}

	// Accesses the last element of LinkedList
	T& back() const { 
		assert(first != NULL);
		return last->data; 
	}

	// Pure Virtual Functions for Ordrered and Unordered LinkedLists
	virtual bool search(const T& key) const = 0;
	virtual void insertFirst(const T& val) = 0;
	virtual void insertLast(const T& val) = 0;
	virtual void deleteNode(const T& val) = 0;

	// Iterator for the start and end of LinkedList
	iterator begin() const { return iterator(first); }
	iterator end() const { return iterator(nullptr); }
	// end() isn't the last element but beyond it

	Node<T>* head() const { return first; }
	Node<T>* tail() const { return last; }
};

template<typename T>
void LinkedListType<T>::copyList(const LinkedListType<T>& lst) {
	Node<T>* newNode;
	Node<T>* curr;
	if (this->begin() != this->end()) destroylist();
	if (lst.begin() == lst.end()) {
		this->first = nullptr;
		this->last = nullptr;
		this->count = 0;
	}
	else {
		curr = lst.first;
		this->first->data = curr->data;
		this->first->next = curr->next;
		this->last = this->first;
		while ((curr = curr->next) != nullptr) {
			newNode = curr;
			last->next = newNode;
			last = last->next;
		}
	}
}

template<typename T>
const LinkedListType<T>& LinkedListType<T>::operator=(const LinkedListType<T>& lst) {
	copyList(lst);
	return *this;
}

template<typename T>
void LinkedListType<T>::initailizeList() {
	destroylist();
}

template<typename T>
void LinkedListType<T>::print() const {
	iterator it = this->begin();
	std::cout << *it++;
	for (it; it != this->end(); ++it) std::cout << " -> " << *it;
	std::cout << '\n';
}

template<typename T>
void LinkedListType<T>::destroylist() {
	Node<T> *temp;
	while (first != nullptr) {
		temp = first;
		first = first->next;
		delete temp;
	}
}
