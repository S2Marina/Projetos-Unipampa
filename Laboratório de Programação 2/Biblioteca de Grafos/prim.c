#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"
#include "conjuntos.h"
#include "heap.h"
#include "prim.h"

void prim(Grafo* g) {
    int tamanhoGrafo = g->tamanho, tamanhoHeap = 0, tamanhoSolucao = 0, u = 0, v = 0, i = 0, parar = 0;
    int* conjuntos;
    Aresta** heap = (Aresta**) malloc(sizeof (Aresta));
    Aresta** solucao = (Aresta**) malloc(sizeof (Aresta));
    Nodo *nodo = g->listaNodos;

    conjuntos = makeSet(tamanhoGrafo);

   //infomar nodo de partida
    nodo = buscaNodo(conjuntos[1], nodo); //busca o primeiro nodo
    while (nodo->adj != NULL) { //adiciona suas arestas na heap
        heap = buildHeap(heap, 1, nodo->adj);
        tamanhoHeap++;
        nodo->adj = nodo->adj->prox;
    }

    do {
        u = heap[0]->chave_partida; //chave do nodo de partida
        v = heap[0]->chave_adj; //chave do nodo de chegada

        if (conjuntos[v] != conjuntos[u]) {
            solucao[i] = heap[0];
            tamanhoSolucao++;
            uniao(conjuntos, u, v);
           // printf("\nConjuntos:\n");
            //imprimir(conjuntos, tamanhoGrafo);
            nodo = buscaNodo(v, nodo);
            tamanhoHeap--;
            heap = deleteHeap(heap, tamanhoHeap);
            while (nodo->adj != NULL) { //adiciona suas arestas na heap
               // printf("%i->%i(%i)\n", nodo->adj->chave_partida, nodo->adj->chave_adj, nodo->adj->peso);
                tamanhoHeap++;
                heap = buildHeap(heap, tamanhoHeap, nodo->adj);
                nodo->adj = nodo->adj->prox;
            }
            //printHeap(heap, tamanhoHeap);
            i++;
        }
        parar = testeFimP(conjuntos, tamanhoGrafo);
    } while (parar == 0);
    printSolucaoP(solucao, tamanhoSolucao);
}

Nodo * buscaNodo(int chave, Nodo* nodo) {
    while (nodo != NULL) {//encontra o nodo
        if (nodo->chave == chave) {
            break;
        } else {
            nodo = nodo->prox;
        }
    }
    return nodo;
}

int testeFimP(int* conj, int tamanho) {
    int parar = 1, x = 0;
    for (x = 1; x < tamanho; x++) {
        if (conj[x] != conj[x + 1]) {
            parar = 0;
        }
    }
    return parar;
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
