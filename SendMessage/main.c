#include <stdio.h>
#include <ntsid.h>
#include <pthread.h>


int canal[3] = {-1,-1,-1};

void sendAssync(int *buff,int c){

    canal[c] = *buff;
    return;
}

void sendSync(int *buff, int c){

    canal[c] = *buff;
    while (canal[c] != -1);
    printf("prossegue\n");
    return;
}

void receive(int *buff, int c){

    while (canal[c] == -1);
    *buff = canal[c];
    canal[c] = -1;
    return;
}

void *p1(){

    int v = 10;
    sendSync(&v, 1);

    pthread_exit(NULL);

}

void *p2(){

    int r;
    receive(&r, 1);
    printf("recebeu o valor %d", r);

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