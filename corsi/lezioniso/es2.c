/*
* Corso di Sistemi Operativi
* A.A. 2019/20
* Corso di Laurea in Scienze e Tecnologie Informatiche
* Universita' della Basilicata
* 
* docente: Ing. Domenico Daniele Bloisi, PhD
*
* domenico.bloisi@unibas.it
*
* es2.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

sem_t s1;
sem_t s2;
sem_t s3;

void* p1(void *arg) {
    sem_wait(&s2);
    sem_wait(&s1);
    printf("G\n");
    sem_post(&s3);
    return NULL;
}

void* p2(void *arg) {
    sem_wait(&s3);
    printf("E\n");
    sem_post(&s1);
    sem_wait(&s3);
    printf("A\n");
    return NULL;
}

void* p3(void *arg) {
    sem_wait(&s1);
    printf("A\n");
    sem_post(&s1);
    printf("D\n");
    sem_post(&s2);
    return NULL;
}

int main() {
    sem_init(&s1, 0, 0);
    sem_init(&s2, 0, 0);
    sem_init(&s3, 0, 1);
    pthread_t th1, th2, th3;
    pthread_create(&th1, NULL, &p1, NULL);
    pthread_create(&th2, NULL, &p2, NULL);
    pthread_create(&th2, NULL, &p3, NULL);
    pthread_join(th1, NULL);
    pthread_join(th2, NULL);
    pthread_join(th3, NULL);
    return 0;
}

