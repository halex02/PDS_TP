#include "multifourche.h"
#include "power.h"

int main (int argc, char* argv[]){
  int logAng;
  func_t tabFunc[3] ;
  int tabInt[3] ;

  tabFunc[0] = &power2 ;
  tabInt[0] = 2 ;
  
  tabFunc[1] = &power3 ;
  tabInt[1] = 3 ;
  
  tabFunc[2] = &power5 ;
  tabInt[2] = 5 ;
  
  logAnd = multif(tabFunc,tabInt,3) ;  
  fprintf(stdout, "%d\n", sum) ;
  return EXIT_SUCCESS ;
}
