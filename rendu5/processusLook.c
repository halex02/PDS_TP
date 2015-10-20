#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include "boolean.h"
#include <string.h>

/*
int atoi (char*)
*/

int main (int argc, char* argv[]){
  int borneMax ;
  int i ;

  borneMax = atoi(argv[1]) ;
  
  for (i = 0 ; i < borneMax ; i++){
    switch(fork()){
    case -1 :
      perror("fork : boom\n");
      exit(EXIT_FAILURE) ;
    case 0 :
      while(TRUE){
	printf("je suis le fils n°%d.\n", getpid()) ;
	sleep(5) ;
      }
      exit(EXIT_SUCCESS) ;
    } 
  }

  system("ps -a") ;
  for (i = 0 ; i < borneMax ; i++) {
    /* printf("fils n°%d terminé.\n", waitpid(-1,NULL, 0)) ; */
    printf("fils n°%d terminé.\n", wait(NULL)) ;
  }
  
  return EXIT_SUCCESS ;
}
