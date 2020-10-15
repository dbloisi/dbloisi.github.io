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
* Esercizio 3 modificato
* Lezione 2.3
*
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main (int argc, char** argv) {
    if(fork() == 0) {
        if(fork() == 0) {
            printf("stampo A (pid: %d)\n", getpid());
            printf ("A\n");
            return 0;
        }
        else {
            printf("sono in attesa (pid: %d)\n", getpid());
            pid_t pid = wait(NULL);
            printf("attesa di %d terminata (pid: %d)\n", pid, getpid());
            printf("stampo B (pid: %d)\n", getpid());
            printf("B\n");
        }
    }
    else {
        if(fork() == 0) {
            printf("stampo C (pid: %d)\n", getpid());
            printf("C\n");
            exit(0);
        }
        else {
            printf("sono in attesa (pid: %d)\n", getpid());
            pid_t pid = wait(NULL);
            printf("attesa di %d terminata (pid: %d)\n", pid, getpid());
        }
        printf("sono in attesa (pid: %d)\n", getpid());
        pid_t pid = wait(NULL);
        printf("attesa di %d terminata (pid: %d)\n", pid, getpid());
        printf("stampo D (pid: %d)\n", getpid());
        printf("D\n");
    }
    printf("stampo E (pid: %d)\n", getpid());
    printf ("E");
    return 0;
}

