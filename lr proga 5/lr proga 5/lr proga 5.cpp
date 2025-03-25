#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
    srand(time(NULL));
    int M; 
    int N; 
    int i, j; 
    int** a; 
    char F;
    int maxElement = -1000;
    int isIncreasing;
    printf("\nEnter M: ");
    scanf_s("%d", &M);
    printf("\nEnter N: ");
    scanf_s("%d", &N);
    if (M <= 0 || N <= 0) {
        printf("Invalid input. M and N should be greater than 0.\n");
        return 1; 
    }
    
    a = (int**)malloc(sizeof(int*) * M);
    for (i = 0; i < M; i++)
        a[i] = (int*)malloc(sizeof(int) * N);
    
 
    printf("Enter 1 if you want use random values or 2 if you want use your own values or z to cancel\n");
    scanf_s(" %c", &F);
    switch (F)
    {
    case '1':
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
              a[i][j] =rand()%101;
           
        }
    }
    break;
    case '2':
        for (i = 0; i < M; i++) {
            for (j = 0; j < N; j++) {
                scanf_s("%d", &a[i][j]);
            }
        }
        break;
    case 'z':
        break;
    }
   
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++)
            printf("%6d", a[i][j]);
        printf("\n");
    }
    bool flag = 1;
    
    for (int i = 0; i < M; i++) {
        isIncreasing = 1;
        for (int j = 1; j < N; j++) {
            if (a[i][j] < a[i][j - 1]) {
                isIncreasing = 0;
                break;
            }
        }
        if (isIncreasing) {
            if (flag) {
                maxElement = a[i][N - 1];
                flag = 0;
            }
            if (!flag) {
                if (a[i][N - 1] > maxElement) {
                    maxElement = a[i][N - 1];
                }
            }
        }
    }
  
    if (maxElement == -1000){
        printf("There is zero increasing rows");
    }
    else {

        printf("The maximum element among elements in increasing rows: %d\n", maxElement);
    }
    
    for (i = 0; i < M; i++) {
        free(a[i]);
    }
    free(a);
    return 0;
}