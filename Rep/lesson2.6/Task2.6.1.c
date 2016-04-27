#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define LIM 40
// #define MAX 1000
int i =0;//, m=0;

int main ()//int argc, char *argv[]) 
{
	FILE *fp;
	int g,k,l,z=0, a;
	// if (argc !=2) 
	// {
	// 	printf("Использование: %s\n", argv[0]);
	// }
	if ((fp=fopen("source.txt", "r"))==NULL) 
	{
		printf("Не удаётся открыть \n");
		exit(1);
	}
	char empty[LIM];
	while (fscanf(fp, "%s", empty)!=EOF) 
	{
		i++;
	}
	char words[i][LIM];
	while (fscanf(fp, "%s", words[z])!=EOF) 
	{
		for (g = 0; g != '\0'; g++)
		{
			if (isalnum(words[z][g]) == 0 && words[z][g] != '('  && words[z][g] != '{'  && words[z][g] != '"' && words[z][g] != '[')
				words[z][g]='\0';
		}
		z++;
	}
	fclose(fp);
	// l = i;
	int nums[i];
	for (a = 0; a<=i; a++)
		nums[a]=0;
	for ( g = 0; g<i; g++)
	{
		for ( k = g+1; k<i; k++)
		{
			if(strcmp(words[g], words[k])!=0 && nums[g]>=0)
			{
				nums[g]+=1;
				nums[k]-=1;
			}
		}
	}
	if((fp=fopen("results.txt", "w"))==NULL) 
	{
		printf("Не удаётся открыть results.txt\n");
		exit(1);
	}
	for (g=i; g>=0; g--)
	{
		for (k=0; k<i; k++)
		{
			if(nums[k]==g)
			{
				fprintf(fp, "one two %s 	-	 %d times\n", words[i], g+1);
			}
		}
	}
	fclose(fp);
	return 0;
}