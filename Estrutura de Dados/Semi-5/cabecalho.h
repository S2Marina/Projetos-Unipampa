#include <stdio.h>
#include <stdlib.h>

struct pilha {
    float vet[10];
    int n;
}; typedef struct pilha Pilha;

struct lista {
    float info;
    struct lista* prox;
};
typedef struct lista Lista;

struct filad {
    Lista * ini;
    Lista *fim;
};
typedef struct filad FilaD;

struct filav {
    int n;
    int ini;
    float vet[10];

};
typedef struct filav FilaV;


void filadImprime(FilaD* f);
FilaD * filadCria();
void filadInsere(FilaD* f, float v);
float filadRetira(FilaD * f);
void filadLibera(FilaD * f);
FilaV * filavCria();
void filavInsere(FilaV* f, float v);
float filavRetira(FilaV * f);
void filavImprime(FilaV * f);
void filadImprime(FilaD* f);
void filavLibera(FilaV *f);
void inverter(FilaV *f);
Pilha * criapilha();
void pilhaPush(Pilha * p, float valor);
float pilhaPop(Pilha * p);
void liberapilha(Pilha * p);