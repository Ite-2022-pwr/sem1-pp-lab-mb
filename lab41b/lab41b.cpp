#include <iostream>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

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

void czytajRownanie(float *a, float *b, float *c);

void wypiszRozwiazanie(int n, float x, float y);

float obliczWyznacznik(float p1, float p2, float p3, float p4);

int obliczRozwiazanie(float a1, float b1, float c1, float a2, float b2, float c2, float *x, float *y);

int main(int argc, char *argv[]) {
    printf("Miłosz Bedryło\npodstawy programowania\n lab4 zad 1b\nponiedziałek nieparzysty\n\n\n");
    float A1, B1, C1;  // pierwsze równanie,
    float A2, B2, C2; // drugie równanie,
    float X, Y; // rozwiązanie,
    int N; // liczba rozwiazan.
    czytajRownanie(&A1, &B1, &C1);
    czytajRownanie(&A2, &B2, &C2);
    N = obliczRozwiazanie(A1, B1, C1, A2, B2, C2, &X, &Y);
    wypiszRozwiazanie( N, X, Y);
    fflush(stdin);
    getchar();
    return 0;
}

void czytajRownanie(float *a, float *b, float *c){
    printf("Podaj wyznaczniki A, B i C równania w postaci Ax+By=C\n");
    scanf("%f %f %f", a, b, c);
}

void wypiszRozwiazanie(int n, float x, float y){
    switch (n) {
        case 2:
            printf("układ ma nieskonczenie wiele rozwiazan\n");
            break;
        case 1:
            printf("układ ma jedno rozwiazanie, x=%f, y=%f\n", x, y);
            break;
        case 0:
            printf("układ nie ma rozwiązań");
            break;
    }
}

float obliczWyznacznik(float p1, float p2, float p3, float p4){
    return (p1*p4)-(p3*p2);
}

int obliczRozwiazanie(float a1, float b1, float c1, float a2, float b2, float c2, float *x, float *y){
    float w = obliczWyznacznik(a1,b1,a2,b2);
    float wx = obliczWyznacznik(c1,b1,c2,b2);
    float wy = obliczWyznacznik(a1,c1,a2,c2);
    if(w != 0){
        *x = wx/w;
        *y = wy/w;
        return 1;
    } else if(w == 0 && wx == 0 && wy == 0){
        return 2;
    } else{
        return 0;
    }

}