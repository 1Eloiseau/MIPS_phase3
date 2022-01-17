#ifndef __detraduction_h__
#define __detraduction_h__

#include "fonctions.h"

//renvoie le mot de 32 bits de l'adresse demandée
int lireMemoire(int adresse);

//écrit le mot demandé dans la mémoire de manière gros-boutiste
void ecrireMemoire(int adresse, int donnee);

#endif