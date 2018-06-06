#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "funcao.h"
/*Inserir: lê as informações a partir do teclado e insere um novo registro na tabela hash. Caso
já exista um registro na tabela com o código informado o programa deve dar uma mensagem
de erro e não realizar a inclusão;*/
void inicializa(void)
{
	int i;
		for(i=0;i<TAM;i++)
		{
			tabela[i] = NULL;
		}
}

void criaTabela(void){
    Nodo* novo, *aux;
    int endereco=0, i=0, cont=0, igual=0, codigo;	
		printf("Digite o código\n");
		scanf("%d", &codigo);
		while(cont!=TAM)
		{
			cont++;
			aux=tabela[cont];
				while(aux!=NULL)
				{
					if(aux->codigo==codigo)
					{
						printf("ERRO!!\nCodigo ja existente\n");
						igual++;
					}
				aux=aux->prox;
				}
		}
		if(igual==0)
		{
		novo = malloc(sizeof(Nodo));
			novo->codigo = codigo;
			printf("Valor=");
				scanf("%f", &novo->valor);
			printf("Descricao:");
				scanf("%s", novo->desc);
				setbuf(stdin, NULL);
			novo->prox = NULL;
				endereco = novo->codigo % TAM;
					novo->prox = tabela[endereco];
						tabela[endereco] = novo;
			 printf("Tabela criada com sucesso!!!\n");
		}
}

void imprime(void)
{
	int i, cont=0;
	Nodo*aux;
		for (i = 0; i < TAM; i++)
		{
			cont = 0;
				aux = tabela[i];
					printf("ENDEREÇO[%d] -> ", i);
			while (aux != NULL)
		   {
			printf("CODIGO=%d\tVALOR=%0.2f\tDESCRICAO:%s -> ", aux->codigo, aux->valor, aux->desc); 
				aux = aux->prox;
					cont++;
			}
		printf("NULL (%d)\n", cont);
		} 
}

void busca(int valor)
{
 int endereco;
 endereco = valor % TAM;
 Nodo *tab = tabela[endereco];
 int cont=0;
		if (valor == tab->codigo)
		{
			 printf("codigo=%d\tvalor=%2.f\tdescricao=%s\n", tab->codigo, tab->valor, tab->desc);
		cont++;
		}
		if(cont==0)
		{
		printf("Codigo nao existente na tabela!\n");
		}
}

