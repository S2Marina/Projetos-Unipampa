#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

int main() {
    int m = 0, tamanho = 0, valor = 0, raiz = 0;
    int * heap = (int*) malloc(sizeof(int));
    heap = NULL;
    do {
        printf("\nMenu:\n 1-Inserir elemento na heap\n 2-Deletar elemento da heap\n 3-Mostrar heap\n 4-Mostrar raiz\n 0-Sair\nOpcao: ");
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
        }
    } while (m != 0);
    return 0;
}
