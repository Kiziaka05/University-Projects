#ifndef BINARYHEAP_H_INCLUDE

#define BINARYHEAP_H_INCLUDE
#include "Array.h"


template <typename T>
struct BinaryHeap {
private:
	int height;
	Dynamicarray<T> heap;

	int getParent(int index);
	int getLeftChild(int index);
	int getRightChild(int index);

	void siftUp(int index);
	void siftDown(int index);
public:

	BinaryHeap();

	T top();
	T back();

	void remove_top();
	void insert(T& value);
	
	void printHeap();
	void clean();
	int size();
	bool empty();
};


#include "BinaryHeap.inl"

#endif