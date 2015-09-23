#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>

#define TRUE 1
#define FALSE 0

int main (int argc, char** argv)
{ 
  /*
    i : variable de boucle. 
    mode : détermine les permissions à tester sur le fichier passé
    en paramètre.
    verboseCheck : détermine si le mode verbose doit être utilisé
    ou non pour le retour des erreurs.
    permissions : l'entier représentant les permissions sur le fichier testé
    pour l'utilisateur lançant le programme.
   */
  int i, mode, permissions ;
  /*int verboseCheck ;*/

  /*
    param: l'ensemble des flags permettant de choisir les permissions
    à tester sur le fichier, et d'activer ou non le mode verbose.
    chemin : le chemin vers le fichier à tester.
    c : l'un des flags.
  */
  char *param, *chemin, c ;

  mode = 0 ;
  /* ayant eu des segfault problématiques nous avons laissé de côté le mode verbeux*/
  /*verboseCheck = FALSE ;*/
  permissions = (-1) ; 

  /*
    si on a pas le bon nombre de paramètres sur la ligne de commande, on fait planter le programme.
   */
  if (argc < 3 && argc > 3)
    exit(EXIT_FAILURE) ;
  
  /*
    on aura au plus 5 caractères dans la chaine param "-rwxv" + le '\0' de fin de chaine.
  */
  param = (char*)malloc(6*sizeof(char)) ; /* tentative de résoudre la segfault en utilisant malloc : inefficace*/
  
  chemin = (char*)malloc(PATH_MAX*sizeof(char)) ; /* même chose que pour le pointeur param */

  
  param = *(argv+1) ;
  chemin = *(argv+2);
  printf("%s\n", param) ;
  printf("%s\n", chemin) ;
  
  
  /*
    boucle de sélection des modes.
   */
  for (i = 1 ; i < strlen(param) ; i++)
    {
      c = *(param+i);
      switch (c)
	{
	case 'r' :
	  mode = mode | R_OK ;
	  break ;

	case 'w' :
	  mode = mode | W_OK ;
	  break ;

	case 'x' :
	  mode = mode | X_OK ;
	  break ;

	/* case 'v' : */
	/*   verboseCheck = TRUE ; */
	/*   break ; */

	default :
	  /*
	    si on passe un paramètre non reconnu, on envoie un message
	    à l'utilisateur et on force la fermeture du programme sans tester
	    les permissions.
	   */
	  printf("Le flag %c n'est pas valide.", c) ;
	  exit(EXIT_FAILURE) ;
	  break ;
	}	
    }
  permissions = access(chemin, mode) ;
  printf("%d\n", permissions) ;
  return 0 ;
}
