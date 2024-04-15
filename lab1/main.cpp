#include <iostream>
#include <math.h>

/*
 * Tytuł: Lab 1
 * Data utworzenia: 09.10.2022
 * Autor: Miłosz Bedryło
 * Grupa: Poniedziałek nieparzysty
 * Nr Albumu: 272934
 * ITE 1 rok
 * Podstawy programowania laboratoria 1
 * IDE: jetbrains clion
 */

void kwadratowa() { //zadanie 1
    float a, b, c;
    std::cout << "podaj współczynnik a funkcji kwadratowej: " << std::endl;
    std::cin >> a;
    std::cout << "podaj współczynnik b funkcji kwadratowej: " << std::endl;
    std::cin >> b;
    std::cout << "podaj współczynnik c funkcji kwadratowej: " << std::endl;
    std::cin >> c;
    if (a != 0) {
        float delta = (b * b) - (4 * a * c);
        if (delta < 0) {
            std::cout << "ta funkcja nie ma rozwiązań rzeczywistych" << std::endl;
        } else if (delta == 0) {
            float x1 = -b / (2 * a);
            std::cout << "funkcja ma jedno miejsce zerowe: " << std::endl << x1 << std::endl;
        } else {
            float x1 = (-b - sqrt(delta)) / (2 * a);
            float x2 = (-b + sqrt(delta)) / (2 * a);
            std::cout << "funkcja ma dwa miejsca zerowe: " << std::endl << x1 << std::endl << x2 << std::endl;
        }
    } else {
        std::cout << "to nie jest funkcja kwadratowa" << std::endl;
    }
}

void poprawnaData() { //zadanie 2
    int dzien, miesiac, rok;
    std::cout << "podaj dzień daty do sprawdzenia: " << std::endl;
    std::cin >> dzien;
    std::cout << "podaj miesiąc daty do sprawdzenia: " << std::endl;
    std::cin >> miesiac;
    std::cout << "podaj rok daty do sprawdzenia: " << std::endl;
    std::cin >> rok;
    std::cout << "Podana data to: " << std::endl << dzien << "." << miesiac << "." << rok << "r." << std::endl;
    if (dzien < 1 || miesiac < 1 || miesiac > 12 || rok < 1) {
        std::cout << "data niepoprawna" << std::endl;
    } else {
        if (miesiac == 1 || miesiac == 3 || miesiac == 5 || miesiac == 7 || miesiac == 8 || miesiac == 10 ||
            miesiac == 12) {
            if (dzien >= 1 && dzien <= 31) {
                std::cout << "Data Poprawna" << std::endl;
            } else {
                std::cout << "Data niepoprawna" << std::endl;
            }
        } else if (miesiac == 4 || miesiac == 6 || miesiac == 9 || miesiac == 11) {
            if (dzien >= 1 && dzien <= 30) {
                std::cout << "Data Poprawna" << std::endl;
            } else {
                std::cout << "Data niepoprawna" << std::endl;
            }
        } else if (miesiac == 2) {
            if ((rok % 4 != 0) || ((rok % 100 == 0) && (rok % 400 != 0))) {
                if (dzien >= 1 && dzien <= 28) {
                    std::cout << "Data Poprawna" << std::endl;
                } else {
                    std::cout << "Data niepoprawna" << std::endl;
                }
            } else {
                if (dzien >= 1 && dzien <= 29) {
                    std::cout << "Data Poprawna" << std::endl;
                } else {
                    std::cout << "Data niepoprawna" << std::endl;
                }
            }
        }
    }
}

void trojkaty() { //zadanie 3
    float boki[3];
    int temp = 0;
    std::cout << "Podaj 1 bok trójkąta do sprawdzenia: " << std::endl;
    std::cin >> boki[0];
    std::cout << "Podaj 2 bok: " << std::endl;
    std::cin >> boki[1];
    std::cout << "Podaj 3 bok: " << std::endl;
    std::cin >> boki[2];
    if (boki[0] + boki[1] > boki[2] && boki[2] + boki[1] > boki[1] && boki[0] + boki[2] > boki[1] && boki[0] > 0 && boki[1] > 0 && boki[2] > 0) {
        if (boki[0] == boki[1] && boki[1] == boki[2] && boki[0] == boki[2]) {
            temp += 1;
        }
        if (boki[0] == boki[1] || boki[1] == boki[2] || boki[0] == boki[2]) {
            temp += 2;
        }
        if (pow(boki[0],2)+pow(boki[1],2) > pow(boki[2],2) && pow(boki[0],2)+pow(boki[2],2) > pow(boki[1],2) && pow(boki[1],2)+pow(boki[2],2) > pow(boki[0],2)) {
            temp += 4;
        }
        if (pow(boki[0],2)+pow(boki[1],2) == pow(boki[2],2) || pow(boki[0],2)+pow(boki[2],2) == pow(boki[1],2) || pow(boki[1],2)+pow(boki[2],2) == pow(boki[0],2)) {
            temp += 8;
        }
        if (pow(boki[0],2)+pow(boki[1],2) < pow(boki[2],2) && pow(boki[0],2)+pow(boki[2],2) < pow(boki[1],2) && pow(boki[1],2)+pow(boki[2],2) < pow(boki[0],2)) {
            temp += 16;
        }
        switch (temp) {
            case 4:
                std::cout << "trójkąt ostrokątny" << std::endl;
                break;
            case 6:
                std::cout << "trójkąt równoramienny ostrokątny" << std::endl;
                break;
            case 7:
                std::cout << "trójkąt równoboczny" << std::endl;
                break;
            case 8:
                std::cout << "trójkąt prostokątny" << std::endl;
                break;
            case 10:
                std::cout << "trójkąt prostokątny równoramienny" << std::endl;
                break;
            case 16:
                std::cout << "trójkąt rozwartokątny" << std::endl;
                break;
            case 18:
                std::cout << "trójkąt rozwartokątny równoramienny" << std::endl;
                break;
        }
    } else {
        std::cout << "to nie trójkąt" << std::endl;
    }
}

void tabelka() { //zadanie 4
    float przedzialStart, przedzialKoniec, odstep, promien;
    int wiersze;

    std::cout << "Podaj start zakresu promieni: " << std::endl;
    std::cin >> przedzialStart;
    std::cout << "Podaj koniec zakresu promieni: " << std::endl;
    std::cin >> przedzialKoniec;
    std::cout << "Podaj liczbe wierszy: " << std::endl;
    std::cin >> wiersze;
    std::cout << std::endl;

    odstep = (przedzialKoniec - przedzialStart)/(wiersze - 1);

    std::cout << "=================================" << std::endl;
    std::cout << "|LP|promien|obwód koła|pole koła|" << std::endl;
    std::cout << "=================================" << std::endl;

    for (int i = 0; i < wiersze; ++i) {
        promien = przedzialStart + (odstep * i);
        printf("|%2d|%7.2f|%10.2f|%9.2f| \n", i+1, promien, (promien*2*M_PI),(pow(promien, 2)*M_PI));
        //std::cout << "|" << i + 1 << "|" << roundf(promien * 100) / 100 << "|" << roundf((promien*2*M_PI) * 100) / 100 << "|" << roundf((pow(promien, 2)*M_PI) * 100) / 100 << "|" << std::endl;
    }
    std::cout << "=================================" << std::endl;
}

int main() {

    std::cout << "Miłosz Bedryło \n podstawy programowania \n poniedziałek nieparzysty\n\n";

    kwadratowa();
    poprawnaData();
    trojkaty();
    tabelka();
    return 0;
}
