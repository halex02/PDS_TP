#include "power.h"

/*
  fonction qui calcule la puissance p (positive ou nulle) d'un entier n (positif ou nul)
 */
int power(int n, int p){

  /*
    on s'assure que n et p sont positifs sinon la fonction plante, 
    j'ai eu une flemingite aigue à l'idée de généraliser aux entiers relatifs
    pour des fonctions de test.
   */
  assert(n>=0 && p>=0) ;

  switch(p){

    /*
      cas de base 1 : n'importe quoi à la puissance 0, ça fait toujours 1
    */
  case 0 :
    return 1 ;

    /*
      cas de base 2 : n'importe quoi à la puissance 1, ça fait toujours n'importe quoi.
    */
  case 1 :
    return n ;
    
    /*
      récursion : parce qu'on aime les algos récursifs et puis c'est tout <3
    */
  default :
    return n*power(n, p-1) ;
  }
}

/*
  application de la fonction précédente aux puissances de 2, 3 et 5 afin d'avoir des
  fonctions de test pour multif qui ont des prototypes valides pour le type func_t 
  défini dans multifourche.h.
  On a aussi un effet de bord : on imprime les valeurs pour visualiser le fonctionnement,
  ce qui permet de voir en lançant en chaîne le programme de test que les 3 fonctions
  ne seront pas nécessairement exécutées dans le même ordre par les processus-fils du programme
  de test.
 */

int power2(int p) {
  /*
    static pour que la variable n'existe que dans le contexte de ces fonctions,
    comme ça on peut réutiliser le même nom de variable dans chaque fonction.
    Sans ça je n'ai aucune idée de ce que ça peut faire, sûrement des chocapic.
   */
  static int i = power(2,p) ;
  fprintf(stdout, "2^%d = %d\n", p, i) ;
  return i ;
}
 
int power3(int p) {
  static int i = power(3,p) ;
  fprintf(stdout, "3^%d = %d\n", p, i) ;
  return i ;
}

int power5(int p) {
  static int i = power(5,p) ;
  fprintf(stdout, "5^%d = %d\n", p, i) ;
  return i ;
}
