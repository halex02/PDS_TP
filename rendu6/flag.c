#include "flag.h"

int isAShortOption(char *opt){
  return opt[0]=='-' && opt[1]!='-' && strlen(opt)==2 ;
}

int isALongOption(char *opt){
  return opt[0]='-' && opt[1]=='-' && strlen(opt)>=3 ; 
}

int isAnOption(char *opt){
  return isALongOption(opt) || isAShortOption(opt) ;
}

flag_t valueOfShortFlag(char c){
  switch(c){
  case 'a' :
    return AND ;
  case 'o' :
    return OR ;
  case 'c' :
    return CC ;
  case 'k' :
    return KILL ;
  default :
    return NIHIL ;
  }
}

flag_t valueOfLongFlag(char *s){
  return valueOfShortFlag(s[0]) ;
}

int getCtrlValue(int argc, char *argv[], char *optList, int *check){
  int opt ;
  while((opt = getopt(argc, argv, optList))!=-1){
    switch(opt) {
    case -1 :
      perror("do : something wrong was happened. Case -1 uses normally not to be treated.\n") ;
      return EXIT_FAILURE ;
    case '?' :
      perror("do : You try to use a flag not recognized.\n") ;
      return EXIT_FAILURE ;
    case 'a' :
      *check += AND ;
      break ;
    case 'o' :
      *check += OR ;
      break ;
    case 'c' :
      check* += CC ;
      break ;
    case 'k' :
      check* += KILL ;
      break ;
    default :
      check* += NIHIL ;
      break ;
    }
  }
  return EXIT_SUCCESS ;
}

void checkInvalidCtrlValue(int check) {
  if (!(check==1 || check==2 || check==5 || check==6 || check==13 || check==14)){
    perror("do : You used invalid, incompatible or multiple occurences of a flag.\n")
    exit(EXIT_FAILURE) ;
  }
  return ;
}
