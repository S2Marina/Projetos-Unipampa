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
int numConj(float cap, int larg, int bloco);
float tamTotal(float cap, int larg, int bloco);
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
    float total;
    int opc, opt;

    do {
        printf("\n==MENU==\n");
        printf("1- Parte 1\n2- Parte 2\n3- Sair\n>>OPCAO:");
        scanf("%d", &opc);
        switch (opc) {
            case 1:
                do {
                    printf("1 - Inserir informacoes da cache\n2 - Calcular tamanho total da cache\n3 - Mostrar outros dados da cache\n4 - Voltar \n>>OPCAO:");
                    scanf("%d", &opt);
                    switch (opt) {
                        case 1:
                            printf("Informe a capacidade da cache para armazenamento de informacoes do usuario (KB): ");
                            scanf("%f", &capUser);
                            printf("Informe a largura da palavra (bytes): ");
                            scanf("%d", &largWord);
                            printf("Informe o tamanho do bloco (em palavras) : ");
                            scanf("%d", &tamBloco);
                            break;
                        case 2:
                            total = tamTotal(capUser, largWord, tamBloco);
                            printf(" O tamanho total da cache e %.2f ! \n", total);
                            break;
                        case 3:
                            offB = offsetByte(largWord);
                            offW = offsetWord(tamBloco);
                            conj = numConj(capUser, largWord, tamBloco);
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
                            break;
                    }
                }while(opt!=4);
                break;
            case 2:
                 do {
                    printf("1 - Inserir informacoes da cache\n2 - Calcular tamanho do bloco de memoria da cache\n3 - Mostrar outros dados da cache\n4 - Voltar \n>>OPCAO:");
                    scanf("%d", &opt);
                    switch (opt) {
                        case 1:
                            printf("Informe o numero de bits do campo de indice do endereco: ");
                            scanf("%i", &index);
                            printf("Informe a largura do endereco (bytes): ");
                            scanf("%i", &largEnd);
                            printf("Informe overhead da cache (bytes) : ");
                            scanf("%f", &overhead);
                            break;
                        case 2:
                            tamBloco = tamanhoBloco(index, largEnd, overhead);
                            printf("\n O tamanho do bloco de memoria da cache e %i bytes por endereco! \n\n", tamBloco);
                            break;
                        case 3:
							conj = pow(2, index);
							offW = offsetWord((tamBloco/4));
							printf("offw %i \n", offW);
							offB = offsetByte(largEnd);
							tag = tamTag(largEnd, index, offW, offB);

                            printf("\n A largura da palavra eh %i bytes!\n", largEnd);
                            printf(" O tamanho do offset de byte eh: %i bits! \n", offB);
                            printf(" O tamanho do offset de palavra eh: %i bits! \n", offB);
                            printf(" O numero de conjuntos da cache: %i! \n", conj);
                            printf(" O tamanho do indice eh: %i bits! \n", index);
                            printf(" O tamanho da tag eh: %i bits! \n\n", tag);
                            break;
                    }
                }while(opt!=4);
                break;
        }

    }while(opc!=3);

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
float tamTotal(float cap, int larg, int bloco){
    int conjuntos = numConj(cap, larg, bloco);
    int offB = offsetByte(larg);
    int offW = offsetWord(bloco);
    int index = tamIndex(conjuntos);
    int tag = tamTag(larg, index, offW, offB);
    float total;
    larg = (int)bytetoBit(larg);
    total = conjuntos * (1 + tag + (larg*bloco));
    total = bittoByte(total);
    total = bytetoKb(total);
    return total;
}
//numero de conjuntos
int numConj(float cap, int larg, int bloco){
    int conjuntos;
    cap = kbtoByte(cap);
    conjuntos = (int)cap/(larg*bloco);
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
