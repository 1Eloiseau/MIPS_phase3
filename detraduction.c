#include "detraduction.h"


/*Testée et fonctionnelle*/
/*gros boutiste*/
int type_inst(char bin[], char matrice_speciale[16][4][7], char matrice[10][7][7]) {
    char opcode[7];
    char opcode_bis[7];
    int i;
    int k = 0;
    int get_out = 0;
    int type = 0;

    for (i = 0; i < 6; i += 1) {
        opcode[i] = bin[i];
    }
    opcode[i] = '\0';
    if (!strcmp(opcode, "000000")) {
        for (i = 0; i < 6; i += 1) {
            opcode_bis[i] = bin[i];
        }
        opcode_bis[i] = '\0';
        while (get_out != 1) {
            if (!strcmp(opcode_bis, "000010")) {
                if (bin[21] = '0') {
                    get_out = 1;
                    type = 24;
                } else {
                    get_out = 1;
                    type = 21;
                }
            } else if (!strcmp(opcode_bis, matrice_speciale[k][0])) {
                get_out = 1;
                type = 11 + k;
            }
            k += 1;
        }
    } else {
        while (get_out != 1) {
            if (!strcmp(opcode, matrice[k][0])) {
                get_out = 1;
                type = 1 + k;
            }
            k += 1;
        }
    }

    return (type);
}

/*Testée et fonctionnelle*/
/*gros boutiste*/
void hexa_2_bin(char Hex[], char bin[]) {
    int i = 0;
    int k = 0;
    int j = 0;
    int get_out = 0;
    char matrice_conv[32][5] = {"0", "0000", "1", "0001", "2", "0010", "3", "0011", "4", "0100", "5", "0101", "6", "0110", "7", "0111", "8", "1000", "9", "1001", "A", "1010", "B", "1011", "C", "1100", "D", "1101", "E", "1110", "F", "1111"};
    
    while (j < 8) {
        get_out = 0;
        while(get_out != 1){
            if (Hex[j] == matrice_conv[k][0]) {
                get_out = 1;
                bin[i] = matrice_conv[k+1][0];
                bin[i+1] = matrice_conv[k+1][1];
                bin[i+2] = matrice_conv[k+1][2];
                bin[i+3] = matrice_conv[k+1][3];
            }
            k += 2;
        }
        i += 4;
        j += 1;
        k = 0;
    }
    bin[32] = '\0';
}

/*Testée et fonctionnelle*/
/*gros boutiste*/
int bin_2_int(char chaine[]) {
    int nombre = 0;
    int i;
    int n = strlen(chaine);

    i = n - 1;

    while (i != -1) {
        nombre += puissance(2, i) * (chaine[i] - 48);
        i -= 1;
    }
    return (nombre);
}

/*Testée et fonctionnelle*/
/*gros boutiste*/
int lecture_valeur(char inst[], int nb_bit, int place_bit) {
    int i ;
    char str_valeur[nb_bit + 1];
    int valeur;
    for (i = 0; i < nb_bit; i += 1) {
        str_valeur[i] = inst[place_bit + i];
    }
    printf("str : %s\n", str_valeur);
    str_valeur[i] = '\0';
    valeur = bin_2_int(str_valeur);
    printf("val : %d\n", valeur);
    return (valeur);
}


void calcul(int type_op, char matrice_csv[10][7][7], char matrice_csv_speciale[15][4][7], char inst[], int registres[]) {
    int var1;
    int var2;
    int var3;
    if (type_op == 1) {
        var1 = lecture_valeur(inst, atoi(matrice_csv[type_op - 1][4]), atoi(matrice_csv[type_op - 1][1]));
        var2 = lecture_valeur(inst, atoi(matrice_csv[type_op - 1][5]), atoi(matrice_csv[type_op - 1][2]));
        var3 = lecture_valeur(inst, atoi(matrice_csv[type_op - 1][6]), atoi(matrice_csv[0][3]));
        addi(var1, var2, var3, registres);
    } else if (type_op == 2) {
        var1 = lecture_valeur(inst, atoi(matrice_csv[type_op - 1][4]), atoi(matrice_csv[type_op - 1][1]));
        var2 = lecture_valeur(inst, atoi(matrice_csv[type_op - 1][5]), atoi(matrice_csv[type_op - 1][2]));
        var3 = lecture_valeur(inst, atoi(matrice_csv[type_op - 1][6]), atoi(matrice_csv[type_op - 1][3]));
        beq(var1, var2, var3, registres);
    } else if (type_op == 3) {
        var1 = lecture_valeur(inst, atoi(matrice_csv[type_op - 1][4]), atoi(matrice_csv[type_op - 1][1]));
        var2 = lecture_valeur(inst, atoi(matrice_csv[type_op - 1][5]), atoi(matrice_csv[type_op - 1][2]));
        bgtz(var1, var2, registres);
    } else if (type_op == 4) {
        var1 = lecture_valeur(inst, atoi(matrice_csv[type_op - 1][4]), atoi(matrice_csv[type_op - 1][1]));
        var2 = lecture_valeur(inst, atoi(matrice_csv[type_op - 1][5]), atoi(matrice_csv[type_op - 1][2]));
        blez(var1, var2, registres);
    } else if (type_op == 5) {
        var1 = lecture_valeur(inst, atoi(matrice_csv[type_op - 1][4]), atoi(matrice_csv[type_op - 1][1]));
        var2 = lecture_valeur(inst, atoi(matrice_csv[type_op - 1][5]), atoi(matrice_csv[type_op - 1][2]));
        var3 = lecture_valeur(inst, atoi(matrice_csv[type_op - 1][6]), atoi(matrice_csv[type_op - 1][3]));
        bne(var1, var2, var3, registres);
    } else if (type_op == 6) {
        var1 = lecture_valeur(inst, atoi(matrice_csv[type_op - 1][4]), atoi(matrice_csv[type_op - 1][1]));
        j(var1, registres);
    } else if (type_op == 7) {
        var1 = lecture_valeur(inst, atoi(matrice_csv[type_op - 1][4]), atoi(matrice_csv[type_op - 1][1]));
        j(var1, registres);
    } else if (type_op == 8) {
        var1 = lecture_valeur(inst, atoi(matrice_csv[type_op - 1][4]), atoi(matrice_csv[type_op - 1][1]));
        var2 = lecture_valeur(inst, atoi(matrice_csv[type_op - 1][5]), atoi(matrice_csv[type_op - 1][2]));
        lui(var1, var2, registres);
    } else if (type_op == 9) {
        var1 = lecture_valeur(inst, atoi(matrice_csv[type_op - 1][4]), atoi(matrice_csv[type_op - 1][1]));
        var2 = lecture_valeur(inst, atoi(matrice_csv[type_op - 1][5]), atoi(matrice_csv[type_op - 1][2]));
        var3 = lecture_valeur(inst, atoi(matrice_csv[type_op - 1][6]), atoi(matrice_csv[type_op - 1][3]));
        lw(var2, var1, var3, registres);
    } else if (type_op == 10) {
        var1 = lecture_valeur(inst, atoi(matrice_csv[type_op - 1][4]), atoi(matrice_csv[type_op - 1][1]));
        var2 = lecture_valeur(inst, atoi(matrice_csv[type_op - 1][5]), atoi(matrice_csv[type_op - 1][2]));
        var3 = lecture_valeur(inst, atoi(matrice_csv[type_op - 1][6]), atoi(matrice_csv[type_op - 1][3]));
        sw(var2, var1, var3, registres);
    } else if (type_op == 11) {
        var1 = lecture_valeur(inst, 5, atoi(matrice_csv[type_op - 1][1]));
        var2 = lecture_valeur(inst, 5, atoi(matrice_csv[type_op - 1][2]));
        var3 = lecture_valeur(inst, 5, atoi(matrice_csv[type_op - 1][3]));
        add(var2, var1, var3, registres);
    } else if (type_op == 12) {
        var1 = lecture_valeur(inst, 5, atoi(matrice_csv[type_op - 1][1]));
        var2 = lecture_valeur(inst, 5, atoi(matrice_csv[type_op - 1][2]));
        var3 = lecture_valeur(inst, 5, atoi(matrice_csv[type_op - 1][3]));
        and(var2, var1, var3, registres);
    } else if (type_op == 13) {
        var1 = lecture_valeur(inst, 5, atoi(matrice_csv[type_op - 1][1]));
        var2 = lecture_valeur(inst, 5, atoi(matrice_csv[type_op - 1][2]));
        div_2(var1, var2, registres);
    } else if (type_op == 14) {
        var1 = lecture_valeur(inst, 5, atoi(matrice_csv[type_op - 1][1]));
        jr(var1, registres);
    } else if (type_op == 15) {
        var1 = lecture_valeur(inst, 5, atoi(matrice_csv[type_op - 1][1]));
        mfhi(var1, registres);
    } else if (type_op == 16) {
        var1 = lecture_valeur(inst, 5, atoi(matrice_csv[type_op - 1][1]));
        mflo(var1, registres);
    } else if (type_op == 17) {
        var1 = lecture_valeur(inst, 5, atoi(matrice_csv[type_op - 1][1]));
        var2 = lecture_valeur(inst, 5, atoi(matrice_csv[type_op - 1][1]));
        mult(var1, var2, registres);
    } else if (type_op == 18) {
        nop();
    } else if (type_op == 19) {
        var1 = lecture_valeur(inst, 5, atoi(matrice_csv[type_op - 1][1]));
        var2 = lecture_valeur(inst, 5, atoi(matrice_csv[type_op - 1][2]));
        var3 = lecture_valeur(inst, 5, atoi(matrice_csv[type_op - 1][3]));
        or(var2, var1, var3, registres);
    } else if (type_op == 20) {
        var1 = lecture_valeur(inst, 5, atoi(matrice_csv[type_op - 1][1]));
        var2 = lecture_valeur(inst, 5, atoi(matrice_csv[type_op - 1][2]));
        var3 = lecture_valeur(inst, 5, atoi(matrice_csv[type_op - 1][3]));
        rotr(var2, var1, var3, registres);
    } else if (type_op == 21) {
        var1 = lecture_valeur(inst, 5, atoi(matrice_csv[type_op - 1][1]));
        var2 = lecture_valeur(inst, 5, atoi(matrice_csv[type_op - 1][2]));
        var3 = lecture_valeur(inst, 5, atoi(matrice_csv[type_op - 1][3]));
        sll(var2, var1, var3, registres);
    } else if (type_op == 22) {
        var1 = lecture_valeur(inst, 5, atoi(matrice_csv[type_op - 1][1]));
        var2 = lecture_valeur(inst, 5, atoi(matrice_csv[type_op - 1][2]));
        var3 = lecture_valeur(inst, 5, atoi(matrice_csv[type_op - 1][3]));
        slt(var3, var1, var2, registres);
    } else if (type_op == 23) {
        var1 = lecture_valeur(inst, 5, atoi(matrice_csv[type_op - 1][1]));
        var2 = lecture_valeur(inst, 5, atoi(matrice_csv[type_op - 1][2]));
        var3 = lecture_valeur(inst, 5, atoi(matrice_csv[type_op - 1][3]));
        srl(var2, var1, var3, registres);
    } else if (type_op == 24) {
        var1 = lecture_valeur(inst, 5, atoi(matrice_csv[type_op - 1][1]));
        var2 = lecture_valeur(inst, 5, atoi(matrice_csv[type_op - 1][2]));
        var3 = lecture_valeur(inst, 5, atoi(matrice_csv[type_op - 1][3]));
        sub(var3, var1, var2, registres); 
    } else if (type_op == 25) {
        syscall();
    }
}
