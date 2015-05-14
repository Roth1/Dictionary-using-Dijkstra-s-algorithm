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
  unsigned int longueur_mot_liste = 0;
  while(p != NULL) {
    longueur_mot_liste = strlen(p->val);
    if((longueur_mot == longueur_mot_liste) && compare_mots(e, p->val, longueur_mot)) {
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


unsigned char compare_mots(unsigned char *mot1, unsigned char *mot2, unsigned int taille_mot) {
  unsigned int i = 0;
  for(i = 0; i < taille_mot; i++) {
      if(mot1[i] != mot2[i]) {
	return 0;
      }
  }
  return 1;
}


Cout_Liste ajout_cout_tete(unsigned char *mot, unsigned int longueur_mot, unsigned int cout, Cout_Liste pere, Cout_Liste C_L) {
  unsigned int i = 0;
  Cout_Liste j = (Cout_Liste)calloc(1, sizeof(*j));
  if(j == NULL) {
    return NULL;
  }
  j->val = (unsigned char *)calloc(longueur_mot, sizeof(unsigned char));
  for(i = 0; i < longueur_mot; i++) {
    j->val[i] = mot[i];
  }
  j->cout = cout;
  j->pere = pere;
  j->suiv = C_L;
}

unsigned int trouve_min_cout(Cout_Liste C_L) {
  unsigned int min_cout = 0;
  Cout_Liste j = NULL;
  j = C_L;
  min_cout = j->cout;
  j = j->suiv;
  while(j->suiv != NULL) {
    if(min_cout > j->cout) {
      min_cout = j->cout;
    }
    j = j->suiv;
  }
  return min_cout;
}

Cout_Liste trouve_sommet_min_cout(Cout_Liste C_L) {
  unsigned int min_cout = trouve_min_cout(C_L);
  Cout_Liste j = C_L;
  while(j->cout != min_cout) {
    j = j->suiv;
  }
  return j;
}
   
Cout_Liste supprime_cout_sommet(unsigned int min_cout, Cout_Liste C_L) {
  Cout_Liste j = C_L;
  if(j == NULL) {
    return NULL;
  }
  if(j->suiv == NULL) {
    free(j);
    return NULL;
  }
  while((j->cout != min_cout) && j != NULL) {
    j = j->suiv;
  }
  if(j == NULL) puts("ERROR!");
  Cout_Liste k = j->suiv->suiv;
  free(j->suiv);
  j->suiv = k;
  return C_L;
}


Cout_Liste recherche_cout_liste(unsigned char *e, unsigned int longueur_mot, Cout_Liste C_L) {
  Cout_Liste j = C_L;
  while(j != NULL) {
    if((longueur_mot == strlen(j->val)) && compare_mots(e, j->val, longueur_mot)) {
	return j;
    }
    j =j->suiv;
  }
  return j;
}
