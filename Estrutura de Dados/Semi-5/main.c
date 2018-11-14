/*
// Lista 05
// 13/10/2017
// Gabriel Porto Oliveira (patonoideoriginal@gmail.com), Marina Silva da Silva (marina_silva98@hotmail.com).
 */

#include <stdio.h>
#include <stdlib.h>
#include "cabecalho.h"


int main(int argc, char** argv) {
    int opcao = 0;
    int escolhedor = 0;
    FilaD *d;
    FilaV * v;
    float elemento;
    int estadov = 0, estadod = 0; 
/*
    Estados 0: lista nao foi criada ainda
            1: ja foi criada mas esta vazia
            2: ja foi inserido algum elemento nela
*/
    int elementoi;
    printf("Portinho e MiniMarina Productions EC e nois 2017.\n");
    do {
        printf("\n\nDigite a opcao desejada de acordo com o menu\n 1-Criar filas\n 2-Inserir elemento nas filas \n 3-Excluir o elemento da fila.\n 4-Inverter a fila (Vetor).\n 5-Imprimir a fila.\n 6-Demitir a fila.\n 7-Sair\nOpcao:");
        scanf("%i", &opcao);

        switch (opcao) {
            case 1:
            {
                d = filadCria();
                v = filavCria();
                estadod = 1;
                estadov = 1;
                printf("\nFila criada com sucesso!!!");
                break;
            }
            case 2:
            {
                printf("\nSe escolha qual fila ira receber o seu elemento: \n1-Fila Vector\n2-Fila com lista tipo D\n Opcao: ");
                scanf("%i", &escolhedor);
                setbuf(stdin, NULL);
                printf("\nDigite o elemento: ");
                scanf("%f", &elemento);
                setbuf(stdin, NULL);

                if (escolhedor == 1 && estadov != 0) {

                    filavInsere(v, elemento);
                    estadov = 2;
                    printf("\nSucesso\n");

                } else
                    if (escolhedor == 2 && estadod != 0) {

                    filadInsere(d, elemento);
                    estadod = 2;
                    printf("\nSucesso\n");

                } else {

                    printf("\n Algo esta errado.");

                }

                break;
            }
            case 3:
            {
                printf("\nEscolha de qual fila o elemento sera excluido: \n1-Fila Vector\n2-Fila com lista tipo D\n Opcao: ");
                scanf("%i", &escolhedor);

                if (escolhedor == 1 && estadov == 2) {
                    elemento = filavRetira(v);

                    printf("\nO elemento e:%.2f", elemento);
                } else
                    if (escolhedor == 2 && estadod == 2) {
                    elemento = filadRetira(d);
                    printf("\nO elemento e:%.2f", elemento);
                } else {
                    printf("\n Algo esta errado.");
                }

                break;
            }
            case 4:
            {
                inverter(v);
                printf("\nFila (Vetor) invertida com sucesso!!!\n");
                filavImprime(v);
                break;
            }
            case 5:
            {
                printf("\nEscolha de qual fila o elemento sera mostrado: \n1-Fila Vector\n2-Fila com lista tipo D\n Opcao: ");
                scanf("%i", &escolhedor);

                if (escolhedor == 1 && estadov == 2) {
                    filavImprime(v);

                } else
                    if (escolhedor == 2 && estadod == 2) {
                    filadImprime(d);

                } else {
                    printf("\n Opcao errada.");
                }

                break;
            }
            case 6:
            {
<<<<<<< HEAD
                printf("\nEscolha qual fila sera libertada: \n1-Fila Vector\n2-Fila com lista tipo D\n Opcao: ");
=======
                printf("\nEscolha qual fila sera liberada: \n1-Fila Vector\n2-Fila com lista tipo D\n Opcao(Rei Hey  Apple): ");
>>>>>>> 36adc8166acf6e6c44b40b31a975dcc3e56a5f28
                scanf("%i", &escolhedor);

                if (escolhedor == 1) {
                    filavLibera(v);
                    estadov = 0;

                } else
                    if (escolhedor == 2) {
                    filadLibera(d);
                    estadod = 0;
                } else {
                    printf("\n Opcao errada.");
                }
                break;
            }

        }
    } while (opcao != 7);
    printf("\nSaindo...\n");
    return (EXIT_SUCCESS);
}

