#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "exo1.h"


int main ( int argc , char * argv[] ) {

  
  char *str = argv[1];
  char *ptr;
  int tailletab = strtol(str, &ptr, 10);
  
  int i;
  int k = 2; 
  int* tab = malloc(sizeof(int) * tailletab);
  
  tab[0] = 3;
  tab[1] = 5;

 
  for(i=5; ;i+=2) {
    if(pas_premier(tab,tailletab,i)){
      tab[k] = i;
      k++;
      if(k == tailletab) {
	break;
      }
    }
  }

  afficherTableau(tab, tailletab);
  free(tab);
  return EXIT_SUCCESS;
} 
