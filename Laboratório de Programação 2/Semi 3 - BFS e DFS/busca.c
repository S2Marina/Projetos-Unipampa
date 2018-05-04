#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"
#include "busca.h"

//funcoes pilha

Pilha * criaPilha() {
    Pilha *p = (Pilha*) malloc(sizeof (Pilha));
    p->tamanho = 0;
    p->prim = NULL;
    return p;
}

void pilhaPush(Pilha * p, Nodo* n) {
    Lista *novo = (Lista*) malloc(sizeof (Lista));
    novo->info = n;
    novo->prox = p->prim;
    p->prim = novo;
    p->tamanho++;
}

Nodo* pilhaPop(Pilha * p) {
    Lista *aux;
    Nodo* n;
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
        printf(" %i \n", aux->info->chave);

    }
}

//funcoes fila

Fila * criaFila() {
    Fila * f = (Fila *) malloc(sizeof (Fila));
    f->ini = f->fim = NULL;
    f->tamanho = 0;
    return f;
}

void filaInsere(Fila* f, Nodo* n) {
    Lista * novo = (Lista *) malloc(sizeof (Lista));
    novo-> info = n;
    novo-> prox = NULL;
    if (f->fim == NULL && f-> ini == NULL) {
        f->ini = novo;
        f->fim = novo;
    } else {
        f->fim->prox = novo;
        f-> fim = novo;
    }
    f->tamanho++;
}
Nodo* filaRetira(Fila * f) {
    Lista * t;
    Nodo* n;
    if (f-> fim == NULL && f-> ini == NULL) {
        printf(" esta vazio...");
        exit(1);

    }
    t = f->ini;
    n = t->info;
    f->ini = t->prox;
    if (f->ini == NULL) {
        f->fim = NULL;
    }
    free(t);
    f->tamanho--;
    return n;
}

void liberaFila(Fila * f) {
    Lista * q = f-> ini;
    while (q != NULL) {
        Lista * t = q -> prox;
        free(q);
        q = t;
    }
    free(f);
}

void imprimeFila(Fila* f) {
    Lista * q = f->ini;
    Lista * p;
    
    for (p = q; p != NULL; p = p->prox) {
        printf("\n%i", p->info->chave);
    }
    printf("\n");

}


//buscas

void dfs(Grafo* g) {
    Nodo* temp = g->listaNodos;
    int* solucao = malloc(sizeof (int) * g->tamanho);
    int x = 0, y = 0, z = 0, visitado;
    Pilha* pilha = criaPilha();
    pilhaPush(pilha, temp);
    Nodo* nodo = NULL;
    Aresta* adj = NULL;

    while (pilha->tamanho != 0) {
        nodo = pilhaPop(pilha); //retira nodo da pilha (visita)
        solucao[x] = nodo->chave; //adiciona ao conjunto solucao
       
        //percorre as adjacencias do nodo visitado
        adj = nodo->adj;

        if (adj != NULL) {
            y = 1;
        }
        while (y == 1) {
            //adicionar nodo adjacente na pilha
            temp = g->listaNodos;

            while (temp->chave != adj->chave_adj) { //procuro pelo nodo correspondente a chave_adj
                temp = temp->prox;
            }

            visitado = 0;
            for (z = 0; z < x; z++) { //verifica se o nodo ja foi visitado
                if (solucao[z] == temp->chave) {
                    visitado = 1;
                }
            }

            if (visitado != 1) { //se nao foi visitado 
                pilhaPush(pilha, temp); //adiciono na pilha
            }

            if (adj->prox != NULL) {
                adj = adj->prox;
            } else { //se nao houver mais adjacencias, saio do while
                y = 0;
            }
        }
        x++;
    }

    for (y = 0; y < x; y++) {
        printf("%i \n", solucao[y]);
    }
}

void bfs(Grafo* g){
    Nodo* temp = g->listaNodos;
    int* solucao = malloc(sizeof (int) * g->tamanho);
    int x = 0, y = 0, z = 0, visitado;
    Fila* fila = criaFila();
    filaInsere(fila, temp);
    Nodo* nodo = NULL;
    Aresta* adj = NULL;

    while (fila->tamanho != 0) {
        nodo = filaRetira(fila); //retira nodo da pilha (visita)
        solucao[x] = nodo->chave; //adiciona ao conjunto solucao
       
        //percorre as adjacencias do nodo visitado
        adj = nodo->adj;

        if (adj != NULL) {
            y = 1;
        }
        while (y == 1) {
            //adicionar nodo adjacente na pilha
            temp = g->listaNodos;

            while (temp->chave != adj->chave_adj) { //procuro pelo nodo correspondente a chave_adj
                temp = temp->prox;
            }

            visitado = 0;
            for (z = 0; z < x; z++) { //verifica se o nodo ja foi visitado
                if (solucao[z] == temp->chave) {
                    visitado = 1;
                }
            }

            if (visitado != 1) { //se nao foi visitado 
                filaInsere(fila, temp); //adiciono na pilha
            }

            if (adj->prox != NULL) {
                adj = adj->prox;
            } else { //se nao houver mais adjacencias, saio do while
                y = 0;
            }
        }
        x++;
    }

    for (y = 0; y < x; y++) {
        printf("%i \n", solucao[y]);
    }
}