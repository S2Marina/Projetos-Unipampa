#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float bytetoBit(float x);
float bittoByte(float x);
float kbtoByte(float x);
float bytetoKb(float x);
int tamanhoTag(int largura, int index, int offset);
int tamanhoIndex(int conjuntos);
int offsetByte(int largura);
int numConjuntos(float cap, int largura);
float tamanhoTotal(float cap, int largura);


int main(int argc, char **argv)
{
	float capacidadeDoUsuario; //kb
	int larguraDaPalavra; //bytes
	int offset;
	int conjuntos;
	int indice;
	int tag;
	float total;
	int opc;
	
	do {
        printf("\n==MENU==\n");
        printf(" 0-Sair\n 1 - Inserir informacoes da cache\n 2 - Calcular tamanho total da cache\n 3 - Mostrar outros dados da cache \n>>OPCAO:");
        scanf("%d", &opc);
        switch (opc) {
			case 1: 
				printf("Informe a capacidade da cache para armazenamento de informações do usuário (KB):");
				scanf("%f", &capacidadeDoUsuario);
				printf("Informe a largura da palavra (bytes):");
				scanf("%i", &larguraDaPalavra);
				break;
			case 2:
				total = tamanhoTotal(capacidadeDoUsuario, larguraDaPalavra);
				printf(" O tamanho total da cache e %.2f ! \n", total);
				break;
			case 3:
				offset = offsetByte(larguraDaPalavra);
				conjuntos = numConjuntos(capacidadeDoUsuario, larguraDaPalavra);
				indice = tamanhoIndex(conjuntos);
				tag = tamanhoTag(larguraDaPalavra, indice, offset);
				
			    printf(" A capacidade da cache para armazenamento de informações do usuário e %.2f ! \n", capacidadeDoUsuario);
				printf(" A largura da palavra e %i!\n", larguraDaPalavra);
				printf(" O tamanho do offset de byte e: %i! \n", offset);
				printf(" O numero de conjuntos da cache: %i! \n", conjuntos);
				printf(" O tamanho do indice e: %i! \n", indice);
				printf(" O tamanho da tag e: %i! \n", tag);
				
				break;
			
		}	
			
	}while(opc!=0);		
	
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
	
	float tamanhoTotal(float cap, int largura){
		int conjuntos = numConjuntos(cap, largura);
		int offset = offsetByte(largura);
		int index = tamanhoIndex(conjuntos);
		int tag = tamanhoTag(largura, index, offset);
	    float total;
	    largura = bytetoBit(largura);
	    total = conjuntos * (1 + tag + largura);	
	    total = bittoByte(total);
	    total = bytetoKb(total);
	    return total;
	}
	
	int numConjuntos(float cap, int largura){
		int conjuntos;
		cap = kbtoByte(cap);
		conjuntos = cap/largura;
		return conjuntos;
	} 
	
	int offsetByte(int largura){
		int offset;
		offset = log10(largura)/log10(2);
		return offset;
	}
	
	int tamanhoIndex(int conjuntos){
		int index;
		index = (log10(conjuntos))/(log10(2));
		return index;
	}
	
	int tamanhoTag(int largura, int index, int offset){
		int tag;
		largura = bytetoBit(largura);
		tag = largura - index - offset;
		return tag;
	}
	
	
	
