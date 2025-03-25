#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;
void task5(double x0,double y0,double r,double xt,double yt) {
    double V = sqrt(pow((xt - x0), 2) + pow((yt - y0), 2));
    if (V<=r) {
        cout << "belongs to the circle";

    }
    else cout << "did not belongs to the circle";
}
int main() {
    cout << "pick task 1-5" << endl;
    char z;
    cin >> z;
    switch (z)
    {
    case '1'://task 1
        double x1, x2, y1, y2;
        cout << "Enter coordinates (x1, y1, x2, y2): ";
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 == x2) {
            cout << "Error! Division by zero." << endl;
        }
        else {
            double a = (y1 - y2) / (x1 - x2);
            cout << "coefficient: " << a << endl;
        }
        break;
    case '2':// task 2
        int a, b, c;
        cout << "enter 3 numbers";
        cin >> a >> b >> c;

        if (a < 0 || a > 2) {
            cout << "Number a: " << a << " does not belongs to the interval [0,2]" << endl;
        }
        if (b < 0 || b > 2) {
            cout << "Number b: " << b << " does not belongs to the interval [0,2]" << endl;
        }
        if (c < 0 || c > 2) {
            cout << "Number c: " << c << " does not belongs to the interval [0,2]" << endl;
        }
        else if (a >= 0 && a <= 2 && b >= 0 && b <= 2 && c >= 0 && c <= 2) {
            cout << "all numbers belong to the interval" << endl;
        }
        break;
    case '3': // task 3
        int x, y;
        cout << "Enter interval x<y" << endl;
        cin >> x >> y;
        if (x < y) {
            int NumSum = 0;
            for (x; x <= y; x++) {
                cout << x << " ";
                NumSum++;
            }
            cout << endl << "There are " << NumSum << " Numbers";
        }
        else
            cout << "x should be smaller than y";
        break;
    case '4': // task 4
        int arr[99];
        for (int i = 0; i < 99; i++) {
            arr[i] = rand() % 100 + 1;    //1-100
            cout << arr[i] << " ";
        }
        cout << endl << "replace every number with  even index with 0 " << endl;
        for (int i = 0; i < 99; i++) {
            if (i % 2 == 0)
                arr[i] = 0;  //1-100
            cout << arr[i] << " ";
        }
        break;
    case '5': // task 5
        cout << "enter x0,y0,r and x1,y1" << endl;
        double x0, y0, r, xt, yt;
        cin >> x0 >> y0 >> r >> xt >> yt;
        task5(x0, y0, r, xt, yt);
        break;
    default:
        cout << "No answer";
        break;
    }
    return 0;
}