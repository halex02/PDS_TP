#include "power.h"

int power(int n, int p){
  /*
    on s'assure que n et p sont positifs sinon la fonction plante.
   */
  assert(n>=0 && p>=0) ;

  switch(p){

    /*
      cas de base 1
    */
  case 0 :
    return 1 ;

    /*
      cas de base 2
    */
  case 1 :
    return n ;
    /*
      récursion
    */
  default :
    return n*power(n, p-1) ;
  }
}

/*
  application de la fonction précédente aux puissances de 2, 3 et 5.
 */

int power2(int p) {
  return power(2,p) ;
}

int power3(int p) {
  return power(3,p) ;
}

int power5(int p) {
  return power(5,p) ;
}
