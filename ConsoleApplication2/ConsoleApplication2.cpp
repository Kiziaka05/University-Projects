#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void rearrangeVector(int arr[], int n, int chunkSize) {
    int i, j;
    //if(i%19==0){}
    // Виводимо першу частину чисел без змін
    for (i = 0; i < chunkSize; i++) {
        printf("%d ", arr[i]);
    }
    // Міняємо наступні блоки чисел з наступними
    for (i = chunkSize; i < n - chunkSize; i += 2 * chunkSize) {
        for (j = 0; j < chunkSize; j++) {
            swap(&arr[i + j], &arr[i + chunkSize + j]);
        }
    }
    // Виводимо другу частину чисел без змін
    for (i = chunkSize; i < n; i++) {
        printf("%d ", arr[i]);
    }
}

int main() {
    int arr[] = { -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int chunkSize = 5; // Розмір кожного блоку

    rearrangeVector(arr, n, chunkSize);

    return 0;
}
