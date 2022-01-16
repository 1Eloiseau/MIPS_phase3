#include "fonctions.h"

//rempli tabLabels (tabLabels.numInstruction est l'index en comptant les instructions et labels)
//renvoie le nombre de labels (= la taille de tabLabels)
int remplirTabLabels(FILE* fichier, structLabel** tabLabels) {
	int nbLabels = 0;
	int nbInstructions = 0;
	int typeLigne;
	char ligne[TAILLE_LIGNE];
	structLabel* l_tabLabels = *tabLabels;

	while(lireLigneFichier(fichier, ligne) != 1) {
		typeLigne = formaterLigne(ligne); //on récupère la ligne et son type
		if(typeLigne == 1) {
			l_tabLabels = (structLabel*) realloc(l_tabLabels, (nbLabels+1) * sizeof(structLabel));
			strcpy(l_tabLabels[nbLabels].label, ligne);
			l_tabLabels[nbLabels].numInstruction = (nbLabels + nbInstructions);
			printf("%d %s %d\n", nbLabels, l_tabLabels[nbLabels].label, l_tabLabels[nbLabels].numInstruction);
			nbLabels++;
		}
		if(typeLigne == 0)
			nbInstructions++;
	}
	*tabLabels = l_tabLabels;
	return (nbLabels);
}

//l'instruction ou le label est formaté : supprime les commentaires, espaces, tabulations
//ex : " 	ADD    $3  ,    $2,  $1 # commentaire  " devient "ADD $3,$2,$1" terminé par \0
//renvoie 0 si la ligne est une instruction, 1 si label(renvoyé sans le ":"), -1 si vide/commentaire (ligne n'est pas modifié dans ce cas)
int formaterLigne(char* ligne)
{
	int typeLigne = -1;
	char l_ligne[TAILLE_LIGNE];
	int i=0; //index ligne
	int j=0; //index l_ligne
	bool espace;

	while (ligne[i] == ' ' || ligne[i] == '\t') {
		i++;
	}

	while (ligne[i] != '\r' && ligne[i] != '\n' && ligne[i] != '\0' && ligne[i] != '#' && ligne[i] != ':') {
		l_ligne[j] = ligne[i];
		//printf("i, j, l_l, l == %d - %d - %c - %c\n", i, j, l_ligne[i], ligne[j]);
		i++;
		j++;
		typeLigne = 0;
		
		if(ligne[i] == ' ' || ligne[i] == '\t') {
			if(espace == 0) {
				l_ligne[j] = ' '; //on ajoute un espace après le nom d'instruction
				espace = 1;
				j++;
			}
			
			while(ligne[i] == ' ' || ligne[i] == '\t') {
				i++;
			}
		}
		if(ligne[i] == ':') {
			typeLigne = 1; //la ligne est un label
		}
	}
	if(l_ligne[j-1] == ' ')
		j--;
	l_ligne[j] = '\0';
	if(typeLigne != -1)
		strcpy(ligne, l_ligne);

	return typeLigne;
}

//lit la ligne actuelle (pointée par FILE*)
//renvoie 0 s'il y a une ligne, 1si on est à la fin du fichier
int lireLigneFichier(FILE * fichier, char* ligne) {
	char l_ligne[TAILLE_LIGNE];
	int etatLigne = 1;

	if(fgets(l_ligne, TAILLE_LIGNE, fichier) != NULL) {
		etatLigne = 0;
		strcpy(ligne, l_ligne);
	}
		
	return etatLigne;
}

//ecrit une ligne dans le fichier (avec un /n)
void ecrireLigneFichier(FILE * fichier, char donnees[]) {

	fputs(donnees, fichier); //ajoute la chaine à la fin du fichier
	fputs("\n", fichier);
}