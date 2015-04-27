#ifndef LISTE_H_
#define LISTE_H_

#include <stdio.h>
#include <stdlib.h>

struct cellule {
  ELEMENT val;
  struct cellule* suiv;
};

typedef struct cellule* Liste;

Liste creer_liste(void);
int est_vide(Liste L);
Liste ajout_tete(ELEMENT e, LISTE L);
Liste rech_chaine(char* chaine, Liste L);
Liste rech(ELEMENT e, Liste L);
int taille_liste(Liste L);

#endif
