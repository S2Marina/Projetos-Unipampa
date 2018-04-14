#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cabecalho.h"

//pilha pode apontar aluno
//aluno não pode apontar pilha

Pilha * criarPilha(int max){
	Pilha *p = (Pilha*) malloc(sizeof (Pilha));
    p->quantidade = 0;
    p->topo = NULL;
    p->maximo = max;
    return p;
}

void inserir(Pilha * p, int mat, char n[50], float med){
	//criar
	aluno *novo = ((aluno*) malloc(sizeof(aluno)));
	novo->matricula = mat;
	strcpy(novo->nome, n);
	novo->media = med;
	
	//push
	novo->prox = p->topo;
	p->topo = novo;
	p->quantidade++;
}

aluno remover(Pilha * p) {
    aluno *aux;
    aluno a;
    if (p->topo != NULL) { //se tem algo na Pilha
        aux = p->topo;
        p->topo = aux->prox;
        free(aux);
        p->quantidade--;
    } else {
        printf("A Pilha está vazia!!!");
    }
    return a;
}

void liberar(Pilha * p) {
    aluno *tmp, *aux = p->topo;
    while (aux != NULL) {
        tmp = aux->prox;
        free(aux);
        aux = tmp;
    }
    free(p);
}

void imprimir(Pilha * p) {
    aluno *aux;

    for (aux = p->topo; aux != NULL; aux = aux->prox) {
		printf("\n Matricula: %i\n", aux->matricula);
        printf(" Nome: %s\n", aux->nome);
        printf(" Media: %.2f\n\n", aux->media);
    }
}

void buscar(Pilha *p, int matricula){
	aluno *a;
	int cont=0;
	a = p->topo;
	while(a!=NULL){
		if(a->matricula==matricula){
			printf("\n Matricula: %i \n", a->matricula);
            printf(" Nome: %s \n", a->nome);
            printf(" Media: %.2f\n\n", a->media);
			cont++;
		}
			a=a->prox;
		}
	
   if(cont==0){
		printf("\nAluno não cadastrado!!!\n");
	}		
}	

int tamanho(Pilha *p){
	int q = 0;
	if(p->topo==NULL){
		printf("A Pilha está vazia!!!");
	}else{
		q=p->quantidade;
	}
	return q;
}

