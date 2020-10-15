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
* Esercizio 3
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
            printf ("A");
            return 0;
        }
        else {
            wait(NULL);
            printf("B");
        }
    }
    else {
        if(fork() == 0) {
            printf("C");
            exit(0);
        }
        else {
            wait(NULL);
        }
        wait(NULL);
        printf("D");
    }
    printf ("E");
    return 0;
}

