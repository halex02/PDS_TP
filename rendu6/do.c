#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "boolean.h"
#include <string.h>
#include <assert.h>

int main (int argc, char *argv[]){

  char optList[], *cmd[];
  int check, cpt ;
  cpt = 1 ;
  optList = "ao" ;

  assert(getCtrlValue(argc, argv, optList, &check)==EXIT_SUCCESS) ;
  checkInvalidCtrlValue(check) ;

  modeSelector(check) ;
  
  
  while(cpt++ < argc){
    if(!isAnOption(argv[cpt]))
      cmd[cpt-1]= argv[cpt] ;
  }

  
  
  return EXIT_SUCCESS ;
}
