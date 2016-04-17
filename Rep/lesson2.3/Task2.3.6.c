#include <stdio.h>

int main(void)
{
	int perc, i, space;
	printf("Введите количесвто процентов:\n");
	scanf("%d", &perc);
	while (perc<0 || perc>100)
	{
		printf("Введите корректное число:\n"); 
		scanf("%d", &perc);
	}
	printf("[");
	perc/= 5;
	for(i=0; i<perc; i++)
		printf("*");
	space = 20 - perc;
	for(i=0; i<space; i++)
		printf(" ");
	printf("]\n");
	return 0;
}
