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

//fonction pour changer le chemin
Liste *change_chemin(void);

//fonction de hashage
int hash(const unsigned char *str);

//fonction pour ajouter un mot dans la table de hashage
void ajout_mot(const unsigned char *mot, const unsigned int longueur_mot, Liste *hashtable);

//fonction pour créer une table de hashage
Liste *creer_hashtable(const char *f);

//fonction pour créer le graphe
Cout_Liste creer_graphe(const unsigned int longueur_mot, const Liste *hashtable);

//fonction pour trouver les voisins à distance 1
Liste get_proche_voisins(const unsigned char *mot, const Liste *hashtable);

//fonction qui trouve le plus court chemin en utilisant Dijkstra's algorithm
void get_court_chemin(const unsigned char *mot_depart, const unsigned char *mot_cible, const Liste *hashtable);

//fontion pour lire les mots et trouver le chemin en utilisant get_proche_voisins()
void trouve_chemin(const Liste *hashtable);

#endif
