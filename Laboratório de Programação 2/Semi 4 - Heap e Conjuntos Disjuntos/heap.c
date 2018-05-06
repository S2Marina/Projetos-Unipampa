#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

int * buildHeap(int* heap, int tamanho, int elemento) {
    int * vetor;
    int x = 0;
    vetor = malloc(tamanho * sizeof (int));
  	if(tamanho != 1){
          	for (x = 0; x < tamanho-1; x++) {
             		vetor[x] = heap[x];
          	}
  	}
    vetor[tamanho-1] = elemento;
    vetor = percolate(vetor, tamanho);
	return vetor;
}

int * deleteHeap(int* heap, int tamanho) {
    int x = 0;
    int * vetor;
    vetor = malloc((tamanho) * sizeof (int)); //aloco um novo vetor
    heap[0] = 0;
    vetor = heap;
    for (x = 0; x < tamanho; x++) {
        vetor[x] = heap[x + 1];
    }
    vetor = siftDown(vetor, tamanho);
    return vetor;
}

void printHeap(int* heap, int tamanho) {
    int x = 0;
    printf("\nHeap:\n");
    for (x = 0; x < tamanho; x++) {
        printf("%i \n", heap[x]);
    }
}

int * siftDown(int* heap, int tamanho) {
    int x = 0, aux = 0;
    for (x = 0; x < tamanho-1; x++) {
        if (heap[x] > heap[x + 1]) {
            aux = heap[x];
            heap[x] = heap[x + 1];
            heap[x + 1] = aux;
        }
    }
    return heap;
}

int *  percolate(int * heap, int tamanho) {
    int x = 0, aux = 0;
    for (x = tamanho-1; x >= 0; x--) {
        if (heap[x] < heap[x - 1]) {
            aux = heap[x - 1];
            heap[x - 1] = heap[x];
            heap[x] = aux;
        }
    }
    return heap;
}

int getRaiz(int *heap) {
    return heap[0];
}
