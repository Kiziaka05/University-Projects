#include "Array.h"
#include "BinaryHeap.h"
#include <iostream>
#include <time.h>
#include <string>
#include <algorithm>


using namespace std;


//конструктор
template <typename T>
BinaryHeap<T>::BinaryHeap(){
    heap;
    
}


//індекс батьківського
template <typename T>
int BinaryHeap<T>::getParent(int index){
    return (index - 1) / 2;

}


//індекс лівого дочірнього
template <typename T>
int BinaryHeap<T>::getLeftChild(int index){
    
    return 2 * index + 1;
}


//індекс правого дочірнього
template <typename T>
int BinaryHeap<T>::getRightChild(int index){
    
    return 2 * index + 2;
}


//просіювання догори
template <typename T>
void BinaryHeap<T>::siftUp(int index){
    while (index > 0 && heap.myget(index) > heap.myget(getParent(index))) {
        swap(heap.myget(index), heap.myget(getParent(index)));
        index = getParent(index);
    }

}


//просіювання вниз
template <typename T>
void BinaryHeap<T>::siftDown(int index) {
    int largest = index;
    int leftChildIndex = getLeftChild(index);
    int rightChildIndex = getRightChild(index);
    if (leftChildIndex < heap.mysize() && heap.myget(leftChildIndex) > heap.myget(largest))
        largest = leftChildIndex;

    if (rightChildIndex < heap.mysize() && heap.myget(rightChildIndex) > heap.myget(largest))
        largest = rightChildIndex;

    if (largest != index) {
        swap(heap.myget(index), heap.myget(largest));
        siftDown(largest);
    }
}


//видалити верхній
template <typename T>
void BinaryHeap<T>::remove_top() {
    if (heap.empty())
        throw std::out_of_range("Heap is empty");

    T maxData = heap.myget(0);
    heap.myget(0) = heap.back();
    heap.mypop();
    siftDown(0);
   
}


//вставка елементу
template <typename T>
void BinaryHeap<T>::insert(T& value) {
    heap.mypush(value);
    int index = heap.mysize() - 1;
    siftUp(index);
}


//виведення купи
template <typename T>
void BinaryHeap<T>::printHeap()  {
    
    std::cout << "Heap elements: "<<endl;
    for (int i = 0; i < heap.current_size;i++) {
        cout <<heap.myget(i)<<endl;
    }
    cout << endl;


}


//останній елемент
template <typename T>
T  BinaryHeap<T>::back(){
    if (heap.empty())
        throw std::out_of_range("Heap is empty");

    return heap.back();
}


//верхній елемент
template <typename T>
T  BinaryHeap<T>::top()  {
    if (heap.empty())
        throw std::out_of_range("Heap is empty");

    return heap.front();
}


//розмір купи
template <typename T>
int BinaryHeap<T>::size(){
  
    return heap.mysize();
}


//перевірка на порожність
template <typename T>
bool BinaryHeap<T>::empty() {

    return heap.empty();
}