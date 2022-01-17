#include "fonctions.h"


void ecrire_registre(int registres[], int num_registre, int var) {
    int var_temp;

    if (num_registre != 0) {
        var_temp = var & 4294967296;  /*4294967296 = 2^32 - 1; le but est de faire en sorte que var ne dépasse pas 32 bits.*/
        registres[num_registre] = var;
    }
}

int lireRegistre(int num_registre) {
    return (tabRegistres[num_registre]);
}

//renvoie le mot de 32 bits de l'adresse demandée
int lireMemoire(int adresse) {
    int donnee = 0;
    for(int i = 0; i<4; i++) {
        donnee = donnee << 8;
        donnee += tabMemoire[adresse+i];
    }
    return donnee;
}

//écrit le mot demandé dans la mémoire de manière gros-boutiste
void ecrireMemoire(int adresse, int donnee) {
    for (int i = 3; i >= 0; i--) {
        tabMemoire[adresse + i] = donnee;
        donnee = donnee >> 8;
    }
}