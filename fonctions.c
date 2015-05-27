#include "fonctions.h"


/****************************************************************************************
 * fonction pour changer le chemin - donne le nouveau chemin                            *
 ****************************************************************************************/
Sommet *change_chemin(void) {
  //nettoyer l'entrée
  fflush(stdin);
  //l'entrée (maximale)
  char nouveau_chemin[30];
  //lire le nouveau chemin
  if(fgets(nouveau_chemin, 30, stdin) == NULL) {
    perror("Erreur");
    return NULL;
  }
  unsigned int i = 0;
  for(i = 0; i < 30; i++) {
    //determiner la taille réelle du string
    if(nouveau_chemin[i] == '\n') {
      nouveau_chemin[i] = '\0';
      break;
    }
  }
  //i+1 est égal à la taille du string (chemin)
  char chemin[i+1];
  unsigned int j = 0;
  for(j = 0; j < i+1; j++) {
    chemin[j] = nouveau_chemin[j];
  }
  //vérifier si le chemin est bon
  if(chemin == NULL) {
    puts("-> Impossible de créer une table de hashage!\n");
    return NULL;
  }
  if(creer_hashtable(chemin) == NULL) {
    puts("-> Impossible de créer une table de hashage!\n");
    return NULL;
  } else {
    //créer la table de hashage
    return creer_hashtable(chemin);  
  }
}


/****************************************************************************************
 * fonction de hashage - donne la valeur de hashage                                     *
 * @param - str:  le mot pour lequel on crée une valeur de hashage                      *
 ****************************************************************************************/
int hash(const unsigned char *str) {
  int hash_value = 0;
  int k = strlen(str);
  int multiplier = 31;
  int i;
  for(i = 0; i < k; i++) {
    hash_value = (hash_value * multiplier + str[i]) % TAILLE_HASHTABLE;
  }
  return hash_value;
}


/****************************************************************************************
 * fonction pour ajouter un mot dans la table de hashage                                *
 * @param - mot: le mot à ajouter                                                       *
 * @param - longueur_mot: le longueur du mot à ajouter                                  *
 * @param - hashtable: la table de hashage crée, dans laquelle on ajoute le mot         *
 ****************************************************************************************/
void ajout_mot(const unsigned char *mot, const unsigned int taille_mot, Sommet *hashtable) {
  int index = hash(mot);
  if(hashtable[index] == NULL) {
    //clé pas encore utilisé: crée une nouvelle entrée
    hashtable[index] = ajout_tete(mot, taille_mot, NULL);
  } else {
    //collision -> ajoute le sommet à la liste
    hashtable[index]  = ajout_tete(mot, taille_mot, hashtable[index]);
  }
}


/****************************************************************************************
 * fonction de crèation d'une table de hashage - donne la tete du tableau               *
 * @param - f: le chemin d'un fichier *.txt avec les mots                               *
 ****************************************************************************************/
Sommet *creer_hashtable(const char *f) {
  FILE *fichier = NULL;
  //ouvre un fichier *.txt avec chemin + nom
  fichier = fopen(f,"r+");
  //Erreur
  if(!fichier) {
    perror("Impossible de lire/ouvrir le fichier");
    return NULL;
  }
  //table de hashage va avoir une position statique/constante dans la mémoire
  static Sommet hashtable[TAILLE_HASHTABLE];
  //lit le fichier *.txt
  char mot[MAX_TAILLE_MOT];
  while(fgets(mot, MAX_TAILLE_MOT + 1, fichier) != NULL) {
    //seulement ajoute des vrais mots avec leurs vrais longueurs
    if(mot[0] != '\n') {
      unsigned int vraie_longueur_mot = 0;
      unsigned int i = 0;
      while(mot[vraie_longueur_mot] != '\n') {
	vraie_longueur_mot++;
      }
      char cpymot[vraie_longueur_mot];
      for(i = 0; i < vraie_longueur_mot; i++) {
	cpymot[i] = mot[i];
      }
      //ajoute le mot dans la table de hashage (comme sommet)
      ajout_mot(cpymot, vraie_longueur_mot, hashtable);
    }
  }
  //ferme le fichier
  fclose(fichier);
  //retourne la table de hashage
  return hashtable;
}


/****************************************************************************************
 * fonction pour la libération de la mémoire (table de hashage)                         *
 * @param - hashtable: la table de hashage créée                                        *
 ****************************************************************************************/
void free_hashtable(Sommet *hashtable) {
  Sommet p = NULL;
  unsigned int i = 0;
  for(i = 0; i < 1000; i++) {
    if(hashtable[i] != NULL) {
      p = hashtable[i];
      //free() toute la liste de collision
      while(hashtable[i]->suiv != NULL) {
	hashtable[i] = hashtable[i]->suiv;
        free(p->val);
	free(p);
	p = hashtable[i];
      }
      free(hashtable[i]->val);
      free(hashtable[i]);
    }
  }
}


/****************************************************************************************
 * fonction pour la libération de la mémoire (table de hashage - cout)                  *
 * @param - hashtable: la table de hashage (avec cout)  créée                           *
 ****************************************************************************************/
void free_cout_hashtable(Cout_Sommet *hashtable) {
  Cout_Sommet p = NULL;
  unsigned int i = 0;
  for(i = 0; i < 1000; i++) {
    if(hashtable[i] != NULL) {
      p = hashtable[i];
      //free() toute la liste de collision
      while(hashtable[i]->suiv != NULL) {
	hashtable[i] = hashtable[i]->suiv;
        free(p->val);
	free(p);
	p = hashtable[i];
      }
      free(hashtable[i]->val);
      free(hashtable[i]);
    }
  }
}


/****************************************************************************************
 * fonction pour la libération de la mémoire (liste des éléments du type Cout_Sommet)   *
 * @param - graphe_liste: une cout-liste                                                *
 ****************************************************************************************/
void free_cout_liste(Cout_Sommet cout_liste) {
  Cout_Sommet p = cout_liste;
  while(cout_liste->suiv != NULL) {
    cout_liste = cout_liste->suiv;
    free(p->val);
    free(p);
    p = cout_liste;
  }
  free(cout_liste->val);
  free(cout_liste);
}
    

/****************************************************************************************
 * fonction qui trouve tous les proches voisins à distance 1 - les donne comme liste    *
 * @param - mot: le mot pour lequel on cherche les proches voisins                      *
 * @param - hashtable: la table de hashage crée                                         *
 ****************************************************************************************/
Sommet get_proche_voisins(const unsigned char *mot, const Sommet *hashtable) {
  unsigned int i;
  unsigned char c;
  unsigned int longueur_mot = strlen(mot);
  unsigned char voisin_mot[longueur_mot];
  Sommet head_of_collision_list = NULL;
  Sommet liste_voisins = NULL;
  //change lettre après lettre
  for(i = 0; i < longueur_mot; i++) {
    //change de 'a' à 'z'
    for(c = 'a'; c <= 'z'; c++) {
      strcpy(voisin_mot, mot);
      voisin_mot[i] = c;
      //collision dans la table de hashage
      head_of_collision_list = hashtable[hash(voisin_mot)];
      //le mot de départ n'est pas un proche voisin
      if(head_of_collision_list && !compare_mots(mot, voisin_mot, longueur_mot)) {
	//trouve le voisin dans la liste
	if(recherche_liste(voisin_mot, longueur_mot, head_of_collision_list)) {
	  //ajoute le voisin à une liste de sommets
	  liste_voisins = ajout_tete(voisin_mot, longueur_mot, liste_voisins);
	}
      }
    }
  }
  return liste_voisins;
}


/****************************************************************************************
 * fonction pour trouver le plus court chemin en utilisant l'algorithme de Dijkstra     *
 * @param - mot_depart: le mot de départ                                                *
 * @param - mot_cible: le mot cible                                                     *
 * @param - hashtable: la table de hashage crée                                         *
 ****************************************************************************************/
void get_court_chemin(const unsigned char *mot_depart, const unsigned char *mot_cible, const Sommet *hashtable) {
  //traitement des cas spéciaux
  if(strlen(mot_depart) != strlen(mot_cible)) {
    puts("\n\nLes mots que vous avez entré n'ont pas le meme longueur et par conséquence ne sont pas compatibles!\n");
    puts("\nPoussez RETURN pour rentrer dans le menu.\n");
    return;
  }
  unsigned int longueur_mot = strlen(mot_depart);
  if(compare_mots(mot_depart, mot_cible, longueur_mot)) {
    puts("\n\nVous avez entré deux fois le meme mot! La distance est égale à 0.\n");
    puts("\nPoussez RETURN pour rentrer dans le menu.\n");
    return;
  }
  unsigned int index_depart = hash(mot_depart);
  if(!recherche_liste(mot_depart, longueur_mot, hashtable[index_depart])) {
      puts("\n\nLe mot de départ que vous avez entré n'est pas dans le fichier *.txt!\n");
      puts("\nPoussez RETURN pour rentrer dans le menu.\n");
      return;
  }
  if(!recherche_liste(mot_cible, longueur_mot, hashtable[hash(mot_cible)])) {
    puts("\n\nLe mot cible que vous avez entré n'est pas dans le fichier *.txt!\n");
    puts("\nPoussez RETURN pour rentrer dans le menu.\n");
    return;
  }
  //la liste qui va comporter les sommets traités
  Cout_Sommet chemin_liste = NULL;
  //deuxième table de hashage qui sert comme graphe
  Cout_Sommet graphe_hashtable[TAILLE_HASHTABLE];
  //création du graphe
  Sommet p = NULL;
  unsigned int i = 0;
  for(i = 0; i < 1000; i++) {
    if(hashtable[i] != NULL) {
      //important s'il n'y a pas de mot du meme longueur dans une liste de sommets
      graphe_hashtable[i] = NULL;
      for(p = hashtable[i]; p != NULL; p = p->suiv) {
	//on veut que des mots du meme longueur
	if(longueur_mot == strlen(p->val)) {
	    graphe_hashtable[i] = ajout_cout_tete(p->val, longueur_mot, INT_MAX, NULL, graphe_hashtable[i]);
	}
      }
    }
  }
  //trouve le cout-sommet du mot de départ et donne lui un cout de 0
  Cout_Sommet j = recherche_cout_liste(mot_depart, longueur_mot, graphe_hashtable[index_depart]);
  j->cout = 0;
  //le cout-sommet de notre mot cible
  Cout_Sommet but = NULL;
  //entre la boucle de l'algorithme
  do {
    i = 0;
    //prend un sommet comme référence
    if(graphe_hashtable[0] == NULL) {
      while(graphe_hashtable[i] == NULL) {
	i++;
      }
    }
    Cout_Sommet min_sommet = graphe_hashtable[i];
    //trouve le sommet avec le cout minimal
    for(i; i < TAILLE_HASHTABLE; i++) {
      if(graphe_hashtable[i] != NULL) {
	Cout_Sommet g = trouve_sommet_min_cout(min_sommet->cout, graphe_hashtable[i]);
	if(g != NULL && g->cout < min_sommet->cout) {
	  min_sommet = g;
	}
      }
    }
    //j est le sommet de cout minimal
    j = min_sommet;
    //k et l sont utilisé pour itérer vers les listes
    Cout_Sommet k = NULL;
    Sommet l = NULL;
    //crée une liste des proches voisins
    Sommet distance_1 = get_proche_voisins(j->val, hashtable);
    //ajoute j dans la liste des cout-sommets traités
    chemin_liste = ajout_cout_tete(j->val, longueur_mot, j->cout, j->pere, chemin_liste);
    //supprime j du graphe
    unsigned int index = hash(j->val);
    graphe_hashtable[index] = supprime_cout_sommet(j, graphe_hashtable[index]);
    //pour chaque proche voisin
    for(l = distance_1; l != NULL; l = l->suiv) {
      //trouve le cout-sommet correspondant au sommet du proche voisin dans le graphe
      k = recherche_cout_liste(l->val, longueur_mot, graphe_hashtable[hash(l->val)]);
      //k est encore dans le graphe
      if(k != NULL) {
	//si le cout est supérieur au cout de passer par j
	//j se trouve à la tête de chemin-liste, donc il ne faut pas le chercher
	if(k->cout > (chemin_liste->cout + 1)) {
	  //incremente le cout et enregistre le père
	  k->cout = chemin_liste->cout + 1;
	  k->pere = chemin_liste;
	}
      }
    }
    //si but == NULL on n'a pas encore traité le mot cible
    but = recherche_cout_liste(mot_cible, longueur_mot, chemin_liste);
  } while((but == NULL) && (j->cout != INT_MAX));
  if(but == NULL) {
    //il n'y a pas de chemin entre les deux mots
    puts("\n\nIl n'y a pas de chemin dans le dictionnaire entre vos deux mots!");
    return;
  }
  Cout_Sommet l = but;
  //montre le résultat
  while(l != NULL) {
    printf("\t%s\t%d\n", l->val, l->cout);
    l=l->pere;
    }
  //libère la mémoire
  free_cout_hashtable(graphe_hashtable);
  free_cout_liste(chemin_liste);
  puts("\n\nPoussez RETURN pour rentrer dans le menu.\n");
  return;
}


/****************************************************************************************
 * fontion pour lire les mots et trouver le chemin en utilisant get_proche_voisins()    *
 * @param - hashtable: la table de hashage crée                                         *
 ****************************************************************************************/
void trouve_chemin(const Sommet *hashtable) {
  char mot_d[MAX_TAILLE_MOT+1];
  char mot_c[MAX_TAILLE_MOT+1];
  //nettoyer l'entrée
  fflush(stdin);
  puts("\nEntrez votre mot de départ:\t");
  if(fgets(mot_d, MAX_TAILLE_MOT+1, stdin) == NULL) {
    perror("\nErreur");
    return;
  }
  //nettoyer l'entrée
  fflush(stdin);
  puts("\nEntrez votre mot cible:\t");
  if(fgets(mot_c, MAX_TAILLE_MOT+1, stdin) == NULL) {
    perror("\nErreur");
    return;
  }
  //trouver le vrai longueur
  unsigned int i = 0;
  for(i = 0; i < MAX_TAILLE_MOT+1; i++) {
    if(mot_d[i] == '\n') {
      mot_d[i] = '\0';
      break;
    }
  }
  char mot_depart[i+1];
  strcpy(mot_depart, mot_d);
  //trouver le vrai longueur
  unsigned int k = 0;
  for(k = 0; k < MAX_TAILLE_MOT+1; k++) {
    if(mot_c[k] == '\n') {
      mot_c[k] = '\0';
      break;
    }
  }
  char mot_cible[k+1];
  strcpy(mot_cible, mot_c);
  puts("\n\n");
  //trouve le plus court chemin entre les deux mots
  get_court_chemin(mot_depart, mot_cible, hashtable);
}

