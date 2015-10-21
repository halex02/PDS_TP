#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include "boolean.h"
#include <string.h>
/* 
  Comportement : le processus père va créer
  autant de fils que demandé via le paramètre
  de la ligne de commande, puis se mettre en
  attente.
  Ces X fils vont exécuter le même code en boucle,
  jusqu'à intervention manuel de l'utilisateur
  (meurtre de processus par l'utilisation de kill),
à savoir : afficher leur pid et dormir 5 secondes.
Après avoir créé les fils, le père effectue un ps,
pour que l'on voit les processus en cours 
d'exécution, puis il se met en attente de la fin
d'un fils.
Après la terminaison d'un fils, le père annonce sa fin en renvoyant son pid.
Quand il n'y a plus de fils, le père se termine.
  
Si on tue le processus père, les enfants sont 
adoptés par le processus init et continue leur
exécution en boucle. On peut encore le voir sur
la sortie standard du terminal utilisé,
néanmoins les processus ne semblent plus
s'exécuter dans cet environnement,
en effet Ctrl-C n'a aucun effet sur ces derniers.
il faut les tuer avec kill ou killall pour
les terminer.

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
