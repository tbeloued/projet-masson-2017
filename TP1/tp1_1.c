#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef unsigned int Uint ; /*redefinition plus compact du type */
typedef unsigned short Ushort ; /*redefinition plus compact du type */
typedef unsigned char Uchar ; /*redefinition plus compact du type */

int main (void)
{

  int d = INT_MAX;
  Uint u = UINT_MAX;
  long l = 1000 ;
  long long L = 1000000 ;
  char c = 'a';
  Uchar C = 'A';
  char * s = "chaîne";
  float f = 1.04;
  double e = 1500;
  void * p = (void *) main;
  /* pointeur sur la fonction main.
     Il donnera juste l'adresse du debut du programme */
  /* le prototype de la fonction a écrire pour toutes les variables
     printf( "la variable vaut %<ici le type>, sa taille est %d et son adresse %p \n",
 <le nom>, sizeof( ) <le nom>; &<le nom>) ;
  */
  
  printf("la variable vaut %d, sa taille est %lu et son adresse %p \n",d, sizeof(d), &d) ;
  printf("la variable vaut %u, sa taille est %lu et son adresse %p \n",u, sizeof(u), &u) ;
  printf("la variable vaut %ld, sa taille est %lu et son adresse %p \n",l, sizeof(l), &l) ;
  printf("la variable vaut %lld, sa taille est %lu et son adresse %p \n",L, sizeof(L), &L) ;
  printf("la variable vaut %c, sa taille est %lu et son adresse %p \n",c, sizeof(c), &c) ;
  printf("la variable vaut %u, sa taille est %lu et son adresse %p \n",C, sizeof(C), &C) ;
  printf("la variable vaut %s, sa taille est %lu et son adresse %p \n",s, sizeof(s), &s);
  printf("la variable vaut %f, sa taille est %lu et son adresse %p \n",f, sizeof(f), &f) ;
  printf("la variable vaut %e, sa taille est %lu et son adresse %p \n",e, sizeof(e), &e) ;
  printf("la variable vaut %s, sa taille est %lu et son adresse %p \n",(char *)p, sizeof(p), &p);
  return EXIT_SUCCESS;
} /* inspiré de Thierry Grandpierre prof à l'Esiee de Noisy */ 
