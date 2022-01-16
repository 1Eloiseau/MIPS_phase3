#include "fonctions.h"

int main(int argc, char ** argv) { //  ./emul-mips in1.s in1.hex in1.state  par exemple
	char* nomFichierSource = argv[1];
	char* nomFichierDestination = argv[2];
	char* nomFichierRegistres = argv[3]; //on y stocke la valeur des registres à la fin
	char ligne[TAILLE_LIGNE];
	int tabRegistres[35]; //dans cet ordre : R0 - ... - R31 - PC - HI - LO
	char tabMemoire[1000]; //octets de mémoire gros-boutiste
	int nbLignes = 0;
	int typeLigne = -1;

	structLabel* tabLabels = NULL;
	//FAIRE une fonction qui rempli tabLabels !!

	//Ouvrir un fichier en écriture efface tout son contenu, cela permet d'avoir un fichier out directement nettoyé pour éviter de devoir le faire à chaque fois.
	FILE * fichierSource = fopen(nomFichierSource, "r");
	FILE * fichierDestination = fopen(nomFichierDestination, "a+");
	if(fichierSource == NULL) {
		printf("Erreur dans l'ouverture du fichier %s :(  Existe-t-il ?", nomFichierSource);
	}

	int nb = remplirTabLabels(fichierSource, &tabLabels);
	printf("%d\n", nb);
	printf("%s %d \n", tabLabels[0].label, tabLabels[0].numInstruction);
	for (int i = 0; i < nb; i++)
	{
		printf("%s %d \n", tabLabels[i].label, tabLabels[i].numInstruction);
	}
	

	while(lireLigneFichier(fichierSource, ligne) == 0) {
		printf("type %d\n", formaterLigne(ligne));
		printf("formate : >%s< \n", ligne);
	}
	
	fclose(fichierSource);
	fclose(fichierDestination);
	return (0);
}
