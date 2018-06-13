#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float bytetoBit(float x);
float bittoByte(float x);
float kbtoByte(float x);
float bytetoKb(float x);
int tamTag(int larg, int index, int offW, int offB);
int tamIndex(int conj);
int offsetByte(int larg);
int offsetWord(int bloco);
int numConj(float cap, int larg, int bloco, int vias);
float tamTotal(float cap, int larg, int bloco, int vias);
int tamanhoBloco(int index, int largEnd, int overhead);


int main() {
    float capUser = 0.0; //kb
    int largWord = 0; //bytes
    int tamBloco = 0; //words
    int largEnd; //bytes
    float overhead; //bytes
    int offB;
    int offW;
    int conj;
    int index;
    int tag;
    int vias;
    float total;
    int opc, opt;

    do {
        printf("\n==MENU==\n");
        printf("1 - Inserir informacoes da cache\n2 - Calcular tamanho total da cache\n3 - Mostrar outros dados da cache\n4 - Sair \n>>OPCAO:");
        scanf("%d", &opt);
        switch (opt) {
        case 1:
            printf("Informe a capacidade da cache para armazenamento de informacoes do usuario (KB): ");
            scanf("%f", &capUser);
            printf("Informe a largura da palavra (bytes): ");
            scanf("%d", &largWord);
            printf("Informe o tamanho do bloco (em palavras) : ");
            scanf("%d", &tamBloco);
            printf("Informe o numero de vias : ");
            scanf("%d", &vias);
            break;
            case 2:
                total = tamTotal(capUser, largWord, tamBloco, vias);
                printf(" O tamanho total da cache e %.2f ! \n", total);
                break;
            case 3:
                offB = offsetByte(largWord);
                offW = offsetWord(tamBloco);
                conj = numConj(capUser, largWord, tamBloco, vias);
                index = tamIndex(conj);
                tag = tamTag(largWord, index, offW, offB);

                printf(" A capacidade da cache para armazenamento de informacoes do usuario eh %.2f KB! \n",
                       capUser);
                printf(" A largura da palavra eh %i bytes!\n", largWord);
                printf(" O tamanho do bloco eh de %i palavras\n", tamBloco);
                printf(" O tamanho do offset de byte eh: %i bits! \n", offB);
                printf(" O tamanho do offset de palavra eh: %i bits! \n", offB);
                printf(" O numero de conjuntos da cache: %i! \n", conj);
                printf(" O tamanho do indice eh: %i bits! \n", index);
                printf(" O tamanho da tag eh: %i bits! \n", tag);
                printf(" O numero de vias eh: %i! \n", vias);
                break;
        }
    }while(opt!=4);
    return 0;
}

//funcoes de conversao de unidades

float bytetoBit(float x){
    x = x * 8;
    return x;
}

float bittoByte(float x){
    x = x / 8;
    return x;
}

float kbtoByte(float x){
    x = x * 1024;
    return x;
}

float bytetoKb(float x){
    x = x / 1024;
    return x;
}

//tamanho total da cache
float tamTotal(float cap, int larg, int bloco, int vias){
    int conjuntos = numConj(cap, larg, bloco, vias);
    int offB = offsetByte(larg);
    int offW = offsetWord(bloco);
    int index = tamIndex(conjuntos);
    int tag = tamTag(larg, index, offW, offB);
    float total;
    larg = (int)bytetoBit(larg);
    printf("%i larg\n", larg);
    printf("%i bloco\n", bloco);
    printf("%i vias\n", vias);
    printf("%i conjuntos\n", conjuntos);
    total = conjuntos * (3 + tag + (larg*bloco)) * vias;
    total = bittoByte(total);
    total = bytetoKb(total);
    return total;
}

//numero de conjuntos
int numConj(float cap, int larg, int bloco, int vias){
    int conjuntos;
    cap = kbtoByte(cap);
    conjuntos = (int)cap/(larg*bloco);
    conjuntos = conjuntos/vias;
    return conjuntos;
}

int offsetByte(int larg){
    int offset;
    offset = (int)(log10(larg)/log10(2));
    return offset;
}

int offsetWord(int bloco){
    int offset;
    offset = (int)(log10(bloco)/log10(2));
    return offset;
}

int tamIndex(int conj){
    int index;
    index = (int)((log10(conj))/(log10(2)));
    return index;
}

int tamTag(int larg, int index, int offW, int offB){
    int tag;
    larg = (int)bytetoBit(larg);
	offW = offW + 1;
    tag = larg - index - offW - offB;
    return tag;
}

int tamanhoBloco(int index, int largEnd, int overhead){
	int conj;
	int tag;
	int bitsValidade;
	int offsets; //op + ob
	int tamBloco;

	overhead = bytetoBit(overhead);
	largEnd = bytetoBit(largEnd);

	conj = pow(2, index); //calcula o tamanho do conjunto para determinar o tamanho da tag
	bitsValidade = pow(2, index);

	tag = (overhead - bitsValidade)/conj;
	offsets = (largEnd - index) - tag;

	tamBloco = pow(2, offsets);
    tamBloco = bytetoKb(tamBloco);

	return tamBloco;
}
