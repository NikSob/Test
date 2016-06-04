#include <stdio.h>
#define SIZE 1000

void change(char * a, char * b);
void printing(char * a, int b);

int main()
{	
	int i=0, g =0;
	char massiv1[SIZE], massiv2[SIZE];
	printf("Программа содержит функцию, для копирования строк.\n");
	printf("Работу программы мы можем рассмотреть на примере.\n");
	printf("Введите строку, которая впоследстии будет копированна:\n");
	while((massiv1[i]=getchar()) != '\n' && i<SIZE+1)
		i++;
	printf("Введите строку, которая впоследстии будет заменена:\n");
	while((massiv2[g]=getchar()) != '\n' && i<SIZE+1)
		g++;
	printf("Ваши строки до копирования:\n");
	printing(massiv1, i);
	printing(massiv2, g);
	change(massiv1, massiv2);
	printf("Ваши строки после копирования:\n");
	printing(massiv1, i);
	printing(massiv2, i);
	return 0;
}	

void change(char * a, char * b)
{
	int c;
	for(c=0; c<SIZE; c++)
	*(b+c) = *(a+c);
}

void printing(char * a, int b)
{
	int c;
	for(c=0; c<b; c++)
	printf("%c", *(a+c));
	printf("\n");
}