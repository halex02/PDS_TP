#include <stdio.h>
#include <stdlib.h>
#include "stringManipulation.h"

int main (int argc, char *argv[]){
  int i ;
  char **s ;
  i = 0 ;
  s = cutString(' ', argv[1]) ;
  while (s[i++]!=NULL){
    printf("%s\n", s[i]) ;
  }
  return EXIT_SUCCESS ;
}
