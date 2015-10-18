#include "forkfork.h"

void recfork (func_t f, void *arg, int *acc) {

  if (*acc == RECLEVEL){
    f(arg) ;
    return ;
  }
  
  switch(fork()){

  case -1 :
    perror("fork : boom\n") ;
    exit(EXIT_FAILURE) ;

  case 0 :
    ++(*acc);
    recfork(f, arg, acc) ;
    exit(EXIT_SUCCESS) ;

  case 1 :
    return ;
  }
    
}

void forkfork (func_t f, void *arg){
  int acc ;
  acc = 0 ;
  
  recfork(f, arg, &acc) ;

  return ;
}
