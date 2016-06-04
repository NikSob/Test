#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) 
{
	FILE *first;
   	FILE *second;
	char letter;
	char key[6]={'1', '0', '1', '1', '1', '0'};
	int i=0;
    if (argc !=2) {
        printf("Ошибка: %s\n", argv[0]);
    }
    if ((first=fopen(argv[1], "rb"))==NULL) {
        printf("Невозможно открыть файл\n");
        exit(1);
    }
    if ((second=fopen("output.txt", "wb"))==NULL) {
        printf("Невозможно открыть файл\n");
        exit(1);
    } 
    while(feof(first) == 0) {
        fread(&letter, 1, 1, first);
        if(letter != '\n') 
        {
            i = (i == 6) ? i : 0;
            letter^=key[i];
            i++;
        }
        fwrite(&letter, 1, 1, second);
    }	
    fclose(first);
    fclose(second);
    return 0;
}
