#include <stdio.h>
#include <string.h>
#include "funcao.h"
#include <stdlib.h>
#include <time.h>

int main() {
    int x, *vetor, i = 0, opc;
    float b = 0, s = 0, ins = 0;
    FILE *arquivo;
    printf("Digite a quantidade de numeros inteiros:");
    scanf("%d", &x);
    //cria vetor com valores aleatórios
    vetor = malloc(sizeof (int)* x);
    srand(time(NULL));
    //abrindo arquivo que guardará os números gerados
    if ((arquivo = fopen("entrada.txt", "w")) == NULL) {
        printf("Nao e possivel criar um arquivo de texto. Tente novamente\n");
    }
    fprintf(arquivo, "%d\n", x); //primeiro elemento é o tamanho do meu vetor de números para a ordenação
    for (i = 0; i < x; i++) {
        vetor[i] = rand() % (x * 2);
        //printf("%d\n", vetor[i]);
        fprintf(arquivo, "%d\t", vetor[i]);
    }
    fclose(arquivo);
    printf("-->NUMEROS GERADOS E SALVOS COM SUCESSO<--\n");
    //menu
    do {
        printf("\n==MENU==\n");
        printf("0-Sair\n1-Ordenar por Borbulhamento:BUBBLESORT\n2-Ordenar por selecao:SELECTON SORT\n3-Ordenar por insercao:INSERTION SORT\n4-Mostrar valores de entrada\n5-Mostrar valores ordenados\n6-Mostrar tempo de execucao\n>>OPCAO:");
        scanf("%d", &opc);
        switch (opc) {
            case 1:
            { //BUBBLE
                b = ordenabubblue();
                break;
            }
            case 2:
            { //SELECTION
                s = ordenaselection();
                break;
            }
            case 3:
            { //INSERTION
                ins = ordenainsertion();
                break;
            }
            case 4:
            { //MOSTRAR VALORES DE ENTRADA 	
                mostraentrada();
                break;
            }
            case 5:
            { //MOSTRAR VALORES ORDENADOS
                mostraordenado();
                break;
            }
            case 6:
            { //TEMPO DE EXECUÇÃO DE CADA PROCESSO
                printf("-->Tempo de execucao<--\n[1] BUBBLE=%f\n[2]SELECTION=%f\n[3]INSERTION=%f\n", b, s, ins);
                break;
            }
        }
    } while (opc != 0);
    return 0;
}
