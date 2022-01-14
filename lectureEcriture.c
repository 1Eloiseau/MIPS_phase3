#include "fonctions.h"

//lit la ligne du fichier sans \n
//retourne 1 si la ligne existe, 0 si elle est vide/commentaire, -1 sinon (fin du fichier)
int lireLigneFichier(FILE * fichier, char ligne[], int numeroLigne) {
	char i_ligne[TAILLE_LIGNE];
	int i = 0;
	int etatLigne = -1;
	int j = 0;
	int m = 0;
	int test = 0;

	if(fgets(i_ligne, TAILLE_LIGNE, fichier) != NULL) { 
		if(i == numeroLigne-1) {
			
			strcpy(ligne, i_ligne);
			while (i_ligne[j] == ' ') {
				j += 1;
			}
			while (i_ligne[m] != '\n' && i_ligne[m] != '\0' && i_ligne[m] != '#' && i_ligne[m] != ':') {
				m += 1;
			}
			if (i_ligne[j] == '#' || i_ligne[j] == '\n' || i_ligne[m] == ':' || i_ligne[j] == '\r' || i_ligne[j] == '\t') {
				etatLigne = 0;
			} else {
				etatLigne = 1;
			}
		}
		i += 1;
	}
	//suppression du \n éventuel
	if(etatLigne != -1) {
		if(ligne[strlen(ligne)-1] == '\n')
			ligne[strlen(ligne)-1] = 0;
	}
	return etatLigne;
}

//ecrit une ligne dans le fichier (gère le /n)
//va à la ligne si on le l'est pas déjà
void ecrireFichier(FILE * fichier, char donnees[]) {

/*
	char caractere = '\n';
    //vérifie si on est à la ligne
    while (!feof(fichier)) {
        fscanf(fichier, "%c", &caractere);
    }
	printf("%c\n", caractere);
    //va à la ligne si on ne l'était pas
    if(caractere != '\n') {
        fputs("\n", fichier);
		printf("OUI\n");
    }
*/
	fputs(donnees, fichier); //ajoute la chaine à la fin du fichier
	fputs("\n", fichier);
}