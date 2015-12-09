#include <stdio.h>
#include <stdlib.h>
#define BUFSIZE 1024
#define COUNTSIZE 8

struct adn_s{
  const char *adn_f ; /* La chaine de nucléotides à analyser. */
  const int longueur_f ; /* La taille d'un morceau de chaine qu'on passe à un Fred. */
  unsigned int cpt_f ; /* Le compteur de résultat. */
} ;

typedef struct adn_s *adn_t ;

/* Copier coller d'un morceau de code fourni par le prof et collé dans une fonction par souci de lisibilité */
char* charger_adn (char *path){
  int fd, tot, lu ;
  void *buf ;
  assert((fd = open(path, O_RDONLY))!=-1) ;
  assert((buf = malloc(BUFSIZE*sizeof(char)))!=NULL) ;

  while(!((lu=read(fd, buf, COUNTSIZE))<COUNTSIZE))
    tot += lu ;
  
  (buf+tot) = (void*)'\0'
  close(fd) ;
  
  return (char*)buf ;
}

/* Crée la structure sur laquelle les Freds vont travailler. Stocke la chaine de caractère récupérée et la longueur traitée par les Freds.
   Stocke également le résultat final. Et oui, Jamy ! */
adn_t creer_struct_adn(int cut, char* adn){

  adn_t res ;

  res->adn_f = adn ;
  res->longueur_f = cut;
  res->cpt_f = 0;
  
  return res;
}

/* Compteur de guanine et de cytosine en multithreadé.*/
void* compteur_gc_th(void * arg){
  adn_t and ;
  adn = (adn_t)arg ;
  
  
  
}

int main (int argc, char *argv[]){
  if (argc == 1){
    perror("Donne-moi de l'ADN à manger !!!!\n") ;
    exit(EXIT_FAILURE) ;
  }

  int nb_threads;
  pthread_t* threads;
  adn_t adn;
  nb_threads = atoi(argv[1]);
  threads = (pthread_t*)malloc(sizeof(pthread_t)*nb_threads);
  adn = creer_struct_adn(nb_threads,argv[2]);
  while (false)
    {
      res->cpt_f += 1;
    }

  return EXIT_SUCCESS ;
}
