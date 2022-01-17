#include "fonctions.h"

//rempli tabLabels (tabLabels.numInstruction est l'index en comptant les instructions et labels)
//renvoie le nombre de labels (= la taille de tabLabels)
int remplirTabLabels(FILE* fichier, structLabel* l_tabLabels);

//l'instruction ou le label est formaté : supprime les commentaires, espaces, tabulations
//ex : " 	ADD    $3  ,    $2,  $1 # commentaire  " devient "ADD $3,$2,$1" terminé par \0
//renvoie 0 si la ligne est une instruction, 1 si label(renvoyé sans le ":"), -1 si vide/commentaire (ligne n'est pas modifié dans ce cas)
int formaterLigne(char* ligne);

//lit la ligne actuelle (pointée par FILE*)
//renvoie 0 s'il y a une ligne, 1si on est à la fin du fichier
int lireLigneFichier(FILE * fichier, char* ligne);

//ecrit une ligne dans le fichier (ajoute un /n)
void ecrireLigneFichier(FILE * fichier, char donnees[]);

/*Lis le fichier Valeurs.csv et mets l'ensemble de son contenu dans une matrice à 3 dimensions*/
void lecture_csv(char matrice[26][10][15]);

/*Testée et fonctionnelle*/
void lecture_csv2(char tableur[], char matrice[16][4][7]);

/*Testée et fonctionnelle*/
void lecture_csv_3(char tableur[], char matrice[10][7][7]);

//écrit dans le fichier les valeurs des registres en décimal
void ecrireFichierState(char nomFichier[]);

//affiche les registres sur le terminal
void afficherRegistres();

//affiche la mémoire sur le terminal
void afficherMemoire();