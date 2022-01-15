#include "fonctions.h"

//l'instruction ou le label est formaté : supprime les commentaires, espaces, tabulations
//ex : " 	ADD    $3  ,    $2,  $1 # commentaire  " devient "ADD $3,$2,$1" terminé par \0
//renvoie 0 si la ligne est une instruction, 1 si label(ligne renvoyé avec le ":"), -1 si vide/commentaire (ligne n'est pas modifié dans ce cas)
int formaterLigne(char* ligne)
{
	int typeLigne = -1;
	char l_ligne[TAILLE_LIGNE];
	int i=0; //index ligne
	int j=0; //index l_ligne

	while (ligne[i] == ' ' || ligne[i] == '\t') {
		i++;
	}

	while (ligne[i] != '\r' && ligne[i] != '\n' && ligne[i] != '\0' && ligne[i] != '#' && ligne[i] != ':') {
		l_ligne[j] = ligne[i];
		//printf("i, j, l_l, l == %d - %d - %c - %c\n", i, j, l_ligne[i], ligne[j]);
		i++;
		j++;
		
		if(ligne[i] == ':') {
			l_ligne[j] = ':';
			typeLigne = 1; //la ligne est un label
			j++;
		}
		if(ligne[i] == ' ' || ligne[i] == '\t') {
			if(typeLigne == -1) {
				l_ligne[j] = ' '; //on ajoute un espace après le nom d'instruction
				j++;
			}
			typeLigne = 0;
			while(ligne[i] == ' ' || ligne[i] == '\t') {
				i++;
			}
		}
	}
	l_ligne[j] = '\0';
	if(typeLigne != -1)
		strcpy(ligne, l_ligne);

	return typeLigne;
}

//lit le fichier et enregistre chaque ligne dans le tableau de lignes
//renvoie le nombre de lignes lues
int lireFichier(FILE * fichier, char*** tabLignes) {
	int numLigne = 0;
	char l_ligne[TAILLE_LIGNE];
	char** l_tabLignes; //tabLignes interne/local

	while(fgets(l_ligne, TAILLE_LIGNE, fichier) != NULL) {
		l_tabLignes = (char**)realloc(l_tabLignes, (numLigne+1)*sizeof(char*)); //realloc pour ajouter une ligne
		l_tabLignes[numLigne] = (char*)malloc(100*sizeof(char)); //on alloue 100 char à la nouvelle ligne 
		strcpy(l_tabLignes[numLigne], l_ligne);
		numLigne++;
	}
	*tabLignes = l_tabLignes;

	return numLigne;
}

//ecrit une ligne dans le fichier (avec un /n)
void ecrireLigneFichier(FILE * fichier, char donnees[]) {

	fputs(donnees, fichier); //ajoute la chaine à la fin du fichier
	fputs("\n", fichier);
}