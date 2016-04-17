#include <stdio.h>

int febonachi(int n);
int main(void)
{
	int n, i;
	scanf("%d", &n);
	for(i=1; i<=n; i++)
	printf ("%d ", febonachi(i));
	return 0;
}
int febonachi(int n)
	{
		int d;
		if (n>2)
		{
		d = febonachi(n-1)+ febonachi(n-2);
		return d;
		}
		else
		return 1;	
	}