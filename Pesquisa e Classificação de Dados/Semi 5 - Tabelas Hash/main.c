// Pesquisa e Classificação de Dados - Atividade Semi-Presencial 05
// 22 de junho de 2018
// Andrelise Nunes Lemos Pinheiro (andrelisenunes@hotmail.com) , Marina Silva da Silva (marina_silva98@hotmail.com).

#include <stdio.h>
#include <stdlib.h>
#include "funcao.h"

int main(int argc, char **argv){
  int m=0;
  Tabela *hash = (Tabela*) malloc(101 * sizeof(Tabela));
  hash = inicializa(hash);
  do {
    printf("\nMenu:\n 1-Inserir\n 2-Consultar\n 3-Exibir tudo\n 0-Sair\nOpcao: ");
    scanf("%i", &m);
    switch (m) {
      case 1:{
        hash = inserir(hash);
        break;
      }
      case 2:{
        consultar(hash);
        break;
      }
      case 3:{
        imprimir(hash);
        break;
      }
      case 0:{
        printf("Saindo...\n");
        break;
      }
      default:{
        printf("Opcao invalida!!!");
        break;
      }
    }
  } while (m != 0);
  return 0;
}
