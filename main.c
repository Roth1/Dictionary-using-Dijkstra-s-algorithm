#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include "liste.h"

int main() {
  //créer la table de hashage
  Liste *hashtable = creer_hashtable("./mots/ufrancais.txt");

  printf("\n\n");
  printf("\n\n");
  printf("\n***********************************************************************************************");
  printf("\n*                                                                                             *");
  printf("\n*                               MESDAMES, MESSIEURS, BONJOUR !                                *");
  printf("\n*   Ce jeux vous permet de trouver le plus court chemin entre deux mots d'une dictionnaire!   *");
  printf("\n*                                                                                             *");
  printf("\n***********************************************************************************************\n");
  //entrer boucle du menue
  char input;
  do {
    printf("\n\nVeuillez entrer: \t [0]                    -> pour entrer les mots et trouver le chemin");
    printf("\n                 \t [1]                    -> pour changer le chemin de la source (*.txt)");
    printf("\n                 \t [tous les autres]      -> pour quitter le programme");
    printf("\n\n");
    printf("\n\nEntrez-vous votre choix:\t");
    //l'entrée
    //fseek(stdin,0,SEEK_END);
    input = getchar();
    getchar();
    putchar(input);
    //soit on cherche le plus court chemin entre deux mots
    //soit on change le chemin de la source *.txt
    switch(input) {
    case '0':
      printf("\nTrouver le plus court chemin:\n");
      //trouve_chemin(hashtable);
      get_court_chemin("bonne", "femme", hashtable);
      break;
    case '1':
      printf("\nChanger le chemin de la source:\nEntrez-vous le nouveau chemin:\t");
      //free_hash(hashtable)
      if(change_chemin() != NULL) {
	hashtable = change_chemin();
      }
      break;
    default:
      printf("\n");
      input = '9';
      //free_hash(hashtable);
      break;
    }
  } while(input != '9');

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
