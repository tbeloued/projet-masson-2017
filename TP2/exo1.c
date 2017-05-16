#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "exo1.h"


int pas_premier(int* tab,int tailletab,int num)
{
  int est_premier = 1;
  int i;
  int maxVal = (int) sqrt(num);
 
  for(i=0; i<tailletab-1 && i<=maxVal; i++) {
    if(tab[i] != 0 && num % tab[i] == 0) {
      est_premier = 0;
      break;
    }
  }

  return est_premier;
}

void afficherTableau(int* tab, int taille)
{
  int i = 0;
  printf("Le tableau contient les elements suivant \n");
  
  for(i=0; i < taille;i++) {
    printf("[%d]\n",tab[i]);
  }
  
}

