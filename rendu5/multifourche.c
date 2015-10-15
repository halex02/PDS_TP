#include "multifourche.h"

int multif (func_t f[], int args[], int n) {
  int i, status, val, ret ;
  
  for(i=0 ; i<n ; i++) {
    switch(fork()) {
      /*
	fork ne crée pas de processus fils pour une raison x,y ou z : on stoppe donc l'exécution du programme tout de suite, renvoie
	'EXIT_FAILURE' et imprime un message sur la sortie d'erreur.
      */
    case -1 :
      perror("fork : boom\n") ;
      exit(EXIT_FAILURE) ;
      /*
	un processus fils est créé, il exécute le code du 'case 0' et renvoie la valeur contenue dans 'val' au père.
       */
    case 0 :
      val = f[i](args[i]) ;
      fprintf(stdout, "f(%d)=%d\n", args[i], val) ; 
      exit(val) ;
    }
  }
  /*
    code exécuté par le père : il boucle tant que tout les fils ne se sont pas terminés
  */
  for(i=0; i<n ; i++){
    wait(&status) ;
    if(WIFEXITED(status))
      ret = ret && WEXITSTATUS(status) ;
  }
  /*
    valeur de retour de multif : ici la somme des résultats fournis par les fonctions du tableau 'f[]'
   */
  return ret ;
}
