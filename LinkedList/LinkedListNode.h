#pragma once

// Makes the building unit of LinkedList (Node)

template<typename T>
class LinkedListNode {
public:
	T data; // Value inside Node
	LinkedListNode<T>* next; // Where the next node is located -> "Address of next node"

	// Paramertized Constructor for Node with given value
	LinkedListNode(T val) {
		data = val;
		next = nullptr;
	}

	// Default Constructor when Initializing Node
	LinkedListNode() {
		// DO NOTHING...
	}

	// Copy Constructor
	LinkedListNode(const LinkedListNode<T>& nd) {
		this->data = nd->data;
		this->next = nd->next;
	}
};