#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include "liste.h"

int main() {
  Liste *hashtable = creer_hashtable("./mots/umot4.txt");
  int taille = taille_liste(hashtable[411]);
  printf("\n\nLength of '%s' list: %d\n", hashtable[411]->val, taille);
  Cout_Liste graphe = get_court_chemin("rage", "rats", hashtable);
  Cout_Liste l = recherche_cout_liste("rats", 4, graphe);
  if(l == NULL) puts("\nBUZZKILL!!");
  //printf("\nLength of neighbor list: %d\n", taille_liste(l));
  while(l != NULL) {
    printf("%s\t%d\n", l->val, l->cout);
    l=l->pere;
    }
  printf("\nEnding Theme...\n\n");
  return 0;
}
