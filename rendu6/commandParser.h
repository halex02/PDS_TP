#include <string.h>
#include "boolean.h"
#include "flag.h"

struct command_s{
  char *command ;
  char *argv[] ;
} ;

typedef struct command_s *command_t ;

char* getExecutable(char* cmd) ;

char* getArguments(char* cmd) ;

char** parseArgv(char* args) ;

command_t isACommand(char *opt) ;


