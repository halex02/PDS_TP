#include "mon_tail.h"

#ifdef TAIL_SIMPLE

int tail(char *path, int nline)
{
  int count_lines1, count_lines2, fd, i ;
  char *buffer ;
   
  cpt_lines1 = (cpt_lines2 = 0) ;
  fd = open(path, O_RDONLY) ;
  buffer=(char*)malloc(STRINGSIZE*sizeof(char)) ;

  //contrôle de la réussite de open et de malloc
  assert(fd != -1) ;
  assert(buffer != NULL) ;

  while(size=read(fd, buffer, STREAMSIZE) != 0) ;
  //tant qu'on n'est pas en fin de buffer, on boucle
  for(i=0;i<size;i++)
    {
      // comptage des lignes
      if (*(buffer+i) == '\n')
	count_lines1++ ;
    }
  //on ajoute 1 car la dernière ligne ne se finira pas par '\n'
  count_lines1++ ;

  
  
  
}

#endif

#ifdef TAIL_RELATIVE

int index_tail_buffer(const char *buffer, int bufsize, int ntail, int *nlines)
{

  int index ;
  index = (-1) ;

  while (index <= bufsize)
    {
      ++index ;
    }

  *nlines = index + 1 ;
  
  return index ;
  
}

int tail_before_pos(int fd, unsigned int pos, int ntail)
{
  
}

#endif

#ifdef TAIL_EFFICACE

int tail(const char *path, int ntail)
{

}

#endif

#ifdef TAIL_UTILE

#endif
