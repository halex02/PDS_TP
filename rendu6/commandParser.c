#include "commandParser.c"

int isACommand(char *opt){
  return !isAnOption(opt) ;
}


char* getExecutable(char *cmd, int *index){
  char* res ;
  *index = 0 ;
  while(cmd[*index] != ' ' || cmd[*index] != '\0'){
    res[*index] = cmd[*index] ;
    ++index ;
  }
  res[*index]='\0' ;
  return res ;
}

char* getArguments(char* cmd, int *index){
  char *res ; 

  switch(cmd[*index]){
  case '\0' :
    return NULL ;

  case ' ' :
    ++(*index) ;
    break ;
  }

  while(cmd[*index] != '\0'){
    res[*index] = cmd[*index] ;
    ++index ;
  }
  res[*index]='\0' ;
  return res ;
}

char** parseArgv(char* args, int nd){
  int i, j, k ;
  char **res ;
  
  i = (j = (k = 0)) ;
  res = (char**)malloc((nd+2)*sizeof(char*)) ;
  
  while(args[k] != '\0' && i != (nd+1)){
    res[i][j]=args[k] ;
    ++k ;
    ++j ;
    
    if (args[k] == ' '){
      res[i++][j]='\0' ;
      
  }
  res[++i] = NULL ;
  return res ;
}
  
command_t parseCommand(char *cmd){
  command_t command ;
  command->command_f = getExecutable(cmd) ;
  command->argv_f = parseArgv(getArguments(cmd)) ;
  return command ;
}
