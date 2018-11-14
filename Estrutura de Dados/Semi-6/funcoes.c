/*
// Lista 06
// 30/10/2017
// Gabriel Porto Oliveira (patonoideoriginal@gmail.com), Marina Silva da Silva (marina_silva98@hotmail.com).
 */

#include "cabecalho.h"          
#include <stdio.h>
#include <stdlib.h>

Arvore * treeVazia() {
    return NULL;
}

/*
Arvore * cria(int valor, Arvore * sae, Arvore * sad) {
    Arvore * p = (Arvore *) malloc(sizeof (Arvore));
    p->info = valor;
    p->esq = sae;
    p->dir = sad;
    return p;
}
 */

Arvore * insere(Arvore * a, int valor) {
    if (a == NULL) {
        a = (Arvore *) malloc(sizeof (Arvore));
        a->info = valor;
        a->dir = NULL;
        a->esq = NULL;
    } else {
        if (valor < a->info) {
            
            a->esq = insere(a->esq, valor);
        } else {
            
            a->dir = insere(a->dir, valor);
        }
    }
    return a;
}

Arvore * excluir(Arvore * a, int valor) {
    if (a == NULL) { //vazia
        return NULL;
    } else {
        if (valor < a->info) { //exclui sae
            a->esq = excluir(a->esq, valor);
        } else {
            if (valor > a->info) { // exclui sad
                a->dir = excluir(a->dir, valor);
            } else {
                if (a->esq == NULL && a->dir == NULL) { //não tem filhos 
                    free(a);
                    return NULL;
                } else {
                    if (a->dir == NULL) { //não tem filho na direita
                        Arvore * aux = a;
                        a = a->esq; //ve se tem na esquerda
                        free(aux);
                    } else {
                        if (a->esq == NULL) { //não tem filho na esquerda
                            Arvore * aux = a;
                            a = a->dir; //ve se tem na direita
                            free(aux);
                        } else { //arvore tem dois filhos
                            Arvore * temp = a->esq;
                            while (temp->dir != NULL) {
                                temp = temp->dir;
                            }
                            a->info = temp->info;
                            temp->info = valor;
                            a->esq = excluir(a->esq, valor);
                        }
                    }
                }
            }
        }
    }
    return a;
}

void preOrdem(Arvore* a) {
    if(a==NULL){
        printf("<>");
    }
    if (a != NULL) {
        printf("<%i", a->info);
        preOrdem(a->esq);

        preOrdem(a->dir);
        printf(">");
    }
}

void inOrdem(Arvore* a) {
    if(a==NULL){
        printf("<>");
    }
    if (a != NULL) {

        inOrdem(a->esq);
        printf("<%i", a->info);
        inOrdem(a->dir);
        printf(">");
    }
}

void posOrdem(Arvore* a) {
    if(a==NULL){
        printf("<>");
    }
    if (a != NULL) {

        posOrdem(a->esq);
        printf(">");
        posOrdem(a->dir);
        
        printf("<%i", a->info);
    }
}

Arvore * libera(Arvore *a) {
    if (a == NULL) {
        libera(a->esq);
        libera(a->dir);
        free(a);
    }
    return NULL;
}

int altura(Arvore * a) {
    if (a == NULL) {
        return -1;

    } else {
        return 1 + max(altura(a->esq), altura(a->dir));
    }
}

int max(int a, int b) {
    if (a < b) {
        return b;
    } else {
        return a;
    }
}

Arvore* busca(Arvore* a, int valor) {
    if (a == NULL) {
        return NULL;
    } else if (a->info > valor) {
        return busca(a->esq, valor);
    } else if (a->info < valor) {
        return busca(a->dir, valor);
    } else {
        return a;
    }
}
