#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>
#include "list.h"

//Hash-Function
int hash(unsigned char *str, int N);
//Create a Hashtable
Liste* creer_hashtable(char *f);


#endif
