#include "liste.h"

Liste creer_liste(void) { 
  return NULL;
}

int est_vide(Liste L) {
  return !L;
}

/*************************************************************************
 * Add-To-List-Function: Adds an element to the head of a list.          *
 *************************************************************************/
Liste ajout_tete(unsigned char *e, unsigned int taille_mot, Liste L) {
  unsigned int i = 0;
  Liste p = (Liste)calloc(1, sizeof(*p));
  if(p == NULL) {
    return NULL;
  }
  p->val = (unsigned char *)calloc(taille_mot, sizeof(unsigned char));
  for(i = 0; i < taille_mot; i++) {
    p->val[i] = e[i];
  }
  p->suiv = L;
  return p;
}


/*************************************************************************
 * Search-List-Function: Iterates through a list looking for a word.     *
 *************************************************************************/
int recherche_liste(unsigned char *e, unsigned int longueur_mot, Liste L) {
  Liste p = L;
  while(p != NULL) {
    //TEST IF SAME SIZE
    if(compare_mots(e, p->val, longueur_mot)) {
      return 1;
    }
    p = p->suiv;
  }
  return 0;
}


/*************************************************************************
 * Get-List-Size-Function: Returns the size of a list.                   *
 *************************************************************************/
int taille_liste(Liste L) {
  unsigned int i = 0;
  while(!est_vide(L)) {
    L = L->suiv;
    ++i;
  }
  return i;
}


unsigned short compare_mots(unsigned char *mot1, unsigned char *mot2, unsigned int taille_mot) {
  unsigned int i = 0;
  for(i = 0; i < taille_mot; i++) {
      if(mot1[i] != mot2[i]) {
	return 0;
      }
  }
  return 1;
}
   
