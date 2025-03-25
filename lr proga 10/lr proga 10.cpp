#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;
int main() {
	int n;
	int k=0;
	int max = 0;
	scanf_s("%d", &n);
	char *mas=(char*)malloc((n+1)*sizeof(char));
	int i;
	printf("Enter your string: ");
	*mas = getchar();
	gets_s(mas,n+1);
	for (i = 0; i < strlen(mas); i++)
	{
		if (mas[i] == ' ') {
			k++;
			if (k > max){
				max = k; }
		}
		else{k = 0;}
	}
	printf("Max amount of spaces :%d", max);
	return 0;
}