#ifndef __fonctions_h__
#define __fonctions_h__

#define TAILLE_LIGNE 100

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//lit la ligne du fichier (de numéro(commence à 1) passé en parametre), sans \n
//retourne 1 si la ligne existe, 0 si elle est vide/commentaire, -1 sinon (fin du fichier)
int lireligneFichier(FILE * fichier, char ligne[], int numeroLigne);

//ecrit une ligne à la suite du fichier (gère le /n)
//va à la ligne si on le l'est pas déjà
void ecrireFichier(FILE * fichier, char donnees[]);

//Transforme un int en chaine de caractère hexa (de 8 caractères)
void intEnChar(int instruction, char ligneHexa[]);

//Prend en entrée une ligne à traduire et retourne la valeur décimale de l'instruction.
int traduction_dec(char ligne[], FILE * fichier_source, int numero_ligne);

#endif