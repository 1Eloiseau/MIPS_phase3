#ifndef __fonctions_h__
#define __fonctions_h__

#define TAILLE_LIGNE 100
#define PC 32
#define HI 33
#define LO 34

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

extern int tabRegistres[35]; //dans cet ordre : R0 - ... - R31 - PC - HI - LO
extern char tabMemoire[400]; //octets de mémoire gros-boutiste

typedef struct structLabel structLabel;
    struct structLabel{
        char label[100];
        int numInstruction; //numéro en comptant les instructions et les labels
    };




//int traduction_dec(char ligne[], int num_instruction, structLabel matrice_label[],char matrice_csv[26][10][15]);

#endif