#include "registres.h"

void ecrire_registre(int registres[], int num_registre, int var) {
    int var_temp;

    if (num_registre != 0) {
        var_temp = var & 4294967296;  /*4294967296 = 2^32 - 1; le but est de faire en sorte que var ne dépasse pas 32 bits.*/
        registres[num_registre] = var;
    }
}

int lire_registre(int num_registre) {
    return (tabRegistres[num_registre]);
}
