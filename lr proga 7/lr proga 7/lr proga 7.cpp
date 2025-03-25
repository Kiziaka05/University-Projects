#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void arrgen(int* a, int N) {
    for (int j = 0; j < N; j++) {
        a[j] = rand() % 101;
    }
}

void print(int* a, int N) {
    for (int j = 0; j < N; j++) {
        printf("%6d", a[j]);
    }
    printf("\n");
}

int sum(int* a, int size, int index) {
    if (index >= size) {
        return 0;
    }
    else {
        return a[index] + sum(a, size, index + 2);
    }
}

int* memory(int size) {
    int* arr = (int*)malloc(size * sizeof(int));
    return arr;
}

int main() {
    srand(time(NULL));
    int size;

    printf("Enter size of array: ");
    scanf_s("%d", &size);

    int* a = memory(size);
    arrgen(a, size);
    print(a, size);

    int result = sum(a, size, 1);
    printf("sum: %d\n", result);

    
    free(a);

    return 0;
}