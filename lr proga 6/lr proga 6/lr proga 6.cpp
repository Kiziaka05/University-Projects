#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void arrgen(int*** a, int M, int N) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            (*a)[i][j] = rand() % 101;
        }
    }
}
void memory(int*** a, int M, int N) {
    *a = (int**)malloc(sizeof(int*) * M);
    for (int i = 0; i < M; i++) {
        (*a)[i] = (int*)malloc(sizeof(int) * N);
    }
}
void print(int*** a, int M, int N) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            printf("%6d", (*a)[i][j]);
        }
        printf("\n");
    }
}
void findab(int*** a, int M, int N, int left, int right) {
    int sum = 0;
    int K = 0;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if ((*a)[i][j] > left && (*a)[i][j] < right) {
                sum+=(*a)[i][j];
                K++;
            }
        }
    }
    printf("\nThere are %d numbers in range a,b\n", K);
    printf("The sum of numbers is %d\n", sum);

}
int main() {
    srand(time(NULL));
    int M,N;
    int K,L;
    int **X, **Y;
    int a, b;
    printf("\nEnter M: ");
    scanf_s("%d", &M);
    printf("\nEnter N: ");
    scanf_s("%d", &N);
    printf("\nEnter K: ");
    scanf_s("%d", &K);
    printf("\nEnter L: ");
    scanf_s("%d", &L);
    if (M <= 0 || N <= 0|| K<= 0 || L <= 0) {
        printf("Invalid input. M,N,K,L should be greater than 0.\n");
        return 1;
    }
    memory(&X, M, N);
    arrgen(&X, M, N);
    print(&X,M,N);
    memory(&Y, K, L);
    arrgen(&Y, K, L);
    printf("\n\n");
    print(&Y, K, L);
    printf("\nEnter a: ");
    scanf_s("%d", &a);
    printf("\nEnter b: ");
    scanf_s("%d", &b);
    findab(&X, M, N, a, b);
    printf("\n\n");
    findab(&Y, K, L, a, b);
    for (int i = 0; i < M; i++) {
        free(X[i]);
    }
    free(X);
    for (int i = 0; i < K; i++) {
        free(Y[i]);
    }
    free(Y);
    return 0;
}