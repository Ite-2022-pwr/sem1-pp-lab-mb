#include <iostream>
#include <stdio.h>
#define _USE_MATH_DEFINES
#include <cmath>

/*
 * Tytuł: Lab 0
 * Data utworzenia: 09.10.2022 18:20
 * Autor: Miłosz Bedryło
 * Nr Albumu: 272934
 * ITE 1 rok
 * Podstawy programowania laboratoria 0
 * IDE: jetbrains clion
 */

using namespace std;

void wizytowka(string personalia, string adres, string telefon, string mail) {
    cout << endl << "Imie i nazwisko: " << personalia << endl;
    cout << "Adres: " << adres << endl;
    cout << "Telefon: " << telefon << endl;
    cout << "Adres email: " << mail << endl << endl;
}

void obliczenia() {
 int a, b, c;
    cout << endl << "podaj A:" << endl;
    cin >> a;
    cout << endl << "podaj B:" << endl;
    cin >> b;
    cout << endl << "podaj C:" << endl;
    cin >> c;
    int suma = a + b + c;
    int iloczyn = a * b * c;
    float srednia = static_cast<float>(suma) / 3;
    cout << endl << "Suma: " << suma << endl;
    cout << "Iloczyn: " << iloczyn << endl;
    cout << "Średnia: " << srednia << endl;
}

void kolo() {
    float promien = 0;
    printf("Podaj promień koła do obliczenia obwodu i pola: \n");
    scanf("%f", &promien);
    float obwod = 2 * M_PI * promien;
    float pole = M_PI * (promien * promien);
    printf("\nObwód to %f, a pole to %f", obwod, pole);
}

int main() {
    cout << endl <<"Autor: Miłosz Bedryło" << endl;

    wizytowka("Miłosz Bedryło", "Wrocław ul. fikcyjna 15", "123456789", "272934@student.pwr.edu.pl");

    wizytowka("Grzegorz Brzęczyszczykiewicz", "Wrocław ul. fikcyjna 14", "987654321", "123456@student.pwr.edu.pl");

    obliczenia();

    kolo();

    return 0;
}
