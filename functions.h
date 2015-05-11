#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>
#include "liste.h"

#define TAILLE_HASHTABLE 1000
#define MAX_TAILLE_MOT 25

typedef struct sommet_cout {
  unsigned int cout;
  unsigned short visited;
  sommet_cout *suiv;
} sommet_cout;

//Hash-Function
int hash(unsigned char *str);

//Add an element to the hashtable
void ajout_mot(unsigned char *mot, unsigned int taille_mot, Liste *hashtable);

//Create a Hashtable
Liste *creer_hashtable(char *f);

//Find close neighbors
Liste get_proche_voisins(unsigned char *mot, Liste *hashtable);

//Dijkstra's algorithm
Liste get_court_chemin(unsigned char *mot_debut, unsigned char *mot_fin);


#endif
