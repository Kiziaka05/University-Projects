#ifndef ARRAY_H_INCLUDE

#define ARRAY_H_INCLUDE


template <typename T>
struct Dynamicarray {
	T val;
	int capacity;
	T* mas;
	int current_size;
	Dynamicarray();
	void mypush(T val);
	void mypop();
	T& myget(int n);
	int mysize();
	void myclear();
	void relocatememory();
	void print(int index);
	~Dynamicarray();
	bool empty();
	T back();
	T front();
};
#include "Array.inl"

#endif