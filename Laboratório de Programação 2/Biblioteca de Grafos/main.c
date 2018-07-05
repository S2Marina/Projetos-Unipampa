#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"
#include "heap.h"
#include "busca.h"
#include "conjuntos.h"
#include "kruskal.h"
#include "prim.h"
#include "djikstra.h"

int main() {
    Grafo* g = NULL;
    Aresta** heap = (Aresta**) malloc(sizeof (Aresta));
    heap = NULL;
    Aresta* raiz = (Aresta*) malloc(sizeof (Aresta));
    int m = 0, tamanho = 0;

    
    do {
        printf("\nMenu:\n 1-Imprimir grafo\n 2-Kruskal\n 3-Prim\n 4-Djikstra\n 5-DFS\n 6-BFS\n 0-Sair\n\nOpcao: ");
        scanf("%i", &m);
        g = lerArquivo();
        switch (m) {
            case 1:{
                imprimirGrafo(g);
                break;
            }
            case 2:{
                kruskal(g);
                break;
            }
            case 3:{
                prim(g);
                break;
            }
            case 4:{
                djikstra(g);
                break;
            }
            case 5:{
                dfs(g);
                break;
            }
            case 6:{
                bfs(g);
                break;
            }
            case 0:{
                printf("Tchau o/\n");
                break;
            }
            default:{
                printf("Opcao invalida!\n");
                break;
            }
        }
    } while (m != 0);
    return 0;
}
