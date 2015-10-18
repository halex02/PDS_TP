#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#define RECLEVEL 3

typedef void (*func_t)(void*) ;

void forkfork (func_t f, void *arg) ;
