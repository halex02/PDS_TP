#include "stringManipulation.h"

int getNumberOfChar(char c, const char *s){
  int i, cpt ;

  i = (cpt = 0) ;
  
  while(s[i] != '\0'){
    if(s[i++] == c)
      ++cpt ;
  }
  return cpt ;
}

int getNIndex(char c, const char *s, int n){
  int i, cpt ;
  i = (cpt = 0) ;

  while(s[i] != '\0'){
    if(cpt == n)
      return i ;
    if(s[i] == c)
      ++cpt ;
    ++i ;
  }
  return -1 ;
}

int getFirstIndex(char c, const char *s){
  return getNIndex(c, s, 1) ;
}

char** cutString(char delimiter, char *s){
  int nb_delimiter, i ;
  char delim[1] ;
  char **res ;
  
  nb_delimiter = getNumberOfChar(delimiter, s) ;
  if (nb_delimiter == 0){
    perror("cutString : non delimiter was found.\n") ;
    exit(EXIT_FAILURE) ;
  }
  
  res = (char**)malloc((nb_delimiter+2)*sizeof(char*)) ;
  if(res == NULL){
    perror("cutString : malloc failed.\n") ;
    exit(EXIT_FAILURE) ;
  }
  
  if(s == NULL || s[0] == '\0'){
    perror("cutString : unable to cut the given string.\n") ;
    exit(EXIT_FAILURE) ;
  }
  
  delim[0] = delimiter ;
  
  res[0] = strtok(s, delim) ;
  for(i=1 ; i<(nb_delimiter+2) ; i++){
    res[i] = strtok(NULL, delim) ;
  }

  /*Enfin on retourne le tableau contenant notre découpage de chaîne.*/
  return res ;
}
