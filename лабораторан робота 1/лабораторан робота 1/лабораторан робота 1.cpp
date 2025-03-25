#include <stdio.h> /*Виклик головного модуля функцій введення-виводу */
#include <math.h> /* Виклик головного модуля математичних функцій */
int  main() /* Опис головної функції */
{
	char F,F1;
	float a,b,x0,x,c,k,y;

	printf("Enter 1 for first task or 2 for task 2 or z to cancel\n");
	F = getchar();
	
	switch (F)
	{
	case '1':
		printf("Enter 1 if you want use standart values or 2 if you want use your own values or z to cancel\n");
		getchar();
		F1 = getchar();
		switch (F1)
		{
			case '1':
				a = 9.6;
				b = 8.2;
				c = 2.0;
				k = 0.7;
				x = log(a + pow(c, 2)) + pow(sin(c / b),2);
				y = exp(-k * c) * ((c + sqrt(c + a)) / (c - sqrt(fabs(c - b))));
				printf("x=%f", x);
				printf(" ");
				printf("y=%f", y);
				break;
			case '2':
				scanf_s("%f%f%f%f", &a,&b,&c,&k);
				x = log(a + pow(c, 2)) + pow(sin(c / b), 2);
				y = exp(-k * c) * ((c + sqrt(c + a)) /( c - sqrt(fabs(c - b))));
				printf("x=%f", x);
				printf(" ");
				printf("y=%f", y);
				break;
			case 'z':
				break;
		}


		break;
	case '2':
		
		a = 2.8;
		b = -0.3;
		x0 = 0.1;
		for (x = 1; x <= 2.1; x = x + x0) {
			if (fabs(x-1.2)<x0/100)
			{
				y = a / x + sqrt(pow(x, 2) + 1);
			}
			else if (x < 1.2)
			{
				y = a * x + b * x;
			}
			else
			{
				y = (a + b * x) / (sqrt(pow(x,2) + 1));
			}
			printf("x=%f", x);
			printf(" ");
			printf("y=%f", y);
			printf("\n");
		}
		
		
		break;

	case 'z':
		break;
	}
} 
