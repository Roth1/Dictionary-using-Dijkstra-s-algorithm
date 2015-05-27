#include "sommet.h"


/***************************************************************************************************************
 * fonction pour ajouter un élément du type Sommet à la tête d'une liste de sommets                            *
 * @param - mot: le mot à ajouter                                                                              *
 * @param - longueur_mot: le longueur du mot à ajouter                                                         *
 * @param - L: la tête de la liste de sommets                                                                  *
 ***************************************************************************************************************/
Sommet ajout_tete(const unsigned char *mot, const unsigned int taille_mot, Sommet L) {
  unsigned int i = 0;
  Sommet p = (Sommet)calloc(1, sizeof(*p));
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


/***************************************************************************************************************
 * fonction pour la recherche d'un mot dans une liste de sommets - retourne 1 (true) ou 0 (false)              *
 * @param - mot: le mot à rechercher                                                                           *
 * @param - longueur_mot: le longueur du mot à rechercher                                                      *
 * @param - L: la tête de la liste de sommets                                                                  *
 ***************************************************************************************************************/
int recherche_liste(const unsigned char *mot, const unsigned int longueur_mot, const Sommet L) {
  Sommet p = L;
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


/***************************************************************************************************************
 * fonction pour comparer deux mots - retourne 1 (true) ou 0 (false)                                           *
 * @param - mot1: le premier mot                                                                               *
 * @param - mot2: le deuxième mot                                                                              *
 * @param - longueur_mot: le longueur du mot à ajouter                                                         *
 ***************************************************************************************************************/
unsigned char compare_mots(const unsigned char *mot1, const unsigned char *mot2, const unsigned int taille_mot) {
  unsigned int i = 0;
  for(i = 0; i < taille_mot; i++) {
      if(mot1[i] != mot2[i]) {
	return 0;
      }
  }
  return 1;
}


/***************************************************************************************************************
 * fonction pour ajouter un élément du type Cout_Sommet à la tête d'une liste de cout-sommets                  *
 * @param - mot: le mot à ajouter                                                                              *
 * @param - longueur_mot: le longueur du mot à ajouter                                                         *
 * @param - cout: le cout à ajouter                                                                            *
 * @param - pere: le père à ajouter                                                                            *
 * @param - C_L: la tête de la liste cout-sommet                                                               *
 ***************************************************************************************************************/
Cout_Sommet ajout_cout_tete(const unsigned char *mot, const unsigned int longueur_mot, unsigned int cout, Cout_Sommet pere, Cout_Sommet C_L) {
  unsigned int i = 0;
  Cout_Sommet j = (Cout_Sommet)calloc(1, sizeof(*j));
  //si l'allocation ne marche pas
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


/***************************************************************************************************************
 * fonction pour trouver un cout-sommet d'un cout minimal dans une liste de cout-sommets - donne le cout-somme *
 * @param - min_cout: le cout minimal en ce moment                                                             *
 * @param - C_L: la tête de la liste cout-sommet                                                               *
 ***************************************************************************************************************/
Cout_Sommet trouve_sommet_min_cout(unsigned int min_cout, const Cout_Sommet C_L) {
  //j pour itérer la liste, k pour avoir le cout-sommet de cout minimal
  Cout_Sommet j = C_L;
  Cout_Sommet k = NULL;
  while(j != NULL) {
    if(j->cout < min_cout) {
      min_cout = j->cout;
      k = j;
    }
    j = j->suiv;
  }
  return k;
}


/***************************************************************************************************************
 * fonction pour supprimer un cout-sommet d'une liste de cout-sommets - donne la tête de la liste cout-sommet  *
 * @param - mot: le sommet à supprimer                                                                         *
 * @param - C_L: la tête de la liste cout-sommet                                                               *
 ***************************************************************************************************************/
Cout_Sommet supprime_cout_sommet(Cout_Sommet j, Cout_Sommet C_L) {
  Cout_Sommet g = C_L;
  //il y a rien à supprimer
  if(g == NULL) {
    return NULL;
  }
  //le cout-sommet à supprimer est la tête de la liste - si on a qu'un seul élément -> retourne NULL
  if(g == j) {
    g = g->suiv;
    free(j);
    return g;
  }
  //itérer la liste
  while(g->suiv != j && g != NULL) {
    g = g->suiv;
  }
  //l'élement n'est pas dans la liste -> impossible de le supprimer
  if(g == NULL) {
    return C_L;
  }
  //supprimer l'élément de la liste
  //si on est au dernier élément: cas spécial, car NULL n'a pas l'attribut "suiv"
  if(g->suiv->suiv == NULL) {
    free(j);
    g->suiv = NULL;
    return C_L;
  } else {
    Cout_Sommet l = g->suiv->suiv;
    free(j);
    g->suiv = l;
    return C_L;
  }
}


/***************************************************************************************************************
 * fonction pour la recherche d'un mot dans une liste de cout-sommets - donne le cout-sommet                   *
 * @param - mot: le mot à rechercher                                                                           *
 * @param - longueur_mot: le longueur du mot à rechercher                                                      *
 * @param - C_L: la tête de la liste de cout-sommets                                                           *
 ***************************************************************************************************************/
Cout_Sommet recherche_cout_liste(const unsigned char *mot, const unsigned int longueur_mot, const Cout_Sommet C_L) {
  Cout_Sommet j = C_L;
  while(j != NULL) {
    if((longueur_mot == strlen(j->val)) && compare_mots(mot, j->val, longueur_mot)) {
	return j;
    }
    j =j->suiv;
  }
  return j;
}
