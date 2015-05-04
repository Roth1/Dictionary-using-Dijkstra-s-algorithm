#include <stdio.h>
#include "functions.h"
#include "list.h"

int main() {
  creer_hashtable("./mots/umot4.txt");
  int taille = taille_liste(hashtable[406]);
  printf("\n\nLength of list (abra,braa,bara,raba): %d", taille);
  printf("\nActual table: %d\n\n", taille_table);
  return 0;
}
