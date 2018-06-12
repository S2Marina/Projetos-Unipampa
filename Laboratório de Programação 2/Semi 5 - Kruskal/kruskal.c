#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"
#include "heap.h"
#include "conjuntos.h"

Aresta** addHeap(Grafo* g, Aresta** heap, int tamanho) {
    Nodo *temp = g->listaNodos;
    while (temp != NULL) {
        // printf("\nNodo: %i\n", temp->chave);
        while (temp->adj != NULL) {
            Aresta* aresta = temp->adj;
            //printf("%i->%i(%i)\n\n", aresta->chave_partida, aresta->chave_adj, aresta->peso);
            tamanho++;
            heap = buildHeap(heap, tamanho, aresta);
            temp->adj = temp->adj->prox;
        }
        temp = temp->prox;
    }
    return heap;
}

void kruskal(Grafo* g) {
    Aresta** heap = (Aresta**) malloc(sizeof (Aresta));
    Aresta** solucao =  (Aresta**) malloc(sizeof (Aresta));
    int* conjuntos;    
    int tamanho = 0, u = 0, v = 0, i = 0;

    //cria conjuntos 
    conjuntos = makeSet(g->tamanho);
    //imprimir(conjuntos,g->tamanho);

    //adicionar arestas na heap
    heap = addHeap(g, heap, tamanho);
    tamanho = getTamanho(heap);

    do {
        u = heap[0]->chave_partida;
        v = heap[0]->chave_adj;
        printf("%i->%i\n",u, v);

        printf("conjuntos u: % i \n", conjuntos[u]);
        printf("conjuntos v: % i \n", conjuntos[v]);
        if (conjuntos[v] != conjuntos[u]) {
            solucao[i] = heap[0];
            uniao(conjuntos, u, v);
            tamanho--;
            heap = deleteHeap(heap, tamanho);
            printHeap(heap, tamanho);
            i++; //posição do vetor solução
            printf("\nConjuntos:");
            imprimir(conjuntos, g->tamanho);
        }
    } while (getTamanho(heap) > 0);
}