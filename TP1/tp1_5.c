#include<stdio.h>
/* on passe des paramètres à la fonction main.
Ces paramètres sont passé par le système au programme et sont :
 argc est le nombre de paramètres reçu. argv un tableau de chaînes de caractères.
 argv[0] est le nom du programme. argv[1] est le 1er paramètre, etc.
*/
int main ( int argc , char * argv[] ) {
  printf( "nbr. param = %d\n" , argc ) ; /* on affiche le nombre de paramètre */
  printf( "nom prog. = %s\n" , argv[0]) ; /* affiche le nom du programme */
  if ( argc > 1 )
    printf( "param. 1 = %s\n" , argv[1]) ; /* affiche le 1er parametre */
  if ( argc > 2 )
    printf("param. 2 = %s\n" , argv[2]) ; /* affiche le 2em parametre */
  return 0; /* on a remplacé EXIT_SUCCESS par 0 pour ne pas à avoir à inclure limits.h */
} 
