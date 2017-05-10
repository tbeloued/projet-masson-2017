#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main (void)
{
  int d ;
  printf( "| %%6d | %%+6d | %%-6d | %%-+6d| %% 6d | %%06d |\n");
  printf( "+------+------+------+------+------+------+\n");
  d = 0;
  printf( "|%6d|%+6d|%-6d|%-+6d|% 6d|%06d|\n", d, d, d, d, d, d);
  d = 1;
  printf( "|%6d|%+6d|%-6d|%-+6d|% 6d|%06d|\n", d, d, d, d, d, d);
  d = -2;
  printf( "|%6d|%+6d|%-6d|%-+6d|% 6d|%06d|\n", d, d, d, d, d, d);
  d = 100;
  printf( "|%6d|%+6d|%-6d|%-+6d|% 6d|%06d|\n", d, d, d, d, d, d);
  d = 1000;
  printf( "|%6d|%+6d|%-6d|%-+6d|% 6d|%06d|\n", d, d, d, d, d, d);
  d = 10000;
  printf( "|%6d|%+6d|%-6d|%-+6d|% 6d|%06d|\n", d, d, d, d, d, d);
  d = 100000;
  printf( "|%6d|%+6d|%-6d|%-+6d|% 6d|%06d|\n", d, d, d, d, d, d);
  return EXIT_SUCCESS;
} 
