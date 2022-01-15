#ifndef __fonctions_h__
#define __fonctions_h__

#define TAILLE_LIGNE 100

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//PENSER A DECRIRE LES FONCTIONS ICI AVANT LE RENDU

int lireFichier(FILE * fichier, char*** tabLignes);

void ecrireLigneFichier(FILE * fichier, char donnees[]);

void intEnChar(int instruction, char ligneHexa[]);

int traduction_dec(char ligne[], FILE * fichier_source, int numero_ligne);

#endif