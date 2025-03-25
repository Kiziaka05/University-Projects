#include <queue>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "PriorityQueue.h"
#include "BinaryHeap.h"
#include "Array.h"

//варіант 2
using namespace std;

//сортування купою за спаданням
struct HeapSort {

  
public:
    //лівий і правий дочірній елемент
    static int getLeftChild(int index)
    {
        return 2 * index + 1;
    }
    static int getRightChild(int index)
    {
        return 2 * index + 2;
    }


    //метод побудови купи з вихідного масиву
    static void buildHeap(int* array, int arrSize) {
        for (int i = arrSize / 2; i >= 0; --i) {
            seftDown(array, arrSize, i);
        }
    }


    //Просіювання вниз
    static void seftDown(int* array, int arrSize, int index) {
        int largest = index;
        int leftChild = getLeftChild(index);
        int rightChild = getRightChild(index);

        if (leftChild < arrSize && array[leftChild] > array[largest])
            largest = leftChild;

        if (rightChild < arrSize && array[rightChild] > array[largest])
            largest = rightChild;

        if (largest != index) {
            swap(array[index], array[largest]);
            seftDown(array, arrSize, largest);
        }
    }


    //Сортування масиву
    static void heapSort(int* array, int arrSize) {
        buildHeap(array, arrSize);
        for (int i = arrSize - 1; i > 0; --i) {
            swap(array[0], array[i]);
            seftDown(array, i, 0);
        }
    }
};

//структура за завданням з перегруженими операторами
struct Data {
    int hp;
    int skill;
    int damagepoint;


    Data() {
        hp = rand()%101;
        skill = rand() % 1001;
        damagepoint = rand() % 1001;
    }


    bool operator<(const Data& other) const
    {
        if (this->hp != other.hp) {
            return hp < other.hp;
        }
        if (this->skill != other.skill) {
            return skill < other.skill;
        }
        return damagepoint < other.damagepoint;
    }


    bool operator>(const Data& other) const
    {
        if (this->hp != other.hp) {
            return hp > other.hp;
        }
        if (this->skill != other.skill) {
            return skill > other.skill;
        }
        return damagepoint > other.damagepoint;
    }


    bool operator==(const Data& other) const
    {
        return (this->hp == other.hp &&
            this->skill == other.skill && this->damagepoint == other.damagepoint);
    }


    friend std::ostream& operator<< (std::ostream& out, const Data& data) {

        out << " Bot( " << data.hp << ", " << data.skill << ", " << data.damagepoint << ") ";

        return out;
    };

};


//тестування швидкості
template <typename T>
float testPriorityQueueSpeed(T&& priorityQueue)
{
    const int iters = 200000;

    clock_t timeStart = clock();
    for (int i = 0; i < iters; i++)
    {
        int insertDataAmount = rand() % 6 + 5;
        for (int j = 0; j < insertDataAmount; j++)
        {
            priorityQueue.push(Data());
        }

        priorityQueue.top();
        priorityQueue.pop();
    }
    clock_t timeEnd = clock();
    float time = (float(timeEnd - timeStart)) / CLOCKS_PER_SEC;

    return time;
}

//тестування приорітетної черги 
bool testPriorityQueue()
{
    srand(time(NULL));

    const int iters = 20000;

    PriorityQueue<Data> myPriorQueue;
    priority_queue<Data> stlPriorQueue;

    bool isDataEqual = true;
    for (int i = 0; i < iters; i++)
    {
        int insertDataAmount = rand() % 6 + 5;
        for (int j = 0; j < insertDataAmount; j++)
        {
            Data randData = Data();
            myPriorQueue.push(randData);
            stlPriorQueue.push(randData);
        }

        if (!(myPriorQueue.top() == stlPriorQueue.top()))
        {
            isDataEqual = false;
            cerr << "Comparing failed on iteration " << i << endl << endl;
            break;
        }

        int removeDataAmount = rand() % insertDataAmount;
        for (int j = 0; j < removeDataAmount; j++)
        {
            myPriorQueue.pop();
            stlPriorQueue.pop();
        }
    }

    int myQueueSize = myPriorQueue.size();
    int stlQueueSize = stlPriorQueue.size();

    float stlTime = testPriorityQueueSpeed<priority_queue<Data>>(priority_queue<Data>());
    float myTime = testPriorityQueueSpeed<PriorityQueue<Data>>(PriorityQueue<Data>());

    cout << "My PriorityQueue:" << endl;
    cout << "Time: " << myTime << ", size: " << myQueueSize << endl;
    cout << "STL priority_queue:" << endl;
    cout << "Time: " << stlTime << ", size: " << stlQueueSize << endl << endl;

    if (isDataEqual && myQueueSize == stlQueueSize)
    {
        cout << "The lab is completed" << endl << endl;
        return true;
    }

    cerr << ":(" << endl << endl;
    return false;
}

//тестування сортування купою
void testtime() {

    const int iters = 200000;

    int arr[iters];
    int j = 1;
    for (int i = 0; i < iters; i++)
    {
       
        arr[i] =j;
        j++;
       
    }
    clock_t timeStart = clock();
    HeapSort heap;
    heap.heapSort(arr, iters);
    clock_t timeEnd = clock();
    float time = (float(timeEnd - timeStart)) / CLOCKS_PER_SEC;
    cout << "My HeapSort time " << time << endl;
    clock_t timeStart1 = clock();
    sort(arr, arr + iters);
    clock_t timeEnd1 = clock();
    float time1 = (float(timeEnd1 - timeStart1)) / CLOCKS_PER_SEC;
    cout << "STL sort time " << time1;


}


int main() {
 srand(time(NULL));
 /* BinaryHeap<Data>Myheap;
    Dynamicarray<Data> Myarray;
  
    for (int i = 0; i < 10; i++) {
        Data randdata = Data();
        cout << randdata;
        Myheap.insert(randdata);
    }
    int size=Myarray.mysize();
    cout << size;
    Myarray.myget(1);
    Myarray.mypop();
   
    Myheap.printHeap();
    Myheap.remove_top();
    cout << endl;
    Myheap.printHeap();*/

    testPriorityQueue();

    testtime();
  
    return 0;
}

