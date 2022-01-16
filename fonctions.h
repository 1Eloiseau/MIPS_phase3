#ifndef __fonctions_h__
#define __fonctions_h__

#define TAILLE_LIGNE 100

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct structLabel structLabel;
    struct structLabel{
        char label[100];
        int numInstruction; //numéro en comptant les instructions et les labels
    };

//PENSER A DECRIRE LES FONCTIONS ICI AVANT LE RENDU

int remplirTabLabels(FILE* fichier, structLabel* tabLablels);

void lecture_csv(char matrice[26][10][15]);

int formaterLigne(char* ligne);

int lireLigneFichier(FILE * fichier, char* ligne);

void ecrireLigneFichier(FILE * fichier, char donnees[]);

void intEnChar(int instruction, char ligneHexa[]);

//int traduction_dec(char ligne[], int num_instruction, structLabel matrice_label[],char matrice_csv[26][10][15]);

#endif