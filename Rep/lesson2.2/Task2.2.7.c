#include <stdio.h>

int main()
{
	int i, length;
	long num = 67;
	printf("Введте длину последовательности:\n");
	scanf("%d", &length);
	if(length<1)
		{
		printf("Введите число больше единицы:\n");
		scanf("%d", &length);
		}
	else for(i=0; i< length; i++)
	{
		num = (174*num + length)%2524;
		printf("%ld  ", num);
	}
	return 0;
}