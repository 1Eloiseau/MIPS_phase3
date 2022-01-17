
void add(int reg_s1, int reg_s2, int reg_d, int registres[]);

void addi(int reg_s1, int reg_d, int var2, int registres[]);

void and(int reg_s1, int reg_s2, int reg_d, int registres[]);

void or(int reg_s1, int reg_s2, int reg_d, int registres[]);

void xor(int reg_s1, int reg_s2, int reg_d, int registres[]);

void beq(int reg_s1, int reg_s2, int offset, int registres[]);

void bne(int reg_s1, int reg_s2, int offset, int registres[]);

void bgtz(int reg_s1, int offset, int registres[]);

void blez(int reg_s1, int offset, int registres[]);


/*il existe déjà une fonction div, d'où le div_2*/
void div_2(int reg_s1, int reg_s2, int registres[]);

void j(int index, int registres[]);

void jal(int index, int registres[]);

void jr(int reg, int registres[]);

void lui(int reg, int var, int registres[]);

void lw(int reg, int base, int offset, int registres[]);

void mfhi(int reg, int registres[]);

void mflo(int reg,int registres[]);

void mult(int reg1, int reg2,int registres[]);

void nop();

void or(int reg_d, int reg_s1, int reg_s2, int registres[]);

/*Testée et fonctionnelle*/
void rotr(int reg_d, int reg_s, int delimit, int registres[]);

void sll(int reg_d, int reg_s, int var, int registres[]);

void slt(int reg_d, int reg_s1, int reg_s2, int registres[]);

void slr(int reg_d, int reg_s, int var, int registres[]);

void sub(int reg_d, int reg_s1, int reg_s2, int registres[]);

void sw(int reg, int base, int offset, int registres[]);

void syscall();