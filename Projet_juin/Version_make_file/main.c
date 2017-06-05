#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include "prog1.h"
#include <sys/types.h>
#include <sys/time.h>
#include <stdbool.h>

int main(int argc, char * argv[])
{
  
  FILE * fp;
  char * line = NULL;
  size_t len = 0;
  char *userLine = NULL;
  int nbr_fautes = 0;
  int nbr_mots_traite = 0;
  int nbr_mots_max = 0;
  int nbr_mots_fichier = 0;
  int taille_mots = 0;
  char **tableau_mots;
  int i = 0;
  int random = 0;
  int temp = 0;
  int randomIndex = 0;
  int k = 0;
  
  srand (time(NULL));
  fp = fopen("./data.txt", "r");
  if (fp == NULL)
    exit(EXIT_FAILURE);
  
  nbr_mots_fichier = nbrline(fp);
  /* permet de creer un tableau dynamique de chaines de caracteres,*/ 
  tableau_mots = malloc(nbr_mots_fichier * sizeof(char*));
  for (i = 0; i < nbr_mots_fichier; i++) {
    getline(&line, &len, fp);
    taille_mots = strlen(line);
    tableau_mots[i] = malloc((taille_mots+1) * sizeof(char));
    strcpy(tableau_mots[i], line);
  }
  /*si l'utilisateur entre un argument exemple ./prog 10 , argc = 2 et argv[1] = 10*/
  if(argc == 2) {
    nbr_mots_max = (int) strtol(argv[1], (char **)NULL, 10); /* converti string en int*/
  } else {
    nbr_mots_max = nbr_mots_fichier;
  }
    
  gettimeofday(&tv1, NULL);
  int tableau_indice[nbr_mots_max];
  
  for (i = 0; i < nbr_mots_max; i++) {     /* fill array*/
    tableau_indice[i] = i;
  }
 
  for (i = 0; i < nbr_mots_max; i++) {    /* shuffle array*/
    temp = tableau_indice[i];
    randomIndex = rand() % nbr_mots_max;

    tableau_indice[i] = tableau_indice[randomIndex];
    tableau_indice[randomIndex] = temp;
  }


  while(true) {
    random = tableau_indice[k];
    
    tableau_indice[k] = random;
    line = tableau_mots[random % nbr_mots_fichier];
    
    printf("Chaine à saisire : %s \n", line);
    userLine = getLine();
    while(strcmp(line,userLine) != 0) {
      printf("Vous avez fait une faute de frappe , merci de reessayer : ");
      nbr_fautes++;
      userLine = getLine();
      printf("\n");
    }

    /* à la fin du fichier si on a pas atteind le nombre souhaite de mots on reinitialise la boucle*/
    
    nbr_mots_traite++;
    k++;
    
    if(nbr_mots_traite == nbr_mots_fichier) {
      k = 0;
    }
    if(nbr_mots_traite == nbr_mots_max) {
      break;
    }
  }
  
   gettimeofday(&tv2, NULL);
   double time_spent = (double) (tv2.tv_usec - tv1.tv_usec) / 1000000 +(double) (tv2.tv_sec - tv1.tv_sec);
   printf("Vous avez passé %f à faire cet excercice \n",time_spent);
   
   fclose(fp);
   if (userLine)
     free(userLine);
   for(i=0; i<nbr_mots_fichier; i++) {
     if (tableau_mots[i])
       free(tableau_mots[i]);  
   }
   printf("le nombre de mots traité est : %d \n",nbr_mots_traite);
   printf("le nombre de fautes est : %d \n",nbr_fautes);
   
  exit(EXIT_SUCCESS);
}
