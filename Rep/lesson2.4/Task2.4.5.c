#include <stdio.h>

int main()
{
	float first, ifirst, second, isecond, mul,imul, sum, isum, a,b, ia, ib, result, iresult;
	printf("Введите значение первого комплексного сопротивления.\n");
	printf("Значения вещественной и мнимой части вводится численно\n");
	printf("через пробел (например 27 0.5) :\n");
	scanf("%f %f", &first, &ifirst);
	printf("Введите значение второго комплексного сопротивления.\n");
	scanf("%f %f", &second, &isecond);
	sum = first+second;
	isum = ifirst+isecond;
	mul = first*second - ifirst*isecond;
	imul = first*isecond + second*ifirst;
	a = (sum*mul + isum*imul);
	ia = (sum*sum + isum*isum);
	result = a/ia;
	b = (imul*sum-mul*isum);
	ib = (sum*sum + isum*isum);
	iresult = b/ib;
	printf("Комплексное сопротивление двух параллельно соединенных\n");
	printf("комплексных сопротивлений = %g + %gi\n", result, iresult);
	return 0;
}	