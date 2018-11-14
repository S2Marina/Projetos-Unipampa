/*
// Lista 04: Calculadora
// 05/10/2017
// Gabriel Porto Oliveira (patonoideoriginal@gmail.com), Marina Silva da Silva (marina_silva98@hotmail.com).
 */

#include <stdio.h>
#include <stdlib.h>
#include "cabecalho.h"

//funções pilha de operadores

PilhaOp * criaPilhaOp() {
    PilhaOp *p = (PilhaOp*) malloc(sizeof (PilhaOp));
    p->n = 0;
    p->prim = NULL;
    return p;
}

void pilhaOpPush(PilhaOp * p, char c) {
    Lista *novo = (Lista*) malloc(sizeof (Lista));
    novo->info = c;
    novo->prox = p->prim;
    p->prim = novo;
    p->n++;
}

char pilhaOpPop(PilhaOp * p) {
    Lista *aux;
    char c;
    if (p->prim != NULL) {
        aux = p->prim;
        c = aux->info;
        p->prim = aux->prox;
        free(aux);
        p->n--;
    } else {
        printf("A pilha está vazia!!!");
    }
    return c;
}

void liberaPilhaOp(PilhaOp * p) {
    Lista *tmp, *aux = p->prim;
    while (aux != NULL) {
        tmp = aux->prox;
        free(aux);
        aux = tmp;
    }
    free(p);
}

void imprimePilhaOp(PilhaOp * p) {
    Lista *aux;
    printf("Pilha de Operadores:\n");
    for (aux = p->prim; aux != NULL; aux = aux->prox) {
        printf(" %c \n", aux->info);
        
    }
}


//funções pilha de valores

PilhaFloat * criaPilhaFloat() {
    PilhaFloat* p = (PilhaFloat*) malloc(sizeof (PilhaFloat));
    p->n = 0;
    return p;
}

void pilhaFloatPush(PilhaFloat * p, float valor) {
    if (p->n < 20) {
        p->vet[p->n] = valor;
        p->n++;
    } else {
        printf("A pilha está cheia!!!");
    }
}

float pilhaFloatPop(PilhaFloat *p) {
    float valorRemovido = 0.0;

    if (p->n > 0) {
        valorRemovido = p->vet[p->n - 1];
        p->n--;
    } else {
        printf("A pilha está vazia!!!");
    }

    return valorRemovido;
}

void liberaPilhaFloat(PilhaFloat * p) {
    free(p);
}

void imprimePilhaFloat(PilhaFloat * p) {
    int n, x;
    n = p->n;

    printf("Pilha de Valores\n");
    for (x = 0; x < n; x++) {
        printf(" %.2f \n", p->vet[x]);
    }
}

//funções calculadora

Calc *criaCalculadora() {
    Calc *cal;
    cal->operadores = criaPilhaOp();
    cal->valores = criaPilhaFloat();

    return cal;
}

void imprimeCalc(Calc *cal) {
    imprimePilhaFloat(cal->valores);
    imprimePilhaOp(cal->operadores);
}

void insereOp(Calc * cal, char c) {
    if (c == '+' || c == '-' || c == '*' || c == '/') {
        pilhaOpPush(cal->operadores, c);
        printf("Operador inserido com sucesso!!!");
    } else {
        printf("Operador invalido!!!");
    }
}

void insereValor(Calc * cal, float valor) {
    pilhaFloatPush(cal->valores, valor);
    printf("Valor inserido com sucesso!!!");
}

void realizaCalc(Calc * cal) {
    float v, v2;
    char op;
    float res = 0.0;

    if (cal->operadores->n > 0 && cal->valores->n > 1) {
        op = pilhaOpPop(cal->operadores);
        v = pilhaFloatPop(cal->valores);
        v2 = pilhaFloatPop(cal->valores);

        switch (op) {
            case '+':
            {
                res = v + v2;
                break;
            }
            case '-':
            {
                res = v - v2;
                break;
            }
            case '*':
            {
                res = v * v2;
                break;
            }
            case '/':
            {
                res = v / v2;
                break;
            }
            default:
            {
                printf("ERRO");
                break;
            }
        }
        if (v2 == 0 && op == '/') { 
            printf("Nao e possivel dividir por 0\n");
        }else{
            printf("Resultado da operacao %.2f %c %.2f = %.2f", v, op, v2, res);
        }

    } else {
        printf("Nao foi possivel realizar a operacao!!!");
    }

}