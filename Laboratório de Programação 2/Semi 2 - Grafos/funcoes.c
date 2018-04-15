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
    } else {
      while (g->listaNodos->prox != NULL) {
        g->listaNodos = g->listaNodos->prox;
      }
      g->listaNodos->prox = novo;
    }
  }
  return g;
}

Aresta* insereAresta(Nodo* n, int chave, int peso) {
  Aresta* a;
  a = criaAresta();

  a->chave_adj = chave;
  a->peso = peso;
  a->prox = NULL;

  while (n->adj->prox != NULL) {
    n->adj = n->adj->prox;
  }
  n->adj = a;

  return a;
}

Grafo* lerArquivo(){
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

void imprimirGrafo(Grafo* g){

}
