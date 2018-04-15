#include <stdio.h>
#include <stdlib.h>
#include "cabecalho.h"

Nodo* criaNodo() {
    Nodo *n = (Nodo*) malloc(sizeof (Nodo));
    n->chave = 0;
    n->prox = NULL;
    n->adj = NULL;
}

Aresta* criaAresta() {
    Aresta* a = (Aresta*) malloc(sizeof (Aresta));
    a->chave_adj = 0;
    a->peso = 0;
    a->prox = NULL;
}

Grafo* criaGrafo() {
    FILE *arquivo;
    int i, tamanho = 0;
    Nodo * raiz;

    if ((arquivo = fopen("entrada.txt", "r")) == NULL) {
        printf("Impossivel realizar a leitura do arquivo. Tente novamente\n");
    }
    fscanf(arquivo, "%d", &tamanho);

    Grafo *g = (Grafo*) malloc(sizeof (Grafo));
    g->tamanho = tamanho;
    g->listaNodos = NULL;

    for (i = 0; i < tamanho; i++) {
        Nodo* novo = criaNodo();
        if (g->listaNodos == NULL) {
            g->listaNodos = novo;
            raiz = novo;
        } else {
            while (g->listaNodos->prox != NULL) {
                g->listaNodos = g->listaNodos->prox;
            }
            g->listaNodos->prox = novo;
        }
    }

    g->listaNodos = raiz;
    return g;
}

Aresta* insereAresta(Nodo* n, int chave, int peso) {
    Aresta* a;
    a = criaAresta();

    a->chave_adj = chave;
    a->peso = peso;
    a->prox = NULL;

    while (n->adj != NULL) {
        if (n->adj == NULL) {
            n->adj = a;
            return a;
        }
        n->adj = n->adj->prox;
    }

    return a;
}

Grafo* lerArquivo() {
    FILE *arquivo;
    int tamanho = 0;
    int chave = 0;
    int a = 0;
    int peso = 0;

    Grafo* g = NULL;
    g = criaGrafo();
    Nodo* nodo = g->listaNodos;

    if ((arquivo = fopen("entrada.txt", "r")) == NULL) {
        printf("Impossivel realizar a leitura do arquivo. Tente novamente\n");
    }
    fscanf(arquivo, "%d", &tamanho);

    while (fscanf(arquivo, "%i;%i;%i", &chave, &a, &peso) != EOF) {
        nodo->chave = chave;
        nodo->adj = insereAresta(nodo, a, peso);

        nodo = nodo->prox;
    }
    fclose(arquivo);
    return g;
}

void imprimirGrafo(Grafo* g) {
    Nodo* nodo = g->listaNodos;
    printf("%i\n", g->tamanho);
    while (nodo != NULL) {
        printf("%i", nodo->chave);
        while (nodo->adj != NULL) {
            printf("->%i", nodo->adj->chave_adj);
            printf("(%i)", nodo->adj->peso);
            nodo->adj = nodo->adj->prox;
        }
        printf("\n");
        nodo = nodo->prox;
    }
}
