//Módulo E

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int* AbrirArquivo(int *count);
int Resto(int nend, int nconj);
void Cache16(int *vet, int count);
void Cache4x4(int *vet, int count);
void Cache4vias(int *vet, int count);

int main() {
    int count, *vet, opt;
    vet = AbrirArquivo(&count);
    do{
        printf("\nEscolha 1 opcao:\n1- Cache 16 x 1\n2- Cache 4 x 4\n3- Cache 4 vias\n4- Sair\n");
        scanf("%d", &opt);
        switch (opt){
            case 1:
                Cache16(vet,count);
                break;
            case 2:
                Cache4x4(vet,count);
                break;
            case 3:
                Cache4vias(vet,count);
                break;
            case 4:
                exit(0);
        }
    }while (opt != 4);
    return 0;
}


int* AbrirArquivo(int *count){
    FILE *fp;
    char linha[50], *res;
    int *vet = NULL, i=0, aux;
    if((fp = fopen("enderecos.txt", "rt")) == NULL){
        printf("Erro ao abrir o arquivo!\n");
        exit(0);
    }
    (*count) = 0;
    while(!feof(fp)){
        fgets(linha,50,fp);
        (*count)++;
    }
    vet = (int*)malloc(sizeof(int)*(*count));
    rewind(fp);
    while(!feof(fp)){
        res = fgets(linha,50,fp);
        vet[i] = atoi(res);
        i++;
    }
    fclose(fp);
    return vet;
}

int Resto(int nend, int nconj){
    int alvo;
    alvo = nend % nconj;
    return alvo;
}
void Cache16(int *vet, int count){
    printf("Cache diretamente mapeada 16 blocos x 1 palavra:\n");
    int acerto = 0, falha = 0, x=0;
    int  cache[16];
    for (int i = 0; i < 16; i++) {
        cache[i] = 0;
    }
    for (int j = 0; j < count; j++) {
        x=0;
        printf("---->Vet - %d:\n",vet[j]);
        for (int i = 0; i < 16; i++) {
            printf("Cache [%d]- %d\n", i, cache[i]);
            if (vet[j] == cache[i]){
                printf("Acerto!! Encontrado em %d \n", i);
                acerto++;
                x++;
            }
        }
        if (x == 0){
            falha++;
            printf("Falha!! Armazenado em %d\n", Resto(vet[j],16) );
            cache[Resto(vet[j],16)] = vet[j];
        }
    }
    printf("Num de acertos: %d\n", acerto);
    printf("Num de falhas: %d\n", falha);
}

void Cache4x4(int *vet, int count){
    printf("Cache diretamente mapeada 4 blocos x 4 palavras:\n");
    int acerto = 0, falha = 0, x=0;
    int  cache[4];
    for (int i = 0; i < 4; i++) {
        cache[i] = 0;
    }
    for (int j = 0; j < count; j++) {
        x=0;
        printf("---->Vet - %d:\n",vet[j]);
        for (int i = 0; i < 4; i++) {
            printf("Cache [%d]- %d\n", i, cache[i]);
            if (vet[j] == cache[i]){
                printf("Acerto!! Encontrado em %d \n", i);
                acerto++;
                x++;
            }
        }
        if (x == 0){
            falha++;
            printf("Falha!! Armazenado em %d\n", Resto(vet[j],4) );
            cache[Resto(vet[j],4)] = vet[j];
        }
    }
    printf("Num de acertos: %d\n", acerto);
    printf("Num de falhas: %d\n", falha);
}

void Cache4vias(int *vet, int count) {
    printf("Cache associativa 4 vias:\n");
    int acerto = 0, falha = 0, z = 0;
    int cache[4][4];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; ++j) {
            cache[i][j] = 0;
        }
    }
    int via;
    int c1, c2, c3, c4;
    c1 = c2 = c3 = c4 = 0;
    for (int k = 0; k < count; k++) {
        printf("---->Vet - %d:\n",vet[k]);
        z = 0;
        for (int x = 0; x < 4; x++) {
            for (int y = 0; y < 4; y++) {
                printf("Cache[%d][%d]- %d\n", x, y, cache[x][y]);
                if (vet[k] == cache[x][y]) {
                    printf("Acerto!! Encontrado em [%d][%d] \n", x,y);
                    acerto++;
                    z++;
                }
            }
        }
        if (z == 0) {
            falha++;
            via = Resto(vet[k], 4);
            switch (via) {
                case 0:
                    printf("Falha!! Armazenado em [%d][%d]\n", via, c1 );
                    cache[via][c1++] = vet[k];
                    break;
                case 1:
                    printf("Falha!! Armazenado em [%d][%d]\n", via, c2 );
                    cache[via][c2++] = vet[k];
                    break;
                case 2:
                    printf("Falha!! Armazenado em [%d][%d]\n", via, c3 );
                    cache[via][c3++] = vet[k];
                    break;
                case 3:
                    printf("Falha!! Armazenado em [%d][%d]\n", via, c4 );
                    cache[via][c4++] = vet[k];
                    break;
            }
        }
        printf("Num de acertos: %d\n", acerto);
        printf("Num de falhas: %d\n", falha);
    }
}
