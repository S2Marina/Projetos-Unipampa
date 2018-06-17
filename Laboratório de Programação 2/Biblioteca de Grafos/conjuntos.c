#include <stdio.h>
#include <stdlib.h>
#include "conjuntos.h"

int* makeSet(int n) {
    int i, *conj;
    conj = (int*) malloc(n * sizeof (int));
    for (i = 1; i <= n; i++) {
        conj[i] = i;
    }
    return conj;
}


int findSet(int i, int* conj) {
    if (conj[i] == i) {
        return i;
    } else {
        conj[i] = findSet(conj[i], conj);
        return conj[i];
    }
}


/*int findSet(int j, int* conj, int tamanho) {
    int retorno = 0, rep = 0, x = 0; //representante do conjunto
    if (conj[j] == j) { //se j é o proprio representante, retorna ele
        retorno = j;
    } else { //senão
        rep = conj[j]; //pego o valor do representante de j
        for (x = 1; x <= tamanho; x++) {
            if (conj[x] == rep) {//se essa posicao do vetor conj tem o mesmo representante que j
                if (x != rep) { //testa se essa coluna é o representante
                    retorno = rep;
                }
            }
        }
    }
    return retorno;
}*/

int* uniao(int*conj, int i, int j) {
    //int x = 0, findJ = 0, conj_i = 0;
    conj[i] = findSet(j, conj);
    /*conj_i = conj[i]; //pega o representante de i

    for (x = 1; x <= tamanho; x++) {//procura todos os valores do conjunto de i e atribui o representante de j a eles tambem
        if (conj[x] == conj_i) {
            conj[x] = findJ;
        }
    }*/
    return conj;
}

void imprimir(int* conj, int n) {
    int i;
    for (i = 1; i <= n; i++) {
        printf(" %i \n", conj[i]);
    }
}
