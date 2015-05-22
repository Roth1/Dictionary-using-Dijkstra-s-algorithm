#include "liste.h"

/****************************************************************************************
 *           *
 *************************************************************************/
Liste ajout_tete(const unsigned char *mot, const unsigned int taille_mot, Liste L) {
  unsigned int i = 0;
  Liste p = (Liste)calloc(1, sizeof(*p));
  if(p == NULL) {
    return NULL;
  }
  p->val = (unsigned char *)calloc(taille_mot, sizeof(unsigned char));
  for(i = 0; i < taille_mot; i++) {
    p->val[i] = mot[i];
  }
  p->suiv = L;
  return p;
}
/****************************************************************************************
 * Search-List-Function: Iterates through a list looking for a word.     *
 *************************************************************************/
int recherche_liste(const unsigned char *mot, const unsigned int longueur_mot, const Liste L) {
  Liste p = L;
  unsigned int longueur_mot_liste = 0;
  while(p != NULL) {
    longueur_mot_liste = strlen(p->val);
    if((longueur_mot == longueur_mot_liste) && compare_mots(mot, p->val, longueur_mot)) {
	return 1;
    }
    p = p->suiv;
  }
  return 0;
}


/****************************************************************************************
 * Get-List-Size-Function: Returns the size of a list.                   *
 *************************************************************************/
int taille_liste(const Liste L) {
  unsigned int i = 0;
  Liste p = L;
  while(p != NULL) {
    p = p->suiv;
    ++i;
  }
  return i;
}


unsigned char compare_mots(const unsigned char *mot1, const unsigned char *mot2, const unsigned int taille_mot) {
  unsigned int i = 0;
  for(i = 0; i < taille_mot; i++) {
      if(mot1[i] != mot2[i]) {
	return 0;
      }
  }
  return 1;
}


Cout_Liste ajout_cout_tete(const unsigned char *mot, const unsigned int longueur_mot, unsigned int cout, Cout_Liste pere, Cout_Liste C_L) {
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

unsigned int trouve_min_cout(const Cout_Liste C_L) {
  unsigned int min_cout = 0;
  Cout_Liste j = NULL;
  j = C_L;
  min_cout = j->cout;
  //j = j->suiv;
  while(j->suiv != NULL) {
    if(min_cout > j->cout) {
      min_cout = j->cout;
    }
    j = j->suiv;
  }
  //printf("MIN COUT !!! == %d\n", min_cout);
  return min_cout;
}

Cout_Liste trouve_sommet_min_cout(const Cout_Liste C_L) {
  unsigned int min_cout = trouve_min_cout(C_L);
  Cout_Liste j = C_L;
  while(j != NULL) {
    if(j->cout == min_cout) {
      //printf("MIN MOT !!! == %s\n", j->val);
      return j;
    }
    j = j->suiv;
  }
  puts("\n\nERROR: Liste incohérente!\n");
  return NULL;
}
   
Cout_Liste supprime_cout_sommet(Cout_Liste j, Cout_Liste C_L) {
  Cout_Liste g = C_L;
  if(g == NULL) {
    return NULL;
  }
  if((g->suiv == NULL)) {
    free(g);
    return NULL;
  }
  if(g == j) {
    g = g->suiv;
    free(j);
    return g;
  }
  while(g->suiv != j) {
    g = g->suiv;
  }
  if(g->suiv->suiv == NULL) {
    free(j);
    g->suiv = NULL;
    return C_L;
  } else {
    Cout_Liste l = g->suiv->suiv;
    free(j);
    g->suiv = l;
    return C_L;
  }
}


Cout_Liste recherche_cout_liste(const unsigned char *mot, const unsigned int longueur_mot, const Cout_Liste C_L) {
  Cout_Liste j = C_L;
  while(j != NULL) {
    if((longueur_mot == strlen(j->val)) && compare_mots(mot, j->val, longueur_mot)) {
	return j;
    }
    j =j->suiv;
  }
  return j;
}
