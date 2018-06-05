#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "funcao.h"

Nodo** criaTabela(int tamanho){
    Nodo** hash;
    Nodo* novo;
    int endereco=0, i=0;

    srand(time(NULL));
    for (i = 0; i < tamanho * 10; i++) {
      novo = (Nodo*) malloc(sizeof(Nodo));
      novo->codigo = rand() % (tamanho * 100);
      strcpy(novo->desc,"abcd");
      novo->valor = ((float) rand() / RAND_MAX) * tamanho;
      novo->prox = NULL;
      endereco = novo->codigo % tamanho;

      novo->prox = hash[endereco];
      hash[endereco] = novo;
      printf("Codigo: %d\tValor: %f\tEndereco: %d\n",
          novo->codigo, novo->valor, endereco);
    }

    return hash;
}
