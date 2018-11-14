struct lista {
    char info;
    struct lista * prox;
}; typedef struct lista Lista;

struct pilhaOp {
    Lista * prim;
    int n;
}; typedef struct pilhaOp PilhaOp;

struct pilhaFloat {
    float vet[20];
    int n;
}; typedef struct pilhaFloat PilhaFloat;

struct calculadora {
    PilhaFloat * valores;
    PilhaOp * operadores;
}; typedef struct calculadora Calc;

PilhaOp * criapilhaOp();
void pilhaOpPush(PilhaOp * p, char c);
char pilhaOpPop(PilhaOp * p);
void liberapilhaOp(PilhaOp * p);
void imprimepilhaOp(PilhaOp * p);
PilhaFloat * criapilhaFloat();
void pilhaFloatPush(PilhaFloat * p, float valor);
float pilhaFloatPop(PilhaFloat * p);
void liberapilhaFloat(PilhaFloat * p);
void imprimepilhaFloat(PilhaFloat * p);
Calc * criaCalculadora();
void imprimeCalc(Calc *cal);
void insereOp(Calc * cal, char c);
void insereValor(Calc * cal, float valor);
void realizaCalc(Calc * cal);









