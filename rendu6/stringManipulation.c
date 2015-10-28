#include "stringManipulation.h"

int getFirstIndex(char c, char *s, size_t t){
  int i ;
  for (i = 0 ; i < t ; i++) {
    if(s[i]==c)
      return i ;
  }
  return -1 ;
}

int getNumberOfChar(char c, char *s){
  int i, cpt ;

  i = (cpt = 0) ;
  
  while(s[i] != '\0'){
    if(s[i++] == 'c')
      ++cpt ;
  }
  return i ;
}

char** cutString(char del, char *s, char **dest){
  int cpt ;
  cpt = 0 ;
  while(s[cpt]!='\0'){
    if (s[cpt]==del)
      s[cpt++]='\0' ;
  }
  return (char**)s ;
}

int cutString(char del, char *s, char **dest){
  
  
  
  return EXIT_SUCCESS ;
}
