#pragma once

template<typename T>
class LinkedListNode {
public:
	T data;
	LinkedListNode<T>* next;
	LinkedListNode(T val) {
		data = val;
		next = nullptr;
	}
};
