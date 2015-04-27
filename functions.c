#include "functions.h"

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

Liste* creer_hashtable(char *f) {
  Liste* hashtable = NULL;
  FILE* fichier = NULL;
  //Open a text file
  fichier = fopen(f,"r+");
  //Error if file cannot be opened
  if(!fichier) {
    puts("Unable to open/read text file!");
    return NULL;
  }
  //Read text file
  int c;
  char custom_string[5];
  char* word = custom_string;
  int taille_table = 1;
  while((c = fgetc(input_file)) != EOF) {
    for(i = 0; i < 5 && c != '\n'; i++) {
      //DO STUFF
    }
    //Collision
    if(hashtable[hash(word)]) {
      //Create List
      hashtable + hash(word)  = ajout_tete(word, (hashtable + hash(word)));
    }
    //Set size of Hashtable
    taille_table++;
  }
  fclose(fichier);
  
  return hashtable;
}



