#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "grafo.h"
#include "heap.h"
#include "conjuntos.h"
#include "busca.h"
#include "djikstra.h"

void djikstra(Grafo* g) {
    int x = 0, tamanhoHeap = 0, tamanhoSolucao = 0, testeS = 0, i = 0, chegada = 0, partida = 0, chave = 0;
    int* peso = (int*) malloc(sizeof (int));
    int* anterior = (int*) malloc(sizeof (int));
    Nodo* nodo = g->listaNodos;
    Aresta* a = (Aresta*) malloc (sizeof(Aresta));
    Aresta** solucao = (Aresta**) malloc(sizeof (Aresta));
    Aresta** heap = (Aresta**) malloc(sizeof (Aresta));

    while (nodo->prox != NULL) { //inicializa tudo bonitinho
        peso[x] = INT_MAX;
        anterior[x] = -1;
        nodo = nodo->prox;
    }

    printf("Informe o nodo de partida:\n");
    scanf("%i", &chave);
    nodo = buscaNodoD(chave, g);

    while (nodo->adj != NULL) { //adiciona suas arestas na heap
        heap = buildHeap(heap, tamanhoHeap, nodo->adj);
        tamanhoHeap = getTamanho();
        nodo->adj = nodo->adj->prox;
    }
    if (tamanhoHeap == 0) {
        printf("Nodo sem adjacencias!\n");
    }

    printHeap(heap, tamanhoHeap);


    while (tamanhoHeap > 0) {
        a = heap[0];
        chegada = a->chave_adj;
        partida = a->chave_partida;
        heap = deleteHeap(heap, tamanhoHeap);
        tamanhoHeap = getTamanho();

        //testa se o nodo de origem da aresta ta na solucao
        if (!pertenceSolucao(chegada, solucao, tamanhoSolucao)) {//se aresta que parte do nodo não ta na solucao
            solucao[i] = a; //adiciona aresta na solucao
            printf("add solucao: %i->%i\n", a->chave_partida, a->chave_adj);
        }
         //testo se o proximo nodo esta na solucao
        if (peso[i + 1] > peso[i] + a->peso && !pertenceSolucao(chegada, solucao, tamanhoSolucao)) {
            anterior[i + 1] = chegada;
            peso[i + 1] = peso[i] + a->peso;
            nodo = buscaNodoD(chegada,g);
            while (nodo->adj != NULL) { //adiciona as arestas do proximo nodo na heap
                heap = buildHeap(heap, tamanhoHeap, nodo->adj);
                tamanhoHeap = getTamanho();
                nodo->adj = nodo->adj->prox;
            }
        }
        i++;
        printHeap(heap, tamanhoHeap);
    }
}

int pertenceSolucao(int chave, Aresta** solucao, int tamanho) {
    int x = 0, retorno = 0;
    for (x = 0; x < tamanho; x++) {
        if (solucao[x]->chave_partida == chave || solucao[x]->chave_adj) { //se esta na solucao
            retorno = 1; //retorna um
        }
    }
    return retorno;
}

Nodo * buscaNodoD(int chave, Grafo* g) {
    g = lerArquivo();
    Nodo * nodo = g->listaNodos;
    while (nodo != NULL) {
        if (nodo->chave == chave) {
            return nodo;
        }
        nodo = nodo->prox;
    }
    return NULL;
}
