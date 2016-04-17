#include <stdio.h>
#include <math.h>

int main(void)
{
	int a,b,c;
	float D, x1, x2;
	printf("Введите коэффициенты квадратного уравнения:\n");
	printf("A при x^2:\n");
	scanf("%d", &a);
	printf("B при x:\n");
	scanf("%d", &b);
	printf("C cвободный член уравнения:\n");
	scanf("%d", &c);
	D = b*b - 4*a*c;
	if (D<0)
		printf("Дискриминант меньше нуля.\n");
	else{
	D = sqrt(D);
	x1 = (-b+D)/(2*a);
	x2 = (-b-D)/(2*a);
	printf("x1 = %g\n", x1);
	printf("x2 = %g\n", x2);
	}
	return 0;
}