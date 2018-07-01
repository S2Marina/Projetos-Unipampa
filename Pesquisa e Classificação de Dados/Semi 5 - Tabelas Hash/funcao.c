// Pesquisa e Classificação de Dados - Atividade Semi-Presencial 05
// 22 de junho de 2018
// Andrelise Nunes Lemos Pinheiro (andrelisenunes@hotmail.com) , Marina Silva da Silva (marina_silva98@hotmail.com).

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "funcao.h"

Tabela* inserir (Tabela* hash){
  int codigo=0, posicao=0;
  char desc[40];
  float valor= 0.0;

  printf("Informe o codigo do item:\n");
  scanf("%i", &codigo);
  printf("Informe a descricao do item:\n");
  scanf("%s", &desc);
  printf("Informe o valor do item:\n");
  scanf("%f", &valor);

  posicao = endereco(codigo);

  printf("Posicao: %i", posicao);
  if(hash[posicao].codigo==0){
    hash[posicao].codigo = codigo;
    strcpy(hash[posicao].desc, desc);
    hash[posicao].valor = valor;
  }else{
    printf("Posicao ocupada! Não foi possível realizar a insercao!");
  }
  return hash;
}

int endereco(int codigo){ //metodo da multiplicacao
  int posicao=0;
  float a=0.6180339887, val=0.0;

  val = codigo * a;
  val = val -(int) val;
  posicao = (int) (101 * val);

  return posicao;
}

Tabela* inicializa(Tabela *hash){
  int i;
  for(i=0;i<101;i++){
    hash[i].codigo = 0;
  }
  return hash;
}

void consultar(Tabela* hash){
  int codigo=0, x=0, posicao=0;
  printf("Informe o codigo do item que deseja buscar:\n");
  scanf("%i", &codigo);
  posicao = endereco(codigo);
  if(hash[posicao].codigo==codigo){
    printf("\n[%i]\t", posicao);
    printf("Codigo: %i\t", hash[posicao].codigo);
    printf("Descricao: %s\t", hash[posicao].desc);
    printf("Valor: %.2f\n", hash[posicao].valor);
  }else{
    printf("Item não encontrado!\n");
  }
}

void imprimir(Tabela* hash){
  int x;
  printf("\nTabela Hash:\n");
  for(x=0;x<101;x++){
    printf("[%i]\t", x);
    printf("Codigo: %i\t", hash[x].codigo);
    printf("Descricao: %s\t", hash[x].desc);
    printf("Valor: %.2f\n", hash[x].valor);
  }
}
