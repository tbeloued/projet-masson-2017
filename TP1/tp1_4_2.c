#include <stdlib.h>
#include <stdio.h>
int main()
{
  float sum=0;
  int x;
  float i=0.01;
  float j=0.05;

  for(x=0;x<100;x++)
    {
      sum=sum+i;
    }
  printf("la somme est : %f\n", sum);
  printf("la somme est : %1.3f\n", sum);

  sum=0;
  for(x=0;x<100;x++)
    {
      sum=sum+j;
    }
  printf("la somme est : %f\n", sum);
  printf("la somme est : %1.3f\n", sum);
  return EXIT_SUCCESS;
}
