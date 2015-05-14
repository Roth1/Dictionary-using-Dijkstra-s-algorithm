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
Liste creer_liste(void);
int est_vide(Liste L);
Liste ajout_tete(unsigned char *e, unsigned int taille_mot, Liste L);
int recherche_liste(unsigned char *e, unsigned int longueur_mot, Liste L);
int taille_liste(Liste L);
unsigned char compare_mots(unsigned char *mot1, unsigned char *mot2, unsigned int taille_mot);

//Operations pour une Cout_Liste
Cout_Liste ajout_cout_tete(unsigned char *mot, unsigned int longueur_mot, unsigned int cout, Cout_Liste pere, Cout_Liste C_L);
unsigned int trouve_min_cout(Cout_Liste C_L);
Cout_Liste trouve_sommet_min_cout(Cout_Liste C_L);
Cout_Liste supprime_cout_sommet(unsigned int min_cout, Cout_Liste C_L);
Cout_Liste recherche_cout_liste(unsigned char *e, unsigned int longueur_mot, Cout_Liste C_L);

#endif
