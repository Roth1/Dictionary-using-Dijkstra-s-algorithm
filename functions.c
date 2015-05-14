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
void ajout_mot(unsigned char *mot, unsigned int taille_mot, Liste *hashtable) {
  int index = hash(mot);
  if(hashtable[index] == NULL) {
    //Key unused: create new entry
    hashtable[index] = ajout_tete(mot, taille_mot, NULL);
  } else {
    //Collision: add to list
    hashtable[index]  = ajout_tete(mot, taille_mot, hashtable[index]);
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
      ajout_mot(cpymot, vraie_longueur_mot, hashtable);
    }
  }
  fclose(fichier);
  return hashtable;
}


/*************************************************************************
 * Find all neighbors with a distance of 1.                              *
 *************************************************************************/
Liste get_proche_voisins(unsigned char *mot, Liste *hashtable) {
  unsigned int i;
  unsigned char c;
  unsigned int longueur_mot = strlen(mot);
  unsigned char voisin_mot[longueur_mot];
  Liste head_of_collision_list = NULL;
  static Liste liste_voisins = NULL;
  for(i = 0; i < longueur_mot; i++) {
    for(c = 'a'; c <= 'z'; c++) {
      strcpy(voisin_mot, mot);
      voisin_mot[i] = c;
      head_of_collision_list = hashtable[hash(voisin_mot)];
      //printf("\n%s", head_of_collision_list->val);
      if(head_of_collision_list && !compare_mots(mot, voisin_mot, longueur_mot)) {
	if(recherche_liste(voisin_mot, longueur_mot, head_of_collision_list)) {
	  liste_voisins = ajout_tete(voisin_mot, longueur_mot, liste_voisins);
	}
      }
    }
  }
  return liste_voisins;
}


/*************************************************************************
 * Find closest path between two words using Dijkstra's algorithm        *
 *************************************************************************/
Cout_Liste get_court_chemin(unsigned char *mot_debut, unsigned char *mot_fin, Liste *hashtable) {
  if(strlen(mot_debut) != strlen(mot_fin)) {
    return NULL;
  }
  unsigned int longueur_mot = strlen(mot_debut);
  Cout_Liste chemin_liste = NULL;
  Cout_Liste graphe_liste = NULL;
  Liste p = NULL;
  unsigned int i = 0;
  for(i = 0; i < 1000; i++) {
    if( hashtable[i] != NULL) {
      for(p = hashtable[i]; p != NULL; p = p->suiv) {
	if(longueur_mot == strlen(p->val)) {
	  if(compare_mots(mot_debut, p->val, longueur_mot)) {
	    graphe_liste = ajout_cout_tete(p->val, longueur_mot, 0, NULL, graphe_liste);
	  } else {
	    graphe_liste = ajout_cout_tete(p->val, longueur_mot, INT_MAX, NULL, graphe_liste);
	  }
	}
      }
    }
  }
  Cout_Liste j = NULL;
  do {
    j = trouve_sommet_min_cout(graphe_liste);
    Liste k = NULL;
    Liste dist1 = get_proche_voisins(j->val, hashtable);
    chemin_liste = ajout_cout_tete(j->val, longueur_mot, j->cout, j->pere, chemin_liste);
    graphe_liste = supprime_cout_sommet(j, graphe_liste);
    for(k = dist1; k != NULL; k = k->suiv) {
      if(k->cout > (j->cout + 1)) {
	k->cout = j->cout + 1;
	k->pere = j;
      }
    }
  } while(recherche_cout_liste(mot_fin, longueur_mot, graphe_liste) && (j->cout != INT_MAX));
  return chemin_liste;
}
    
    
