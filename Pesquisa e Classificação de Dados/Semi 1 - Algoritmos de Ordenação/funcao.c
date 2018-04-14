#include <stdio.h>
#include <string.h>
#include "funcao.h"
#include <stdlib.h>
#include <time.h>

//ORDENAÇÃO BUBBLE

float ordenabubblue(void) {
    FILE *arquivo;
    int a, i = 0, j, cont = 0, *vetor, temp, aux = 0;
    clock_t inicio, fim;
    float total;
    if ((arquivo = fopen("entrada.txt", "r")) == NULL) {
        printf("Impossivel realizar a leitura do arquivo. Tente novamente\n");
    }
    //descobrir o número de valores
    fscanf(arquivo, "%d", &a); //faz a leitura do primeiro elemento do meu arquivo que por padrão é a quantidade de elementos do meu vetor
    //lendo os valores de entrada
    
    vetor = malloc(sizeof (int)* a);
    
    while (!feof(arquivo)) {
        fscanf(arquivo, "%d", &vetor[i]);
        i++;
    }
    fclose(arquivo);
    inicio = clock();
    for (i = 0; i < a - 1; i++) {
        for (j = i + 1; j < a; j++) {
            if (vetor[i] > vetor[j]) {
                temp = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = temp;
            }
        }
    }
    fim = clock();
    if ((arquivo = fopen("bubble.txt", "w")) == NULL) {
        printf("Nao e possivel criar o arquivo\n");
    } else {
        for (i = 0; i < a; i++) {
            fprintf(arquivo, "%d\t", vetor[i]);
        }
    }
    fclose(arquivo);
    total = ((float) (fim - inicio) / CLOCKS_PER_SEC);
    printf("Vetor ordenado com sucesso!");
    return total;
}

float ordenaselection(void) {
    FILE *arquivo;
    int a, i = 0, j, cont = 0, *vetor, aux, temp;
    clock_t inicio, fim;
    float total;
    if ((arquivo = fopen("entrada.txt", "r")) == NULL) {
        printf("Impossivel realizar a leitura do arquivo. Tente novamente\n");
    }
    //descobrir o número de valores
    fscanf(arquivo, "%d", &a);
    
    vetor = malloc(sizeof (int)* a);
    
    //lendo os valores de entrada
    while (!feof(arquivo)) {
        fscanf(arquivo, "%d", &vetor[i]);
        i++;
    }
    fclose(arquivo);
    inicio = clock();
    for (i = 0; i < a - 1; i++) {
        aux = i;
        for (j = i + 1; j < a; j++) {
            if (vetor[j] < vetor[aux]) {
                aux = j;
            }
        }
        if (i != aux) {
            temp = vetor[i];
            vetor[i] = vetor[aux];
            vetor[aux] = temp;
        }
    }
    fim = clock();
    if ((arquivo = fopen("selection.txt", "w")) == NULL) {
        printf("Nao e possivel criar o arquivo\n");
    } else {
        for (i = 0; i < a; i++) {
            fprintf(arquivo, "%d\t", vetor[i]);
        }
    }
    fclose(arquivo);
    total = ((float) (fim - inicio) / CLOCKS_PER_SEC);
    printf("Vetor ordenado com sucesso!");
    return total;

}

float ordenainsertion() {
    FILE *arquivo;
    int a = 0, i = 0, j = 0, cont = 0, *vetor, aux = 0;
    clock_t inicio = 0, fim = 0;
    float total = 0;
    if ((arquivo = fopen("entrada.txt", "r")) == NULL) {
        printf("Impossivel realizar a leitura do arquivo. Tente novamente\n");
    }
    //descobrir o número de valores
    fscanf(arquivo, "%d", &a);
    
    vetor = malloc(sizeof (int)* a);
    
    //	lendo os valores de entrada
    while (!feof(arquivo)) {
        fscanf(arquivo, "%d", &vetor[i]);
        i++;
    }
    fclose(arquivo);
    inicio = clock();

    for (i = 1; i < a; i++) {
        aux = vetor[i];
        j = i - 1;

        while (j >= 0 && vetor[j] > aux) {
            vetor[j + 1] = vetor[j];
            j = j - 1;
        }
        vetor[j + 1] = aux;
    }

    fim = clock();

    if ((arquivo = fopen("insertion.txt", "w")) == NULL) {
        printf("Nao e possivel criar o arquivo\n");
    } else {
        for (i = 0; i < a; i++) {
            fprintf(arquivo, "%d\t", vetor[i]);
        }
    }

    fclose(arquivo);
    total = ((float) (fim - inicio) / CLOCKS_PER_SEC);
    printf("Vetor ordenado com sucesso!");
    return total;
}

void mostraentrada() {
    FILE *arquivo;
    int a, aux, cont = 0;
    if ((arquivo = fopen("entrada.txt", "r")) == NULL) {
        printf("Impossivel realizar a leitura do arquivo. Tente novamente\n");
    }
    //descobrir o número de valores
    fscanf(arquivo, "%d", &a);
    printf("Quantidade de números no total=%d\n", a);
    //lendo os valores de entrada
    while (cont != a) {
        fscanf(arquivo, "%d", &aux);
        printf("%d\t", aux);
        cont++;
    }
    fclose(arquivo);
}

void mostraordenado() {
    FILE *arquivo;
    int opcao, aux, a, cont;
    //sub=menu
    printf("Mostrar ordem de\n[1]BUBBLE\t[2]SELECTION\t[3]INSERTION\n");
    scanf("%d", &opcao);
    if ((arquivo = fopen("entrada.txt", "r")) == NULL) {
        printf("Impossivel realizar a leitura do arquivo. Tente novamente\n");
    }
    //descobrir o número de valores
    fscanf(arquivo, "%d", &a);
    fclose(arquivo);
    cont = 0; //zerando meu vetor auxiliar para o while
    switch (opcao) {
        case 1:
            if ((arquivo = fopen("bubble.txt", "r")) == NULL) {
                printf("Vetor não ordenado para esse tipo\n");
            } else {
                printf("---BUBBLE SORT---\n");
                while (cont != a) {
                    fscanf(arquivo, "%d", &aux);
                    printf("%d\t", aux);
                    cont++;
                }
            }
            fclose(arquivo);
            break;
        case 2:
            if ((arquivo = fopen("selection.txt", "r")) == NULL) {
                printf("Vetor não ordenado para esse tipo\n");
            } else {
                printf("---SELECTION SORT---\n");
                while (cont != a) {
                    fscanf(arquivo, "%d", &aux);
                    printf("%d\t", aux);
                    cont++;
                }
            }
            fclose(arquivo);
            break;
        case 3:
            if ((arquivo = fopen("insertion.txt", "r")) == NULL) {
                printf("Vetor não ordenado para esse tipo\n");
            } else {
                printf("---INSERTION SORT---\n");
                while (cont != a) {
                    fscanf(arquivo, "%d", &aux);
                    printf("%d\t", aux);
                    cont++;
                }
            }
            fclose(arquivo);
    }
}

