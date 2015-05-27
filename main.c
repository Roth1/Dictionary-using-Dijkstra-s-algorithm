#include <stdio.h>
#include <stdlib.h>
#include "fonctions.h"
#include "sommet.h"


int main() {
  //créer la table de hashage
  Sommet *hashtable = creer_hashtable("./mots/ufrancais.txt");
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
      if(change_chemin() != NULL) {
	free_hashtable(hashtable);
	hashtable = change_chemin();
      }
      break;
    default:
      input = '9';
      break;
    }
  } while(input != '9');
  //libérer la mémoire
  free_hashtable(hashtable);
  //au revoir
  printf("\nVous avez quitté le programme.\nMerci et bonne journée!\n\n");
  return 0;
}
