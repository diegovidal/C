#include <stdio.h>
#include <ntsid.h>
#include <pthread.h>

int *canal[3] = {NULL, NULL, NULL};

void sendAssync(int *buff, int c){

    *canal[c] = *buff;
    return;
}

void sendSync(int *buff, int c){

    canal[c] = buff;
    while (*canal[c] != NULL);

    printf("recebeu a mensagem");
    return;
}

void receive(int *buff, int c){

    while (canal[c] == NULL);

    *buff = *canal[c];
    *canal[c] = NULL;
    return;
}

void *p1(){

    int v = 10;
    sendSync(&v, 1);

    pthread_exit(NULL);
}

void *p2(){

    int c;
    receive(&c, 1);

    printf("a mensagem foi %d", c);

    pthread_exit(NULL);
}

int main() {

    pthread_t pa, pb;

    pthread_create(&pa, NULL, p1, NULL);
    pthread_create(&pb, NULL, p2, NULL);

    pthread_join(pa, NULL);
    pthread_join(pb, NULL);

    return 0;
}