#include "multifourche.h"

int multif (func_t f[], int args[], int n) {

  /*
    i : variable de boucle 
    status : l'état renvoyé par un processus fils
    ret : la valeur de retour de la fonction
  */
  int i, status, ret ;
  
  for(i=0 ; i<n ; i++) {
    switch(fork()) {

      /*
	fork ne crée pas de processus fils pour une raison x,y ou z : 
	on stoppe donc l'exécution du programme tout de suite, renvoie
	'EXIT_FAILURE' et imprime un message sur la sortie d'erreur.
      */
    case -1 :
      perror("fork : boom\n") ;
      exit(EXIT_FAILURE) ;

      /*
	un processus fils est créé, il exécute le code du 'case 0' 
	et renvoie la valeur contenue dans 'val' au père.
       */
    case 0 :
      exit(f[i](args[i])) ;
    }
  }

  /*
    code exécuté par le père : il boucle tant que tout les fils ne se sont pas terminés
  */
  for(i=0; i<n ; i++){

    /* 
       on attend le retour de chaque fils et on (ré)affecte le status.
    */
    wait(&status) ;

    /*
      on s'assure de ne pas avoir de zombies, puis on met à jour ret si tout est sûr
      en faisant le ET logique de ret et de la valeur renvoyée par le fils traité.
    */
    if(WIFEXITED(status))
      ret = ret && WEXITSTATUS(status) ;
  }
  
  /*
    si ret ne vaut pas TRUE après qu'on ait fini de boucler,
    dans le doute on fait planter le programme vu que qqc s'est mal passé.
  */
  assert(ret = TRUE) ;
  
  return ret ;
}
