#include "liste.h"

Liste creer_liste(void) { 
  return NULL;
}

int est_vide(Liste L) {
  return !L;
}

Liste ajout_tete(unsigned char *e, Liste L) {
  Liste p = (Liste) calloc(1, sizeof(*p));
  if(p == NULL) {
    return NULL;
  }
  p->val = e;
  p->suiv = L;
  return p;
}

/*
Liste rech_chaine(char *chaine, Liste L) {
  Liste p = L;
  while(!est_vide(p) && (chaine, compare_chaine(chaine, &(p->val)) != 0)) p = p->suiv;
  return p;
}


Liste rech(unsigned char *e, Liste L) {
  Liste p = L;
  while(!est_vide(p) && (compare(&(p->val), &e) != 0)) p = p->suiv;
  return p;
}
*/

int recherche_liste(unsigned char *e, Liste L) {
  Liste p = L;
  while(p != NULL) {
    printf("\n%s", p->val);
    if(p->val == e) {
      return 1;
    }
    p = p->suiv;
  }
  return 0;
}

int taille_liste(Liste L) {
  unsigned int i = 0;
  while(!est_vide(L)) {
    L = L->suiv;
    ++i;
  }
  return i;
}
