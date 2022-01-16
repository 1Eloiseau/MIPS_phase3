#include "fonctions.h"

int main(int argc, char ** argv) { //  ./emul-mips in1.s in1.hex in1.state  par exemple
	char* nomFichierSource = argv[1];
	char* nomFichierDestination = argv[2];
	char* nomFichierRegistres = argv[3]; //on y stocke la valeur des registres à la fin
	char ligne[TAILLE_LIGNE];
	char ligneHexa[9];
	int tabRegistres[35]; //dans cet ordre : R0 - ... - R31 - PC - HI - LO
	char tabMemoire[1000]; //octets de mémoire gros-boutiste
	int nbLignes = 0;
	int typeLigne = -1;
	structLabel* tabLabels = NULL; //tableau liant labels et leur positions
	char matriceCSV[26][10][15];
	int i_ligne = 0;
	int i_instruction = 0;
	

	//Ouvrir un fichier en écriture efface tout son contenu, cela permet d'avoir un fichier out directement nettoyé pour éviter de devoir le faire à chaque fois.
	FILE * fichierSource = fopen(nomFichierSource, "r");
	FILE * fichierDestination = fopen(nomFichierDestination, "a+");
	if(fichierSource == NULL) {
		printf("Erreur dans l'ouverture du fichier %s :(  Existe-t-il ?\n", nomFichierSource);
	}

	int nbLabels = remplirTabLabels(fichierSource, &tabLabels);
	printf("§\n");

	lecture_csv(matriceCSV);
	printf("§\n");

	while(lireLigneFichier(fichierSource, ligne) != 1) {
		intEnChar(traduction_dec(ligne, i_ligne, tabLabels, matriceCSV), ligneHexa);
		ecrireLigneFichier(fichierSource, ligneHexa);
		printf("i_ligne:%d i_instruction:%d ligne:%s ligneHexa:%s\n", i_ligne, i_instruction, ligne, ligneHexa);
		i_ligne++;
	}
	
/* //affiche les lignes et leur type
	while(lireLigneFichier(fichierSource, ligne) == 0) {
		printf("type %d\n", formaterLigne(ligne));
		printf("formate : >%s< \n", ligne);
	}
*/
	fclose(fichierSource);
	fclose(fichierDestination);
	return (0);
}
