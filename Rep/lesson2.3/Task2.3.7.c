#include <stdio.h>

int main(void)
{
	long  c, z;
	int length, i, g, k, m, length2;
	printf("Введите выосту треугольника Паскаля:\n");
	scanf("%d", &length);
	while(length<0)
	{
		printf("Введите положительное число:\n");
		scanf("%d", &length);
	}
	length2=length;
	for(i=1; i<=length; i++)
	{
		for(g=1; g<length2; g++)
		printf("   ");
		m=i;
	 	for (k=1, c=1, z=1; k<=i; k++)
	 	{
	 		if (k==1)
	 		{	
	 			printf("%-5d ", 1);
	 			continue;
	 		}
	 		m-- ;
	 		z *= m;
	 		c *= k-1;	
	 		printf("%-5ld ", z/c);
		}
		printf("\n");
		length2--;
	}	
	return 0;
}