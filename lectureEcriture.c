#include "fonctions.h"


//rempli tabLabels (tabLabels.numInstruction est l'index en comptant les instructions et labels)
//renvoie le nombre de labels (= la taille de tabLabels)
int remplirTabLabels(FILE* fichier, structLabel* l_tabLabels) {
	int nbLabels = 0;
	int nbInstructions = 0;
	int typeLigne;
	char ligne[TAILLE_LIGNE];


	while(lireLigneFichier(fichier, ligne) != 1) {
		typeLigne = formaterLigne(ligne); //on récupère la ligne et son type
		if(typeLigne == 1) {
			strcpy(l_tabLabels[nbLabels].label, ligne);
			l_tabLabels[nbLabels].numInstruction = (nbLabels + nbInstructions);
			nbLabels++;
		}
		if(typeLigne == 0)
			nbInstructions++;
	}

	rewind(fichier); //pointeur retourné au début

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

//ecrit une ligne dans le fichier (ajoute un /n)
void ecrireLigneFichier(FILE * fichier, char donnees[]) {
	fputs(donnees, fichier); //ajoute la chaine à la fin du fichier
	fputs("\n", fichier);
}

/*Lis le fichier Valeurs.csv et mets l'ensemble de son contenu dans une matrice à 3 dimensions*/
void lecture_csv(char matrice[26][10][15]) {

    FILE * fichier = fopen("val2.csv", "rt");
    char ligne[50];
    int num_ligne = 0;
    int pos_loc = 0;
    int indice_ligne = 0;
    int num_mot = 0;
    while (fgets(ligne, 50, fichier) != NULL)  {
        while (ligne[indice_ligne] != '\0') {
            while (ligne[indice_ligne] != ';' && ligne[indice_ligne] != '\0') {
                matrice[num_ligne][num_mot][pos_loc] = ligne[indice_ligne];
                indice_ligne += 1;
                pos_loc += 1;
            }
            matrice[num_ligne][num_mot][pos_loc] = '\0';
            indice_ligne += 1;
            pos_loc = 0;
            num_mot += 1;
        }
        num_ligne += 1;
        num_mot = 0;
        indice_ligne = 0;
    }
    fclose(fichier);
}

/*Testée et fonctionnelle*/
void lecture_csv2(char tableur[], char matrice[16][4][7]) {

    FILE *  fichier = fopen(tableur, "rt");
    char ligne[50];
    int num_ligne = 0;
    int pos_loc = 0;
    int indice_ligne = 0;
    int num_mot = 0;
    while (fgets(ligne, 50, fichier) != NULL)  {
        while (ligne[indice_ligne] != '\0') {
            while (ligne[indice_ligne] != ';' && ligne[indice_ligne] != '\0') {
                matrice[num_ligne][num_mot][pos_loc] = ligne[indice_ligne];
                indice_ligne += 1;
                pos_loc += 1;
            }
            matrice[num_ligne][num_mot][pos_loc] = '\0';
            indice_ligne += 1;
            pos_loc = 0;
            num_mot += 1;
        }
        num_ligne += 1;
        num_mot = 0;
        indice_ligne = 0;
        
    }
    fclose(fichier);
}

/*Testée et fonctionnelle*/
void lecture_csv_3(char tableur[], char matrice[10][7][7]) {

    FILE *  fichier = fopen(tableur, "rt");
    char ligne[50];
    int num_ligne = 0;
    int pos_loc = 0;
    int indice_ligne = 0;
    int num_mot = 0;
    while (fgets(ligne, 50, fichier) != NULL)  {
        while (ligne[indice_ligne] != '\0') {
            while (ligne[indice_ligne] != ';' && ligne[indice_ligne] != '\0') {
                matrice[num_ligne][num_mot][pos_loc] = ligne[indice_ligne];
                indice_ligne += 1;
                pos_loc += 1;
            }
            matrice[num_ligne][num_mot][pos_loc] = '\0';
            indice_ligne += 1;
            pos_loc = 0;
            num_mot += 1;
        }
        num_ligne += 1;
        num_mot = 0;
        indice_ligne = 0;
        
    }
    fclose(fichier);
}

//retourne dans le tableau le nom du registre ($01: ou LI: par exemple)
void nomRegistre(char nomRetourne[], int numRegistre) {
	char reg[4];
	if(numRegistre < 32) {
		strcpy(nomRetourne, "$");
		sprintf(reg, "%02d", numRegistre); //int to string
		strcat(nomRetourne, reg); //concaténation
	}
	else if(numRegistre == 32) 
		strcpy(nomRetourne, "PC");
	else if(numRegistre == 33)
		strcpy(nomRetourne, "HI");
	else
		strcpy(nomRetourne, "LO");
	strcat(nomRetourne, ":");
}

//écrit dans le fichier les valeurs des registres en décimal
void ecrireFichierState(char nomFichier[]) {
	char ligne[TAILLE_LIGNE];
	char reg[10];
	char valRegistre[10]; //en hexa

	FILE * fichier = fopen(nomFichier, "w+");
	for (char i = 0; i < 35; i++) {
		if(i == 32)
			i++; //on skip PC
		nomRegistre(reg, i);
		strcpy(ligne, reg);
		sprintf(valRegistre, "%d", lire_registre(i));
		strcat(ligne, valRegistre);
		ecrireLigneFichier(fichier, ligne);
	}
	fclose(fichier);
}
//affiche les registres sur le terminal
void afficherRegistres() {
	char nomReg[10];
	int nbColonnes = 5;
	printf("VALEUR DES REGISTRES :\n");
	for (char i = 0; i < 7; i++) {
		for (char j = 0; j < nbColonnes; j++) {
			nomRegistre(nomReg, i*nbColonnes+j);
			if((i*nbColonnes+j) > 31)
				strcat(nomReg, " ");
			printf("%s %4d          ", nomReg, lire_registre(i*nbColonnes+j));
		}
		printf("\n");
	}
}

//affiche la mémoire sur le terminal
void afficherMemoire() {
	int nbColonnes = 5;
	printf("MEMOIRE :\n");
	for(int i = 0; i < 20; i++) {
		for (int j = 0; j < nbColonnes; j++) {
			printf("@%4d: %4d      ", (i*nbColonnes+j)*4, lireMemoire((i*nbColonnes+j)*4));
		}
		printf("\n");
	}
}
