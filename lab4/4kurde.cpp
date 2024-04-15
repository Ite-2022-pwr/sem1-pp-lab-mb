void zadanie4(){
    int zmiennaInt2 = 3;
    int *wi2 = &zmiennaInt2;
    float zmiennaFloat2 = 2.1;
    float *wf2 = &zmiennaFloat2;
    double zmiennaDouble2 = 3.2;
    double *wd2 = &zmiennaDouble2;
    bool zmiennaBool2 = false;
    bool *wb2 = &zmiennaBool2;
    char zmiennaChar2 = 'B';
    char *wc2 = &zmiennaChar2;
    long zmiennaLong2 = 654321;
    long *wl2 = &zmiennaLong2;
    if(true){
        int zmiennaInt3 = 31;
        int *wi3 = &zmiennaInt3;
        float zmiennaFloat3 = 2.32423;
        float *wf3 = &zmiennaFloat3;
        double zmiennaDouble3 = 3.789;
        double *wd3 = &zmiennaDouble3;
        bool zmiennaBool3 = false;
        bool *wb3 = &zmiennaBool3;
        char zmiennaChar3 = 'C';
        char *wc3 = &zmiennaChar3;
        long zmiennaLong3 = 7;
        long *wl3 = &zmiennaLong3;
        printf("\nAdres int globalny: %p ,Wartość: %d, Rozmiar: %lu bajty, Bajty:",wi1,*wi1, sizeof(*wi1));
        for(int j =sizeof(*wi1)-1; j>-1;j--)
            printf("0x%02x ",*((char*)wi1+j));
        printf("\nAdres int lokalny funkcji: %p ,Wartość: %d, Rozmiar: %lu bajty, Bajty:",wi2,*wi2,sizeof(*wi2));
        for(int j =sizeof(*wi2)-1; j>-1;j--)
            printf("0x%02x ",*((char*)wi2+j));
        printf("\nAdres int lokalny w if: %p ,Wartość: %d, Rozmiar: %lu bajty, Bajty:",wi3,*wi3,sizeof(*wi3));
        for(int j =sizeof(*wi3)-1; j>-1;j--)
            printf("0x%02x ",*((char*)wi3+j));
        printf("\nAdres float globalny: %p ,Wartość: %f, Rozmiar: %lu bajty, Bajty:",wf1,*wf1,sizeof(*wf1));
        for(int j =sizeof(*wf1)-1; j>-1;j--)
            printf("0x%02x ",*((char*)wf1+j));
        printf("\nAdres float lokalny funkcji: %p ,Wartość: %f, Rozmiar: %lu bajty, Bajty:",wf2,*wf2,sizeof(*wf2));
        for(int j =sizeof(*wf2)-1; j>-1;j--)
            printf("0x%02x ",*((char*)wf2+j));
        printf("\nAdres float lokalny w if: %p ,Wartość: %f, Rozmiar: %lu bajty, Bajty:",wf3,*wf3,sizeof(*wf3));
        for(int j =sizeof(*wf3)-1; j>-1;j--)
            printf("0x%02x ",*((char*)wf3+j));
        printf("\nAdres double globalny: %p ,Wartość: %f, Rozmiar: %lu bajty, Bajty:",wd1,*wd1,sizeof(*wd1));
        for(int j =sizeof(*wd1)-1; j>-1;j--)
            printf("0x%02x ",*((char*)wd1+j));
        printf("\nAdres double lokalny funkcji: %p ,Wartość: %f, Rozmiar: %lu bajty, Bajty:",wd2,*wd2,sizeof(*wd2));
        for(int j =sizeof(*wd2)-1; j>-1;j--)
            printf("0x%02x ",*((char*)wd2+j));
        printf("\nAdres double lokalny w if: %p ,Wartość: %f, Rozmiar: %lu bajty, Bajty:",wd3,*wd3,sizeof(*wd3));
        for(int j =sizeof(*wd3)-1; j>-1;j--)
            printf("0x%02x ",*((char*)wd3+j));
        printf("\nAdres bool globalny: %p ,Wartość: %d, Rozmiar: %lu bajty, Bajty:",wb1,*wb1,sizeof(*wb1));
        for(int j =sizeof(*wb1)-1; j>-1;j--)
            printf("0x%02x ",*((char*)wb1+j));
        printf("\nAdres bool lokalny funkcji: %p ,Wartość: %d, Rozmiar: %lu bajty, Bajty:",wb2,*wb2,sizeof(*wb2));
        for(int j =sizeof(*wb2)-1; j>-1;j--)
            printf("0x%02x ",*((char*)wb2+j));
        printf("\nAdres bool lokalny w if: %p ,Wartość: %d, Rozmiar: %lu bajty, Bajty:",wb3,*wb3,sizeof(*wb3));
        for(int j =sizeof(*wb3)-1; j>-1;j--)
            printf("0x%02x ",*((char*)wb3+j));
        printf("\nAdres char globalny: %p ,Wartość: %c, Rozmiar: %lu bajty, Bajty:",wc1,*wc1,sizeof(*wc1));
        for(int j =sizeof(*wc1)-1; j>-1;j--)
            printf("0x%02x ",*((char*)wc1+j));
        printf("\nAdres char lokalny funkcji: %p ,Wartość: %c, Rozmiar: %lu bajty, Bajty:",wc2,*wc2,sizeof(*wc2));
        for(int j =sizeof(*wc2)-1; j>-1;j--)
            printf("0x%02x ",*((char*)wc2+j));
        printf("\nAdres char lokalny w if: %p ,Wartość: %c, Rozmiar: %lu bajty, Bajty:",wc3,*wc3,sizeof(*wc3));
        for(int j =sizeof(*wc3)-1; j>-1;j--)
            printf("0x%02x ",*((char*)wc3+j));
        printf("\nAdres long globalny: %p ,Wartość: %ld, Rozmiar: %lu bajty, Bajty:",wl1,*wl1,sizeof(*wl1));
        for(int j =sizeof(*wl1)-1; j>-1;j--)
            printf("0x%02x ",*((char*)wl1+j));
        printf("\nAdres long lokalny funkcji: %p ,Wartość: %ld, Rozmiar: %lu bajty, Bajty:",wl2,*wl2,sizeof(*wl2));
        for(int j =sizeof(*wl2)-1; j>-1;j--)
            printf("0x%02x ",*((char*)wl2+j));
        printf("\nAdres long lokalny w if: %p ,Wartość: %ld, Rozmiar: %lu bajty, Bajty:",wl3,*wl3,sizeof(*wl3));
        for(int j =sizeof(*wl3)-1; j>-1;j--)
            printf("0x%02x ",*((char*)wl3+j));
        char* tab = (char*)wl3;
        for (int i = 0; i < sizeof(tab); ++i) {
            printf("%02#x", tab[i]);
        }

    }
    fflush(stdin);
    getchar();
}