#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <assert.h>
#include "mon_tail.h"

int main (int argc, char** argv) {
  if (argc != 3)
    {
      fprintf(stderr,"%s : nombre de parametres incorrects.\n", argv[0]) ;
      exit EXIT_FAILURE ;
    }
  
  assert(mon_tail(argv[1], argv[2]) == EXIT_SUCCESS) ;
  
  return EXIT_SUCCESS ;
}
