#include <stdio.h>
#include <stdlib.h>

int main () 
{
	FILE *first;
   	FILE *second;
	char letter;
	char key[6]={'1', '0', '1', '1', '1', '0'};
	int i=0;
    first=fopen("begin.txt", "rb");
    second=fopen("end.txt", "wb");
    while(feof(first) == 0) {
        fread(&letter, 1, 1, first);
        if(letter != '\n') 
        {
            i = 6? i : 0;
            letter^=key[i];
            i++;
        }
        fwrite(&letter, 1, 1, second);
    }	
    fclose(first);
    fclose(second);
    return 0;
}
