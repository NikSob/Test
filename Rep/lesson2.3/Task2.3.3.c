#include <stdio.h>

int main(void)
{
	int user1, user2, a,b,c;
	printf("Введите первое число:\n");
	scanf("%d", &user1);
	printf("Введите второе число:\n");
	scanf("%d", &user2);
	if (user1 > user2)
	{
		a=user1;
		b=user2;
	}
	else 
	{
		b=user1;
		a=user2;
	}
	c=b;
	while(b>0)
	{
		if(a%b==0 && c%b==0)
			break;
		b--;
	}
	printf("Наибольший общий делитель = %d\n", b);
	return 0;
}