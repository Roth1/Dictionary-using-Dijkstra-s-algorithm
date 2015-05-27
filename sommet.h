#ifndef SOMMET_H_
#define SOMMET_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct cellule {
  unsigned char *val;
  struct cellule *suiv;
};

struct cout_cellule {
  unsigned char *val;
  unsigned int cout;
  struct cout_cellule *pere;
  struct cout_cellule *suiv;
};

typedef struct cellule *Sommet;
typedef struct cout_cellule *Cout_Sommet;

//fonction pour ajouter un élément du type Sommet à la tête d'une liste de sommets
Sommet ajout_tete(const unsigned char *mot, const unsigned int longueur_mot, Sommet L);

//fonction pour la recherche d'un mot dans une liste de sommets - retourne 1 (true) ou 0 (false)
int recherche_liste(const unsigned char *mot, const unsigned int longueur_mot, const Sommet L);

//fonction pour comparer deux mots - retourne 1 (true) ou 0 (false)
unsigned char compare_mots(const unsigned char *mot1, const unsigned char *mot2, const unsigned int taille_mot);

//fonction pour ajouter un élément du type Cout_Sommet à la tête d'une liste de cout-sommets
Cout_Sommet ajout_cout_tete(const unsigned char *mot, const unsigned int longueur_mot, unsigned int cout, Cout_Sommet pere, Cout_Sommet C_L);

//fonction pour trouver un cout-sommet d'un cout minimal dans une liste de cout-sommets - retourne le cout-sommet
Cout_Sommet trouve_sommet_min_cout(unsigned int min_cout, const Cout_Sommet C_L);

//fonction pour supprimer un cout-sommet d'une liste de cout-sommets - retourne la tête de la liste cout-sommet
Cout_Sommet supprime_cout_sommet(Cout_Sommet k, Cout_Sommet C_L);

//fonction pour la recherche d'un mot dans une liste de cout-sommets - retourne le cout-sommet
Cout_Sommet recherche_cout_liste(const unsigned char *mot, const unsigned int longueur_mot, const Cout_Sommet C_L);


#endif
