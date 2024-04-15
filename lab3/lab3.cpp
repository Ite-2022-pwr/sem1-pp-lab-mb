#include <iostream>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#define ROZMIAR 25
#define ROZMIAR_ALFABETU 26

/*
 * Tytuł: Lab 3
 * Data utworzenia: 07.11.2022
 * Data ukończenia: 07.11.2022
 * Autor: Miłosz Bedryło
 * Grupa: Poniedziałek nieparzysty 11:15
 * Nr Albumu: 272934
 * ITE 1 rok
 * Podstawy programowania laboratoria 3
 * IDE: jetbrains clion
 */

void wczytajZKlawiatury(float tablica[]){
    printf("Podaj kolejne elementy tablicy:\n");
    for (int i = 0; i < ROZMIAR; ++i) {
        printf("Tablica[%i] = ", i);
        scanf("%f", &tablica[i]);
    }
}

void wypiszTablice(float tablica[]){
    printf("Tablica = [");
    for (int i = 0; i < ROZMIAR - 1; ++i) {
        printf("  %.1f,", tablica[i]);
    }
    printf("  %.1f  ]\n", tablica[ROZMIAR-1]);
}

void informacjeOTablicy(float tablica[]){
    int dodatnie = 0;
    int ujemne = 0;
    float sumaDodatnie = 0;
    float sumaUjemne = 0;
    float srDodatnie = 0;
    float srUjemne = 0;
    for (int i = 0; i < ROZMIAR; ++i) {
        if (tablica[i] > 0){
            dodatnie++;
            sumaDodatnie+=tablica[i];
        } else if (tablica[i] < 0) {
            ujemne++;
            sumaUjemne += tablica[i];
        }
    }
    printf("\nByło %i liczb dodatnich, %i liczb ujemnych\nSuma dodatnich to %f, a suma ujemnych to %f\n", dodatnie, ujemne, sumaDodatnie, sumaUjemne);
    if (dodatnie != 0){
        srDodatnie = sumaDodatnie/dodatnie;
        printf("średnia dodatnich wyniosła: %f\n", srDodatnie);
    } else {
        printf("nie można policzyć średniej dodatnich z ich braku\n");
    }
    if (ujemne != 0){
        srUjemne = sumaUjemne/ujemne;
        printf("średnia ujemnych wyniosła: %f\n", srUjemne);
    } else {
        printf("nie można policzyć średniej ujemnych z ich braku\n");
    }
}

void porzadekTablicy(float tablica[]){
    bool rosnaca = true;
    bool malejaca = true;
    bool niemalejaca = true;
    bool nierosnaca = true;
    int i = 0;
    while((rosnaca || malejaca || niemalejaca || nierosnaca) && i < ROZMIAR-1){
        if (tablica[i] < tablica[i+1]){
            malejaca = false;
            nierosnaca = false;
        }
        if (tablica[i] > tablica[i+1]){
            rosnaca = false;
            niemalejaca = false;
        }
        if (tablica[i] == tablica[i+1]){
            malejaca = false;
            rosnaca = false;
        }
        i++;
    }
    if (rosnaca){
        printf("tablica jest rosnąca\n");
    }
    if (niemalejaca){
        printf("tablica jest niemalejąca\n");
    }
    if (malejaca){
        printf("tablica jest malejąca\n");
    }
    if (nierosnaca){
        printf("tablica jest nierosnąca\n");
    }
    if (!rosnaca && !malejaca && !niemalejaca && !nierosnaca){
        printf("tablica nie jest w żaden sposób uporządkowana\n");
    }
}

void bubbleSort(float tablica[]){
    for (int i = 0; i < ROZMIAR; ++i) {
        for (int j = 0; j < ROZMIAR - 1; ++j) {
            if (tablica[j] > tablica[j+1]){
                float temp = tablica[j];
                tablica[j] = tablica[j + 1];
                tablica[j+1] = temp;
            }
        }
    }
}

void z1(float tablica[]){
    int wybor = 0;
    do {
        printf("Wybierz program z listy:\n");
        printf("1. Wczytaj dane z klawiatury do tablicy,\n");
        printf("2. Wypisz zawartość tablicy,\n");
        printf("3. Ile Liczb, średnia i suma,\n");
        printf("4. porządek,\n");
        printf("0. Wyjdź.\n");
        scanf("%i",&wybor);
        switch (wybor) {
            case 1:
                wczytajZKlawiatury(tablica);
                break;
            case 2:
                wypiszTablice(tablica);
                break;
            case 3:
                informacjeOTablicy(tablica);
                break;
            case 4:
                porzadekTablicy(tablica);
                break;
            case 0:
                break;
        }
        printf("\n\n");
    } while (wybor != 0);
}

void z2(float tablica[]){
    float min, max;
    printf("podaj początek i koniec przedziału do losowania liczb:\n");
    scanf("%f %f", &min, &max);
    for (int i = 0; i < ROZMIAR; ++i) {
        tablica[i] = min + (max - min)*rand()/((double)RAND_MAX);
    }
}

void z3(float tablica[]){
    printf("tablica przed sortowaniem bąbelkowym:\n");
    wypiszTablice(tablica);
    bubbleSort(tablica);
    printf("tablica po sortowaniu bąbelkowym:\n");
    wypiszTablice(tablica);
}

//komentarz do zadania 4
// nie mogłem użyć getch() ponieważ biblioteka conio.h nie działa na systemie macos, a nie mam innego komputera z windowsem w domu do sprawdzenia działąnia
//nie zmienia to faktu, że ta implementacja na pewno działa na systemach unixowych takich jak linux, macos i inne
//na systemie windows powinna działać ale wymaga wciśnięcia enter po wciśnięciu ESC

void z4(){
    int alfabet[ROZMIAR_ALFABETU];
    for (int i = 0; i < ROZMIAR_ALFABETU; ++i) {
        alfabet[i] = 0;
    }
    char temp, znak;
    printf("wpisuj znaki na końcu esc i enter.\n");
    do {
        znak = getchar();
        temp = toupper(znak);
        alfabet[temp-65] = alfabet[temp-65] + 1;
    } while (znak != 27);
    printf("częstotliwość liter:\n");
    for (int i = 0; i < ROZMIAR_ALFABETU; ++i) {
        printf("%c :", i+65);
        for (int j = 0; j < alfabet[i]; ++j) {
            printf("#");
        }
        printf("\n");
    }
}

int main() {
    printf("Miłosz Bedryło\npodstawy programowania\n lab3\nponiedziałek nieparzysty\n\n\n");
    srand(time(NULL));
    float tablica[ROZMIAR];
    int wybor = 0;
    do {
        printf("Wybierz program z listy:\n");
        printf("1. Zadanie 1,\n");
        printf("2. Zadanie 2,\n");
        printf("3. Zadanie 3,\n");
        printf("4. Zadanie 4,\n");
        printf("0. Wyjdź.\n");
        scanf("%i",&wybor);
        switch (wybor) {
            case 1:
                z1(tablica);
                break;
            case 2:
                z2(tablica);
                break;
            case 3:
                z3(tablica);
                break;
            case 4:
                z4();
                break;
            case 0:
                break;
        }
        printf("\n\n");
    } while (wybor != 0);
    return 0;
}
