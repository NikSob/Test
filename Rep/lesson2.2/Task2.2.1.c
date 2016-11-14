#include <stdio.h>

int main(void)
{
	int num, year, month, day;
	printf("Введите количество дней:\n");
	scanf("%d", &num);
	year =  num / 365;
	month = (num - (365*year))/30;
	day = num-(365*year)-(30*month);
	printf("%d дней - это %d года(лет), %d месяцев и %d дней!",num, year,month,day);
	return 0;
}
