#include <stdio.h>

int main(void)
{
	int one, two;
	printf("Введите первое число:\n");
	scanf("%d", &one);
	printf("Введите второе число:\n");
	scanf("%d", &two);
	printf("Сумма чисел равно %d\n", one + two);
	printf("Разность чисел равно %d\n", one - two);
	printf("Произведение чисел равно %d\n", one * two);
	printf("Частное чисел равно %.2f\n",(float) one/two);
	return 0;	
}