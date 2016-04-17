#include <stdio.h>

int main(void)
{
	char num, begin=0;
	printf("Введите строку:\n");
	while((num=getchar())!='\n')
	{	
		if( num== begin)
			continue;
		begin = num;
		putchar(begin);
	}
	return 0;
}