#include "fonctions.h"
extern int tabRegistres[35]; //dans cet ordre : R0 - ... - R31 - PC - HI - LO
extern char tabMemoire[1000]; //octets de mémoire gros-boutiste

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