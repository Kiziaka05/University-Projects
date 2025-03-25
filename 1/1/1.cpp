#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;
bool isPrime(int n) {
    if (n < 1) {
        return false;
    }
    bool isPrime = true;
        for (int i = 2; i*i <=n;i++) {
            if (n % i == 0) {
                isPrime = false;
                break;
            }
        
        }
    return isPrime;     
}
int main(){
    int k = 0;
    clock_t startTime = clock();
    for (int t = 0; t <=10000; t++) {
        k = 0;
        for (int i = 100; i <= 999; i++) {
            if (isPrime(i)) {
                //   cout << i << " ";
                k++;
            }
        }

    }
    clock_t endTime = clock();
    double seconds = (double(endTime - startTime)) / CLOCKS_PER_SEC;
    cout<<endl<< "amount of odd numbers is: " << k<<endl;
    cout<<"Time of first algorithm is: "<<seconds; 
}

