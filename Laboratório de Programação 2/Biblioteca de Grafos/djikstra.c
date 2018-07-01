#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "grafo.h"
#include "heap.h"
#include "conjuntos.h"
#include "busca.h"
#include "djikstra.h"


void djikstra(Grafo* g) {
    int x = 0, tamanhoHeap = 0, tamanhoSolucao = 0, testeS = 0, i = 0, u = 0, v = 0;
    int* peso = (int*) malloc(sizeof (int));
    int* anterior = (int*) malloc(sizeof (int));
    Fila* vertices = criaFila(); //esquece isso, fazer com heap
    Nodo* nodo = g->listaNodos;
    Aresta** solucao = (Aresta**) malloc(sizeof (Aresta));
    Aresta** heap = (Aresta**) malloc(sizeof (Aresta));

    while (nodo->prox != NULL) { //inicializa tudo bonitinho
        filaInsere(vertices, nodo);
        peso[x] = INT_MAX;
        anterior[x] = -1;
        nodo = nodo->prox;
    }

    nodo = filaRetira(vertices);

    while (nodo->adj != NULL) { //adiciona as arestas do primeiro nodo na heap
//        heap = buildHeap(heap, 1, nodo->adj);
        tamanhoHeap++;
        nodo->adj = nodo->adj->prox;
    }

    printHeap(heap, tamanhoHeap);

    do {
        u = heap[0]->chave_adj;
        v = heap[0]->chave_partida;

        testeS = pertenceSolucao(u, solucao, tamanhoSolucao); //testa se o nodo de origem da aresta ta na solucao
        if (testeS == 0) {//se aresta que parte do nodo não ta na solucao
            solucao[i] = heap[0]; //adiciona aresta na solucao
        }
        testeS = pertenceSolucao(v, solucao, tamanhoSolucao); //testo se o proximo nodo esta na solucao
        if (peso[i + 1] > peso[i] + heap[0]->peso && (testeS == 0)) {
            anterior[i + 1] = u;
            nodo = filaRetira(vertices);
            while (nodo->adj != NULL) { //adiciona as arestas do proximo nodo na heap
//                heap = buildHeap(heap, tamanhoHeap, nodo->adj);
                tamanhoHeap++;
                nodo->adj = nodo->adj->prox;
            }
        }
        i++;
        printHeap(heap, tamanhoHeap);
        imprimeFila(vertices);
    } while (tamanhoHeap > 0);
}

int pertenceSolucao(int chave, Aresta** solucao, int tamanho) {
    int x = 0, retorno = 0;
    for (x = 0; x < tamanho; x++) {
        if (solucao[x]->chave_partida == chave) { //se esta na solucao
            retorno = 1; //retorna um
        }
    }
    return retorno;
}
