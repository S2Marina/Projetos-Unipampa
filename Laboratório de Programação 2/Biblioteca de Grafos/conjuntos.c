#include <stdio.h>
#include <stdlib.h>
#include "conjuntos.h"

void makeSet(int n, int *conj) {
    int i;
    for (i = 0; i < n; i++) {
        conj[i] = i+1;
    }
}

int findSet(int i, int* conj) {
    if (conj[i-1] == i) {
        return i;
    } else {
        conj[i-1] = findSet(conj[i-1], conj);
        return conj[i-1];
    }
}

void uniao(int*conj, int i, int j) {
    if (i > j) {
        conj[i-1] = findSet(j, conj);
    } else {
        conj[j-1] = findSet(i, conj);
    }
}

void imprimir(int* conj, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf(" %i \n", conj[i      ]);
    }
}
