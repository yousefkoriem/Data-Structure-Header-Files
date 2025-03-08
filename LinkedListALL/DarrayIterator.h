#pragma once


template<typename T>
class DarrayIterator {
	T* ptr;
public:
	DarrayIterator() : ptr(nullptr) {}
	DarrayIterator(T* ptr) : ptr(ptr) {}
	DarrayIterator(const DarrayIterator& it) : ptr(it.ptr) {}

	T& operator*() const { return *ptr; }

	DarrayIterator& operator++() {
		++ptr;
		return *this;
	}
	DarrayIterator& operator++(int) {
		DarrayIterator tmp = *this;
		ptr++;
		return tmp;
	}

	DarrayIterator& operator--() {
		--ptr;
		return *this;
	}
	DarrayIterator& operator--(int) {
		DarrayIterator tmp = *this;
		ptr--;
		return tmp;
	}

	DarrayIterator operator+(size_t x) {
		DarrayIterator tmp = *this;
		tmp->ptr += x;
		return tmp;
	}
	DarrayIterator operator+=(size_t x) {
		this->ptr += x;
		return *this;
	}
	DarrayIterator operator-(size_t x) {
		DarrayIterator tmp = *this;
		tmp->ptr -= x;
		return tmp;
	}
	DarrayIterator operator-=(size_t x) {
		this->ptr -= x;
		return *this;
	}

	bool operator==(const DarrayIterator& it) const { return ptr == it.ptr; }
	bool operator!=(const DarrayIterator& it) const { return ptr != it.ptr; }

	DarrayIterator& operator=(const DarrayIterator & it){
		this->ptr = it.ptr;
		return *this;
	}
};