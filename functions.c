#include "functions.h"


/*************************************************************************
 * Hash-Function: Relatively good Hash-Function.                         *
 *************************************************************************/
int hash(unsigned char *str) {
  int hash_value = 0;
  int k = strlen(str);
  int multiplier = 31;
  int i;
  for(i = 0; i < k; i++) {
    hash_value = (hash_value * multiplier + str[i]) % TAILLE_HASHTABLE;
  }
  //printf( "\nhash_value: %d\n", hash_value);
  return hash_value;
}


/*************************************************************************
 * Add-Function: Add a word to the Hashtable.                            *
 *************************************************************************/
void ajout_mot(Liste *hashtable, unsigned char *mot) {
  int index = hash(mot);
  if(hashtable[index] == NULL) {
    //Key unused: create new entry
    hashtable[index] = (Liste) calloc(1, sizeof(*hashtable[index]));
    hashtable[index]->val = mot;
    //printf("\nNew entry: %s", hashtable[index]->val);
    hashtable[index]->suiv = NULL;
  } else {
    //Collision: add to list
    hashtable[index]  = ajout_tete(mot, hashtable[index]);
    //printf("\nAdded to list: %s", mot); 
  }
  //Count actual size of Hashtable
  //taille_table++;
}


/*************************************************************************
 * Create-Hash-Table-Function: Read in words and create table of lists.  *
 *************************************************************************/
Liste *creer_hashtable(char *f) {
  FILE *fichier = NULL;
  //Open a text file with path+name f
  fichier = fopen(f,"r+");
  //Error if file cannot be opened
  if(!fichier) {
    perror("Unable to open/read text file!");
    return NULL;
  }
  //Hashtable needs to have a static position in memory
  static Liste hashtable[TAILLE_HASHTABLE];
  //Keep track of how many elements we add
  //static int taille_table = 0;
  //Read text file
  char mot[MAX_TAILLE_MOT];
  while(fgets(mot, MAX_TAILLE_MOT + 1, fichier) != NULL) {
    if(mot[0] != '\n') {
      unsigned int vraie_longueur_mot = 0;
      unsigned int i = 0;
      while(mot[vraie_longueur_mot] != '\n') {
	vraie_longueur_mot++;
      }
      char cpymot[vraie_longueur_mot];
      for(i = 0; i < vraie_longueur_mot; i++) {
	cpymot[i] = mot[i];
      }
      ajout_mot(hashtable, cpymot);
    }
  }
  fclose(fichier);
  return hashtable;
}


/*************************************
 *Construction du graphe:
 *************************************/
//void construire_graphe() {
//}

/*************************************************************************
 * Find all neighbors with a distance of 1.                              *
 *************************************************************************/
Liste get_proche_voisins(unsigned char *mot, Liste *hashtable) {
  unsigned int i;
  unsigned char c;
  unsigned char voisin_mot[strlen(mot)];
  Liste head_of_collision_list = NULL;
  static Liste liste_voisins = NULL;
  for(i = 0; i < strlen(mot); i++) {
    for(c = 'a'; c <= 'z'; c++) {
      strcpy(voisin_mot, mot);
      voisin_mot[i] = c;
      head_of_collision_list = hashtable[hash(voisin_mot)];
      printf("\n%s", head_of_collision_list->val);
      if(head_of_collision_list) {
	if(recherche_liste(mot, head_of_collision_list)) {
	  puts("WE HERE?");
	  liste_voisins = ajout_tete(voisin_mot, liste_voisins);
	}
      }
    }
  }
  return liste_voisins;
}
