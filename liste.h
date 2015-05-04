#ifndef LISTE_H_
#define LISTE_H_

#include <stdio.h>
#include <stdlib.h>

struct cellule {
  unsigned char  *val;
  struct cellule *suiv;
};

typedef struct cellule* Liste;

Liste creer_liste(void);
int est_vide(Liste L);
Liste ajout_tete(unsigned char *e, Liste L);
//Liste rech_chaine(char *chaine, Liste L);
//Liste rech(unsigned char *e, Liste L);
int recherche_liste(unsigned char *e, Liste L);
int taille_liste(Liste L);

#endif
