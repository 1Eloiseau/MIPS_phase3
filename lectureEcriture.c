#include "fonctions.h"

//la ligne, l'instruction ou le label est formatté : supprime les commentaires, espaces, tabulations
//ex : " 	ADD    $3  ,    $2,  $1 # commentaire  " devient "ADD $3,$2,$1" terminé par \0
//renvoie 0 si la ligne est une instruction, 1 si label(ligne renvoyé avec le ":"), -1 si vide/commentaire
int formatterLigne(char* ligne)
{
	int typeLigne = -1;
	char i_ligne[TAILLE_LIGNE];
	int i=0; //index ligne
	int j=0; //index i_ligne

	while (ligne[i] == ' ' || ligne[i] == '\t') {
		i++;
	}

	while (ligne[i] != '\n' && ligne[i] != '\0' && ligne[i] != '#' && ligne[i] != ':') {
		i_ligne[j] = i_ligne[i];
		i++;
		j++;
		if(ligne[i] == ':') {
			i_ligne[j] = ':';
			typeLigne = 1; //la ligne est un label
		}
		if(ligne[i] == ' ' || ligne[i] == '\t') {
			if(typeLigne == -1)
				i_ligne[j] = ' '; //on ajoute un espace après le nom d'instruction
			typeLigne = 0;
			while(ligne[i] == ' ' || ligne[i] == '\t') {
				i++;
			}
		}
	}
	i_ligne[j+1] = '\0';
	if(typeLigne != -1)
		ligne = i_ligne;
	
	return typeLigne;
}

//lit le fichier et enregistre chaque ligne dans le tableau de lignes
//renvoie le nombre de lignes lues
int lireFichier(FILE * fichier, char*** tabLignes) {
	int numLigne = 0;
	char i_ligne[TAILLE_LIGNE];
	char** i_tabLignes; //tabLignes interne/local

	while(fgets(i_ligne, TAILLE_LIGNE, fichier) != NULL) {
		i_tabLignes = (char**)realloc(i_tabLignes, (numLigne+1)*sizeof(char*)); //realloc pour ajouter une ligne
		i_tabLignes[numLigne] = (char*)malloc(100*sizeof(char)); //on alloue 100 char à la nouvelle ligne 
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