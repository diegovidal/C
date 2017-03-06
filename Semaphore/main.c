#include <stdio.h>
#include <stdlib.h>
#include <ntsid.h>
#include <pthread.h>

int turn = 1;
int ind = 0;

void *p1(){

    while (turn == 1){

        printf("incremento pelo processo 1");
        ind++; // Região crítica

        turn = 2;
    }
}

void *p2(){

    while (turn == 2){

        printf("incremento pelo processo 2");
        ind++; // Região crítica

        turn = 3;
    }
}

void *p3(){

    while (turn == 3){

        printf("incremento pelo processo 3");
        ind++; // Região crítica

        turn = 1;
    }

}

int main() {

    pthread_t pa,pb,pc;

    pthread_create(&pa, NULL, p1, NULL);
    pthread_create(&pb, NULL, p2, NULL);
    pthread_create(&pc, NULL, p3, NULL);

    pthread_join(pa, NULL);
    pthread_join(pb, NULL);
    pthread_join(pc, NULL);

    return 0;
}