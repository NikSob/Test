#include <stdio.h>

void change(char * a, char * b);
void printing(char * a, int b);

int main()
{	
	int i=0, g =0;
	char massiv1[255], massiv2[255];
	printf("Программа содержит функцию, для копирования строк.\n");
	printf("Работу программы мы можем рассмотреть на примере.\n");
	printf("Введите строку, которая впоследстии будет копированна:\n");
	while((massiv1[i]=getchar()) != '\n' && i<256)
		i++;
	printf("Введите строку, которая впоследстии будет заменена:\n");
	while((massiv2[g]=getchar()) != '\n' && i<256)
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
	for(c=0; c<255; c++)
	*(b+c) = *(a+c);
}

void printing(char * a, int b)
{
	int c;
	for(c=0; c<b; c++)
	printf("%c", *(a+c));
	printf("\n");
}