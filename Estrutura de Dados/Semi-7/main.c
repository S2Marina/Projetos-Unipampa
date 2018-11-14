/*
// Lista 06
// 30/10/2017
// Gabriel Porto Oliveira (patonoideoriginal@gmail.com), Marina Silva da Silva (marina_silva98@hotmail.com).
 */
#include <stdio.h>
#include <stdlib.h>
#include "cabecalho.h"

int main(int argc, char** argv) {
    int opcao = 0;
    int valor;
    Arvore * a;
    Arvore * t;
    printf("Portinho e MiniMarina Productions EC e nois 2017.\n");
    do {
        printf("\nDigite a opcao desejada de acordo com o menu\n 1-Criar arvore.\n 2-Inserir elemento na arvore. \n 3-Excluir o elemento da arvore.\n 4-Imprimir a arvore.\n 5-Altura da arvore.\n 6-Liberar arvore\n 7-Imprimir arvore em arquivo txt\n 0-Sair\nOpcao:");
        scanf("%i", &opcao);

        switch (opcao) {
            case 1:
            {
                a = treeVazia();
                printf("Arvore criada com sucesso!!!");
                break;
            }
            case 2:
            {
                printf("Informe o valor a ser inserido:");
                scanf("%i", &valor);
                t = busca(a, valor);
                if (t == NULL) {
                    a = insere(a, valor);
                    printf("Valor inserido com sucesso!!!");
                } else {

                    printf("Valor ja inserido com sucesso!!!");
                }


                break;
            }
            case 3:
            {
                printf("Informe o valor a ser excluido:");
                scanf("%i", &valor);
                t = busca(a, valor);
                if (t == NULL) {
                    printf("Valor nao encontrado na arvore!!!");
                } else {
                    a = excluir(a, valor);
                    printf("Valor excluido com sucesso!!!");
                }
                break;
            }
            case 4:
            {
                printf("Informe a ordem para impressao:\n 1-Pre ordem\n 2-In ordem\n 3-Pos ordem\n Opcao:");
                scanf("%i", &valor);
                if (valor == 1) {
                    preOrdem(a);
                } else if (valor == 2) {
                    inOrdem(a);
                } else if (valor == 3) {
                    posOrdem(a);
                } else {
                    printf("Opcao Invalida");
                }
                break;
            }
            case 5:
            {
                valor = altura(a);
                printf("A altura da arvore e %i !!!", valor);
                break;
            }
            case 6:
            {
                a = libera(a);
                printf("Arvore liberada com sucesso!!!");
                break;
            }
            case 7:
            {
                printf("Informe a ordem para impressao:\n 1-Pre ordem\n 2-In ordem\n 3-Pos ordem\n Opcao:");
                scanf("%i", &valor);

                FILE *f;


                if (valor == 1) {
                    if ((f = fopen("saidapreordem.txt", "w")) == NULL) {
                        printf("Erro ao abrir o arquivo!!!");
                    }
                    preOrdemF(a, f);
                } else if (valor == 2) {
                    if ((f = fopen("saidainordem.txt", "w")) == NULL) {
                        printf("Erro ao abrir o arquivo!!!");
                    }
                    inOrdemF(a, f);
                } else if (valor == 3) {
                    if ((f = fopen("saidaposordem.txt", "w")) == NULL) {
                        printf("Erro ao abrir o arquivo!!!");
                    }
                    posOrdemF(a, f);
                } else {
                    printf("Opcao Invalida");
                }

                fclose(f);

                printf("Arquivo criado com sucesso!!!");
                break;
            }
            case 0:
            {
                printf("Indo embora...\n...\nTchau o/\n");
                break;
            }
            default:
            {
                printf("Opcao invalida!!!");
                break;
            }
        }

    } while (opcao != 0);

    return (EXIT_SUCCESS);
}

