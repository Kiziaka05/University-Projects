#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
    srand(time(NULL));
    int n;
    printf("Enter amount of numbers n: ");
    scanf_s("%d", &n);
    if (n < 3) {
        printf(" n must be bigger than 3.\n");
        return 0;
    }
    else {
        double prev, current, next;
        prev = rand() % (101)-50;
        current = rand() % (101)-50;
        int i = 2;
        while (i < n) {
            next = rand() % (101)-50;
            if (prev < current && current < next) {
                
                printf("Natural i that, %lf < %lf < %lf: %d\n",prev ,current ,next ,i );
            }
            prev = current;
            current = next;
            i++;
        }
    }
return 0;
}
