#include <stdio.h>

int main(void)
{
	float a,b,c;
	int count;
	char operation;
	printf("Введите необходимую операцию или нажмите любую букву для завершения:\n");
	printf("Внимание! Процесс вычисления остатка деления выполняется только с \n");
	printf("целыми числами. Также возможно возведение только в целую степень.\n");
	while(scanf("%f %c %f", &a, &operation, &b))
	{
		switch (operation)
		{
			case '+' : printf("%g%c%g = %g", a,operation,b, a+b);
					continue;
			case '-' : printf("%g%c%g = %g", a,operation,b, a-b);
					continue;
			case '*' : printf("%g%c%g = %g", a,operation,b, a*b);
					continue;
			case '/' : 
				if( b==0)
				{
				printf("На ноль делить нельзя\n"); 
				continue;
				} 
				printf("%g%c%g = %g", a,operation,b, a/b);
				continue;
			case '%' : 
				if( b==0)
				{
				printf("На ноль делить нельзя\n"); 
				continue;
				} 
				printf("%d%c%d = %d", (int) a,operation,(int) b,(int) a% (int) b);
				continue;
			case '^' :  c = a;
						for (count=1; count<b; count++)
						c *= a;
						printf("%g%c%d = %g\n", a, operation, count, c);
			case 'q' : break;
		}
	}
	printf("Вычисления завершены.\n");
	return 0;
}