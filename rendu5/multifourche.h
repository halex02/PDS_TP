#include <assert.h>

/* 
   inclusions pour les fonctions de bases de C 
*/
#include <stdio.h>
#include <stdlib.h>

/* 
   ça c'est pour le fork 
*/
#include <unistd.h>

/* 
   et c'est deux là c'est pour le wait 
*/
#include <sys/types.h>
#include <sys/wait.h>

/*
  pour ne pas retenir les valeurs des booléens en C.
*/
#include "boolean.h"

/*
  définition d'un type pour les pointeurs de fonction à valeur entière et à un seul paramètre entier
 */
typedef int (*func_t) (int) ;

/*
  La fonction multif va prendre deux tableaux, de même taille, 
  et un entier 'n' pour représenter celle-ci.
  Le premier tableau contient des éléments de types func_t (des pointeurs de fonctions)
  tandis que le second contient les arguments pour les fonctions du premier.

  La fonction multif va appeler fork n fois et chaque processus-fils du processus père
  (celui qui contient les appels à fork) va exécuter une des fonctions f[n] avec son paramètre args[n],
  puis rendre la main au père qui va contrôler l'état des fils (finis ou non) et tester les valeurs
  renvoyées par les fils en faisant le ET logique de ces dernières dans l'attente d'une valeur VRAI.
 */
int multif (func_t f[], int args[], int n) ;
