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
* Esercizio 2
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
  printf ("ciao\n");
  pid_t pid = fork();
  if (pid < 0) {
    printf("%s exit", name) ;
    exit(1);
  }
  if(pid == 0) {
    name = name_1;
    fn1();
  }
  else {
    fn0();
  }
  printf("arrivederci\n");
  exit(0);
}

