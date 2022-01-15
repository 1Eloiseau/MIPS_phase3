#include "fonctions.h"

int main(int argc, char ** argv) { //  ./emul-mips in1.s in1.hex in1.state  par exemple
	char* nomFichierSource = argv[1];
	char* nomFichierDestination = argv[2];
	char* nomFichierRegistres = argv[3]; //on y stocke la valeur des registres à la fin
	char ligne[TAILLE_LIGNE];
	char ligneHexa[9];
	int nbLignes = 0;
	int typeLigne = -1;

	char** tabLignes;

	//Ouvrir un fichier en écriture efface tout son contenu, cela permet d'avoir un fichier out directement nettoyé pour éviter de devoir le faire à chaque fois.
	FILE * fichierSource = fopen(nomFichierSource, "r");
	FILE * fichierDestination = fopen(nomFichierDestination, "a+");
	if(fichierSource == NULL) {
		printf("Erreur dans l'ouverture du fichier %s :(  Existe-t-il ?", nomFichierSource);
	}

	lireFichier(fichierSource, &tabLignes);
	for (int i = 0; i < nbLignes; i++)
	{
		printf("%s \n", tabLignes[i]);
	}
	
	fclose(fichierSource);
	fclose(fichierDestination);
	free(tabLignes);
	return (0);
}
