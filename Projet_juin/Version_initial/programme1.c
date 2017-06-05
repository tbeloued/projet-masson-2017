#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/time.h>

struct timeval  tv1, tv2;

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
  
  if(argc == 2) {
    nbr_mots_max = (int) strtol(argv[1], (char **)NULL, 10);
  }
  
  fp = fopen("./data.txt", "r");
  if (fp == NULL)
    exit(EXIT_FAILURE);

  while ((read = getline(&line, &len, fp)) != -1) {
    nbr_mots_fichier++;
  }
  rewind(fp);

  gettimeofday(&tv1, NULL);
  
  while ((read = getline(&line, &len, fp)) != -1 && (nbr_mots_traite < nbr_mots_max)) {
    nbr_mots_traite++;
    printf("Chaine à saisire : %s \n", line);
    userLine = getLine();
    while(strcmp(line,userLine) != 0) {
      printf("Vous avez fait une faute de frappe , merci de reesayer : ");
      nbr_fautes++;
      userLine = getLine();
      printf("\n");
    }
    if(nbr_mots_traite == nbr_mots_fichier) {
      rewind(fp);
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
  
  


  printf("le nombre de mots traité est : %d \n",nbr_mots_traite);
  printf("le nombre de fautes est : %d \n",nbr_fautes);

 
  exit(EXIT_SUCCESS);
}
