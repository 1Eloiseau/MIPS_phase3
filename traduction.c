#include "traduction.h"

//L est le tableau dans lequel le mot numero_mot sera stocké. Donc si on a ligne [] = 'ADD R0, R1, R2' et on écrit lecture_mot (ligne, L, 2), le mot R0 qui est le second mot sera stocké dans la variable L.

void lecture_mot(char ligne[], char L[4][100]) {
    int i = 0;
    int j = 0;
    int k = 0;
    int num_mot = 4;
    char temp[100];

    while (ligne[i] == ' ') {
        i += 1;
    }
    while (num_mot != 0 && ligne[i] != '\0' && ligne[i] != '#' && ligne[i] != ':') {
        while (ligne[i] != ' ' && ligne[i] != '\0' && ligne[i] != '#' && ligne[i] != ',' && ligne[i] != ':' && ligne[i] != '\r' && ligne[i] != '\t') {
            temp[k] = ligne[i];
            i += 1;
            k += 1;
        }
        temp[k] = '\0';
        strcpy(L[j], temp);
        k = 0;
        j += 1;
        num_mot -= 1;
        while (ligne[i] == ' ' || ligne[i] == ',' || ligne[i] == '\r' || ligne[i] == '\t') {
            i += 1;
        }
    }
}

//Regarde la chaîne de caractère contenue dans mot qui doit représenter un registre et retourne le numéro de ce registre
int numero_registre(char mot[]) {  
    int R = 0;
    if (!strcmp(mot, "$zero") || !strcmp(mot,"$0")) {
        R = 0;
    } else if (!strcmp(mot, "$at") || !strcmp(mot,"$1")) {
        R = 1;
    } else if (!strcmp(mot, "$v0") || !strcmp(mot,"$2")) {
        R = 2;
    } else if (!strcmp(mot, "$v1") || !strcmp(mot,"$3")) {
        R = 3;
    } else if (!strcmp(mot, "$a0") || !strcmp(mot,"$4")) {
        R = 4;
    } else if (!strcmp(mot, "$a1") || !strcmp(mot,"$5")) {
        R = 5;
    } else if (!strcmp(mot, "$a2") || !strcmp(mot,"$6")) {
        R = 6;
    } else if (!strcmp(mot, "$a3") || !strcmp(mot,"$7")) {
        R = 7;
    } else if (!strcmp(mot, "$t0") || !strcmp(mot,"$8")) {
        R = 8;
    } else if (!strcmp(mot, "$t1") || !strcmp(mot,"$9")) {
        R = 9;
    } else if (!strcmp(mot, "$t2") || !strcmp(mot,"$10")) {
        R = 10;
    } else if (!strcmp(mot, "$t3") || !strcmp(mot,"$11")) {
        R = 11;
    } else if (!strcmp(mot, "$t4") || !strcmp(mot,"$12")) {
        R = 12;
    } else if (!strcmp(mot, "$t5") || !strcmp(mot,"$13")) {
        R = 13;
    } else if (!strcmp(mot, "$t6") || !strcmp(mot,"$14")) {
        R = 14;
    } else if (!strcmp(mot, "$t7") || !strcmp(mot,"$15")) {
        R = 15;
    } else if (!strcmp(mot, "$t8") || !strcmp(mot,"$24")) {
        R = 24;
    } else if (!strcmp(mot, "$t9") || !strcmp(mot,"$25")) {
        R = 25;
    } else if (!strcmp(mot, "$s0") || !strcmp(mot,"$16")) {
        R = 16;
    } else if (!strcmp(mot, "$s1") || !strcmp(mot,"$17")) {
        R = 17;
    } else if (!strcmp(mot, "$s2") || !strcmp(mot,"$18")) {
        R = 18;
    } else if (!strcmp(mot, "$s3") || !strcmp(mot,"$19")) {
        R = 19;
    } else if (!strcmp(mot, "$s4") || !strcmp(mot,"$20")) {
        R = 20;
    } else if (!strcmp(mot, "$s5") || !strcmp(mot,"$21")) {
        R = 21;
    } else if (!strcmp(mot, "$s6") || !strcmp(mot,"$22")) {
        R = 22;
    } else if (!strcmp(mot, "$s7") || !strcmp(mot,"$23")) {
        R = 23;
    } else if (!strcmp(mot, "$k0") || !strcmp(mot,"$26")) {
        R = 26;
    } else if (!strcmp(mot, "$k1") || !strcmp(mot,"$27")) {
        R = 27;
    } else if (!strcmp(mot, "$gp") || !strcmp(mot,"$28")) {
        R = 28;
    } else if (!strcmp(mot, "$sp") || !strcmp(mot,"$29")) {
        R = 29;
    } else if (!strcmp(mot, "$fp") || !strcmp(mot,"$30")) {
        R = 30;
    } else if (!strcmp(mot, "$ra") || !strcmp(mot,"$31")) {
        R = 31;
    }
    return (R);
}

//Retourne a puissance p. Utilisée pour la fonction juste en dessous.
int puissance(int a, int p) {  
    int b = 1;
    while (p != 0) {
        b *= a;
        p -= 1;
    }
    return (b);
}

/*Retourne un tableau contenant dans le premier élément les caractères hors parenthèse et en second élément celui dans les parenthèses.*/
/*Si par exemple c'et écrit a0(4), le tableau offset sera base[0] = a0 et base[1]=4. S'il n'y a pas de décalage alors le 2nd élément du tableau sera une chaîne de caractères vide.*/
void parentheses (char base1[], char base2[], char mot[]) {
    char mot_temp1[TAILLE_LIGNE];
    char mot_temp2[TAILLE_LIGNE];
    int i = 0;
    int j = 0;

    while (mot[i] != '(') {
        mot_temp1[i] = mot[i];
        i += 1;
    }

    mot_temp1[i] = '\0';
    i += 1;

    while (mot[i] != ')') {
        mot_temp2[j] = mot[i];
        i += 1;
        j += 1;
    }

    mot_temp2[j] = '\0'; 
    
    strcpy(base1, mot_temp1);
    strcpy(base2, mot_temp2);
}

//Retourne le numéro de ligne du label recherché.
int offset_label(structLabel matrice_label[], char label[100], int nb_label) {
    int get_out = 0;
    int num_label = 0;
    int pos_label = -1;
    while (num_label <= nb_label && get_out != 1){
        if (!strcmp(matrice_label[num_label].label, label)) {
            get_out = 1;
            pos_label = matrice_label[num_label].numInstruction;
        } 
        num_label += 1;
    }
    return (pos_label);
}

/*Prend en entrée un nombre de bits et une variable et retourne cette variable décalée binairement du nombre de bits*/
/*Par exemple si on rendre 2 = "10" et qu'on demande un décalage de 4 bits, la fonction retourne 32 = "100000"*/
int decalage(int var, int num_bit) {
    return (var << num_bit);
}

/*Prend en entrée une variable et un nombre de bits, si par hasard, le nombre de trop grand, il sera réduit*/
/*Par exemple, si on rentre 10 = "1010" et que le nombre de bits max est 3, la fonction renverra 2 = "010*/
int houla_ca_deborde(int variable, int nbr_bit) {
    int i = puissance(2, nbr_bit) - 1;
    return (variable & i);
}

//Transforme un int en chaine de caractère hexa (de 8 caractères)
void intEnChar(int instruction, char ligneHexa[]) {
	const char hexa[] = "0123456789ABCDEF";
	short aConvertir; //nombre sur 4bits à convertir en 1 caractere hexa

	for (int i = 0; i < 8; i += 1)
	{
		aConvertir = instruction>>4*i;
		aConvertir = aConvertir & 0x0000000F;
		ligneHexa[7-i] = hexa[aConvertir];
	}
    ligneHexa[8] = '\0';
}

/*Prenons pas exemple l'instruction ADDI $2, $zero; 5, chaque mot de cette instruction sont dans operation*/
/*ligne_matrice instruction est la ligne à laquelle l'instruction ADDI se trouve dans la matrice csv*/
/*Grâce à cela, on connait le type d'instruction, ADDI est une instruction de type 2*/
/*C'est-à-dire qu'il y a 2 registres et un entier*/
/*La fonction va demander à numero_registre de traduire $2 et $zero et à atoi 5*/
/*Puis va demander à houla_ca_deborde de faire ne sorte que ça ne déborde pas en fonction des infos dans matrice_csv*/
/*Puis à décalage de décaler en fonction des informations stocker dans matrice_csv*/
/*Puis effectue un ou binaire entre chaque variable et le masque, lui aussi stocké dans matrice_csv*/
/*Puis retourne le résultat*/
int string_to_int (char operation[4][100], char matrice_csv[26][10][15], int ligne_matrice_csv, int num_inst, structLabel matrice_label[], int nb_label) {
    int inst_decimal = atoi(matrice_csv[ligne_matrice_csv][1]);
    int variable1 = 0;
    int variable2 = 0;
    int variable3 = 0;
    char label[100];
    int type_op = atoi(matrice_csv[ligne_matrice_csv][9]);

    if (type_op == 1) {

        variable1 = numero_registre(operation[1]);
        variable2 = numero_registre(operation[2]);
        variable3 = numero_registre(operation[3]);

    } else if (type_op == 5) {

        variable1 = numero_registre(operation[1]);
        variable2 = numero_registre(operation[2]);

    } else if (type_op == 4) {

        variable1 = numero_registre(operation[1]);

    } else if (type_op == 6) {
    } else if (type_op == 2) {

        variable1 = numero_registre(operation[1]);
        variable2 = numero_registre(operation[2]);
        variable3 = atoi(operation[3]);

    } else if (type_op == 3) {

        variable1 = numero_registre(operation[1]);
        variable2 = atoi(operation[2]);

    } else if (type_op == 7) {

        variable1 = numero_registre(operation[1]);

        parentheses(label, operation[3], operation[2]);

        if (operation[3][0] == '$') {
            variable3 = numero_registre(operation[3]);
        } else {
            variable3 = atoi(operation[3]);
        }

        variable2 = atoi(operation[2]);
    } else if (type_op == 8) {

        variable1 = numero_registre(operation[1]);

        parentheses(label, operation[2], operation[2]);

        variable3 = atoi(label);

        if (operation[3][0] == '$') {
            variable2 = numero_registre(operation[3]);
        } else {
            variable2 = atoi(operation[3]);
        }
    } else if (type_op == -1) {
        return (-1);
    } else if (type_op == 9) {
        variable1 = offset_label(matrice_label, operation[1], nb_label);

        if (num_inst < variable1) {
            variable1 = (num_inst - variable1 + 1) * 4;;
        } else {
            variable1 = (num_inst - variable1 - 1) * 4;
        }
    }

    houla_ca_deborde(variable1, atoi(matrice_csv[ligne_matrice_csv][6]));
    houla_ca_deborde(variable2, atoi(matrice_csv[ligne_matrice_csv][7]));
    houla_ca_deborde(variable3, atoi(matrice_csv[ligne_matrice_csv][8]));

    variable1 = decalage(variable1, atoi(matrice_csv[ligne_matrice_csv][2]));
    variable2 = decalage(variable2, atoi(matrice_csv[ligne_matrice_csv][3]));
    variable3 = decalage(variable3, atoi(matrice_csv[ligne_matrice_csv][4]));

    inst_decimal = inst_decimal | variable1 | variable2 | variable3;

    return (inst_decimal);
}

int traduction_dec(char ligne[], int num_instruction, structLabel matrice_label[], char matrice_csv[26][10][15], int nb_label) {
    char mot_ligne[4][100];
    int ligne_csv = -1;
    int get_out = 0;
    int inst_dec;

    lecture_mot(ligne, mot_ligne);

    while (ligne_csv <= 26 && get_out != 1) {
        ligne_csv += 1;
        if (!strcmp(mot_ligne[0], matrice_csv[ligne_csv][0])) {
            get_out = 1;
        }
    }

    inst_dec = string_to_int(mot_ligne, matrice_csv, ligne_csv, num_instruction, matrice_label, nb_label);
    
    if (inst_dec == -1) {
        printf("Erreur à l'instruction n°%d", num_instruction);
        return(-1);
    }

    return (inst_dec);
}