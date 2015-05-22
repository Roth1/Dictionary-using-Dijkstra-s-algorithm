#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>
#include "liste.h"

#define TAILLE_HASHTABLE 1000
#define MAX_TAILLE_MOT 26


//Hash-Function
int hash(const unsigned char *str);

//Add an element to the hashtable
void ajout_mot(const unsigned char *mot, const unsigned int longueur_mot, Liste *hashtable);

//Create a Hashtable
Liste *creer_hashtable(const char *f);

Cout_Liste creer_graphe(const unsigned int longueur_mot, const Liste *hashtable);

//Find close neighbors
Liste get_proche_voisins(const unsigned char *mot, const Liste *hashtable);
//Cout_Liste get_proche_voisins_cout(unsigned char *mot, Cout_Liste graphe_liste);

//Dijkstra's algorithm
void get_court_chemin(const unsigned char *mot_depart, const unsigned char *mot_cible, const Liste *hashtable);


#endif
