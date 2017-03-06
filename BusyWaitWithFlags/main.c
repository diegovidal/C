#include <stdio.h>
#include <ntsid.h>
#include <pthread.h>

char listChar[30];

int flagA = 1,
    flagB = 0,
    flagC = 0,
    indice = 0;

void *p1(){

    while (indice <= 27){
        while (flagA == 0);
        listChar[indice] = 'A';
        indice++;

        flagA = 0;
        flagB = 1;
    }

    pthread_exit(NULL);
}

void *p2(){

    while (indice <= 28){

        while (flagB == 0);
        listChar[indice] = 'B';
        indice++;

        flagB = 0;
        flagC = 1;
    }

    pthread_exit(NULL);
}

void *p3(){

    while (indice <= 29){

        while  (flagC == 0);
        listChar[indice] = 'C';
        indice++;

        flagC = 0;
        flagA = 1;
    }

    for (int i = 0; i < indice; ++i) {

        printf("%c ", listChar[i]);
    }

    pthread_exit(NULL);

}

int main() {

    pthread_t pa, pb, pc;

    pthread_create(&pa, NULL, p1, NULL);
    pthread_create(&pb, NULL, p2, NULL);
    pthread_create(&pc, NULL, p3, NULL);

    pthread_join(pa, NULL);
    pthread_join(pb, NULL);
    pthread_join(pc, NULL);

    pthread_exit(NULL);
}