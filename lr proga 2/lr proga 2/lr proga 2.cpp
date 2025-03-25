#include <stdio.h>
#include <math.h>
int main() {
    double x, eps1 = 0.01, eps2 = 0.0001,f=1.0;
    double s1 = 1.0;
    int n = 0;
    printf("Enter x: ");
    scanf_s("%lf", &x);
    if (fabs(x) < 1) {
        double rec = -x * x;
        while (fabs(f) > eps1) {
            f *= rec;
            s1 += f;
            n++;
        }
        printf("Result for eps1 = 0.01: S = %.6f, n = %d\n", s1, n);
        f = 1.0;
        double s2 = 1.0;
        n = 0;
        while (fabs(f) > eps2) {
            f *= rec;
            s2 += f;
            n++;
        }
        printf("Result for eps2 = 0.0001: S = %.6f, n = %d\n", s2, n);

        printf("S=1/(1+x*x),S=%f\n", 1 / (1 + x * x));
    }
    return 0;
}
