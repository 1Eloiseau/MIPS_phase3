#include "fonctions.h"

int main(int argc, char ** argv) { //  ./emul-mips in1.s in1.hex in1.state  par exemple
	char* nomFichierSource = argv[1];
	char* nomFichierDestination = argv[2];
	char* nomFichierRegistres = argv[3]; //on y stocke la valeur des registres à la fin
	char ligne[TAILLE_LIGNE];
	char ligneHexa[9];
	int numeroLigne = 1;
	int etatLigne = 0;

	char** tabLignes;

	//Ouvrir un fichier en écriture efface tout son contenu, cela permet d'avoir un fichier out directement nettoyé pour éviter de devoir le faire à chaque fois.
	FILE * fichierSource = fopen(nomFichierSource, "r");
	FILE * fichierDestination = fopen(nomFichierDestination, "a+");
/*
	while ((etatLigne = lireLigneFichier(fichierSource, ligne, numeroLigne)) != -1) { // tant qu'il reste des lignes à lire
		if(etatLigne == 1) {
			
			intEnChar(traduction_dec(ligne, fichierSource, numeroLigne), ligneHexa);
			ecrireFichier(fichierDestination, ligneHexa);
			printf("§\n");
		}
		numeroLigne++;
	}
*/
	lireFichier(fichierSource, &tabLignes);
	printf("%s\n", tabLignes[0]);
	printf("%s\n", tabLignes[1]);

	fclose(fichierSource);
	fclose(fichierDestination);
	free(tabLignes);
	return (0);
}
