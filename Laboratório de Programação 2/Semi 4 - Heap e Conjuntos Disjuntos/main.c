#include <stdio.h>
#include <stdlib.h>
#include "heap.h"
#include "conjuntos.h"

int main() {
    int m = 0, tamanho = 0, valor = 0, raiz = 0, tam=0,x=0, y=0;
    int * heap = (int*) malloc(sizeof(int));
    int *conjunto;
    heap = NULL;
    do {
        printf("\nMenu Heap:\n 1-Inserir elemento na heap\n 2-Deletar elemento da heap\n 3-Mostrar heap\n 4-Mostrar raiz\n\nMenu Conjuntos Disjuntos:\n 5-Criar Conjunto\n 6-Unir conjuntos\n 7-Mostrar conjunto\n\n 0-Sair\nOpcao: ");
        scanf("%i", &m);
        switch (m) {
            case 1:
            {
                printf("Informe o elemento a ser adicionado na heap:\n");
                scanf("%i", &valor);
                tamanho++;
                heap = buildHeap(heap, tamanho, valor);
                if (heap != NULL) {
                    printf("Elemento adicionado com sucesso!\n");
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
                raiz = getRaiz(heap);
                printf("\nRaiz: %i\n", raiz);
                break;
            }
            case 5:
            {
              printf("Informe numero de elementos :\n");
              scanf("%i", &tam);
              conjunto = makeSet(tam);
              printf("Conjunto criado com sucesso!\n");
              break;
            }
            case 6:{
              printf("Informe os elementos que deseja unir:\n");
              printf("Primeiro elemento:\n");
              scanf("%i", &x);
              printf("Segundo elemento:\n");
              scanf("%i", &y);
              conjunto = uniao(conjunto,x,y);
              break;
            }
            case 7:{
               imprimir(conjunto, tam);
               break;
            }
        }
    } while (m != 0);
    return 0;
}
