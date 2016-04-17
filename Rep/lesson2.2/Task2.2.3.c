#include <stdio.h>

int main(void)
{
	char input;
	int num=1;
	printf("Введите строку, размер которой хотите узнать:\n");
	while ((input = getchar())!= '\n')
		num++;
	printf("Размер введённой строки %d байт(-а, -ов).\n", num );
	return 0;
}