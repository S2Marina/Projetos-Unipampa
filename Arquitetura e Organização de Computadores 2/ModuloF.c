#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int* escrita3(int dado, int* vetor, int* discos, int n_disco, int tam);
int* escrita4(int dado, int* vetor, int* discos, int n_disco, int tam);
void imprimir(int* discos);
int falha(int* discos, int falha);

int main() {
        int *discos, *vetor;
        int n_disco=0, dado=0, tam=0, opt=0, opc=0, x=0, disco_falha=0;

        discos = (int*) malloc(sizeof(int) * 5);
        vetor = (int*) malloc(sizeof(int) * 4);

        for(x=0;x<4;x++){
          vetor[x]=0;
          discos[x]=0;
        }

        do{
            printf("\nEscolha 1 opcao:\n1- RAID 3\n2- RAID 4\n3- Sair\n");
            scanf("%d", &opt);
            switch (opt){
                    case 1: //raid 3
                    do{
                      printf("\nEscolha 1 opcao:\n1- Escrever\n2- Simular falha\n3- Sair\n");
                      scanf("%d", &opc);
                      switch(opc){
                         case 1:
                            printf("Informe o tamanho do dado: 4 bytes ou 16 bytes:\n");
                            scanf("%d", &tam);
                            if(tam==4){
                              printf("Informe o dado que deseja escrever:\n");
                              scanf("%d", &dado);
                              printf("Informe em qual disco deseja escrever:\n");
                              scanf("%d", &n_disco);
                            }else{
                              x=0;
                              do{
                                 printf("Informe o dado para o disco %i:\n", x+1);
                                 scanf("%i", &dado);
                                 vetor[x] = dado;
                                 x++;
                               }while(x<4);
                            }
                            discos = escrita3(dado, vetor, discos, n_disco, tam);
                            break;

                        case 2:
                          printf("Informe o disco onde ocorreu a falha:\n");
                          scanf("%d", &disco_falha);
                          discos[disco_falha] = 0;
                          imprimir(discos);
                          falha(discos, disco_falha);
                          break;
                      }
                    }while(opc!=3);

                    break;
                  case 2: //raid 4
                  do{
                    printf("\nEscolha 1 opcao:\n1- Escrever\n2- Simular falha\n3- Sair\n");
                    scanf("%d", &opc);
                    switch(opc){
                       case 1:
                          printf("Informe o tamanho do dado: 4 bytes ou 16 bytes:\n");
                          scanf("%d", &tam);
                          if(tam==4){
                            printf("Informe o dado que deseja escrever:\n");
                            scanf("%d", &dado);
                            printf("Informe em qual disco deseja escrever:\n");
                            scanf("%d", &n_disco);
                          }else{
                            x=0;
                            do{
                               printf("Informe o dado para o disco %i:\n", x+1);
                               scanf("%i", &dado);
                               vetor[x] = dado;
                               x++;
                             }while(x<4);
                          }
                          discos = escrita4(dado, vetor, discos, n_disco, tam);
                          break;
                      case 2:
                        printf("Informe o disco onde ocorreu a falha:\n");
                        scanf("%d", &disco_falha);
                        discos[disco_falha] = 0;
                        imprimir(discos);
                        falha(discos, disco_falha);
                        break;
                    }
                  }while(opc!=3);
                      break;
                  case 3:
                      exit(0);
              }
        }while (opt != 4);
        return 0;
    }


int* escrita3(int dado, int* vetor, int* discos, int n_disco, int tam){
    int x;
    if(tam == 4){
      switch (n_disco) {
        case 1:
            discos[0] = dado ^ discos[2] ^ discos[3] ^ discos[4];
            discos[1] = dado;
            break;
        case 2:
            discos[0] = dado ^ discos[1] ^ discos[3] ^ discos[4];
            discos[2] = dado;
            break;
       case 3:
            discos[0] = dado ^ discos[2] ^ discos[1] ^ discos[4];
            discos[3] = dado;
            break;
      case 4:
            discos[0] = dado ^ discos[2] ^ discos[3] ^ discos[1];
            discos[4] = dado;
            break;
      }
    }else{
       discos[0] = vetor[0] ^ vetor[1] ^ vetor[2] ^ vetor[3];
       for(x=0;x<4;x++){
         discos[x+1] = vetor[x];
       }
    }

    imprimir(discos);
    return discos;
}

int* escrita4(int dado, int* vetor, int* discos, int n_disco, int tam){
  int x;
  if(tam == 4){
    switch (n_disco) {
      case 1:
          discos[0] = (discos[1] ^ dado) ^ discos[0];
          discos[1] = dado;
          break;
      case 2:
          discos[0] = (discos[2] ^ dado) ^ discos[0];
          discos[2] = dado;
          break;
     case 3:
          discos[0] = (discos[3] ^ dado) ^ discos[0];
          discos[3] = dado;
          break;
    case 4:
          discos[0] = (discos[4] ^ dado) ^ discos[0];
          discos[4] = dado;
          break;
    }
  }else{
     discos[0] = (discos[1] ^ vetor[0]) ^ (discos[2] ^ vetor[1]) ^ (discos[3] ^ vetor[2]) ^ (discos[4] ^ vetor[3]) ^ discos[0];
     for(x=0;x<4;x++){
       discos[x+1] = vetor[x];
     }

  }
  imprimir(discos);
  return discos;
}

void imprimir(int* discos){
    int x=1;
    printf("\n");
    printf("Backup: %i \n", discos[0]);
    do{
      printf("Disco %i: %i\n", x, discos[x]);
      x++;
    }while(x<=4);
    printf("\n");
}

int falha(int* discos, int falha){
  switch (falha) {
    case 1:
        discos[1] = discos[0] ^ (discos[2] ^ discos[3] ^ discos[4]);
        imprimir(discos);
        break;
    case 2:
        discos[2] = discos[0] ^ (discos[1] ^ discos[3] ^ discos[4]);
        imprimir(discos);
        break;
   case 3:
        discos[3] = discos[0] ^ (discos[2] ^ discos[1] ^ discos[4]);
        imprimir(discos);
        break;
  case 4:
        discos[4] = discos[0] ^ (discos[2] ^ discos[3] ^ discos[1]);
        imprimir(discos);
        break;
  }
}
