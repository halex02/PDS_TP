#include <stdio.h>
#include <stdlib.h>
#include "stringManipulation.h"

int main (int argc, char *argv[]) {
  int test, i ;
  char *s, **test_tab ;
  s = "La vie est belle." ;

  /* test de getNumberOfChar : */
  printf("Test de getNumberOfChar :\n") ;

  test = getNumberOfChar(' ', s) ;
  if(test == 3)
    printf ("Succés - getNumberOfChar : le caractère \"%c\" a été compté 3 fois dans la chaine \"%s\"\n.", ' ', s);
  else
    printf ("Echec - getNumberOfChar : 3 occurences du caractère \"%c\" auraient dû être trouvées dans la chaîne \"%s\" au lieu de %d.\n", ' ', s, test) ;

  test = getNumberOfChar('w', s) ;
  if(test == 0)
    printf("Succés - getNumberOfChar : aucune occurence du caractère \"%c\" n'a été trouvé dans la chaîne \"%s\".\n", 'w', s) ;
  else
    printf("Echec - getNumberOfChar : %d occurences du caractères \"%c\" ont/a été trouvée(s) alors qu'il ne devrait y en avoir aucune dans la chaîne \"%s\".\n", test, 'w', s) ;

  /*Test de la fonction getNIndex : */
  printf("Test de la fonction getNIndex :\n") ;

  test = getNIndex('e', s, 2) ;
  if(test == 8)
    printf("Succès - getNIndex : La %dème occurence du caractère \"%c\" dans la chaîne \"%s\" est à l'index %d.\n", 2, 'e', s, test) ;
  else
    printf("Echec - getNIndex : La %dème occurence du caractère \"%c\" n'a pas été trouvé, ou a été trouvé à la mauvaise place.",2, 'e') ;
  
  test = getNIndex('w', s, 2) ;
  if(test == -1)
    printf("Succès - getNIndex : Le caractère \"%c\" n'a pas été trouvé.Valeur de retour : %d.\n",'w',test) ;
  else
    printf("Erreur - getNIndex : Quelque chose a été trouvé...\n.") ;
  
  /* Test de la fonction getFirstIndex : */
  printf("Test de getFirstIndex :\n") ;
  
  test = getFirstIndex(' ', s) ;
  if (test == 2)
    printf("Succès - getFirstIndex : caractère \"%c\" trouvé à l'index %d dans la chaine \"%s\".\n", ' ', test, s) ;
  else
    printf("Echec - getFirstIndex : la première occurence du caractère \"%c\" n'a pas été trouvé dans la chaine \"%s\".\nValeur de retour : %d.\n", ' ', s, test) ;

  test = getFirstIndex('w', s) ;
  if (test == -1)
    printf("Succès - getFirstIndex : le caractère \"%c\" n'a pas été trouvé dans la chaîne \"%s\".\nValeur de retour : %d.\n", 'w', s, test) ;
  else
    printf("Echec - getFirstIndex : le caractère \"%c\" aurait été trouvé dans la chaine \"%s\" à l'index %d, alors qu'il n'est pas dans la chaîne.\n", 'w', s, test) ;

  /*Test de la fonction cutString :
   (Attention, ça va faire mal... au moins autant que la lecture
  du code de la fonction ^^')*/

  printf("Test de la fonction cutString :\n") ;
  test_tab = cutString(' ', s) ;
  printf("%s\n", s);
  i = 0 ;
  while(test_tab[i] != NULL){
    printf("%s\n", test_tab[i]) ;
    free(test_tab[i]) ;
    ++i ;
  }
  free(test_tab[i]) ;
  free(test_tab) ;

  
  return EXIT_SUCCESS ;
}
