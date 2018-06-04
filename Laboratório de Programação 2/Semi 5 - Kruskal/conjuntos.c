#include <stdio.h>
#include <stdlib.h>
#include "conjuntos.h"

int* makeSet(int n) {
  int i, *conj;
  conj = (int*) malloc(n * sizeof(int));
  for (i = 0; i < n; i++) {
    conj[i] = i;
  }
  return conj;
}

int findSet(int i, int* conj){
  if(conj[i]==i){
    return i;
  }else{
    conj[i]=findSet(conj[i], conj);
    return conj[i];
  }
}

int* uniao(int*conj, int i, int j){
    conj[i]=findSet(j, conj);
    return conj;
}

void imprimir(int* conj, int n){
    int i;
    for (i = 0; i < n; i++) {
      printf(" %i \n", conj[i]);
    }
}
