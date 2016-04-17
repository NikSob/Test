#include <stdio.h>

int main(void)
{
	char input;
	printf("Введите строку:\n");
	while ((input = getchar())!= '\n')
	{	
		if(input>='a'&& input<='z')
		putchar(input-32);
		else putchar(input);
	}
	return 0;
}