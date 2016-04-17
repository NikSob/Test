#include <stdio.h>

int main()
{
	int num, length=0, last=0;
	printf("Введите число, больше единицы:\n");
	scanf("%d", &num);
	while (num<0)
	{
		printf("Введите число, больше единицы:\n");
		scanf("%d", &num);
	}
	while (num/10 !=0)
		{
		length++;
		last += num%10;
		num = num/10;
		}
	printf("Количество введённых цифр %d, их сумма %d, их среднее значение %g.\n", length+1, 
	last+(num%10), (float) (last+(num%10))/(length+1));
	return 0;
}