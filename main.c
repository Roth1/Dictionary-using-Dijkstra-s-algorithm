#include <stdio.h>
#include "functions.h"
#include "list.h"

int main() {
  Liste *hashtable = creer_hashtable("./mots/umot4.txt", tableSize);
  return 0;
}
