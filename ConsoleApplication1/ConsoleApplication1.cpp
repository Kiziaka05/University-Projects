#include <stdio.h>
#include <string.h>
#include <math.h>
#include <Windows.h>
using namespace std;
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
int const n = 11;
char str[n]; //рядок ВЕЖМНОПРСТ
char code[n];//рядок шифру 469520336
char key[9];//рядок ключа 1243
int i;
printf("Введіть зашифрований рядок: ");
gets_s(str);
printf("Ваш зашифрований рядок: ");
puts(str);
printf("\n");
printf("Введіть рядок шифру: ");
gets_s(code);
printf("Ваш рядок шифру: ");
puts(code);
printf("\n");
printf("Введіть ключ: ");
gets_s(key);
printf("Ваш ключ: ");
puts(key);
printf("\n");
int j=0;
printf("Розшифрований рядок: ");
for (int i = 0; i < strlen(code); i++) {//розшифровка
    if (j == strlen(key))
        j = 0;
    int code_int = code[i] - '0';
    int key_int = key[j] - '0';
    int result = code_int - key_int;
    if (result < 0) { result = 10 - abs(result); }
    if (j < strlen(key))
        j++;
   // printf("%d\n", result);
    printf("%c", str[result]);
}
return 0;
}