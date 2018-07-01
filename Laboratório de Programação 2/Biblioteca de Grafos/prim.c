#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"
#include "conjuntos.h"
#include "heap.h"
#include "prim.h"

void prim(Grafo* g) {
    int tamanhoGrafo = g->tamanho, tamanhoHeap = 0, tamanhoSolucao = 0, u = 0, v = 0, i = 0, chave = 0, teste = 0;
    int* conjuntos;
    Aresta** heap = (Aresta**) malloc(sizeof (Aresta));
    Aresta** solucao = (Aresta**) malloc(sizeof (Aresta));
    Aresta*a = (Aresta*) malloc(sizeof (Aresta));
    Nodo *nodo = (Nodo*) malloc(sizeof (Nodo));

    makeSet(tamanhoGrafo, conjuntos);

    printf("Informe o nodo de partida:\n");
    scanf("%i", &chave);
    nodo = buscaNodo(chave, g);

    while (nodo->adj != NULL) { //adiciona suas arestas na heap
        heap = buildHeap(heap, tamanhoHeap, nodo->adj);
        tamanhoHeap = getTamanho();
        nodo->adj = nodo->adj->prox;
    }

    do {
        u = heap[0]->chave_partida; //chave do nodo de partida
        v = heap[0]->chave_adj; //chave do nodo de chegada
        a = heap[0];
        
        printHeap(heap, tamanhoHeap);

        teste = testeSolucao(a, tamanhoSolucao, solucao);
        heap = deleteHeap(heap, tamanhoHeap);
        tamanhoHeap = getTamanho();

        if (findSet(conjuntos[v - 1], conjuntos) != findSet(conjuntos[u - 1], conjuntos) && teste == 0) {
            solucao[i] = a;
            tamanhoSolucao++;
            uniao(conjuntos, u, v);
            printf("\nConjuntos:\n");
            imprimir(conjuntos, tamanhoGrafo);
            nodo = buscaNodo(v, g);
            while (nodo->adj != NULL) { //adiciona suas arestas na heap
                printf("%i->%i(%i)\n", nodo->adj->chave_partida, nodo->adj->chave_adj, nodo->adj->peso);
                heap = buildHeap(heap, tamanhoHeap, nodo->adj);
                tamanhoHeap = getTamanho();
                nodo->adj = nodo->adj->prox;
            }
            printHeap(heap, tamanhoHeap);
            i++;
        }
    } while (tamanhoHeap > 0);
    printSolucaoP(solucao, tamanhoSolucao);
}

Nodo * buscaNodo(int chave, Grafo* g) {
    Nodo * nodo = g->listaNodos;
    while (nodo != NULL) {//encontra o nodo
        if (nodo->chave == chave) {
            break;
        } else {
            nodo = nodo->prox;
        }
    }
    return nodo;
}

int testeSolucao(Aresta* a, int tamanho, Aresta** solucao) {
    int x;
    for (x = 0; x < tamanho; x++) {
        if (solucao[x]->chave_adj == a->chave_adj) {
            return 1;
        }
    }
    return 0;
}

void printSolucaoP(Aresta** solucao, int tamanho) {
    int x = 0;
    printf("Árvore Geradora Mínima:\n");
    printf("Solução Prim: ");
    for (x = 0; x < tamanho; x++) {
        printf("%i<%i,%i>  ", solucao[x]->peso, solucao[x]->chave_partida, solucao[x]->chave_adj);
    }
    printf("\n");
}
