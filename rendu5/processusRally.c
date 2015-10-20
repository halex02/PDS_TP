/*
  macros (in)utiles.
  NB : ne pas définir VERBOSE ou alors revenir voir le résultat d'ici une heure ou deux.
  (voir plus bas les explications)
 */
#define TABSIZE 10
#define COUNTMAX 100000000
#define ZOMBIE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main (int argc, char *argv[]){
  /*
    i : variable de boucle
    cpt : compteur pour les processus fils.
   */
  int i, cpt ;
  
#ifdef ZOMBIE
  printf("Ce programme est certifié sans zombies et n'entrainera donc pas d'Apocalypse Zombie.\nPas de souci pour l'humanité aujourd'hui.\n\n") ;
#endif
  
  for(i = 0 ; i < TABSIZE ; i++){
    switch(fork()){
    case -1 :
      perror("fork : boom\n");
      return  EXIT_FAILURE ;

    case 0 :
      cpt = 0 ;
      
      /*
	l'utilisation de la macro VERBOSE a été utilisé pour tester le programme 
	(et visualiser/bidouiller les processus dans htop), et affiche l'intégralité 
	du comptage effectué par chaque processus fils sur la sortie standard; 
	avec ce mode, le programme prend beaucoup trop de temps à s'éxécuter.
	
	on constate en l'utilisant et en tuant le processus père, l'adoption des fils par init,
	qui continuent leur exécution dans la fenêtre xterm (voir les screenshots),
	mais ne répondent plus à la combinaison de touches Ctrl+C dans le terminal.
	On en déduit donc que si leurs sorties standards sont toujours dirigés sur la session bash
	contenue dans xterm, leur exécution n'a plus lieu à cet endroit.
      */
#ifdef VERBOSE

      /*
	post-incrémentation : on compare d'abord la valeur de cpt avec COUNTMAX,
	et seulement ensuite on l'incrémente.
      */
      while(cpt++ != COUNTMAX){
	printf("cpt = %d\n", cpt) ;
      }
#else
      while(cpt++ != COUNTMAX) ;
#endif

      printf("premier comptage fini\n") ;

      /*
	réinitialisation avant le second comptage jusque COUNTMAX
       */
      cpt = 0 ;
      
#ifdef VERBOSE
      while(cpt++ != COUNTMAX){
	printf("cpt = %d\n", cpt) ;
      }
#else
      while(cpt++ != COUNTMAX) ;
#endif

      exit(EXIT_SUCCESS) ;
    }
  }

  /*
    réinitialisation avant réutilisation
  */
  i = 0 ;
  
  /*
    ici, on boucle TABSIZE fois pour imprimer, au fur et à mesure que les fils se
    terminent, leur pid précédé de leur classement dans la course.
    On ne récupére pas les status des processus terminés, et on ne passe aucune option à waitpid
    qui changerait son comportement : chaque appel à waitpid attend tout simplement 
    qu'un processus se finisse, ce qui évite des affichages "bizarres" 
    sur la sortie standard (le terminal qui rend la main à l'utilisateur avant 
    la fin des affichages par exemple) étant donné que printf récupère directement le pid
    et ne peut pas se terminer avant waitpid.
   */
  while (i < TABSIZE){
    printf("#%d : %d\n", i, waitpid(-1, NULL, 0)) ;
    i++ ;
  }
  return EXIT_SUCCESS ;
}
  
