#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "funcao.h"
int main() {
    int m, valor=0;
	inicializa();
    do {
        printf("\n----\nMenu\n----\n0-Sair\n1-Criar Tabela Hash\n2-Imprime\n3-Busca\nOpcao:");
        scanf("%i", &m);
        switch (m) {
            case 1:
				criaTabela();
            break;
            case 2:
				imprime();
            break;
            case 3:
            printf("Digite o codigo a ser buscado\n");
            scanf("%d", &valor);
            busca(valor);
            break;
        }
    } while (m != 0);
    return 0;
}
