#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>

int prlimit()
{
  printf("La valeur de NAME_MAX est : %n.\n", NAME_MAX) ;
  printf("La valeur de PATH_MAX est : %n.\n", PATH_MAX) ;

  return 0 ;
}
