/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   cabecalho.h
 * Author: Asus
 *
 * Created on 29 de Outubro de 2017, 20:05
 */
struct arv {
    struct arv*dir;
    struct arv * esq;
    int info;
};
typedef struct arv Arvore;


Arvore * treeVazia();
Arvore * insere(Arvore * a, int valor);
Arvore * excluir(Arvore * a, int valor);
void preOrdem(Arvore* a);
void inOrdem(Arvore* a);
void posOrdem(Arvore* a);
Arvore * libera(Arvore *a);
int altura(Arvore * a);
int max(int a, int b);
Arvore* busca(Arvore* a, int valor);