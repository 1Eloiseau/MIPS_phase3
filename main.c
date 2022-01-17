#include "fonctions.h"
int tabRegistres[35] = {0}; //dans cet ordre : R0 - ... - R31 - PC - HI - LO
char tabMemoire[400] = {0}; //octets de mémoire gros-boutiste
#define INTERACTIF 0
#define NON_INTERACTIF_PAS 1
#define NON_INTERACTIF 2


int main(int argc, char ** argv) { //  ./emul-mips in1.s in1.hex in1.state  par exemple
	char ligne[TAILLE_LIGNE];
	char ligneHexa[9];
	int nbLignes = 0;
	int typeLigne = -1;
	structLabel tabLabels[10]; //tableau liant labels et leur positions
	char matriceCSV[26][10][15];
	int i_ligne = 0;
	int i_instruction = 0;
	int mode;
	char* nomFichierSource;
	char* nomFichierDestination;
	char* nomFichierRegistres; //on y stocke la valeur des registres à la fin

	switch (argc) { //En fonction du mode choisi
	case 1:
		mode = INTERACTIF;
		break;
	case 2:
		mode = NON_INTERACTIF_PAS;
		nomFichierSource = argv[1];
		break;
	case 4:
	mode = NON_INTERACTIF;
		nomFichierSource = argv[1];
		nomFichierDestination = argv[2];
		nomFichierRegistres = argv[3]; //on y stocke la valeur des registres à la fin
		break;
	default:
		break;
	}
	/*

	//Ouvrir un fichier en écriture efface tout son contenu, cela permet d'avoir un fichier out directement nettoyé pour éviter de devoir le faire à chaque fois.
	FILE * fichierSource = fopen(nomFichierSource, "r");
	FILE * fichierDestination = fopen(nomFichierDestination, "w+");
	if(fichierSource == NULL) {
		printf("Erreur dans l'ouverture du fichier %s :(  Existe-t-il ?\n", nomFichierSource);
	}

	int nbLabels = remplirTabLabels(fichierSource, tabLabels);
	printf("§\n");

	lecture_csv(matriceCSV);
	printf("§\n");
	tabRegistres[5] = -11;
	ecrireFichierState(nomFichierRegistres);
	/*
	while(lireLigneFichier(fichierSource, ligne) != 1) {
		if(formaterLigne(ligne) == 0) { //ligne est une instruction
			intEnChar(traduction_dec(ligne, i_instruction, tabLabels, matriceCSV), ligneHexa);
			ecrireLigneFichier(fichierDestination, ligneHexa);
			printf("i_ligne:%d i_instruction:%d ligne:%s ligneHexa:%s\n", i_ligne, i_instruction, ligne, ligneHexa);
		}
		i_ligne++;
	}
	
	//affiche les lignes de tabLabels
	for (int i = 0; i < nbLabels; i++)
	{
		printf("%s %d\n", tabLabels[i].label, tabLabels[i].numInstruction);
	}
	
/* //affiche les lignes et leur type
	while(lireLigneFichier(fichierSource, ligne) == 0) {
		printf("type %d\n", formaterLigne(ligne));
		printf("formate : >%s< \n", ligne);
	}

	afficherRegistres();
	afficherMemoire();
	if(i_instruction == 0)
		printf("Aucune instruction écrite\n");
	else
		printf("%d instructions écrites avec succès !\n", i_instruction);
    
	fclose(fichierSource);
	fclose(fichierDestination);
	*/
	return (0);
}
