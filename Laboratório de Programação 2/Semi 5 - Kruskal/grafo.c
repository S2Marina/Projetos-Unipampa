#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

Nodo* criaNodo(int chave) {
    Nodo *n = (Nodo*) malloc(sizeof (Nodo));
    n->chave = chave;
    n->prox = NULL;
    n->adj = NULL;
    return n;
}

Aresta* criaAresta(int origem, int destino, int peso) {
    Aresta* a = (Aresta*) malloc(sizeof (Aresta));
    a->chave_partida = origem;
    a->chave_adj = destino;
    a->peso = peso;
    a->prox = NULL;
    return a;
}

Grafo* criaGrafo(int tamanho) {
    int i;

    Grafo *g = (Grafo*) malloc(sizeof (Grafo));
    g->tamanho = tamanho;
    g->listaNodos = NULL;

    for (i = 0; i < tamanho; i++) {
        Nodo* novo = criaNodo(i+1);
        if (g->listaNodos == NULL){
            g->listaNodos = novo;
        } else {
            Nodo *temp = g->listaNodos; //preciso usar temp para não perder o ponteiro do primeiro
            while (temp->prox != NULL) {
                temp = temp->prox;
            }
            temp->prox = novo;
        }
    }
    return g;
}

void insereAresta(Nodo* n, int origem, int destino, int peso) {
    Aresta* a;
    a = criaAresta(origem, destino, peso);
    Aresta *temp = n->adj;

    if(temp == NULL){
        n->adj = a;
    }else{
        while(temp->prox != NULL){
            temp = temp->prox;
        }
        temp->prox = a;
    }
}

Grafo* lerArquivo() {
    FILE *arquivo;
    int tamanho = 0;
    int chave = 0;
    int a = 0;
    int peso = 0;

    if ((arquivo = fopen("entrada.txt", "r")) == NULL) {
        printf("Impossivel realizar a leitura do arquivo. Tente novamente\n");
    }
    fscanf(arquivo, "%d", &tamanho);

    Grafo* g = NULL;
    g = criaGrafo(tamanho);

    while (fscanf(arquivo, "%i;%i;%i", &chave, &a, &peso) != EOF) {
        Nodo* nodo = g->listaNodos;
        while(nodo->chave != chave){
            nodo = nodo->prox;
        }
        insereAresta(nodo, chave, a, peso);
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
    g = lerArquivo();
}
