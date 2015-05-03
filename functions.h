#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>
#include "list.h"

#define tableSize 1000

//Global variables (need to be redefined in *.c files)
extern int taille_table;

//Hash-Function
int hash(unsigned char* str);

//Add an element to the hashtable
void ajout_mot(Liste* hashtable, unsigned char* mot);

//Create a Hashtable
Liste* creer_hashtable(char *f);


#endif
