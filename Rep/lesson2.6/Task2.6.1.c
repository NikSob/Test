#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main ()
{	
	int i, j, n = 1, *m, t = 0;
	char string[1024];
	char **words;
	char *place_for_word;
	FILE *first;
	FILE *second;
	first=fopen("Input.txt","r");
	second=fopen("results.txt","w");
	fscanf(first,"%s",string);
	words = (char**)malloc( sizeof(char*));
	words[0] = (char*)malloc( sizeof(char) * strlen(string) + 1);
	strcpy(words[0], string);
	m = (int*)malloc(sizeof(int));
	m[0] = 1;
	while (fscanf(first,"%s",string) !=EOF)
	{	
		for(i = 0; i < n; ++i)
		{   

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
