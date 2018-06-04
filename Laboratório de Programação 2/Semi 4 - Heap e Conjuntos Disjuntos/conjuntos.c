#include <stdio.h>
#include <stdlib.h>
#include "conjuntos.h"

int* makeSet(int n) {
  int i, *conj;
  conj = (int*) malloc(n * sizeof(int));
  for (i = 0; i < n; i++) {
    conj[i] = i+1;
  }
  return conj;
}

int findSet(int i, int* conj){
  if(conj[i-1]==i){
    return i;
  }else{
    conj[i-1]=findSet(conj[i-1], conj);
    return conj[i-1];
  }
}

int* uniao(int*conj, int i, int j){
    conj[i-1]=findSet(j, conj);
    return conj;
}

void imprimir(int* conj, int n){
    int i;
    for (i = 0; i < n; i++) {
      printf(" %i \n", conj[i]);
    }
}
