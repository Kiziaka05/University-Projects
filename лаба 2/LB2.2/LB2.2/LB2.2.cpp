#include <iostream>
#include <ctime>
using namespace std;
int perV10(int O)
{
    int S = 0;
    for (int i = 0; O != 0; i++)
    {
        S += pow(8, i) * (O % 10);
        O = (O) / 10;
    }
    return S;
}
int perV8(int T) {
    int O = 0;
    int s, i = 1;
    while (T != 0) {
        s = T % 8;
        T /= 8;
        O += s * i;
        i *= 10;
    }
    return O;
}
int main(){
    clock_t startTime = clock();
    for (int i = 1; i <= 1000; i++) {
        if (i != perV10(perV8(i)))cout << "error";
      //  cout << "Number :" << i << " In octal: " << perV8(i) << " And back in decimal: " << perV10(perV8(i)) << endl;
    }
    clock_t endTime = clock();
    double seconds = (double(endTime - startTime)) / CLOCKS_PER_SEC;
    cout << "Time of third algorithm is: " << seconds;
    return 0;
}