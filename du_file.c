#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <limits.h>

static int opt_follow_links = FALSE ;
static int opt_apparent_size = FALSE ;

int du_file(const char *pathname){

  /*
    data : données de l'inoeud.
    content : le chemin que vont suivre les appels récursifs
   */
  struct stat data ;
  struct dirent *content ;
  char entree[PATH_MAX+1] ;
  int size ;
  DIR *dir ;

  if (opt_follow_links)
    assert(stat(pathname, &data)==0) ;
  else
    assert(lstat(pathname, &data)==0) ;

  size=opt_apparent_size ? data.st_size : data.st_blocks ;

  if (S_ISDIR(data.st_mode)){
    
    dir=opendir(pathname) ;
    
    while ((content=readdir(dir)) != NULL){

      if (strcmp(content->d_name, ".") && strcmp(content->d_name, "..")){

	snprintf(entree,PATH_MAX+1, "%s/%s", pathname, content->d_name) ;
	size+=du_file(entree) ;
	  
      }  
    }

    closedir(dir) ;

  }
  return size ;
}

int main (int argc, char *argv[]) {

  getopt(argc, argv[1], "bBL") ;
  
  return EXIT_SUCCESS ;
  
}
