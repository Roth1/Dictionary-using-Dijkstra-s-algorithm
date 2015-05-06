#include <stdio.h>
#include "functions.h"
#include "liste.h"

int main() {
  Liste *hashtable = creer_hashtable("./mots/umot4.txt");
  int taille = taille_liste(hashtable[411]);
  printf("\n\nLength of '%s' list: %d\n", hashtable[411]->val, taille);
  Liste proche_voisins = get_proche_voisins("acta", hashtable);
  Liste l = proche_voisins;
  printf("\nLength of neighbor list: %d\n", taille_liste(l));
  while(l != NULL) {
    printf("%s\n", l->val);
    l++;
    }
  printf("\nEnding Theme\n\n");
  return 0;
}
