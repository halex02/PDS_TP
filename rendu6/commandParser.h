#include "boolean.h"
#include "flag.h"
#include "stringManipulation.h"
#include <stdlib.h>

struct command_s{
  char *command_f ;
  char *argv_f[] ;
} ;

typedef struct command_s *command_t ;

int isACommand(char *opt) ;

char* getExecutable(char* cmd, int *index) ;

char* getArguments(char* cmd, int *index) ;

char** parseArgv(char* args, int nd) ;

command_t parseCommand(char *cmd, int* index) ;
