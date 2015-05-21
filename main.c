#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include "liste.h"

int main() {
  Liste *hashtable = creer_hashtable("./mots/umot4.txt");
  //int taille = taille_liste(hashtable[411]);
  //printf("\n\nLength of '%s' list: %d\n", hashtable[411]->val, taille);
  //Liste k = get_proche_voisins("gage", hashtable);
  //while(k != NULL) {
  //  printf("%s\n", k->val);
  //  k = k->suiv;
  //}
  get_court_chemin("rage", "rose", hashtable);
  //Cout_Liste l = recherche_cout_liste("gage", 4, graphe);
  //if(l == NULL) puts("\nBUZZKILL!!");
  //printf("\nLength of neighbor list: %d\n", taille_liste(l));

  /*****
TO OPTIMIZE:
- do not use a list for the graph -> either original hashtable or hashtable[cout]
- error-handling -> distance infinity, etc
- we need to free() our calloc()s
- optimize/merge/delete functions we do not need
- better names
- comment code
- implement improvements -> see .pdf
  *****/

  
  printf("\nEnding Theme...\n\n");
  return 0;
}
