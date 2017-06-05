#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include <stdbool.h>
/*#include <time.h>*/
#include <sys/types.h>

struct timeval  tv1, tv2;

/* permet de lire la chaine entrée par l'utilisateur*/
char * getLine(void)
{
  char * line = malloc(100), * linep = line;
  size_t lenmax = 100, len = lenmax;
  int c;
  char * linen = NULL;
  
  if(line == NULL)
    return NULL;

  for(;;) {
    c = fgetc(stdin);
    if(c == EOF)
      break;

    if(--len == 0) {
      len = lenmax;
      linen = realloc(linep, lenmax *= 2);

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

/* calcul le nombre de mots dans le fichier*/
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


