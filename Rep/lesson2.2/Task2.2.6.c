#include <stdio.h>

int main()
{
	int input, i;
	long num=1;
	printf("Введите число, факториал которого необходимо найти:\n");
	scanf("%d", &input);
	if (input<0)
	{
		printf("Введите воложительное число\n");
	}
	if ( input == 0)
		printf("0! = 1\n");
	if (input>0)
	{ 
		printf("%d! = ", input);
		for(i=1; i <= input; i++)
		num *= i;
		printf("%ld\n", num);
	}
	return 0;
}