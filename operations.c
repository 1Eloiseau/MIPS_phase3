#include "operations.h"


void add(int reg_s1, int reg_s2, int reg_d, int registres[]) {
    int var1 = lire_registre(registres, reg_s1);
    int var2 = lire_registre(registres, reg_s2);

    ecrire_registre(registres, reg_d, var1 + var2);
}

void addi(int reg_s1, int reg_d, int var2, int registres[]) {
    int var1 = lire_registre(registres, reg_s1);

    ecrire_registre(registres, reg_d, var1 + var2);
}

void and(int reg_s1, int reg_s2, int reg_d, int registres[]) {
    ecire_registre(registres, reg_d, registres[reg_s1] & registres[reg_s2]);
}

void or(int reg_s1, int reg_s2, int reg_d, int registres[]) {
    ecire_registre(registres, reg_d, registres[reg_s1] | registres[reg_s2]);
}

void xor(int reg_s1, int reg_s2, int reg_d, int registres[]) {
    ecire_registre(registres, reg_d, registres[reg_s1] ^ registres[reg_s2]);
}

void beq(int reg_s1, int reg_s2, int offset, int registres[]) {
    int offset_temp = offset << 2;
    if (registres[reg_s1] == registres[reg_s2]) {
        ecire_registre(registres, PC, registres[PC] + offset_temp);
    }
}

void bne(int reg_s1, int reg_s2, int offset, int registres[]) {
    int offset_temp = offset << 2;
    if (registres[reg_s1] != registres[reg_s2]) {
        ecire_registre(registres, PC, registres[PC] + offset_temp);
    }
}

void bgtz(int reg_s1, int offset, int registres[]) {
    int offset_temp = offset << 2;
    if (registres[reg_s1] > 0) {
        ecire_registre(registres, PC, registres[PC] + offset_temp);
    }
}

void blez(int reg_s1, int offset, int registres[]) {
    int offset_temp = offset << 2;
    if (registres[reg_s1] <= 0) {
        ecire_registre(registres, PC, registres[PC] + offset_temp);
    }
}


/*il existe déjà une fonction div, d'où le div_2*/
void div_2(int reg_s1, int reg_s2, int registres[]) {
    int quotient = reg_s1 / reg_s2;
    int reste = reg_s1 % reg_s2;
    ecire_registre(registres, LO, quotient);
    ecire_registre(registres, HI, reste);
}

void j(int index, int registres[]) {
    int index_temp = index << 2;
    ecrire_registre(registres, PC, registres[PC] + index_temp);
}

void jal(int index, int registres[]) {
    int index_temp = index << 2;
    ecrire_registre(registres, 31, registres[PC] + 8);
    ecrire_registre(registres, PC, index_temp);
}  

void jr(int reg, int registres[]) {
    ecrire_registre(registres, PC, registres[reg]);
}

void lui(int reg, int var, int registres[]) {
    int var_temp = var <<16;
    ecrire_registre(registres, reg, var_temp);
}

void lw(int reg, int base, int offset, int registres[]) {
    int var = lire_memoire(base + offset);
    ecrireRegistre(registres, reg, var);
}

void mfhi(int reg, int registres[]) {
    ecrire_registre(registres, reg, registres[HI]);
}

void mflo(int reg,int registres[]) {
    ecrire_registre(registres, reg, registres[LO]);
}

void mult(int reg1, int reg2,int registres[]) {
    long int var = registres[reg1] * registres[reg2];
    long int masque_bas = puissance(2, 32) - 1;
    long int masque_haut = puissance(2, 64) - 1 - masque_bas; 
    ecrire_registre(registres, LO, var & masque_bas);
    ecrire_registre(registres, HI, var & masque_haut);
}

void nop() {
}

void or(int reg_d, int reg_s1, int reg_s2, int registres[]) {
    ecrire_registre(registres, reg_d, registres[reg_s1] | registres[reg_s2]);
}

/*Testée et fonctionnelle*/
void rotr(int reg_d, int reg_s, int delimit, int registres[]) {
    int masque_bas = puissance(2, delimit) - 1;
    int masque_haut = puissance(2, 32) - 1 - masque_bas;
    int var = registres[reg_s];
    int var_bas = var & masque_bas;
    int var_haut = var & masque_haut;

    var_haut = var_haut >> 16;
    var_bas = var_bas << 16;

    var = var_haut + var_bas;

    ecrire_registre(registres, reg_d, var);
}

void sll(int reg_d, int reg_s, int var, int registres[]) {
    ecrire_registre(registres, reg_d, registres[reg_s] << var);
}

void slt(int reg_d, int reg_s1, int reg_s2, int registres[]) {
    int result = 0;
    if (registres[reg_s1] < registres [reg_s2]) {
        result = 1;
    }
    ecrire_registre(registres, reg_d, result);
}

void slr(int reg_d, int reg_s, int var, int registres[]) {
    ecrire_registre(registres, reg_d, registres[reg_s] >> var);
}

void sub(int reg_d, int reg_s1, int reg_s2, int registres[]) {
    ecrire_registre(registres, reg_d, registres[reg_s1] - registres[reg_s2]);
}

void sw(int reg, int base, int offset, int registres[]) {
    int var = registres[reg];
    ecrireMemoire(base + offset, var);
}

void syscall() {
    printf("Vous avez dit 'syscall' ?? ");
}
