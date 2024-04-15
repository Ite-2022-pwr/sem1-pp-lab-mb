#include <iostream>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#define ROZMIAR 100

using namespace std;

/*
 * Tytuł: Lab 4
 * Data utworzenia: 20.11.2022
 * Data ukończenia: 25.11.2022
 * Autor: Miłosz Bedryło
 * Grupa: Poniedziałek nieparzysty 11:15
 * Nr Albumu: 272934
 * ITE 1 rok
 * Podstawy programowania laboratoria 4
 * IDE: jetbrains clion
 */

int zmiennaInt1 = 1;
int *wi1 = &zmiennaInt1;
float zmiennaFloat1 = 1.2;
float *wf1 = &zmiennaFloat1;
double zmiennaDouble1 = 2.3;
double *wd1 = &zmiennaDouble1;
bool zmiennaBool1 = true;
bool *wb1 = &zmiennaBool1;
char zmiennaChar1 = 'A';
char *wc1 = &zmiennaChar1;
long zmiennaLong1 = 123456;
long *wl1 = &zmiennaLong1;

void zadanie2();

int usunCyfry(char *lancuch);

void zadanie3();

void * usunKomentarze(char *lancuch);

int main(int argc, char *argv[]) {
    printf("Miłosz Bedryło\npodstawy programowania\n lab4\nponiedziałek nieparzysty\n\n\n");
    int wybor = 0;
    do {
        printf("Wybierz program z listy:\n");
        printf("1. Zadanie 2,\n");
        printf("2. Zadanie 3,\n");
        printf("0. Wyjdź.\n");
        scanf("%i",&wybor);
        switch (wybor) {
            case 1:
                zadanie2();
                break;
            case 2:
                zadanie3();
                break;
            case 0:
                break;
        }
        printf("\n\n");
    } while (wybor != 0);
    fflush(stdin);
    getchar();
    return 0;
}

int usunCyfry(char *lancuch){
    int dlugosc = strlen(lancuch);
    int cyfry = 0;
    for(int i = 0; i < dlugosc; i++)
    {
        if(lancuch[i] >= 48 && lancuch[i] <= 57)
        {
            cyfry++;
            for(int j = i; j < dlugosc; j++)
            {
                lancuch[j] = lancuch[j + 1];
            }
            dlugosc--;
            i--;
        }
    }
    return cyfry;
}

void zadanie2(){
    char tab[ROZMIAR];
    printf("podaj lancuch znakow z ktorego zostana usuniete cyfry:\n");
    size_t bytes = ROZMIAR;
    char * s = (char*)tab;
    getline(&s, &bytes, stdin);
    int cyfry = usunCyfry(tab);
    printf("usunięto %d cyfr, a lancuch to teraz:\n%s", cyfry, tab);
    fflush(stdin);
    getchar();
};

void * usunKomentarze(char *lancuch){
    int dlugosc = strlen(lancuch);
    char temp[ROZMIAR];
    int k = 0;
    for(int i = 0; i < dlugosc; i++)
    {
        if(lancuch[i] == '/' && lancuch[i+1] == '/')
        {
            lancuch[i] = 0;
            break;
        }
    }
    dlugosc = strlen(lancuch);
    bool pomin = false;
    for (int i = 0; i < dlugosc; ++i) {
        if(lancuch[i] == '/' && lancuch[i+1] == '*'){
            pomin = true;
        } else if(lancuch[i] == '*' && lancuch[i+1] == '/'){
            i+=2;
            pomin = false;
        }
        if(!pomin){
            temp[k] = lancuch[i];
            k++;
        }
    }
    for (int i = 0; i < strlen(temp)+1; i++) {
        lancuch[i] = temp[i];
    }
    lancuch[strlen(temp)+1] = 0;
    return (void*)&lancuch;
}

void zadanie3(){
    char tab[ROZMIAR];
    printf("podaj lancuch znakow z ktorego zostana usuniete komentarze:\n");
    size_t bytes = ROZMIAR;
    char * s = (char*)tab;
    fflush(stdin);
    getline(&s, &bytes, stdin);
    printf("Adres to:%0#x\n",usunKomentarze(tab));
    printf("lancuch to teraz:\n%s", tab);
    fflush(stdin);
    getchar();
};

