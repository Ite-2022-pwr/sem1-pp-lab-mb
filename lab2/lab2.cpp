#include <iostream>
#include <stdio.h>
#include <math.h>

/*
 * Tytuł: Lab 2
 * Data utworzenia: 24.10.2022
 * Data ukończenia: 28.10.2022
 * Autor: Miłosz Bedryło
 * Grupa: Poniedziałek nieparzysty 11:15
 * Nr Albumu: 272934
 * ITE 1 rok
 * Podstawy programowania laboratoria 1
 * IDE: jetbrains clion
 */

void tabelka() {
    int wiersz, kolumna;
    printf("Program drukuje tabliczke mnożenia \n");
    printf("Podaj liczbę wierszy: ");
    scanf("%i", &wiersz);
    printf("Podaj liczbę kolumn: ");
    scanf("%i", &kolumna);
    for (int j = 0; j < 2; j++){
        for(int i = 0; i <= kolumna; i++){
            if (i == 0 && j == 0){
                printf("    | ");
            } else if (i == 0 && j == 1) {
                printf("----|-");
            } else if (j == 1) {
                printf("----");
                if (i == kolumna){
                    printf("\n");
                }
            } else {
                printf("%4i", i);
                if (i == kolumna) {
                    printf("\n");
                }
            }
        }
    }
    for (int i = 1; i <= wiersz; ++i) {
        for (int j = 0; j <= kolumna; ++j) {
            if (j == 0){
                printf("%4i| ", i);
            } else if (j == kolumna) {
                printf("%4i\n", i*j);
            } else {
                printf("%4i", i*j);
            }
        }
    }


}

void sumaCyfr() {
    int liczba;
    int modulo;
    int suma = 0;
    printf("Podaj liczbę całkowitą:");
    scanf("%i", &liczba);
    while(liczba>0)
    {
        modulo=liczba%10;
        suma=suma+modulo;
        liczba=liczba/10;
    }
    printf("%i\n", suma);
}

void NWDiNWW() {
    int a, b;
    printf("Podaj a:");
    scanf("%i",&a);
    printf("Podaj b:");
    scanf("%i",&b);
    int kopiaA = a;
    int kopiaB = b;
    while(kopiaA!=kopiaB){
        if (kopiaA>kopiaB){
            kopiaA -= kopiaB;
        } else {
            kopiaB -= kopiaA;
        }
    }
    int NWD = kopiaA;
    int NWW = (a/NWD)*b;
    printf("NWD: %i i %i, to: %i\nNWW: %i i %i, to: %i\n",a,b,NWD,a,b,NWW);
}

void szeregi() {
    double S1 = 0;
    double S2 = 0;
    double eps, w1, w2;
    printf("%s", "podaj dokładność obliczania sumy szeregów S1 i S2, mniejszą niż 0.1\n");
    scanf("%lf", &eps);
    int i = 1;
    do {
        w1 = 1. / ((2.*i) - 1.);
        if (!((i)%2)) {
            w1 *= -1.;
        }
        S1 += w1;
        i++;
    } while (fabs(w1) >= eps);
    S1 *=4;

    int k = 0;
    int silnia = 1;
    do {
        if (k == 0){
            w2 = 1;
        } else {
            silnia *= k;
            w2 = 1. / silnia;
        }
        S2 += w2;
        k++;
    } while (fabs(w2) >= eps);

    printf("Suma S1: %lf\nSuma S2: %lf\n", S1, S2);
}

void losowaSuma() {
    srand(time(NULL));
    int min, max, ile, losowa;
    printf("podaj początek i koniec przedziału do losowania liczb:\n");
    scanf("%i %i", &min, &max);
    printf("podaj ilość liczb:\n");
    scanf("%i", &ile);
    printf("\n");
    int dodatnie = 0;
    int ujemne = 0;
    int ileDodatnich = 0;
    int ileUjemnych = 0;
    int ileZer = 0;
    float srDodatnie = 0;
    float srUjemne = 0;
    for (int i = 0; i < ile; ++i) {
        losowa = min + rand()%(max - min + 1);
        printf("%4i liczba losowa: %6i\n", i+1, losowa);
        if (losowa > 0) {
            dodatnie += losowa;
            ileDodatnich++;
        } else if (losowa < 0) {
            ujemne += losowa;
            ileUjemnych++;
        } else {
            ileZer++;
        }
    }
    srDodatnie = (float)dodatnie / (float)ileDodatnich;
    srUjemne = (float)ujemne / (float)ileUjemnych;
    printf("\nPodsumowanie\n");
    printf("Liczb dodatnich było: %i\n", ileDodatnich);
    printf("ich średnia to: %f\n\n", srDodatnie);
    printf("Liczb ujemnych było: %i\n", ileUjemnych);
    printf("ich średnia to: %f\n\n", srUjemne);
    printf("w losowych było tyle zer: %i\n", ileZer);
}

int main() {
    printf("Miłosz Bedryło\npodstawy programowania\nponiedziałek nieparzysty\n\n\n");
    int wybor = 0;
    do {
        printf("Wybierz program z listy:\n");
        printf("1. Tabliczka mnożenia,\n");
        printf("2. Suma cyfr liczby dodatniej całkowitej,\n");
        printf("3. Największy wspólny dzielnik i najmniejsza wspólna wielokrotność\n");
        printf("4. Suma szeregów zbieżnych do PI i e,\n");
        printf("5. Suma losowych liczb całkowitych,\n");
        printf("0. Wyjdź.\n");
        scanf("%i",&wybor);
        switch (wybor) {
            case 1:
                tabelka();
                break;
            case 2:
                sumaCyfr();
                break;
            case 3:
                NWDiNWW();
                break;
            case 4:
                szeregi();
                break;
            case 5:
                losowaSuma();
                break;
            case 0:
                break;
        }
        printf("\n\n");
    } while (wybor != 0);
    return 0;
}
