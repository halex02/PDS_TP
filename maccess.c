#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main (char** argv, int argc)
{

  if (argc < 2 && argc > 2)
    exit(EXIT_FAILURE) ;

  int i ;
  char* param, chemin, c ;
  param = argv+1 ;

  for (i = 1 ; i < strlen(param) ; i++)
    {
      c = param+i ;
      switch (*c)
	{
	case 'r' :
	  access(chemin,R_OK) ;
	  break ;

	case 'w' :
	  access(chemin,W_OK) ;
	  break ;

	case 'x' :
	  access(chemin, X_OK) ;
	  break ;

	case 'v' :
	  break ;

	default :
	  printf("Le flag %c n'est pas valide.", *c) ;
	  break ;
	}
	
	
    }
}
