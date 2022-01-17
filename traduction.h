#include "fonctions.h"

//Retourne a puissance p. Utilisée pour la fonction juste en dessous.
int puissance(int a, int p);

//Transforme un int en chaine de caractère hexa (de 8 caractères)
void intEnChar(int instruction, char ligneHexa[]);

int traduction_dec(char ligne[], int num_instruction, structLabel matrice_label[], char matrice_csv[26][10][15], int nb_label);
