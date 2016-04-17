#include <stdio.h>

int main(void)
{
	char num, begin=0;
	printf("Введите строку:\n");
	while((num=getchar())!='\n')
	{
		begin=(begin>num) ? begin : num;
	}
	printf("Наибольший ASCII код имеет символ: %c\n", begin);
	return 0;
}
