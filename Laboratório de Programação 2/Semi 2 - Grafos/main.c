#include <stdio.h>
#include <stdlib.h>
#include "cabecalho.h"


//portinho esteve aqui :)
int main() {
  Grafo* g = NULL;
  int m = 0;

  do {
    printf("\nMenu:\n 1-Criar Grafo\n 2-Imprimir grafo\n 0-Sair\nOpcao: ");
    scanf("%i", &m);
    switch (m) {
      case 1:{
        g = lerArquivo();
        if(g!=NULL){
            printf("Grafo criado com sucesso!\n");
        }
        break;
      }
      case 2:{
        imprimirGrafo(g);
        break;
      }
    }
  } while (m != 0);
  return 0;
}
