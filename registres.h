#ifndef __registres_h__
#define __registres_h__
#include "fonctions.h"

//écrit var dans le registre demandé
void ecrire_registre(int registres[], int num_registre, int var);

//retourne le registre passé en paramètre
int lireRegistre(int num_registre);

#endif