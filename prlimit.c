#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>

int main(int argc, char** argv)
{
  printf("La valeur de NAME_MAX est : %d.\n", NAME_MAX) ;
  printf("La valeur de PATH_MAX est : %d.\n", PATH_MAX) ;

  return 0 ;
}
