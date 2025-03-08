#pragma once
#include "DarrayIterator.h"
#include <iostream>
using namespace std;

#define MAX_SIZE 100

template<typename T>
class Darray {
	T* arr;
	size_t sz;
	void copyArray(const Darray<T>& Arr);
public:
	using iterator = DarrayIterator<T>;
	Darray() {
		T* arr = new T[MAX_SIZE]{};
		sz = 0;
	}
	Darray(const Darray<T>& Arr) {
		copyArray(Arr);
	}
	~Darray() {
		distroyArray();
	}

	void initalizeArray();
	void distroyArray();

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

	T& front() const { return arr[0]; }
	T& back() const { return arr[sz - 1]; }


	iterator begin() const { return iterator(arr); }
	iterator end() const { return iterator(arr+sz); }

};