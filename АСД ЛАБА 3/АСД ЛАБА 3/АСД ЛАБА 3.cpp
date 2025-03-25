#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
void bubblesort(int* numbers, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (numbers[j] > numbers[j + 1]) {
                swap(numbers[j], numbers[j + 1]);
            }
        }
    }
}
int linsearch(int key,int* numbers,int size ,int first){
    int current=first;
    for (current;current<= size-1; current++) {
        if (numbers[current] ==key) {
            return current;
        }
    
    }
    return -1;
}
int binsearch(int* numbers, int size,int value) {
    int low = 0;
    int high = (size - 1);
    while (low <= high) {
        int mid = (high + low) / 2;
        if (numbers[mid] > value) { high = mid - 1; }
        else if (numbers[mid] < value) {
            low = mid + 1;
        }
        else return mid;
    }
    return -1;
}

int main() {
    srand(time(NULL));
    const int size = 1001;
    int key, value;
    int a[size];
    for (int i = 0; i < size; i++) {
        a[i] = rand() % 4001 - 2000;
        cout << a[i] << " ";
    }
    cout << endl;
    cout << endl;
    bubblesort(a, size);

    for (int i = 0; i < size; i++) {
        cout << a[i] << " ";
    }

    cout << endl << "Enter key" << endl;
    cin >> key;
    cout<<linsearch(key, a, size, 0);



    cout << endl << "Enter value" << endl;
    cin >> value;
    cout << binsearch(a, size, value);

   clock_t startTime = clock();
    for (int i = 1; i <= 10000; i++) {
      

      linsearch(key, a, size, 0);
    }
  
    clock_t endTime = clock();
    double seconds = (double(endTime - startTime)) / CLOCKS_PER_SEC; 
    cout << endl << "Time of this algorithm is: " << seconds;

    clock_t startTime2 = clock();
    for (int i = 1; i <= 10000; i++) {
        binsearch(a, size, value);
    }

    clock_t endTime2 = clock();
    double seconds2 = (double(endTime - startTime)) / CLOCKS_PER_SEC;
    cout << endl << "Time of this algorithm is: " << seconds2;
    
    return 0;
}