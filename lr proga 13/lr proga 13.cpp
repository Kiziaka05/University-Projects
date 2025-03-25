#include <iostream>
#include <cmath>
using namespace std;
// Макрос для обчислення площі трикутника
#define AREA_TRIANGLE(a, b, c, area) \
    do { \
        if (a + b > c && a + c > b && b + c > a) { \
            double s = (a + b + c) / 2.0; \
            area = sqrt(s * (s - a) * (s - b) * (s - c)); \
        } else { \
            cerr << "Error: A triangle with such sides does not exist" << std::endl; \
            area = -1; \
        } \
    } while(0)

// Макрос для обчислення площі трапеції
#define AREA_TRAPEZOID(base1, base2, height, area) \
    do { \
        if (base1 > 0 && base2 > 0 && height > 0) { \
            area = ((base1 + base2) / 2.0) * height; \
        } else { \
            cerr << "Error: A trapezoid with these parameters does not exist" << std::endl; \
            area = -1; \
        } \
    } while(0)

int main() {
    double a, b, c, base1, base2, height, area;

 
    cout << "Enter the lengths of the sides of the triangle a, b and c: ";
    cin >> a >> b >> c;
   
    
    AREA_TRIANGLE(a, b, c, area);
    if (area != -1) {
        cout << "Area of the triangle: " << area << std::endl;
    }
    else {
        cout << "Enter the lengths of the bases of the trapezoid base1 and base2: ";
        cin >> base1 >> base2;
        cout << "Enter the height of the trapezoid: ";
        cin >> height;

        
        AREA_TRAPEZOID(base1, base2, height, area);
        if (area != -1) {
            cout << "The area of the trapezoid: " << area << std::endl;
        }
    }
    return 0;
}
