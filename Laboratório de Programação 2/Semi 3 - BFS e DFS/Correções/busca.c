#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"
#include "busca.h"

Pilha * criaPilha() {
    Pilha *p = (Pilha*) malloc(sizeof (Pilha));
    p->tamanho = 0;
    p->prim = NULL;
    return p;
}

void pilhaPush(Pilha * p, int n) {
    Lista *novo = (Lista*) malloc(sizeof (Lista));
    novo->info = n;
    novo->prox = p->prim;
    p->prim = novo;
    p->tamanho++;
}

int pilhaPop(Pilha * p) {
    Lista *aux;
    int n;
    if (p->prim != NULL) {
        aux = p->prim;
        n = aux->info;
        p->prim = aux->prox;
        free(aux);
        p->tamanho--;
    } else {
        printf("A pilha está vazia!!!");
    }
    return n;
}

void liberaPilha(Pilha * p) {
    Lista *tmp, *aux = p->prim;
    while (aux != NULL) {
        tmp = aux->prox;
        free(aux);
        aux = tmp;
    }
    free(p);
}

void imprimePilha(Pilha * p) {
    Lista *aux;
    printf("Pilha:\n");
    for (aux = p->prim; aux != NULL; aux = aux->prox) {
        printf(" %i \n", aux->info);

    }
}

void dfs(Nodo* nodo) {
    Pilha* pilha = criaPilha();
		//seria necessário inserir o ponto de partida da busca na pilha
    //while (nodo->prox != NULL) { //o laço da dfs é sobre a pilha, ou seja, enquanto a pilha possue alguém para navegar chama a busca.
  //      pilhaPush(pilha, nodo->chave); //retira um elemento da pilha, marca como visitado (colocar na solução)
										//e verifica suas adjacencias para serem adicionados na pilha de nodos a serem visitados
        while (nodo->adj != NULL) { //para cada adjacencia se ainda não foi visitado adiciona na pilha
//            pilhaPush(pilha, nodo->adj->chave_adj);
 //           nodo->adj = nodo->adj->prox;
        }
 //       nodo = nodo->prox;
    //}
//    imprimePilha(pilha);
}
