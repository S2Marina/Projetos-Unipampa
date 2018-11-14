/*
// Lista 05
// 13/10/2017
// Gabriel Porto Oliveira (patonoideoriginal@gmail.com), Marina Silva da Silva (marina_silva98@hotmail.com).
 */

#include <stdio.h>
#include <stdlib.h>
#include "cabecalho.h"

//funcoes fila com lista:

FilaD * filadCria() {
    FilaD * f = (FilaD *) malloc(sizeof (FilaD));
    f->ini = f->fim = NULL;
    return f;
}

void filadInsere(FilaD* f, float v) {
    Lista * novo = (Lista *) malloc(sizeof (Lista));
    novo-> info = v;
    novo-> prox = NULL;
    if (f->fim == NULL && f-> ini == NULL) {
        f->ini = novo;
        f->fim = novo;
    } else {
        f->fim->prox = novo;
        f-> fim = novo;
    }
}

float filadRetira(FilaD * f) {
    Lista * t;
    float v;
    if (f-> fim == NULL && f-> ini == NULL) {
        printf(" esta vazio...");
        exit(1);

    }
    t = f->ini;
    v = t->info;
    f->ini = t->prox;
    if (f->ini == NULL) {
        f->fim = NULL;
    }
    free(t);
    return v;
}

void filadLibera(FilaD * f) {
    Lista * q = f-> ini;
    while (q != NULL) {
        Lista * t = q -> prox;
        free(q);
        q = t;

    }
    
    free(f);
}

void filadImprime(FilaD* f) {
    Lista * q = f->ini;
    Lista * p;
    
    for (p = q; p != NULL; p = p->prox) {
        printf("\n%.2f", p->info);
    }
    printf("\n");

}

//funções pilha

Pilha * criaPilha () {
    Pilha * p = (Pilha *) malloc(sizeof (Pilha));
    p->n = 0;
    return p;
}

void pilhaPush(Pilha * p, float valor) {
    if (p->n < 10) {
        p->vet[p->n] = valor;
        p->n++;
    } else {
        printf("A pilha está cheia!!!");
    }
}

float pilhaPop(Pilha  *p) {
    float valorRemovido = 0.0;

    if (p->n > 0) {
        valorRemovido = p->vet[p->n - 1];
        p->n--;
    } else {
        printf("A pilha está vazia!!!");
    }

    return valorRemovido;
}

void liberaPilha (Pilha * p) {
    free(p);
}

//funcoes fila com vetores

FilaV * filavCria() {
    FilaV * f = (FilaV*) malloc(sizeof (FilaV));
    f->n = 0;
    f->ini = 0;
    return f;
}

void filavInsere(FilaV* f, float v) {
    int fim;
    if (f->n != 10) {
        fim = (f->ini + f->n) % 10;
        f->vet[fim] = v;
        f->n++;

    } else {
        printf("cheia");
        exit(1);
    }
}

float filavRetira(FilaV * f) {
    float v;
    if (f->n != 0) {
        v = f-> vet[f-> ini ];
        f->n--;
        f->ini = (f->ini + 1) % 10;
        return v;
    } else {
        printf("vazia");
        exit(1);
    }
}

void filavImprime(FilaV * f) {
    int i, cont = 0;
    for (i = 0; i < f->n; i++) {
        printf("\n%.2f", f->vet[((f->ini + i) % 10)]);
        cont++;
    }
    if (cont == 0) {
        printf("\n A fila esta vazia!!");
    }
}

void filavLibera(FilaV *f) {
    int i;
    for (i = 0; i < f->n; i++) {
        free(f);
    }
    f->n = 0;
}

void inverter(FilaV *f){
    Pilha *p = criaPilha();
    int x;
    int n = f->n;   
    
    for(x=0;x<n;x++){
        pilhaPush(p, filavRetira(f));
    }
    
    for(x=0;x<n;x++){
        filavInsere(f, pilhaPop(p));
    }
    
    liberaPilha(p);   
}

