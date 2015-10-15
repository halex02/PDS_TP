#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

typedef int (*func_t) (int) ;

int multif (func_t f[], int args[], int n) ;
