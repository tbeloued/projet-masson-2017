#include <stdio.h>
#include <stdlib.h>
#include <math.h>


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
  printf("Le tableau contient les elements suivant \n");

  int i = 0;
  for(i=0; i < taille;i++) {
    printf("[%d]\n",tab[i]);
  }
  
}

int main ( int argc , char * argv[] ) {

  
  char *str = argv[1];
  char *ptr;
  int tailletab = strtol(str, &ptr, 10);
  
  
  int tab[tailletab];
  tab[0] = 3;
  tab[1] = 5;

  int i,k = 2;
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
  
  return EXIT_SUCCESS;
} 
