#ifndef FONCTIONS_H_
#define FONCTIONS_H_

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>
#include "sommet.h"

#define TAILLE_HASHTABLE 1000
#define MAX_TAILLE_MOT 26


//fonction pour changer le chemin 
Sommet *change_chemin(Sommet *hashtable);

//fonction de hashage
int hash(const unsigned char *str);

//fonction pour ajouter un mot dans la table de hashage
void ajout_mot(const unsigned char *mot, const unsigned int longueur_mot, Sommet *hashtable);

//fonction pour créer une table de hashage
Sommet *creer_hashtable(const char *f);

//fonction pour la libération de la mémoire (table de hashage)
void free_hashtable(Sommet *hashtable);

//fonction pour la libération de la mémoire (table de hashage)
void free_cout_hashtable(Cout_Sommet *hashtable);

//fonction pour créer le graphe
Cout_Sommet *creer_graphe(const unsigned int longueur_mot, const Sommet *hashtable);

//fonction pour la libération de la mémoire (liste de sommets)
void free_liste(Sommet liste);

//fonction pour la libération de la mémoire (liste de cout-sommets)
void free_cout_liste(Cout_Sommet cout_liste);

//fonction pour trouver les voisins à distance 1
Sommet get_proche_voisins(const unsigned char *mot, const Sommet *hashtable);

//fonction qui trouve le plus court chemin en utilisant Dijkstra's algorithm
void get_court_chemin(const unsigned char *mot_depart, const unsigned char *mot_cible, const Sommet *hashtable);

//fontion pour lire les mots et trouver le chemin en utilisant get_proche_voisins()
void trouve_chemin(const Sommet *hashtable);


#endif
