#include <stdio.h>
#define SIZE 255


char punkt( char ch);

int main(void)
{
	char srting[SIZE];
	int i,k,n,z,result,ind = 0, next, number =0;
	int num[SIZE] = {0,0,0};
	printf("Введите строку для проверки баланса скобок:\n");
	while((srting[number] = getchar()) && srting[number] != '\n')
		number++;
	for(i = 0; i<SIZE ; i++)
		{
			num[i] = punkt(srting[i]);
		}
	for(z = 0; z<SIZE; z++)
	{
	for (k = 0; k<SIZE ; k++)
	{
		
		n = k;
		
		do
		{
			next = num[++n];
			
		}while(next == 'o');
		if(((num[k] == '(') && (next == ')')) || ((num[k] == '{') && (next == '}')) || ((num[k] == '[') && (next == ']')) || ((num[k] == '<') && (next == '>')) || ((num[k] == '"') && (next == '"')) || ((num[k] == '\'') && (next == '\'')) || ((num[k] == '`') && (next == '`')))
		{
			num[k] = 'o';
			num[n] = 'o';
		}
	}
	}
	for(result = 0; result<number; result++)
	{
		if(num[result] != 'o' && num[result] != '\0')
			ind = 1;
	}
	if (ind)
		printf("Баланс скобок не соблюдён.\n");
	else printf("Баланс скобок соблюдён.\n");
	return 0;
}


char punkt( char ch)
{

	switch(ch)
		{
		case '(' : 
			return '(';
			break;
		case '[' : 
			return '[';
			break;
		case '{' :
			return '{';
			break;
		case '<' : 
			return '<';
			break;
		case '"' : 
			return '"';
			break;
		case '\'' : 
			return '\'';
			break;
		case '`' : 
			return '`';
			break;
		case ')' : 
			return ')';
			break;
		case ']' : 
			return ']';
			break;
		case '}' :
			return '}';
			break;
		case '>' : 
			return '>';
			break;
		default:
			return 'o';
			break;
		
		}
}
