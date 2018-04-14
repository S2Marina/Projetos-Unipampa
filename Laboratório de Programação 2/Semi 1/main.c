#include <stdio.h>
#include <stdlib.h>
#include "cabecalho.h"

int main(int argc, char **argv)
{
	 
	 aluno a;
	 int mat = 0, m, maximo;
	 float med = 0.0;
	 char nome[50];
	 
	 printf("Informe a quantidade maxima de alunos:\n");
	 scanf("%i", &maximo);
	 Pilha *p;
	 p = criarPilha(maximo);
	 do {
		printf("\nMenu:\n 1-Imprimir aluno\n 2-Inserir aluno\n 3-Excluir aluno\n 4-Quantidade de alunos\n 5-Buscar aluno\n 0-Sair\nOpcao: ");
        scanf("%i", &m);
        switch (m) {
            case 1:{
                if(p->topo == NULL){
					printf("\nA Pilha está vazia!\n");
				}else{
					imprimir(p);
				}		
                break;
            }
            case 2:{
				if(p->quantidade < p->maximo){
					setbuf(stdin,NULL);
					printf("\nInforme o nome do aluno:\n");
					scanf("%[^\n]s", nome);
					setbuf(stdin,NULL);
					printf("\nInforme a matricula do aluno:\n");
					scanf("%i", &mat);
					setbuf(stdin,NULL);
					printf("\nInforme a media do aluno:\n");
					scanf("%f", &med);
					setbuf(stdin,NULL);
					inserir(p, mat, nome, med);
				}else{
					printf("A Pilha ja esta cheia!!!");
				}
                break;
            }
            case 3:{
                a=remover(p);
                printf("\nALuno %s removido com sucesso!\n", a.nome);
                break;
            }
            case 4:{setbuf(stdin,NULL);
				int q = 0;
				q = tamanho(p);
				if(q>0){
					printf("\n%i alunos cadastrados!\n", q);
				}
                break;
            }
            case 5:{
				setbuf(stdin,NULL);
                printf("\nInforme a matricula do aluno que deseja buscar:\n");
                scanf("%i", &mat);
                buscar(p,mat);
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

