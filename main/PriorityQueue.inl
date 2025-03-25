#include "Array.h"
#include "BinaryHeap.h"
#include "PriorityQueue.h"
#include <iostream>
#include <time.h>
#include <string>
#include <algorithm>


using namespace std;
//конструктор
template <typename T>
PriorityQueue<T>::PriorityQueue() {
	priorityqueue;

}


//вставка елементу
template <typename T>
void PriorityQueue<T>::push(T obj) {
	priorityqueue.insert(obj);

}


//верхній елемент
template <typename T>
T PriorityQueue<T>::top() {
	return priorityqueue.top();

}


//видалення верхнього
template <typename T>
void PriorityQueue<T>::pop() {
	priorityqueue.remove_top();

}


//розмір черги
template <typename T>
int PriorityQueue<T>::size() {
	return priorityqueue.size();

}


//перевірка на порожність
template <typename T>
bool PriorityQueue<T>::empty() {
	return priorityqueue.empty();
}


//очистка
template <typename T>
void PriorityQueue<T>::clean() {
	priorityqueue.clean();

}
