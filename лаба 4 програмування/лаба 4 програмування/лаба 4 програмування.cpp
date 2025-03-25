#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define N 5
int main(){
	srand(time(NULL));
	int nespad = 0;
	int Sum = 0;
	int a[N];
	int masi[N];
	int i;
	for (i = 0; i < N; i++){
		a[i] = rand() % 11 - 5;
		printf("%d ", a[i]);
	}
	for (i = 0; i < N; i++) {
		if (a[i] < 0) {
			a[i] = a[i] * a[i];
			masi[i] = i;
		}
		else masi[i] = -1;
	}
	printf("\n\n");
	for (int i = 0; i < N; i++){
		printf("%d ", a[i]);
	}
	for (i = 0; i < N-1; i++){
		if (a[i] > a[i + 1]) {
			break;
		}
		
	}
	if (i == N - 1) {
		printf("NonDecreasing\n");
		for (i = 0; i < N; i++){
			if (masi[i] == i) {
				a[i] =-sqrt(a[i]);
			}
			Sum += a[i];
		}
	}
	else{
		printf("Decreasing\n");
		for (i = 0; i < N; i++){
			Sum += a[i];
		}
	}
	printf("\n%d", Sum);
	return 0;
}
