#include "fonctions.h"

//L est le tableau dans lequel le mot numero_mot sera stocké. Donc si on a ligne [] = 'ADD R0, R1, R2' et on écrit lecture_mot (ligne, L, 2), le mot R0 qui est le second mot sera stocké dans la variable L.
void lecture_mot(char ligne[], char L[], int numero_mot) {  
    int i = 0;
    int j = 0;
    while (ligne[i] == ' ') {
        i += 1;
    }

    while (numero_mot != 1) {
        while (ligne[i] != ' ' && ligne[i] != ',') {
            i += 1;
        }
        while (ligne[i] == ' ' || ligne[i] == ',') {
            i += 1;
        }
        numero_mot -= 1;
    }


    while (ligne[i] != ' ' && ligne[i] != '\0' && ligne[i] != '#' && ligne[i] != ',' && ligne[i] != ':' && ligne[i] != '\r' && ligne[i] != '\t') {
        L[j] = ligne[i];
        i += 1;
        j += 1;
    }
    L[j] = '\0';

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

//Retourne la valeur décimale d'une chaine de caractère, exemple : valeurDecimale('2021') = 2021 (entier). 
int valeurDecimale (char S[]) {
    int i = 0;
    int n = strlen(S);
    int rang = puissance(10, n-1);
    int nbr = 0;
    int chiffre;

    if(S[0]=='-') {
        i++;
        rang/=10;
    }
    while (S[i] != '\0') {
        chiffre = S[i] - 48;
        nbr += rang * chiffre;
        rang /= 10;
        i += 1;
    }
    if(S[0]=='-') {
        nbr = -nbr;
    }
    return (nbr);
}

//Retourne un tableau contenant dans le premier élément les caractères hors parenthèse et en second élément celui dans les parenthèses. Si par exemple c'et écrit a0(4), le tableau offset sera base[0] = a0 et base[1]=4. S'il n'y a pas de décalage alors le 2nd élément du tableau sera une chaîne de caractères vide. 
void parentheses (char base1[], char base2[], char mot[]) {
    char mot_temp1[TAILLE_LIGNE];
    char mot_temp2[TAILLE_LIGNE];
    // strcpy(mot_temp1, mot);
    // strcpy(mot_temp2, mot);
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

//Prend en entrée une ligne à traduire et retourne la valeur décimale de l'instruction.
int traduction_dec (char ligne[], FILE * fichier_source, int numero_ligne) {
    char operation[8];
    int inst_decimal;
    int variable1; //le type short est indispensable pour le complément à 2 16 bits
    int variable2;
    int variable3;
    char label[100];
    char string_temp1[TAILLE_LIGNE];
    char string_temp2[TAILLE_LIGNE];
    char string_temp3[TAILLE_LIGNE];

    lecture_mot(ligne, operation, 1);

    if (!strcmp(operation, "ADD")) {
        inst_decimal = 32;

        lecture_mot(ligne, string_temp1, 2);
        lecture_mot(ligne, string_temp2, 3);
        lecture_mot(ligne, string_temp3, 4);


        variable1 = numero_registre(string_temp1);
        variable2 = numero_registre(string_temp2);
        variable3 = numero_registre(string_temp3);

        variable1 = variable1 << 11;
        variable2 = variable2 << 21;
        variable3 = variable3 << 16;

        inst_decimal = inst_decimal | variable1;
        inst_decimal = inst_decimal | variable2;
        inst_decimal = inst_decimal | variable3;

    } else if (!strcmp(operation, "AND")) {
        inst_decimal = 36;

        lecture_mot(ligne, string_temp1, 2);
        lecture_mot(ligne, string_temp2, 3);
        lecture_mot(ligne, string_temp3, 4);


        variable1 = numero_registre(string_temp1);
        variable2 = numero_registre(string_temp2);
        variable3 = numero_registre(string_temp3);

        variable1 = variable1 << 11;
        variable2 = variable2 << 21;
        variable3 = variable3 << 16;

        inst_decimal = inst_decimal | variable1;
        inst_decimal = inst_decimal | variable2;
        inst_decimal = inst_decimal | variable3;

    } else if (!strcmp(operation, "DIV")) {
        inst_decimal = 26;

        lecture_mot(ligne, string_temp1, 2);
        lecture_mot(ligne, string_temp2, 3);


        variable1 = numero_registre(string_temp1);
        variable2 = numero_registre(string_temp2);

        variable1 = variable1 << 21;
        variable2 = variable2 << 16;

        inst_decimal = inst_decimal | variable1;
        inst_decimal = inst_decimal | variable2;
    } else if (!strcmp(operation, "JR")) {
        inst_decimal = 8;

        lecture_mot(ligne, string_temp1, 2);

        variable1 = numero_registre(string_temp1);

        variable1 = variable1 << 21;

        inst_decimal = inst_decimal | variable1;
    } else if (!strcmp(operation, "MFHI")) {
        inst_decimal = 16;

        lecture_mot(ligne, string_temp1, 2);

        variable1 = numero_registre(string_temp1);

        variable1 = variable1 << 11;

        inst_decimal = inst_decimal | variable1;
    } else if (!strcmp(operation, "MFLO")) {
        inst_decimal = 18;

        lecture_mot(ligne, string_temp1, 2);

        variable1 = numero_registre(string_temp1);

        variable1 = variable1 << 11;

        inst_decimal = inst_decimal | variable1;
    } else if (!strcmp(operation, "MULT")) {
        inst_decimal = 24;

        lecture_mot(ligne, string_temp1, 2);
        lecture_mot(ligne, string_temp2, 3);


        variable1 = numero_registre(string_temp1);
        variable2 = numero_registre(string_temp2);

        variable1 = variable1 << 21;
        variable2 = variable2 << 16;

        inst_decimal = inst_decimal | variable1;
        inst_decimal = inst_decimal | variable2;

    } else if (!strcmp(operation, "NOP")) {
        inst_decimal = 0;
    } else if (!strcmp(operation, "OR")) {
        inst_decimal = 37;

        lecture_mot(ligne, string_temp1, 2);
        lecture_mot(ligne, string_temp2, 3);
        lecture_mot(ligne, string_temp3, 4);


        variable1 = numero_registre(string_temp1);
        variable2 = numero_registre(string_temp2);
        variable3 = numero_registre(string_temp3);


        variable1 = variable1 << 11;
        variable2 = variable2 << 21;
        variable3 = variable3 << 16;

        inst_decimal = inst_decimal | variable1;
        inst_decimal = inst_decimal | variable2;
        inst_decimal = inst_decimal | variable3;
    } else if (!strcmp(operation, "ROTR")) {
        inst_decimal = 2097154;

        lecture_mot(ligne, string_temp1, 2);
        lecture_mot(ligne, string_temp2, 3);
        lecture_mot(ligne, string_temp3, 4);


        variable1 = numero_registre(string_temp1);
        variable2 = numero_registre(string_temp2);
        variable3 = valeurDecimale(string_temp3);

        variable1 = variable1 << 11;
        variable2 = variable2 << 16;
        variable3 = variable3 << 6;

        inst_decimal = inst_decimal | variable1;
        inst_decimal = inst_decimal | variable2;
        inst_decimal = inst_decimal | variable3;
    } else if (!strcmp(operation, "SLL")) {
        inst_decimal = 0;

        lecture_mot(ligne, string_temp1, 2);
        lecture_mot(ligne, string_temp2, 3);
        lecture_mot(ligne, string_temp3, 4);


        variable1 = numero_registre(string_temp1);
        variable2 = numero_registre(string_temp2);
        variable3 = valeurDecimale(string_temp3);

        variable1 = variable1 << 11;
        variable2 = variable2 << 16;
        variable3 = variable3 << 6;

        inst_decimal = inst_decimal | variable1;
        inst_decimal = inst_decimal | variable2;
        inst_decimal = inst_decimal | variable3;
    } else if (!strcmp(operation, "SLT")) {
        inst_decimal = 42;

        lecture_mot(ligne, string_temp1, 2);
        lecture_mot(ligne, string_temp2, 3);
        lecture_mot(ligne, string_temp3, 4);


        variable1 = numero_registre(string_temp1);
        variable2 = numero_registre(string_temp2);
        variable3 = numero_registre(string_temp3);

        variable1 = variable1 << 11;
        variable2 = variable2 << 21;
        variable3 = variable3 << 16;

        inst_decimal = inst_decimal | variable1;
        inst_decimal = inst_decimal | variable2;
        inst_decimal = inst_decimal | variable3;
    } else if (!strcmp(operation, "SRL")) {
        inst_decimal = 2;
        
        lecture_mot(ligne, string_temp1, 2);
        lecture_mot(ligne, string_temp2, 3);
        lecture_mot(ligne, string_temp3, 4);


        variable1 = numero_registre(string_temp1);
        variable2 = numero_registre(string_temp2);
        variable3 = valeurDecimale(string_temp3);

        variable1 = variable1 << 11;
        variable2 = variable2 << 16;
        variable3 = variable3 << 6;

        inst_decimal = inst_decimal | variable1;
        inst_decimal = inst_decimal | variable2;
        inst_decimal = inst_decimal | variable3;
    } else if (!strcmp(operation, "SUB")) {
        inst_decimal = 34;
       
        lecture_mot(ligne, string_temp1, 2);
        lecture_mot(ligne, string_temp2, 3);
        lecture_mot(ligne, string_temp3, 4);


        variable1 = numero_registre(string_temp1);
        variable2 = numero_registre(string_temp2);
        variable3 = numero_registre(string_temp3);

        variable1 = variable1 << 11;
        variable2 = variable2 << 21;
        variable3 = variable3 << 16;

        inst_decimal = inst_decimal | variable1;
        inst_decimal = inst_decimal | variable2;
        inst_decimal = inst_decimal | variable3;
    } else if (!strcmp(operation, "SYSCALL")) {
        inst_decimal = 12;
    } else if (!strcmp(operation, "XOR")) {
        inst_decimal = 38;
        
        lecture_mot(ligne, string_temp1, 2);
        lecture_mot(ligne, string_temp2, 3);
        lecture_mot(ligne, string_temp3, 4);


        variable1 = numero_registre(string_temp1);
        variable2 = numero_registre(string_temp2);
        variable3 = numero_registre(string_temp3);

        variable1 = variable1 << 11;
        variable2 = variable2 << 21;
        variable3 = variable3 << 16;

        inst_decimal = inst_decimal | variable1;
        inst_decimal = inst_decimal | variable2;
        inst_decimal = inst_decimal | variable3;
    } else if (!strcmp(operation, "ADDI")) {
        inst_decimal = 536870912;
        
        lecture_mot(ligne, string_temp1, 2);
        lecture_mot(ligne, string_temp2, 3);
        lecture_mot(ligne, string_temp3, 4);


        variable1 = numero_registre(string_temp1);
        variable2 = numero_registre(string_temp2);
        variable3 = valeurDecimale(string_temp3);

        variable1 = variable1 << 16;
        variable2 = variable2 << 21;
        variable3 = variable3 & 0x0000FFFF; //int->short int (pour complement à 2 sur 16 bits)

        inst_decimal = inst_decimal | variable1;
        inst_decimal = inst_decimal | variable2;
        inst_decimal = inst_decimal | variable3;
    } else if (!strcmp(operation, "BEQ")) {
        inst_decimal = 268435456;
        
        lecture_mot(ligne, string_temp1, 2);
        lecture_mot(ligne, string_temp2, 3);
        lecture_mot(ligne, string_temp3, 4);


        variable1 = numero_registre(string_temp1);
        variable2 = numero_registre(string_temp2);
        variable3 = valeurDecimale(string_temp3);

        variable1 = variable1 << 21;
        variable2 = variable2 << 16;
        variable3 = variable3 & 0x0000FFFF; //int->short int (pour complement à 2 sur 16 bits)

        inst_decimal = inst_decimal | variable1;
        inst_decimal = inst_decimal | variable2;
        inst_decimal = inst_decimal | variable3;
    } else if (!strcmp(operation, "BGTZ")) {
        inst_decimal = 469762048;

        lecture_mot(ligne, string_temp1, 2);
        lecture_mot(ligne, string_temp2, 3);

        variable1 = numero_registre(string_temp1);
        variable2 = valeurDecimale(string_temp2);

        variable1 = variable1 << 21;
        variable2 = variable2 & 0x0000FFFF; //int->short int (pour complement à 2 sur 16 bits)

        inst_decimal = inst_decimal | variable1;
        inst_decimal = inst_decimal | variable2;
    } else if (!strcmp(operation, "BLEZ")) {
        inst_decimal = 402653184;

        lecture_mot(ligne, string_temp1, 2);
        lecture_mot(ligne, string_temp2, 3);


        variable1 = numero_registre(string_temp1);
        variable2 = valeurDecimale(string_temp2);

        variable1 = variable1 << 21;
        variable2 = variable2 & 0x0000FFFF; //int->short int (pour complement à 2 sur 16 bits)

        inst_decimal = inst_decimal | variable1;
        inst_decimal = inst_decimal | variable2;
    } else if (!strcmp(operation, "BNE")) {
        inst_decimal = 335544320;
        lecture_mot(ligne, string_temp1, 2);
        lecture_mot(ligne, string_temp2, 3);
        lecture_mot(ligne, string_temp3, 4);

        variable1 = numero_registre(string_temp1);
        variable2 = numero_registre(string_temp2);
        variable3 = valeurDecimale(string_temp3);

        variable1 = variable1 << 21;
        variable2 = variable2 << 16;
        variable3 = variable3 & 0x0000FFFF; //int->short int (pour complement à 2 sur 16 bits)

        inst_decimal = inst_decimal | variable1;
        inst_decimal = inst_decimal | variable2;
        inst_decimal = inst_decimal | variable3;
    } else if (!strcmp(operation, "J")) {
        inst_decimal = 134217728;

        lecture_mot(ligne, string_temp1, 2);

        variable1 = offsetLabel(ligne, fichier_source, string_temp1);

        if (numero_ligne < variable1) {
            variable1 = (numero_ligne - variable1 + 1) * 4;;
        } else {
            variable1 = (numero_ligne - variable1 - 1) * 4;
        }

        inst_decimal = inst_decimal | variable1;
    } else if (!strcmp(operation, "JAL")) {
        inst_decimal = 201326592;

        lecture_mot(ligne, string_temp1, 2);

        variable1 = offsetLabel(ligne, fichier_source, string_temp1);

        if (numero_ligne < variable1) {
            variable1 = (numero_ligne - variable1 + 1) * 4;;
        } else {
            variable1 = (numero_ligne - variable1 - 1) * 4;
        }

        inst_decimal = inst_decimal | variable1;
    } else if (!strcmp(operation, "LUI")) {
        inst_decimal = 1006632960;

        lecture_mot(ligne, string_temp1, 2);
        lecture_mot(ligne, string_temp2, 3);


        variable1 = numero_registre(string_temp1);
        variable2 = valeurDecimale(string_temp2);

        variable1 = variable1 << 16;
        variable2 = variable2 & 0x0000FFFF; //int->short int (pour complement à 2 sur 16 bits)

        inst_decimal = inst_decimal | variable1;
        inst_decimal = inst_decimal | variable2;
    } else if (!strcmp(operation, "LW")) {
        inst_decimal = 2348810240;

        lecture_mot(ligne, string_temp1, 2);
        lecture_mot(ligne, string_temp2, 3);

        variable1 = numero_registre(string_temp1);

        parentheses(label, string_temp3, string_temp2);

        if (string_temp3[0] == '$') {
            variable3 = numero_registre(string_temp3);
        } else {
            variable3 = valeurDecimale(string_temp3);
        }

        variable2 = valeurDecimale(label);

        variable1 = variable1 << 16;
        variable2 = variable2 & 0x0000FFFF; //int->short int (pour complement à 2 sur 16 bits)
        variable3 = variable3 << 21;

        inst_decimal = inst_decimal | variable1;
        inst_decimal = inst_decimal | variable2;
        inst_decimal = inst_decimal | variable3;
    } else if (!strcmp(operation, "SW")) {
        inst_decimal = 2885681152;
        lecture_mot(ligne, string_temp1, 2);
        lecture_mot(ligne, string_temp2, 3);

        variable1 = numero_registre(string_temp1);

        parentheses(label, string_temp3, string_temp2);

        variable3 = valeurDecimale(label);

        if (string_temp3[0] == '$') {
            variable2 = numero_registre(string_temp3);
        } else {
            variable2 = valeurDecimale(string_temp3);
        }

        variable1 = variable1 << 16;
        variable2 = variable2 << 21;
        variable3 = variable3 & 0x0000FFFF; //int->short int (pour complement à 2 sur 16 bits)

        inst_decimal = inst_decimal | variable1;
        inst_decimal = inst_decimal | variable2;
        inst_decimal = inst_decimal | variable3;
    }

    return (inst_decimal);
}

//Transforme un int en chaine de caractère hexa (de 8 caractères)
void intEnChar(int instruction, char ligneHexa[]) {
	const char hexa[] = "0123456789abcdef";
	short aConvertir; //nombre sur 4bits à convertir en 1 caractere hexa

	for (int i = 0; i < 8; i += 1)
	{
		aConvertir = instruction>>4*i;
		aConvertir = aConvertir & 0x0000000F;
		ligneHexa[7-i] = hexa[aConvertir];
	}
    ligneHexa[8] = '\0';
}