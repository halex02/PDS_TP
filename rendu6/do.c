#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "boolean.h"
#include <string.h>

int main (int argc, char *argv[]){

  char optList[], *cmd[];
  int opt, cpt ;
  cpt = 1 ;
  optList = "ao" ;
  

  while(cpt++ < argc){
    if(!isAnOption(argv[cpt]))
      cmd[cpt-1]= argv[cpt] ;
  }

  
  
  return EXIT_SUCCESS ;
}
