#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
void fishperest(int* num, int size) {
    srand(time(NULL));
    for (int i = size-1; i > 1; i--) {
       int j = rand()%(i+1);
       swap(num[i], num[j]);
    }
}
int sumOfDigits(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}
void Selectsort(int* num, int size) {
    for (int i = 0; i < size ; i++) {
        int min = i;
        for (int j = 0; j < size; j++) {
            int a= sumOfDigits(num[j]);
            int b= sumOfDigits(num[min]);
            if (a<b) {
             min = j;
             swap(num[i], num[min]);
            }
            if (sumOfDigits(num[j]) == sumOfDigits(num[min])){
                if (num[j] > num[min]) {
                    min = j;
                    swap(num[i], num[min]);
                }
            }

        }
    }
}

int main() {
    srand(time(NULL));
    const int size = 201;
    int a[size];
    for (int i = 0; i < size; i++) {
        a[i] = i;
        cout << a[i] << " ";
    }
    cout << endl << endl<<"array after shuffling" << endl << endl;

    fishperest(a, size);

    for (int i = 0; i < size; i++) {
        cout << a[i] << " ";
    }
    cout << endl << endl <<"sorted array"<< endl << endl;

    Selectsort(a, size);

    for (int i = 0; i < size; i++) {
        cout << a[i] << " ";
    }
    return 0;
}