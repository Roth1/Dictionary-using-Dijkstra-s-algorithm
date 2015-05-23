#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include "liste.h"

int main() {
  //créer la table de hashage
  Liste *hashtable = creer_hashtable("./mots/ufrancais.txt");
  //salutation
  printf("\n\n");
  printf("\n\n");
  printf("\n**********************************************************************************************");
  printf("\n*                                                                                            *");
  printf("\n*                               MESDAMES, MESSIEURS, BONJOUR !                               *");
  printf("\n*   Ce jeu vous permet de trouver le plus court chemin entre deux mots d'un dictionnaire!    *");
  printf("\n*                                                                                            *");
  printf("\n**********************************************************************************************\n");
  //entrer la boucle du menue
  char input;
  do {
    printf("\n_____________________________________________________________________________________________");
    printf("\n\nVeuillez entrer: \t [0]                    -> pour entrer les mots et trouver le chemin");
    printf("\n                 \t [1]                    -> pour changer le chemin de la source *.txt");
    printf("\n                 \t [tous les autres]      -> pour quitter le programme");
    printf("\n\n");
    printf("\n\nEntrez votre choix:\t");
    //l'entrée
    input = getchar();
    getchar();
    //soit on cherche le plus court chemin, soit on change le chemin de la source, soit on quitte
    switch(input) {
    case '0':
      printf("\n*** Trouver le plus court chemin ***\n");
      trouve_chemin(hashtable);
      getchar();
      break;
    case '1':
      printf("\n*** Changer le chemin de la source ***\n\nEntrez-vous le nouveau chemin:\t");
      //free_hash(hashtable)
      if(change_chemin() != NULL) {
	hashtable = change_chemin();
      }
      break;
    default:
      input = '9';
      //free_hash(hashtable);
      break;
    }
  } while(input != '9');

  /*****
TO OPTIMIZE:
- do not use a list for the graph -> either original hashtable or hashtable[cout]
- we need to free() our calloc()s
- optimize/merge/delete functions we do not need
- better names
- comment code
- implement improvements -> see .pdf
  *****/
  
  printf("\nVous avez quitté le programme.\nMerci et bonne journée!\n\n");
  return 0;
}
