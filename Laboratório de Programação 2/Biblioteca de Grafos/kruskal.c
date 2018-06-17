#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"
#include "heap.h"
#include "conjuntos.h"
#include "kruskal.h"

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
    Aresta** solucao = (Aresta**) malloc(sizeof (Aresta));
    int* conjuntos;
    int tamanhoGrafo = g->tamanho;
    int tamanhoSolucao = 0;
    int tamanhoHeap = 0, u = 0, v = 0, i = 0, parar = 0;

    //cria conjuntos
    conjuntos = makeSet(tamanhoGrafo);
    //imprimir(conjuntos,g->tamanho);

    //adicionar arestas na heap
    heap = addHeap(g, heap, tamanhoHeap);
    tamanhoHeap = getTamanho(heap);

    do {
        u = heap[0]->chave_partida;
        v = heap[0]->chave_adj;

        if (findSet(conjuntos[v], conjuntos) != findSet(conjuntos[u], conjuntos)) { //findSet
            solucao[i] = heap[0];
            tamanhoSolucao++;
            uniao(conjuntos, u, v);
            tamanhoHeap--;
            heap = deleteHeap(heap, tamanhoHeap);
            printHeap(heap, tamanhoHeap);
            i++; //posição do vetor solução
            printf("\nConjuntos:");
            imprimir(conjuntos, tamanhoGrafo);
        }
        parar = testeFim(conjuntos, tamanhoGrafo);
    } while (parar == 0);
    printSolucao(solucao,tamanhoSolucao);
}

int testeFim(int* conj, int tamanho) {
    int parar = 1, x = 0;
    for (x = 1; x < tamanho; x++) {
        if (conj[x] != conj[x + 1]) {
            parar = 0;
        }
    }
    return parar;
}

void printSolucao(Aresta** solucao, int tamanho){
    int x=0;
    printf("Árvore Geradora Mínima:\n");
    printf("Solução Kruskal: ");
    for(x=0;x<tamanho;x++){
        printf("%i<%i,%i>  ", solucao[x]->peso, solucao[x]->chave_partida, solucao[x]->chave_adj);
    }
    printf("\n");
}
