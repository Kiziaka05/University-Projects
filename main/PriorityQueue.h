#ifndef PRIORITYQUEUE_H_INCLUDE

#define PRIORITYQUEUE_H_INCLUDE

#include "BinaryHeap.h"

template <typename T>
struct PriorityQueue{
	BinaryHeap<T> priorityqueue;
	PriorityQueue();
	void push(T obj);
	T top();
	void pop();
	int size();
	bool empty();
	void clean();




};

#include "PriorityQueue.inl"

#endif