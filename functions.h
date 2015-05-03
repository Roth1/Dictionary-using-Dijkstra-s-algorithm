#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>
#include "list.h"

#define tableSize 1000

//Global variables (need to be redefined in *.c files)
extern unsigned int taille_table;

//Hash-Function
<<<<<<< HEAD
int hash(unsigned char* str, int N);

//Add an element to the hashtable
void ajout_mot(Liste* hashtable, unsigned char* mot);

=======
int hash(unsigned char *str, int N);
>>>>>>> 48ecd2240429c8173cf6c0f470f2beea53bd158c
//Create a Hashtable
Liste* creer_hashtable(char *f);


#endif
