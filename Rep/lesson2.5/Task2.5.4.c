#include <stdio.h>
#define SIZE 255

int main(void)
{
	char srting[SIZE], local;
	int i, first=0, second=0, third=0, fourth=0;
	printf("Введите строку для проверки баланса скобок:\n");
	scanf("%s", srting);
	for(i=0; i<SIZE; i++)
	{
		local=srting[i];
		switch(local)
		{
		case '(' : first++;
			continue;
		case '[' : second++;
			continue;
		case '{' : third++;
			continue;
		case '<' : fourth++;
			continue;
		case ')' : first--;
			continue;
		case ']' : second--;
			continue;
		case '}' : third--;
			continue;
		case '>' : fourth--;
			continue;
		}
	}
	if (first==0 && second ==0 && third == 0 && fourth ==0)
		printf("Баланс скобок соблюдён.\n");
	else printf("Баланс скобок не соблюдён.\n");
	return 0;
}