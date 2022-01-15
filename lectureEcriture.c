#include "fonctions.h"

//Renvoit l'instruction ou le label formatté : supprime commentaires
int formatterLigne()
{
	/*
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
	*/
}

//lit le fichier et enregistre chaque ligne dans le tableau
//renvoit le nombre de lignes lues
int lireFichier(FILE * fichier, char*** tabLignes) {
	int numLigne = 0;
	char i_ligne[TAILLE_LIGNE];
	char** i_tabLignes; //tabLignes interne/local

	while(fgets(i_ligne, TAILLE_LIGNE, fichier) != NULL) {
		i_tabLignes = (char**)realloc(i_tabLignes, (numLigne+1)*sizeof(char*));
		i_tabLignes[numLigne] = (char*)malloc(100*sizeof(char));
		strcpy(i_tabLignes[numLigne], i_ligne);
		numLigne++;
	}
	*tabLignes = i_tabLignes;

	return numLigne;
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