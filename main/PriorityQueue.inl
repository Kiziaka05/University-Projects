#include "Array.h"
#include "BinaryHeap.h"
#include "PriorityQueue.h"
#include <iostream>
#include <time.h>
#include <string>
#include <algorithm>


using namespace std;
//�����������
template <typename T>
PriorityQueue<T>::PriorityQueue() {
	priorityqueue;

}


//������� ��������
template <typename T>
void PriorityQueue<T>::push(T obj) {
	priorityqueue.insert(obj);

}


//������ �������
template <typename T>
T PriorityQueue<T>::top() {
	return priorityqueue.top();

}


//��������� ���������
template <typename T>
void PriorityQueue<T>::pop() {
	priorityqueue.remove_top();

}


//����� �����
template <typename T>
int PriorityQueue<T>::size() {
	return priorityqueue.size();

}


//�������� �� ���������
template <typename T>
bool PriorityQueue<T>::empty() {
	return priorityqueue.empty();
}


//�������
template <typename T>
void PriorityQueue<T>::clean() {
	priorityqueue.clean();

}
