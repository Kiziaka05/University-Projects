#include <iostream>
#include <ctime>
using namespace std;
int Eratos() {
    int k = 0;
    const int n = 999;
    bool arr[n + 1];
    for (int i = 0; i <= n; i++) {
        arr[i] = true;
    }
    for (int p = 2; p * p <= n; p++) {
        if (arr[p]) {
            for (int i = p* p; i <= n; i += p) {
                arr[i] = false;
            }
        }
    }
    for (int p = 100; p <= n; p++) {
        if (arr[p]) {
            k++;
           // cout << p << " ";
        }
    }
   // cout << endl<<"amount of odd numbers is: "<< k << endl;
    return k;
}
int main() {
    clock_t startTime = clock();
    int k;
    
    for (int t = 0; t <= 10000; t++) {
        k=Eratos();
    }
    clock_t endTime = clock();
    double seconds = (double(endTime - startTime)) / CLOCKS_PER_SEC;
    cout << k<<endl;
    cout << "Time of second algorithm is: " << seconds;  
    return 0;
}
