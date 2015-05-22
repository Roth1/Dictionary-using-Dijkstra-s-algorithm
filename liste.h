#ifndef LISTE_H_
#define LISTE_H_

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

typedef struct cellule *Liste;
typedef struct cout_cellule *Cout_Liste;

//Operations pour une Liste
Liste ajout_tete(const unsigned char *mot, const unsigned int longueur_mot, Liste L);
int recherche_liste(const unsigned char *mot, const unsigned int longueur_mot, const Liste L);
int taille_liste(const Liste L);
unsigned char compare_mots(const unsigned char *mot1, const unsigned char *mot2, const unsigned int taille_mot);

//Operations pour une Cout_Liste
Cout_Liste ajout_cout_tete(const unsigned char *mot, const unsigned int longueur_mot, unsigned int cout, Cout_Liste pere, Cout_Liste C_L);
unsigned int trouve_min_cout(const Cout_Liste C_L);
Cout_Liste trouve_sommet_min_cout(const Cout_Liste C_L);
Cout_Liste supprime_cout_sommet(Cout_Liste k, Cout_Liste C_L);
Cout_Liste recherche_cout_liste(const unsigned char *mot, const unsigned int longueur_mot, const Cout_Liste C_L);


#endif
