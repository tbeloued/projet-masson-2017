#include<stdio.h>
/* on passe des paramètres à la fonction main.
Ces paramètres sont passé par le système au programme et sont :
 argc est le nombre de paramètres reçu. argv un tableau de chaînes de caractères.
 argv[0] est le nom du programme. argv[1] est le 1er paramètre, etc.
*/
int main ( int argc , char * argv[] ) {
  
  if ( argc == 2 && *argv[1] == '+')
    printf( "Le paramètre est : %s\n" , argv[1]) ; /* affiche le 1er parametre */
  if ( argc == 2 && *argv[1] == '/')
    printf( "Le paramètre est : %s\n" , argv[1]) ; /* affiche le 1er parametre */
  if ( argc == 2 && *argv[1] == '%')
    printf( "Le paramètre est : %s\n" , argv[1]) ; /* affiche le 1er parametre */
  if ( argc == 2 && *argv[1] == '-')
    printf( "Le paramètre est : %s\n" , argv[1]) ; /* affiche le 1er parametre */
  
  return 0; /* on a remplacé EXIT_SUCCESS par 0 pour ne pas à avoir à inclure limits.h */
} 
