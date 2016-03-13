#include <stdio.h>

int main(void)
{
	int day, month, change;
	day = 22;
	month = 11;
	change = day;
	day = month;
	month = change;
	printf("%d/%d",day,month); 
	return 0;
}