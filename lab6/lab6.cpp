#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>

/*
 * Tytuł: Lab 6
 * Data utworzenia: 22.12.2022
 * Data ukończenia: 5.1.2023
 * Autor: Miłosz Bedryło
 * Grupa: Poniedziałek nieparzysty 11:15
 * Nr Albumu: 272934
 * ITE 1 rok
 * Podstawy programowania laboratoria 6
 * IDE: jetbrains clion
 */

struct Towar
{
    char nazwa[21];
    float cena;
    int ilosc;
};



void inicjalizujTablice(Towar *&tablica, int &rozmiar);

void wyswietlTablice(Towar *&tablica, int &rozmiar);

void deklarujTablice(Towar *&tablica, int &rozmiar);

void dodajTowar(Towar *&tablica, int &rozmiar);

void usunTowar(Towar *&tablica, int &rozmiar);

void usunTablice(Towar *&tablica, int &rozmiar);

void zapiszTablice(Towar *&tablica, int &rozmiar,FILE *&plik);

void wczytajTablice(Towar *&tablica, int &rozmiar,FILE *&plik);


int main(int argc, char const *argv[])
{
    printf("Miłosz Bedryło\npodstawy programowania\nlab 6\nponiedziałek nieparzysty\n\n\n");

    struct Towar *tablica = NULL;
    int rozmiar = 0;

    FILE * plik;

    int wybor = 0;
    do {
        printf("adres tablicy: %p\nrozmiar tablicy: %i\n", tablica, rozmiar);
        printf("Wybierz co zrobić z tablicą:\n");
        printf("1. zainicjuj tablice,\n");
        printf("2. Zadeklaruj początkową tablice,\n");
        printf("3. Dodaj towar,\n");
        printf("4. Usuń towar,\n");
        printf("5. Pokaż wszystkie towary,\n");
        printf("6. usuń tablice dynamiczną towarów,\n");
        printf("7. zapisz tablice dynamiczną towarów na dysku,\n");
        printf("8. wczytaj tablice dynamiczną towarów z dysku,\n");
        printf("0. Wyjdź.\n");
        scanf("%i",&wybor);
        switch (wybor) {
            case 1:
                inicjalizujTablice(tablica, rozmiar);
                break;
            case 2:
                deklarujTablice(tablica, rozmiar);
                break;
            case 3:
                dodajTowar(tablica, rozmiar);
                break;
            case 4:
                usunTowar(tablica, rozmiar);
                break;
            case 5:
                wyswietlTablice(tablica, rozmiar);
                break;
            case 6:
                usunTablice(tablica, rozmiar);
                break;
            case 7:
                zapiszTablice(tablica, rozmiar, plik);
                break;
            case 8:
                wczytajTablice(tablica, rozmiar, plik);
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

void inicjalizujTablice(Towar *&tablica, int &rozmiar)
{
    tablica = (Towar *)malloc(sizeof(Towar *));
    rozmiar = 0;
}

void wyswietlTablice(Towar *&tablica, int &rozmiar)
{
    if (tablica == NULL)
    {
        printf("brak tablicy\n");
        return;
    }
    printf("%20s|%16s|%8s\n","towar","cena","ilosc");
    for (int i = 0; i < rozmiar; i++)
    {
        printf("%20s|%16.2lf|%8i\n", *&tablica[i].nazwa, *&tablica[i].cena, *&tablica[i].ilosc);
    }
}

void deklarujTablice(Towar *&tablica, int &rozmiar)
{
    if (tablica != NULL){
        free(tablica);
        tablica = NULL;
        rozmiar = 0;
    }
    printf("podaj długość tablicy towarów:\n");
    scanf("%i", &rozmiar);
    tablica = (Towar *)malloc(sizeof(Towar) * rozmiar);
    printf("\nTeraz dodawaj towary:\n");
    for (int i = 0; i < rozmiar; i++)
    {
        printf("podaj nazwe do 20 znaków:\n");
        scanf("%20s",&tablica[i].nazwa);
        printf("podaj cene:\n");
        scanf("%f", &tablica[i].cena);
        printf("podaj ilość:\n");
        scanf("%i", &tablica[i].ilosc);
    }
}

void dodajTowar(Towar *&tablica, int &rozmiar)
{
    tablica = (Towar *)realloc(tablica,sizeof(Towar)*(rozmiar+2));
    printf("podaj nazwe do 20 znaków:\n");
    scanf("%20s",&tablica[rozmiar].nazwa);
    printf("podaj cene:\n");
    scanf("%f", &tablica[rozmiar].cena);
    printf("podaj ilość:\n");
    scanf("%i", &tablica[rozmiar].ilosc);
    rozmiar++;
}

void usunTowar(Towar *&tablica, int &rozmiar) //TODO napraw bo nie usuwa
{

    char temp[21];
    printf("podaj nazwe towaru do usunięcia:\n");
    scanf("%20s", &temp);
    int i = 0;
    while (i < rozmiar)
    {
        if (strcmp(tablica[i].nazwa, temp) == 0)
        {
            for(int j=i; j<rozmiar; j++){
                memcpy(&tablica[j], &tablica[j+1], sizeof(tablica[j]));
            }
            rozmiar--;
            tablica = (Towar  *)realloc(tablica, (rozmiar*sizeof(Towar)));
            return;
        }
        i++;
    }
    
}

void usunTablice(Towar *&tablica, int &rozmiar){
    if(tablica == NULL) {
        printf("brak tablicy\n");
    } else {
        memset(tablica, 0 ,sizeof(Towar)*rozmiar);
        free(tablica);
        tablica = NULL;
        rozmiar = 0;
    }
}

void zapiszTablice(Towar *&tablica, int &rozmiar,FILE *&plik){
    char nazwa[20];
    printf("podaj nazwe pliku do zapisu:\n");
    scanf("%19s", &nazwa);
    plik = fopen(nazwa, "w");
    if (plik){
        fprintf(plik,"%i\n", rozmiar);
        for (int i = 0; i < rozmiar; i++)
        {
            fprintf(plik,"%s\n%lf\n%i\n", *&tablica[i].nazwa, *&tablica[i].cena, *&tablica[i].ilosc);
        }
    } else {
        printf("coś poszlo nie tak\n");
    }
    fclose(plik);
}

void wczytajTablice(Towar *&tablica, int &rozmiar,FILE *&plik) {
    char nazwa[20];
    printf("podaj nazwe pliku do odczytu:\n");
    scanf("%19s", &nazwa);
    plik = fopen(nazwa, "r");
    if (plik){
        rozmiar = 0;
        free(tablica);
        tablica = NULL;
        fscanf(plik,"%i",&rozmiar);
        tablica = (Towar *)malloc(sizeof(Towar) * rozmiar);
        for (int i = 0; i < rozmiar; ++i) {
            fscanf(plik,"%s", &*tablica[i].nazwa);
            fscanf(plik,"%f", &tablica[i].cena);
            fscanf(plik,"%i", &tablica[i].ilosc);
        }
    } else {
        printf("coś poszło nie tak\n");
        rozmiar = 0;
        free(tablica);
        tablica = NULL;
    }
    fclose(plik);
}

void sortujTablice(Towar *&tablica, int &rozmiar){
    int wybor;
    printf("wybierz po czym chcesz sortować:\n");
    printf("1. nazwa\n");
    printf("2. cena\n");
    printf("3. ilość\n");
    scanf("%i", &wybor);
    switch (wybor)
    {
    case 1:
        qsort(tablica, rozmiar, sizeof(Towar), compareNazwa);
        break;
    case 2:
        qsort(tablica, rozmiar, sizeof(Towar), compareCena);
        break;
    case 3:
        qsort(tablica, rozmiar, sizeof(Towar), compareIlosc);
        break;
    default:
        break;
    }
}
