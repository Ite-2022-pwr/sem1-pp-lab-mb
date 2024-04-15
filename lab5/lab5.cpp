#include <iostream>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

/*
 * Tytuł: Lab 5
 * Data utworzenia: 12.11.2022
 * Data ukończenia: 12.11.2022
 * Autor: Miłosz Bedryło
 * Grupa: Poniedziałek nieparzysty 11:15
 * Nr Albumu: 272934
 * ITE 1 rok
 * Podstawy programowania laboratoria 3
 * IDE: jetbrains clion
 */

void InitTab(char **&wsk);

void AddName(char *buf, char **&wsk);

void RemoveNameByPos(int nr, char **&wsk);

void RemoveName(char *buf, char **&wsk);

void PrintAllNames(char **wsk);

void PrintNames(char first_letter, char **wsk);

void SortAlphabet(char **wsk);

void SortLength(char **wsk);

int main() {
    printf("Miłosz Bedryło\npodstawy programowania\nlab 5\nponiedziałek nieparzysty\n\n\n");

    char **WSK;

    char buf[81];

    InitTab(WSK);

    int nr = 0;
    int wybor = 0;
    do {
        printf("Wybierz co zrobić z tablicą:\n");
        printf("1. Dodaj Imie,\n");
        printf("2. Usuń imie po numerze pozycji,\n");
        printf("3. Usuń imie po podaniu go,\n");
        printf("4. Pokaż wszystkie imiona,\n");
        printf("5. Pokaż wszystkie imiona na daną litere,\n");
        printf("6. Sortuj alfabetycznie,\n");
        printf("7. Sortuj po długości,\n");
        printf("0. Wyjdź.\n");
        scanf("%i",&wybor);
        switch (wybor) {
            case 1:
                AddName(buf, WSK);
                break;
            case 2:
                printf("Podaj numer imienia do usunięcia:\n");
                fflush(stdin);
                scanf("%i", &nr);
                RemoveNameByPos(nr, WSK);
                break;
            case 3:
                RemoveName(buf, WSK);
                break;
            case 4:
                PrintAllNames(WSK);
                break;
            case 5:
                printf("podaj pierwszą literę:\n");
                char lit;
                fflush(stdin);
                scanf("%c", &lit);
                lit = tolower(lit);
                PrintNames(lit, WSK);
                break;
            case 6:
                SortAlphabet(WSK);
                break;
            case 7:
                SortLength(WSK);
                break;
            case 0:
                return 0;
                break;
        }
        fflush(stdin);
        printf("\nwciśnij klawisz enter/return aby kontynuować\n");
        getchar();
        printf("\n\n");
    } while (wybor != 0);
    return 0;
}

void InitTab(char **&wsk){
    wsk = (char **) malloc(sizeof(char *));
    wsk[0] = NULL;
}

void AddName(char *buf, char **&wsk){
    printf ("Wprowadź imię: ");
    fflush(stdin);
    fgets (buf, 81, stdin);
    int poz = 0;
    while( wsk[poz] != NULL ) poz++;
    wsk = (char**)realloc(wsk, (poz+2)*sizeof(char *));
    wsk[poz+1] = NULL;
    wsk[poz]=(char*)malloc(sizeof(char)*(strlen(buf)+1));
    strcpy(wsk[poz], buf);
}

void RemoveNameByPos(int nr, char **&wsk){
    int poz = 0;
    while( wsk[poz] != NULL ) poz++;
    if (nr>=poz) {
        return;
    }
    free(wsk[nr]);
    for(int i=nr; i<poz; i++) wsk[i] = wsk[i+1];
    wsk = (char**)realloc(wsk, (poz*sizeof(char *)));
}

void RemoveName(char *buf, char **&wsk){
    printf ("Wprowadź imię: ");
    fflush(stdin);
    fgets (buf, 81, stdin);
    int poz = 0;
    while( wsk[poz] != NULL ) poz++;
    for (int i = 0; i < poz; ++i) {
        if(strcmp(buf, wsk[i]) == 0){
            free(wsk[i]);
            for(int j=i; j<poz; j++) wsk[j] = wsk[j+1];
            wsk = (char**)realloc(wsk, (poz*sizeof(char *)));
            return;
        }
    }


}

void PrintAllNames(char **wsk){
    int poz = 0;
    while(*(wsk+poz) != NULL){
        printf("%i -> %s",poz,  *(wsk+poz));
        poz++;
    }
}

void PrintNames(char first_letter, char **wsk){
    int poz = 0;
    int i = 0;
    while(*(wsk+poz) != NULL){
        if(tolower(*(*(wsk+poz))) == first_letter){
            printf("%i -> %s",i, *(wsk+poz));
            i++;
        }
        poz++;
    }
}

void SortAlphabet(char **wsk){
    int poz = 0;
    char temp[81];
    while( wsk[poz] != NULL ) poz++;
    for (int i = 0; i < poz-1; ++i) {
        for (int j = 0; j < poz-1; ++j) {
            if(strcmp(wsk[j], wsk[j+1]) > 0){
                strcpy(temp, wsk[j]);
                strcpy(wsk[j], wsk[j+1]);
                strcpy(wsk[j+1], temp);
            }
        }
    }
}

void SortLength(char **wsk){
    int poz = 0;
    char temp[81];
    while( wsk[poz] != NULL ) poz++;
    for (int i = 0; i < poz-1; ++i) {
        for (int j = 0; j < poz-1; ++j) {
            if(strlen(wsk[j])>strlen(wsk[j+1])){
                strcpy(temp, wsk[j]);
                strcpy(wsk[j], wsk[j+1]);
                strcpy(wsk[j+1], temp);
            }
        }
    }
}
