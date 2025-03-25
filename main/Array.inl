#include "Array.h"
#include "Binaryheap.h"
#include "PriorityQueue.h"
#include <iostream>
#include <time.h>
#include <string>

using namespace std;
	//�����������
	template <typename T>
	Dynamicarray<T>::Dynamicarray() {
		T val;
		capacity = 1000;
		mas = new T[capacity];
		current_size = 0;
	}


	//���������� ��������
	template <typename T>
	void Dynamicarray<T>::mypush(T val){
		if (current_size >= capacity) {
			relocatememory();
		}
		mas[current_size] = val;
		current_size++;
	}


	//��������� ��������
	template <typename T>
	void Dynamicarray<T>::mypop() {
		if (current_size == 0) {
			cout << "Array is empty!\n";
		}
		else {
			
			current_size--;
		}
	}


	//������� �� ��������
	template <typename T>
	T& Dynamicarray<T>::myget(int n) {
		if (n < 0 || n >= current_size) {
			cout << "Index out of range." << endl;
		}
		return mas[n];
	}


	//����� ���������� ������
	template <typename T>
	int Dynamicarray<T>::mysize() {
		return current_size;
	}


	//������� ���������� ������
	template <typename T>
	void Dynamicarray<T>::myclear() {
		current_size == 0;

	}


	//����������� ���'��
	template <typename T>
	void Dynamicarray<T>::relocatememory() {
		int newcapacity = 2 * capacity;
		T* newmas = new T[newcapacity];

		memcpy(newmas, mas, sizeof(T) * capacity);

		delete[] mas;

		mas = newmas;
		capacity = newcapacity;
	}


	//�������������
	template <typename T>
	Dynamicarray<T>:: ~Dynamicarray() {
		delete[] mas;
	}


	//��������� ������
	template <typename T>
	void Dynamicarray<T>::print(int index) {
		cout << mas[index];
	}


	//�������� �� ���������
	template <typename T>
	bool Dynamicarray<T>::empty() {
		if (current_size == 0) {
			return 1;

		}
		else return 0;

	}


	//������� �������
	template <typename T>
	T Dynamicarray<T>::back() {
		return mas[current_size-1];
	}


	//������ �������
	template <typename T>
	T Dynamicarray<T>::front() {
		return mas[0];
	}