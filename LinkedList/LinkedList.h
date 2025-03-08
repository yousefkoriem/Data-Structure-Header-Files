#pragma once
#include "LinkedListNode.h"
#include "LinkedListIterator.h"
#include <iostream>
using namespace std;

template<typename T>
using Node = LinkedListNode<T>;


template<typename T>
class LinkedList
{
	Node<T>* HeadT;
	Node<T>* TailT;
	size_t sz;
	void copyList(const LinkedList<T>& lst);
public:
	using iterator = LinkedListIterator<T>;

	LinkedList() {
		HeadT = nullptr;
		TailT = nullptr;
		sz = 0;
	}
	LinkedList(T val) {
		HeadT = new Node<T>(val);
		TailT = HeadT;
		sz = 1;
	}
	LinkedList(const LinkedList<T>& lst) {
		copyList(lst);
	}
	~LinkedList() {
		destroylist();
	}

	void initailizelist();
	void destroylist();

	void push_front(T val);
	T pop_front();

	void push_back(T val);
	T pop_back();

	void insert(T val, T key);
	void erase(T key);

	void insert_at(T val, size_t pos);
	void erase_at(size_t pos);

	void print() const;
	size_t find(T key) const;


	size_t size() const { return sz; }
	bool empty() const { return sz == 0; }

	T& front() const { return HeadT->data; }
	T& back() const { return TailT->data; }
	Node<T>* head() const { return HeadT; }
	Node<T>* tail() const { return TailT; }

	T& operator[](size_t pos) {
		if (pos >= sz) 
			throw out_of_range("Index out of range");
		if(pos == 0)
			return front();
		if(pos == sz - 1)
			return back();

		iterator it = begin();
		for (size_t i = 1; i <= pos && it != end(); ++i) {
			++it;
		}
		return *it;
	}
	LinkedList<T>& operator+=(T val);
	LinkedList<T>& operator+=(const LinkedList<T>& lst);

	friend ostream& operator<< <>(ostream& os, LinkedList<T>& lst);
	friend istream& operator>> <>(istream& is, LinkedList<T>& lst);

	iterator begin() const { return iterator(HeadT); }
	iterator end() const { return iterator(nullptr); }
};



template<typename T>
void LinkedList<T>::copyList(const LinkedList<T>& lst) {
	Node<T>* newNode;
	Node<T>* curr;
	if (this->begin() != this->end()) destroylist();
	if (lst.begin() == lst.end())
		return;
	for (iterator it = lst.begin(); it != lst.end(); ++it) {
		push_back(*it);
	}
	sz = lst.sz;
}

template<typename T>
void LinkedList<T>::push_front(T val) {
	Node<T>* newNode = new Node<T>(val);
	++sz;
	if (HeadT == nullptr) {
		TailT = HeadT = newNode;
	}
	else {
		newNode->next = HeadT;
		HeadT = newNode;
	}
}

template<typename T>
T LinkedList<T>::pop_front()
{
	if (!HeadT) {
		throw invalid_argument("There's no elements");
		return T();
	}
	--sz;
	T tmp = HeadT->data;
	Node<T>* curr = HeadT;
	HeadT = HeadT->next;
	delete curr;

	return tmp;
}

template<typename T>
void LinkedList<T>::push_back(T val) {
	Node<T>* newNode = new Node<T>(val);
	++sz;

	if(TailT == nullptr) {
		HeadT = TailT = newNode;
	}
	else {
		TailT->next = newNode;
		TailT = newNode;
	}
}

template<typename T>
inline T LinkedList<T>::pop_back()
{
	if (!TailT) {
		throw invalid_argument("There's no elements");
		return T();
	}
	--sz;
	T tmp = TailT->data;

	if(HeadT == TailT) {
		delete TailT;
		HeadT = TailT = nullptr;
		return tmp;
	}

	Node<T>* curr = HeadT;
	while (curr->next != TailT) {
		curr = curr->next;
	}
	delete TailT;
	TailT = curr;
	TailT->next = nullptr;

	return tmp;
}

template<typename T>
void LinkedList<T>::insert(T val, T key) {
	Node<T>* newNode = new Node<T>(val);
	Node<T>* curr = HeadT;
	while (curr != nullptr) {
		if (curr->data == key) {
			newNode->next = curr->next;
			curr->next = newNode;
			++sz;
			return;
		}
		curr = curr->next;
	}
	throw invalid_argument("Key not found");
}

template<typename T>
void LinkedList<T>::erase(T key) {
	if(HeadT->data == key)
		return pop_front();
	if (TailT->data == key)
		return pop_back();

	Node<T>* curr = HeadT;
	while (curr->next != nullptr) {
		if (curr->next->data == key) {
			Node<T>* temp = curr->next;
			curr->next = temp->next;
			delete temp;
			--sz;
			return;
		}
		curr = curr->next;
	}
	throw invalid_argument("Key not found");
}

template<typename T>
void LinkedList<T>::insert_at(T val, size_t pos) {
	if (pos > sz)
		throw out_of_range("Index out of range");
	if (pos == 0)
		return push_front(val);
	if (pos == sz)
		return push_back(val);

	Node<T>* newNode = new Node<T>(val);
	Node<T>* curr = HeadT;
	for (size_t i = 0; i < pos - 1; ++i) {
		curr = curr->next;
	}
	newNode->next = curr->next;
	curr->next = newNode;
	++sz;
}

template<typename T>
void LinkedList<T>::erase_at(size_t pos) {
	if (pos >= sz)
		throw out_of_range("Index out of range");
	if (pos == 0)
		return (void)pop_front();
	if (pos == sz - 1)
		return (void)pop_back();

	Node<T>* curr = HeadT;
	for (size_t i = 0; i < pos - 1; ++i) {
		curr = curr->next;
	}
	Node<T>* temp = curr->next;
	curr->next = temp->next;
	delete temp;
	--sz;
}

template<typename T>
void LinkedList<T>::print() const {
	iterator it = begin();
	std::cout << "List: " << *it;
	++it;
	for(it; it != end(); ++it) {
		std::cout << " -> " << *it;
	}
	std::cout << std::endl;
}

template<typename T>
inline size_t LinkedList<T>::find(T key) const
{
	size_t pos = 0;

	for (iterator it = begin(); it != end(); ++it) {
		if (*it == key)
			return pos;
		++pos;
	}
	return size_t(-1);
}

template<typename T>
void LinkedList<T>::initailizelist() {
	destroylist();
}

template<typename T>
void LinkedList<T>::destroylist() {
	while (HeadT != nullptr) {
		pop_front();
	}
	sz = 0;
	HeadT = TailT = nullptr;
}

template<typename T>
inline LinkedList<T>& LinkedList<T>::operator+=(T val) {
	push_back(val);
	return *this;
}

template<typename T>
LinkedList<T>& LinkedList<T>::operator+=(const LinkedList<T>& lst) {
	for (iterator it = lst.begin(); it != lst.end(); ++it) {
		push_back(*it);
	}
	return *this;
}

template<typename T>
ostream& operator<<(ostream& os, LinkedList<T>& lst) {
	iterator it = lst.begin();
	os << *it;
	for (it; it != lst.end(); ++it)
		os << " -> " << *it;
	return os;
}

template<typename T>
istream& operator>>(istream& is, LinkedList<T>& lst) {
	T val;
	is >> val;
	lst.push_back(val);
	return is;
}