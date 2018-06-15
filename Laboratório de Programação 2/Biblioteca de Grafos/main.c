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
        printf("\nMenu:\n 1-Criar grafo\n 2-Kruskal\n 3-Prim\n 0-Sair\n\nOpcao: ");
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
                break;
            }
            case 3:{
                break;
            }
        }
    } while (m != 0);
    return 0;
}