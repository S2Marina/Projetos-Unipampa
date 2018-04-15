#include <stdio.h>
#include <stdlib.h>
#include "cabecalho.h"

Grafo* criaGrafo() {
  FILE *arquivo;
  int chave = 0;
  int a = 0;
  int peso = 0;
  int tamanho = 0;
  int x = 0;

  if ((arquivo = fopen("entrada.txt", "r")) == NULL) {
    printf("Impossivel realizar a leitura do arquivo. Tente novamente\n");
  }

  fscanf(arquivo, "%d", &tamanho);

  Grafo *g = (Grafo*) malloc(sizeof (Grafo));
  g->tamanho = tamanho;
  g->listaNodos = NULL;

  while (fscanf(arquivo, "%i;%i;%i", &chave, &a, &peso) != EOF) {
    x = verifica(g, chave); //verifica se o nodo já foi inserido

    if (x != 1) {
      Nodo* n = (Nodo*) malloc(sizeof (Nodo));
      n->chave = chave;
      n->prox = NULL;
      n->adj = NULL;

      if (g->listaNodos == NULL) { //primeiro nodo
        g->listaNodos = n;
      } else {
        Nodo* n2 = (Nodo*) malloc(sizeof (Nodo));
        while (n2 == g->listaNodos) {
          n2 = n2->prox;
        }
        n2->prox = n;
      }
    }
    g->listaNodos=g->listaNodos->prox;
  }
  return g;
}

void criaArestas(Grafo* g) {
  FILE *arquivo;
  int chave = 0;
  int adj = 0;
  int peso = 0;
  int tamanho = 0;
  int x = 0;

  Nodo *aux = (Nodo*) malloc(sizeof (Nodo));
  aux = g->listaNodos;
  aux->adj = (Aresta*) malloc(sizeof (Aresta));

  Aresta *a = (Aresta*) malloc(sizeof (Aresta));
  a->prox = (Aresta*) malloc(sizeof (Aresta));
  a->peso = 0;
  a->chave_adj = 0;


  if ((arquivo = fopen("entrada.txt", "r")) == NULL) {
    printf("Impossivel realizar a leitura do arquivo. Tente novamente\n");
  }

  fscanf(arquivo, "%d", &tamanho);

  while (fscanf(arquivo, "%i;%i;%i", &chave, &adj, &peso) != EOF) {
    while (aux != NULL) {
      x = verifica(g, chave); //verifica se o nodo já foi inserido
      if (x != 1) { //se o nodo não foi inserido ainda
        if (aux->chave == chave) {
          a->chave_adj = adj;
          a->peso = peso;
          a->prox = NULL;
          aux->adj = a;
        }
      } else {
        a->chave_adj = adj;
        a->peso = peso;
        a->prox = NULL;
        aux->adj->prox = a;
      }
      aux = aux->prox;
      g->listaNodos=g->listaNodos->prox;

    }
  }
}

void imprimirGrafo(Grafo* g) {
  while (g->listaNodos != NULL) {
    printf("Chave: %i \n", g->listaNodos->chave);
    if (g->listaNodos->adj != NULL) {
      printf("Aresta: %i \n", g->listaNodos->adj->chave_adj);
      printf("Peso: %i \n", g->listaNodos->adj->peso);
      while (g->listaNodos->adj->prox != NULL) {
        printf("Aresta: %i \n", g->listaNodos->adj->chave_adj);
        printf("Peso: %i \n", g->listaNodos->adj->peso);
        g->listaNodos->adj = g->listaNodos->adj->prox;
      }
    } else {
      //sem adj
    }
    g->listaNodos = g->listaNodos->prox;
  }
}

int verifica(Grafo* g, int chave) {
  int x = 0;
  Nodo *aux = g->listaNodos;
  while (aux != NULL) {
    if (aux->chave == chave) { //verifica se o nodo já foi inserido
      x = 1;
    }
    aux = aux->prox;
  }
  return x;
}
