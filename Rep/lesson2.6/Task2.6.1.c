#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main (int argc, char *argv[])
{	
	int i, j, n = 1, *m, t = 0, point=0, s_point =0;
	char string[1024];
	char **words;
	char *place_for_word;
	FILE *first;
	FILE *second;
	if (argc !=2) 
	{
		printf("Неверное количество аргументов.\n");
	}
	if ((first=fopen(argv[1], "r"))==NULL) 
	{
		printf("Невозможно открыть файл.\n");
		exit(1);
	}
	if((second=fopen("results.txt", "w"))==NULL) 
	{
		printf("Невозможно открыть файл.\n");
		exit(1);
	}
	fscanf(first,"%s",string);
	words = (char**)malloc( sizeof(char*));
	words[0] = (char*)malloc( sizeof(char) * strlen(string) + 1);
	strcpy(words[0], string);
	m = (int*)malloc(sizeof(int));
	m[0] = 1;
	while (fscanf(first,"%s",string) !=EOF)
	{	
		for(i = 0; i < n; i++)
		{   

			while(words[i][point] != '\0')
			{
				if(ispunct(words[i][point]))
				{
					words[i][point] = '\0';
					break;
				}
				point++;
			}
			point = 0;
			while(string[s_point] != '\0')
			{
				if(ispunct(string[s_point]))
				{
					string[s_point] = '\0';
					break;
				}
				s_point ++;
			}
			if(strcmp(words[i],string) == 0)
			{
				m[i]++;
				t = 1;
			}
		}
		if(!t)
		{
			n++;
			words = (char**)realloc(words, n * sizeof(char*));
			words[n-1] = (char*)malloc(sizeof(char) * strlen(string) + 1);
			strcpy(words[n-1], string);
			m = (int*)realloc(m, sizeof(int) * n);
			m[n-1] = 1;
		}
	t = 0;
	}
	fprintf(second,"Введёные вами слова::\n\n");
	for (j=0; j<=n-1;j++)
	{
		for (i=0;i<n-j-1;i++)
		{
			while (m[i] > m[i+1])
			{
				place_for_word = words[i]; 
				int place = m[i];
				m[i]=m[i+1];
				words[i]=words[i+1];
				words[i+1]=place_for_word;
				m[i+1] = place;	
			}
		}
	fprintf(second,"%s 		-		%d\n",words[i], m[i]);
	}
fclose(first);
fclose(second);
return 0;
}
