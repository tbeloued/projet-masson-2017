#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/time.h>

struct timeval  tv1, tv2;

// permet de lire la chaine entrée par l'utilisateur
char * getLine(void)
{
  char * line = malloc(100), * linep = line;
  size_t lenmax = 100, len = lenmax;
  int c;

  if(line == NULL)
    return NULL;

  for(;;) {
    c = fgetc(stdin);
    if(c == EOF)
      break;

    if(--len == 0) {
      len = lenmax;
      char * linen = realloc(linep, lenmax *= 2);

      if(linen == NULL) {
	free(linep);
	return NULL;
      }
      line = linen + (line - linep);
      linep = linen;
    }

    if((*line++ = c) == '\n')
      break;
  }
  *line = '\0';
  return linep;
}

// calcul le nombre de mots dans le fichier
int nbrline(FILE* fp) {
  char * line = NULL;
  size_t len = 0;
  ssize_t read;
  int nbrline = 0;
  while ((read = getline(&line, &len, fp)) != -1) {
    nbrline++;
  }
  rewind(fp);
  return nbrline;
}

int main(int argc, char * argv[])
{
  
  FILE * fp;
  char * line = NULL;
  size_t len = 0;
  ssize_t read;
  char *userLine = NULL;
  int nbr_fautes = 0;
  int nbr_mots_traite = 0;
  int nbr_mots_max = 0;
  int nbr_mots_fichier = 0;
  int taille_mots = 0;
  char **tableau_mots;
  int i = 0;
  int loop = 0;
  
  fp = fopen("./data.txt", "r");
  if (fp == NULL)
    exit(EXIT_FAILURE);
  
  nbr_mots_fichier = nbrline(fp);
  // permet de creer un tableau dynamique de chaines de caracteres, 
  tableau_mots = malloc(nbr_mots_fichier * sizeof(char*));
  for (int i = 0; i < nbr_mots_fichier; i++) {
    getline(&line, &len, fp);
    taille_mots = strlen(line);
    tableau_mots[i] = malloc((taille_mots+1) * sizeof(char));
    strcpy(tableau_mots[i], line);
  }
  //si l'utilisateur entre un argument exemple ./prog 10 , argc = 2 et argv[1] = 10
  if(argc == 2) {
    nbr_mots_max = (int) strtol(argv[1], (char **)NULL, 10);
  } else {
    nbr_mots_max = nbr_mots_fichier;
  }
  
  gettimeofday(&tv1, NULL);
  
  for(i=0; i<nbr_mots_fichier && (nbr_mots_traite < nbr_mots_max); i++) {
    if(loop == 1) {
      loop = 0;
      i = 0;
    }
    nbr_mots_traite++;
    line = tableau_mots[i];
    
    printf("Chaine à saisire : %s \n", line);
    userLine = getLine();
    while(strcmp(line,userLine) != 0) {
      printf("Vous avez fait une faute de frappe , merci de reessayer : ");
      nbr_fautes++;
      userLine = getLine();
      printf("\n");
    }

    // à la fin du fichier si on a pas atteind le nombre souhaite de mots on reinitialise la boucle
    if(nbr_mots_traite == nbr_mots_fichier) {
      loop = 1;
      i = 0;
    }
  }
  
   gettimeofday(&tv2, NULL);
   double time_spent = (double) (tv2.tv_usec - tv1.tv_usec) / 1000000 +(double) (tv2.tv_sec - tv1.tv_sec);
   printf("Vous avez passé %f à faire cet excercice \n",time_spent);
   
   fclose(fp);
   if (line)
     free(line);
   if (userLine)
     free(userLine);
   for(i=0; i<nbr_mots_fichier; i++) {
     free(tableau_mots[i]);  
   }
   printf("le nombre de mots traité est : %d \n",nbr_mots_traite);
   printf("le nombre de fautes est : %d \n",nbr_fautes);
   
 
  exit(EXIT_SUCCESS);
}
