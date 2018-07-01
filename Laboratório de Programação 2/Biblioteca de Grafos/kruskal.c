#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"
#include "heap.h"
#include "conjuntos.h"
#include "kruskal.h"

Aresta ** addHeap(Grafo* g, Aresta** heap, int tamanho) {
    Nodo *temp = g->listaNodos;
    while (temp != NULL) {
        while (temp->adj != NULL) {
            Aresta* aresta = temp->adj;
            heap = buildHeap(heap, tamanho, aresta);
            tamanho = getTamanho();
            temp->adj = temp->adj->prox;
        }
        temp = temp->prox;
    }
    return heap;
}

void kruskal(Grafo* g) {
    Aresta** heap = (Aresta**) malloc(sizeof (Aresta));
    Aresta** solucao = (Aresta**) malloc(sizeof (Aresta));
    Aresta* a = (Aresta*) malloc(sizeof (Aresta));
    int* conjuntos;
    int tamanhoGrafo = g->tamanho;
    int tamanhoSolucao = 0;
    int tamanhoHeap = 0, u = 0, v = 0, i = 0, parar = 0;

    //cria conjuntos
    makeSet(tamanhoGrafo, conjuntos);
    //imprimir(conjuntos,g->tamanho);

    //adicionar arestas na heap
    heap = addHeap(g, heap, tamanhoHeap);
    tamanhoHeap = getTamanho();
    printf("COMECO\n");
    printHeap(heap, tamanhoHeap);
    
    do {
        u = findSet(heap[0]->chave_partida, conjuntos);
        v = findSet(heap[0]->chave_adj, conjuntos);
        a = heap[0];
        
        heap = deleteHeap(heap, tamanhoHeap);
        tamanhoHeap = getTamanho();
        printHeap(heap, tamanhoHeap);

        if (findSet(conjuntos[v-1], conjuntos) != findSet(conjuntos[u-1], conjuntos)) { //findSet 
            solucao[i] = a;
            tamanhoSolucao++;
            uniao(conjuntos, u, v);
            i++; //posição do vetor solução
            printf("\nConjuntos:");
            imprimir(conjuntos, tamanhoGrafo);
        }
    } while (tamanhoHeap > 0);
    printSolucao(solucao, tamanhoSolucao);
}

void printSolucao(Aresta** solucao, int tamanho) {
    int x = 0;
    printf("Árvore Geradora Mínima:\n");
    printf("Solução Kruskal: ");
    for (x = 0; x < tamanho; x++) {
        printf("%i<%i,%i>  ", solucao[x]->peso, solucao[x]->chave_partida, solucao[x]->chave_adj);
    }
    printf("\n");
}
