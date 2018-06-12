#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"
#include "heap.h"
#include "conjuntos.h"
#include "kruskal.h"

int main() {
    Grafo* g = NULL;
    Aresta** heap = (Aresta**) malloc(sizeof (Aresta));
    heap = NULL;
    Aresta* raiz = (Aresta*) malloc(sizeof (Aresta));
    int m = 0, tamanho = 0;

    do {
        printf("\nMenu:\n 1-Criar grafo\n 2-Kruskal\n\nOpcao: ");
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
            case 2:{
                kruskal(g);
                printf("kruskal");
            }
/*
            case 2:
            {
                heap = deleteHeap(heap, tamanho);
                printf("Elemento apagado com sucesso!\n");
                tamanho = getTamanho(heap);
                break;
            }
            case 3:
            {
                printHeap(heap, tamanho);
                break;
            }
            case 4:
            {
                imprimirGrafo(g);
                break;
            }
            case 5:
            {
                heap = addHeap(g, heap, tamanho);
                if (heap != NULL) {
                    printf("Heap criada com sucesso!\n");
                }
                tamanho = getTamanho(heap);
                break;
            }
            case 6:
            {
                tamanho = getTamanho(heap);
                printf("%i", tamanho);
                break;
            }
*/
        }
    } while (m != 0);
    return 0;
}