//codigo de exemplo do professor

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 101

struct _nodo {
  int codigo;
  float valor;
  struct _nodo *prox;
};
typedef struct _nodo TNodo;

TNodo *Tabela[TAM];

int main() {
  int i, endereco, cont;
  TNodo *novo = NULL, *aux = NULL;

  // Inicializa os ponteiros em NULL
  for (i = 0; i < TAM; i++)
    Tabela[i] = NULL;

  // Preenche a tabela
  srand(time(NULL));
  for (i = 0; i < TAM * 10; i++) {
    // Aloco e preencho o nodo
    novo = malloc(sizeof(TNodo));
    novo->codigo = rand() % (TAM * 100);
    novo->valor = ((float) rand() / RAND_MAX) * TAM;
    novo->prox = NULL;
    // Calculo o valor da funcao de hash
    endereco = novo->codigo % TAM;
    // Insiro o novo nodo na tabela
    novo->prox = Tabela[endereco];
    Tabela[endereco] = novo;
    // Imprimir informacoes
    printf("Codigo: %d\tValor: %f\tEndereco: %d\n",
        novo->codigo, novo->valor, endereco);
  }

  // Imprime a tabela hash
  for (i = 0; i < TAM; i++) {
    cont = 0;
    aux = Tabela[i];
    printf("%d) -> ", i);
    while (aux != NULL) {
      printf("|%d|%f| -> ", aux->codigo,
        aux->valor);
      aux = aux->prox;
      cont++;
    }
    printf("NULL (%d)\n", cont);
  }
}
