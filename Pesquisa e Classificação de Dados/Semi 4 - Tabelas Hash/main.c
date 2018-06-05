#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "funcao.h"

int main() {
    int m=0, tamanho=0;
    Nodo** hash;

    do {
        printf("Menu: \n 1-Criar Tabela Hash\n 0-Sair\n Opcao:");
        scanf("%i", &m);
        switch (m) {
            case 1:
            {
                printf("Informe o tamanho da tabela Hash: ");
                scanf("%i\n", &tamanho);
                hash = criaTabela(tamanho);
                break;
            }
            case 2:
            {
                break;
            }
            case 3:
            {
                break;
            }
            case 4:
            {
                break;
            }
            case 5:
            {
                break;
            }
            case 6:
            {
                break;
            }
        }
    } while (m != 0);
    return 0;
}
