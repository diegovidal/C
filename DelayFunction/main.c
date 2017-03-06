#include <stdio.h>
#include "time.h"


void delayFunc(float tempo){

    time_t inicio, fim;

    inicio = time(NULL);

    do {
        fim = time(NULL);
//        printf("diftime is %lf\n", difftime(fim, inicio));
    } while (difftime(fim, inicio) <= tempo);
}

int main() {

    printf("\n\nBem vamos chamar o delay\n");
    delayFunc(1);
    printf("Teve o delay");

    return 0;
}