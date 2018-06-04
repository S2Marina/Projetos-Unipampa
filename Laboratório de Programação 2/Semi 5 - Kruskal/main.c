#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"
#include "heap.h"
#include "conjuntos.h"
#include "kruskal.h"

int main(){
  Grafo* g = NULL;
  Aresta** heap = (Aresta**) malloc(sizeof (Aresta));
  heap = NULL;
  Aresta* raiz = (Aresta*) malloc(sizeof (Aresta));
  int m = 0,tamanho = 0;

  do {
      printf("\nMenu:\n 1-Criar grafo\n 5-Inserir elemento na heap\n 2-Deletar elemento da heap\n 3-Mostrar heap\n 4-Mostrar raiz\n\nOpcao: ");
      scanf("%i", &m);
      switch (m) {
          case 1:
          {
              g = lerArquivo();
              if (g != NULL) {
                  printf("Grafo criado com sucesso!\n");
              }
              break;
          }
          case 5:
          {
              g=lerArquivo();
              imprimirGrafo(g);
              heap = addHeap(g, heap, tamanho);
              if (heap != NULL) {
                  printf("Heap criada com sucesso!\n");
              }

              break;
          }
          case 2:
          {
              tamanho--;
              heap = deleteHeap(heap, tamanho);
              printf("Elemento apagado com sucesso!\n");
              break;
          }
          case 3:
          {
              printHeap(heap, tamanho);
              break;
          }
          case 4:
          {
              g=lerArquivo();
              imprimirGrafo(g);
              break;
          }
      }
  } while (m != 0);
  return 0;
}
