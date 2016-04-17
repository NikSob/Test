#include <stdio.h>
#define MAX(a,b) ((a>b) ?  a : b)

int main() 
{
	int i, length,num = 67, num2;
	printf("Введте количество пар:\n");
	scanf("%d", &length);
	printf("Перове число     Второе число     Большее число\n");
	length= length*2;
	if(length<0)
		{
		printf("Введите число больше нуля:\n");
		scanf("%d", &length);
		length=length*2;
		}
	else for(i=0; i< length; i++)
	{
		num = (174*num + length)%2524;
		printf("%-17d", num);
		if(i%2==1)
			printf("%d\n", MAX(num,num2));;
		if(i%2==0 )
		{
			num2 = num;
		}
	}
	return 0;
}