#include <stdio.h>
#include <string.h>


int main(void)
{
	char string[255];
	int b[155]={0,0,0,0},i=0,j,length;
	char massiv[]="0123456789QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm`~!@#$%^&*(){}[];'\"\\/,.<>";
	printf("Введи строку, для вывода символов:\n");
	while ( (string[i] = getchar()) != '\n')
		i++;
	printf("Символы в порядке убывания:");
	length=strlen(string);
	for(i=0;i<length;i++)
	{
		for(j=0;j<89;j++)
		{
			if(massiv[j]==string[i])
				b[j]+=1;
		}
	}
	for(i=length -1;i>-1;i--)
	{
		for(j=0;j<89;j++) 
        {
           if(b[j]!=0 && b[j]==i)
			{
				printf("%c ",massiv[j]);
			}
		}
	}
	return 0;
}
