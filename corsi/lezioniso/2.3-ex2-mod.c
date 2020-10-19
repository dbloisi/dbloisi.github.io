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
* Esercizio 2 modificato
* Lezione 2.3
*
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

# define A_STEPS 2
# define B_STEPS 5

const char name_0[] = "A|";
const char name_1[] = "B|";
const char *name = name_0;

void fn0() {
  for(unsigned int i = 0; i < A_STEPS; i++) {
    printf ("%s iterazione: #%d \n", name, i);
    sleep(1);
  }
}

void fn1() {
  for(unsigned int i = 0; i < B_STEPS; i++) {
    printf("%s iterazione: #%d \n", name, i);
    sleep(1);
  }
}

int main(int argc, char** argv) {
  printf ("ciao da pid: %d\n", getpid());
  pid_t pid = fork();
  if (pid < 0) {
    printf("%s exit", name) ;
    exit(1);
  }
  if(pid == 0) {
    printf("eseguo name = name_1 (pid: %d)\n", getpid());
    name = name_1;
    printf("invoco fn1() (pid: %d)\n", getpid());
    fn1();
  }
  else {
    printf("invoco fn0() (pid: %d)\n", getpid());
    fn0();
  }
  printf("arrivederci da pid: %d\n", getpid());
  exit(0);
}

