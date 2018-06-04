#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"
#include "heap.h"


Aresta** addHeap(Grafo* g, Aresta** heap, int tamanho){
    Nodo *temp = g->listaNodos;
    while (temp != NULL) {
      printf("\nNodo: %i\n", temp->chave);
        while (temp->adj != NULL) {
            Aresta* aresta = temp->adj;
            printf("%i->%i(%i)\n\n", aresta->chave_partida, aresta->chave_adj, aresta->peso);
            tamanho++;
            heap = buildHeap(heap, tamanho, aresta);
            printHeap(heap, tamanho);
            temp->adj = temp->adj->prox;
        }
        temp = temp->prox;
    }
    return heap;
}
