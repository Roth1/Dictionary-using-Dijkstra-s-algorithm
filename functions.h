#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>
#include "list.h"

#define TAILLE_HASHTABLE 1000
#define MAX_TAILLE_MOT 25

//Global variables (need to be redefined in *.c files)
extern Liste hashtable[TAILLE_HASHTABLE];
extern int taille_table;

//Hash-Function
int hash(unsigned char *str);

//Add an element to the hashtable
void ajout_mot(Liste *hashtable, unsigned char *mot);

//Create a Hashtable
void creer_hashtable(char *f, int size);


#endif
