#include <stdio.h>
#include <ntsid.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>

int canal[6] = {-1, -1, -1, -1, -1, -1};

void sendAssync(int *buff, int c){

    canal[c] = *buff;
    return;
}

void receive(int *buff, int c){

    while(canal[c] == -1);

    *buff = canal[c];
    canal[c] = -1;
    return;
}

int altWait(int c, int vetor[]){

    while (1){

        for (int i = 0; i < c; ++i) {

            if (vetor[i] != -1)
                return i;
        }
    }
}

int compara(int vetor[], int *maj){

    if (vetor[0] == vetor[1] && vetor[1] != vetor[2]){
        *maj = vetor[0];
        return 2;
    }
}

void *p1(){

    int voto = 10;
    int status;

    sendAssync(&voto, 0);
    receive(&status, 3);

    if (status == 1){

        printf("P1 Gerou voto errado!\n");
        pthread_exit(NULL);
    }

    printf("P1 continua sua execução\n");
    //while (1);

}

void *p2(){

    int voto = 10;
    int status;

    sendAssync(&voto, 1);
    receive(&status, 4);

    if (status == 1){

        printf("P2 Gerou voto errado!\n");
        pthread_exit(NULL);
    }

    printf("P2 continua sua execução\n");
    //while (1);

}

void *p3(){

    int voto = 2;
    int status;

    sendAssync(&voto, 2);
    receive(&status, 5);

    if (status == 1){

        printf("P3 Gerou voto errado!\n");
        pthread_exit(NULL);
    }

    printf("P3 continua sua execução\n");
    //while (1);

}

int *drive(){

    int can = 0;
    int vetor_comp[3] = {-1, -1, -1};
    int versao = 0;
    int majo = 0;

    int s0 = 0;
    int s1 = 1;

    for (int i = 0; i < 3; ++i) {

        can = altWait(3, canal);
        receive(&vetor_comp[can], can);
    }

    versao = compara(vetor_comp, &majo);
    printf("voto majoritário é %d\n", majo);

    if (versao == 2){

        sendAssync(&s0, 3);
        sendAssync(&s0, 4);
        sendAssync(&s1, 5);
    }
}

int main() {

    pthread_t pa, pb, pc, pd;

    pthread_create(&pa, NULL, p1, NULL);
    pthread_create(&pb, NULL, p2, NULL);
    pthread_create(&pc, NULL, p3, NULL);
    pthread_create(&pd, NULL, drive, NULL);

    pthread_join(pa, NULL);
    pthread_join(pb, NULL);
    pthread_join(pc, NULL);
    pthread_join(pd, NULL);

    return 0;
}