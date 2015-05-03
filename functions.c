#include "functions.h"

int taille_table;

/* OLD HASH-FCT
int hash(unsigned char *str, int dimension_hashtable) {
  int k = strlen(str);
  int hash_value = 0;
  int muliplier = 31;
  int i;
  for(i = 0; i < k; i++ ) {
    hash_value = (hash_value * multiplier + tolower(str[i])) % dimension_hashtable;
  }
  return hash_value;
}
*/


/*************************************************************************
 * Hash-Function: Anagrams are guaranteed to create the same key.        *
 *************************************************************************/
int hash(unsigned char *str) {
  int hash_value = 0;
  int index = 0;
  unsigned int i;
  for(i = 0; i < strlen(str); i++) {
    hash_value = hash_value + (int)str[i];
  }
  index = hash_value % tableSize;
  return index;
}


/*************************************************************************
 * Add-Function: Add a word to the Hashtable.                            *
 *************************************************************************/
void ajout_mot( Liste *hashtable, unsigned char *mot) {
  int index = hash(mot);
  //Collision
  if(hashtable[index]) {
    //Create or add to list
    hashtable[index]  = ajout_tete('\0', hashtable[index]);
  } else {
    hashtable[index] = (Liste) calloc(1, sizeof(*hashtable[index]));
    hashtable[index]->val = '\0';
    hashtable[index]->suiv = NULL;
  }
  //Count actual size of Hashtable
  taille_table++;
}


/*************************************************************************
 * Create-Hash-Table-Function: Read in words and create table of lists.  *
 *************************************************************************/
Liste *creer_hashtable(char *f, int size) {
  taille_table = 0;
  Liste hashtable[size];
  FILE *fichier = NULL;
  //Open a text file
  fichier = fopen(f,"r+");
  //Error if file cannot be opened
  if(!fichier) {
    perror("Unable to open/read text file!");
    return NULL;
  }
  //Read text file
  char mot[4]; //Needs to be changed accordingly later on
  int longueur_mot = strlen(mot) - 1;
  while(fgets(mot, 4, fichier) != NULL) {
    if(mot[longueur_mot] < 32) {
      mot[longueur_mot] = '\0';
    }
    ajout_mot(hashtable, mot);
  }
  fclose(fichier);
  return hashtable;
}



