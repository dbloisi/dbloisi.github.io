/*
* Corso di Sistemi Operativi
* 
* Corso di Laurea in Scienze e Tecnologie Informatiche
* Universita' della Basilicata
* 
* docente: Ing. Domenico Daniele Bloisi, PhD
*
* domenico.bloisi@unibas.it
*
* Esercizio 1
* Lezione 2.3
*
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <pthread.h>

# define NUM_STEPS 5

unsigned int value = 0;
pid_t pid;
pthread_t tid;

void* runner(void* param);

int main(int argc, char* argv []) {
    pthread_attr_t attr;
    pid = fork ();

    if(pid < 0)
        return -1;

    if(pid == 0) {
        pthread_attr_init(& attr);
        pthread_create(&tid, &attr, runner, NULL);
        pthread_join(tid, NULL);
        printf("linea A, valore = %d\n", value); /* LINEA A */
    }
    else {
        wait(NULL);
        printf("linea B, valore = %d\n", value); /* LINEA B */
    }
    return 0;
}

void* runner(void* param) {
    for(int s = 0; s < NUM_STEPS; ++s) {
        if(pid) {
            value++;
        }
    }
    return param;
}

