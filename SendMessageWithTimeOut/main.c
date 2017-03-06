#include <stdio.h>
#include <ntsid.h>
#include <pthread.h>
#include "time.h"


int canal[3] = {-1, -1, -1};

void delayFunc(float tempo){

    time_t inicio, fim;

    inicio = time(NULL);

    do {
        fim = time(NULL);
//        printf("diftime is %lf\n", difftime(fim, inicio));
    } while (difftime(fim, inicio) <= tempo);
}

void sendSync(int *buff, int c, float tempo){

    time_t inicio, fim;

    canal[c] = *buff;
    inicio = time(NULL);

    do {

        fim = time(NULL);

    } while (canal[c] != -1 && difftime(fim, inicio) <= tempo);

    if (canal[c] == -1){

        printf("A mensagem já foi entregue\n");

    } else printf("A mensagem enviada entrou no time-out\n");
}

void receive(int *buff, int c, float tempo){

    time_t inicio, fim;
    inicio = time(NULL);

    do{

        fim = time(NULL);

    } while (canal[c] == -1 && difftime(fim, inicio) <= tempo);

    if (canal[c] != -1){

        *buff = canal[c];
        printf("A mensagem foi recebida com sucesso\n");
        canal[c] = -1;

    } else printf("A mensagem recebida entrou no time-out\n");
}

void *p1(){

    int v = 10;
    sendSync(&v, 1, 2);
}

void *p2(){

    int v;
    delayFunc(4);
    receive(&v, 1, 2);
}

int main() {

    pthread_t pa, pb;

    pthread_create(&pa, NULL, p1, NULL);
    pthread_create(&pb, NULL, p2, NULL);

    pthread_join(pa, NULL);
    pthread_join(pb, NULL);

    return 0;
}