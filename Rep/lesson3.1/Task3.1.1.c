#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct phonebook
{
    char name[30];
    char  number[15];
    struct phonebook *next;
    struct phonebook *previous;
};


struct phonebook *begin;
struct phonebook *end;
struct phonebook *search_of_name(char *);
void getting(void), search(void), save_to_file(void);
void get_from_file(void), print_all(void);
void del_num(struct phonebook **, struct phonebook **);
void make_print_all(struct phonebook *inpt, struct phonebook **begin, struct phonebook **end);
int menu(void);


int main(void)
{
    begin = NULL;
    end = NULL;
    while(1) {
        switch(menu()) {
            case 1: getting();
              break;
            case 2: del_num(&begin, &end);
              break;
            case 3: print_all();
              break;
            case 4: search();
              break;
            case 5: save_to_file();
              break;
            case 6: get_from_file();
              break;
            case 0: exit(0);            
        }
    }
    return 0;
}


int menu(void)
{
    char s[80];
    int c=10;
    printf("1 - Записать новый контакт\n"); 
    printf("2 - Удалить контакт\n");
    printf("3 - Вывести список контактов\n");
    printf("4 - Поиск по записям\n");
    printf("5 - Сохранить изменения в файл\n");
    printf("6 - Запросить информацию из файла\n");
    printf("0 - Выйти из телефонной книги\n\n\n");
    while(c<0 || c>6)
    {
        printf("Введите значение:\n");
        fgets(s, sizeof(s), stdin);
        c=atoi(s);
    }
    return c;
}


void getting(void)
{
    struct phonebook *helpfull;

        char strlon1[255];
        char strlon2[255];
        helpfull=(struct phonebook *)malloc( sizeof(struct phonebook));
        if(helpfull==0) 
        {
            printf("Нет свободной памяти");
            return;
        }
        printf("Введите имя:");
        do {
            fgets(strlon1, 254, stdin);
            if(strlen(strlon1)>30) 
            printf("Слишком длинное имя!");
        }while(strlen(strlon1)>30);
        strlon1[strlen(strlon1)-1]=0;
        strcpy(helpfull->name, strlon1);
        printf("Введите номер:");
        do {
            fgets(strlon2, 254, stdin);
            if(strlen(strlon2)>15) 
            printf("Слишком длинное имя!");
        }while(strlen(strlon2)>15);
        strlon2[strlen(strlon2)-1]=0;
        strcpy(helpfull->number, strlon2);
        make_print_all(helpfull, &begin, &end);




}


void del_num(struct phonebook **begin, struct phonebook **end)
{
    struct phonebook *helpfull;
    char strlon3[30];
    char find_to_del[30];
    printf("Введите имя:");
    do {
        fgets(strlon3, 254, stdin);
        if(strlen(strlon3)>30) 
        printf("Слишком длинное имя!");
    }while(strlen(strlon3)>30);
    strlon3[strlen(strlon3)-1]=0;
    strcpy(find_to_del, strlon3);    
    helpfull=search_of_name(find_to_del);
    if(helpfull) 
    {
        if(*begin==helpfull) 
        {
            *begin=helpfull->next;
            if(*begin) 
            {
                (*begin)->previous=NULL;
            }
            else
            { 
            *end=NULL;
            }
        }
        else 
        {
            helpfull->previous->next=helpfull->next;
            if(helpfull!=*end)
            {
                helpfull->next->previous=helpfull->previous;
            }
            else
            {
                *end=helpfull->previous;
            }
        }
        free(helpfull);
    }
}

void print_all(void)
{
    struct phonebook *helpfull;
    helpfull=begin;
    do
    {
        printf("%s: %s\n", helpfull->name, helpfull->number);
        printf("\n\n");
        helpfull=helpfull->next;
    }while(helpfull!= end);
    printf("%s: %s\n", helpfull->name, helpfull->number);
    printf("\n");
}

void search(void)
{
    char word[30];
    char strlon4[30];
    struct phonebook *helpfull;
    printf("Введите имя: \n");
    do {
            fgets(strlon4, 254, stdin);
            if(strlen(strlon4)>30) 
            printf("Слишком длинное имя!");
        }while(strlen(strlon4)>30);
        strlon4[strlen(strlon4)-1]=0;
        strcpy(word, strlon4);
    helpfull=search_of_name(word);
    if(!helpfull) 
    {
        printf("Контакт не найден.\n");
    }
    else 
     {
        printf("%s: %s\n", helpfull->name, helpfull->number);
        printf("\n\n");
     }   
      
}

void save_to_file(void)
{
    struct phonebook *helpfull;
    FILE *ptr;
    ptr=fopen("Phonebook.txt", "wb");
    if(!ptr) {
        printf("Не получается открыть файл\n");
        exit (1);
    }
    helpfull=begin;
    while(helpfull) {
        fwrite(helpfull, sizeof(struct phonebook), 1, ptr);
        helpfull=helpfull->next;
    }
    printf("Сохранено!\n");
    fclose(ptr);
}

void get_from_file()
{
    struct phonebook *helpfull;
    FILE *ptr;
    ptr=fopen("Phonebook.txt", "rb");
    if(!ptr) 
    {
        printf("нельзя открыть файл\n");
        exit (1);
    }
    else
    {
        while(begin) 
        {
            helpfull=begin->next;
            free(begin);
            begin=helpfull;
        }
        begin=end=NULL;
        printf("Файл прочитан.");
        while(!feof(ptr)) 
        {
            helpfull =(struct phonebook *)malloc( sizeof(struct phonebook));
            if (!helpfull) 
            {
                printf("Нет свободной памяти!\n");
                return;
            }
            if(fread(helpfull, sizeof(struct phonebook), 1, ptr)!= 1) break;
            make_print_all(helpfull, &begin, &end);
        }
        fclose(ptr);
    }
}



void make_print_all(struct phonebook *inpt, struct phonebook **begin, struct phonebook **end)
{
    struct phonebook *before, *pilot;
    if(*end==NULL) 
    {
        inpt->next=NULL;
        inpt->previous=NULL;
        *end=inpt;
        *begin=inpt;
        return;
    }
    else
    {
        pilot= *begin;
        before=NULL;
        while(pilot) 
        {
            if(strcmp(pilot->name, inpt->name)<0) 
            {
                before=pilot;
                pilot=pilot->next;
            }
            else 
            {
                if(pilot->previous) 
                {
                    pilot->next=inpt;
                    inpt->next=pilot;
                    inpt->previous=pilot->previous;
                    pilot->previous=inpt;
                    return;
                }
                else
                {
                inpt->next=pilot;
                inpt->previous=NULL;
                pilot->previous=inpt;
                *begin=inpt;
                return;
                }
            }
        }
        before->next=inpt;
        inpt->next=NULL;
        inpt->previous=before;
        *end=inpt;
    }
}


struct phonebook *search_of_name( char *word)
{
    struct phonebook *helpfull;
    helpfull=begin;
    while(helpfull)
    {
        if(!strcmp(word, helpfull->name)) 
            return helpfull;
        helpfull=helpfull->next;
    } ;
    printf("Введено несуществующее имя\n");
    return NULL;
}
