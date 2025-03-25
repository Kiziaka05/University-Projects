
#include <cstdlib>
#include <ctime>
#include <iostream>
#include<vector>
using namespace std;
struct Heap
{
    int getLeftChild(int index)
    {
        return 2 * index + 1;
    }

    int getRightChild(int index)
    {
        return 2 * index + 2;
    }

    void siftDown(vector<int>& arr, int ArrSize, int index)
    {
        int leftChild = getLeftChild(index);
        int rightChild = getRightChild(index);
        int minChild = index;

        if (leftChild < ArrSize && arr[leftChild] < arr[minChild])
        {
            minChild = leftChild;
        }
        if (rightChild < ArrSize && arr[rightChild] < arr[minChild])
        {
            minChild = rightChild;
        }

        if (minChild == index)
        {
            return;
        }

        swap(arr[index], arr[minChild]);
        siftDown(arr, ArrSize, minChild);
    }

    void BuildHeap(vector<int>& arr, int k)
    {
        for (int i = (k - 2) / 2; i >= 0; i--)
        {
            siftDown(arr, k, i);
        }
    }

    int findKthLargest(vector<int>& arr, int k)
    {
        BuildHeap(arr, k);

        for (int i = k; i < arr.size(); i++)
        {
            if (arr[i] > arr[0])
            {
                swap(arr[0], arr[i]);
                siftDown(arr, k, 0);
            }
        }
        return arr[0];
    }
};

int main()
{
    vector<int> mas = {3,2,1,5,6,4};
    Heap heap;
    cout<<heap.findKthLargest(mas,2);

}

