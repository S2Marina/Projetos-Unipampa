#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

Nodo* criaNodo(int chave) {
    Nodo *n = (Nodo*) malloc(sizeof (Nodo));
    n->chave = chave;
    n->prox = NULL;
    n->adj = NULL;
    return n;
}

Aresta* criaAresta(int chave_adj, int peso) {
    Aresta* a = (Aresta*) malloc(sizeof (Aresta));
    a->chave_adj = chave_adj;
    a->peso = peso;
    a->prox = NULL;
    return a;
}

Grafo* criaGrafo(int tamanho) {
    int i;

    Grafo *g = (Grafo*) malloc(sizeof (Grafo));
    g->tamanho = tamanho;
    g->listaNodos = NULL;

    for (i = 0; i < tamanho; i++) {
        Nodo* novo = criaNodo(i+1); //O IDEAL ERA CRIAR OS NODOS AQUI JÀ COM AS CHAVES, POR EXEMPLO DE 1 a TAMANHO;
        if (g->listaNodos == NULL) {
            g->listaNodos = novo;
        } else {
			Nodo *temp = g->listaNodos;
            while (temp->prox != NULL) { 
                temp = temp->prox;
            }
            temp->prox = novo; //AQUI SEMPRE ESTÀ ALTERANDO A RAIZ 
        }
    }
    return g;
}

void insereAresta(Nodo* n, int chave, int peso) {
    Aresta* a;
    a = criaAresta(chave, peso); //SIMPLIFIQUEI AQUI
    //navega nas adjacencias até achar uma posição valida
    Aresta *temp=n->adj;
    if(temp == NULL){
		n->adj = a;
	}
    else{
		while (temp->prox != NULL) {
            temp = temp->prox;
		}
		temp->prox = a;
    }
    
}

Grafo* lerArquivo() {
    FILE *arquivo;
    int tamanho = 0;
    int chave = 0;
    int a = 0;
    int peso = 0;

    if ((arquivo = fopen("entrada.txt", "r")) == NULL) {
        printf("Impossivel realizar a leitura do arquivo. Tente novamente\n");
    }
    fscanf(arquivo, "%d", &tamanho);

    Grafo* g = NULL;
    g = criaGrafo(tamanho); //MODIFIQUEI AQUI PARA FACILITAR pois tu abria o arquivo duas vezes para pegar tamanho

    while (fscanf(arquivo, "%i;%i;%i", &chave, &a, &peso) != EOF) {
		
		//encontra o nodo a ser inserido
		Nodo *temp = g->listaNodos;
		while(temp->chave != chave){
			temp= temp->prox;
		}
		
        //nodo->chave = chave; //AQUI ESTÁ ESTRANHO POIS CRIAS NODOS CONFORME APARECEM COMO ADJACENCIAS MAS SE TIVERES DUAS ADJACENCIAS 
							 //DO MESMO NODO CRIARIA DOIS NODOS COM A MESMA CHAVE
							 
		//chama a função de inserção de aresta
        insereAresta(temp, a, peso);
    }
    fclose(arquivo);
    return g;
}

void imprimirGrafo(Grafo* g) {
    Nodo* nodo = g->listaNodos;
    printf("quantidade de nodos: %i\n", g->tamanho);
    printf("arestas e (pesos):\n");
    while (nodo != NULL) {
        printf("%i", nodo->chave);
        while (nodo->adj != NULL) {
            printf("->%i", nodo->adj->chave_adj);
            printf("(%i)", nodo->adj->peso);
            nodo->adj = nodo->adj->prox;
        }
        printf("\n");
        nodo = nodo->prox;
    }
    g = lerArquivo();
}
