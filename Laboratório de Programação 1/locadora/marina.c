#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct filme{
    int codigo;
    char titulo[100];
    int ano;
    int quantidade;
    char genero[10];
};typedef struct filme Filme;

int nFilmes();
void carregarAcervo(Filme* filmes);
void carregar(Filme* filmes, Filme* f, int n);
Filme buscaPorCod(Filme* filmes, int c, int n);
void buscaPorTitulo(Filme* filmes, char titulo[], int n);
void buscaPorAno(Filme* filmes, int ano, int n);
void buscaPorGenero(Filme* filmes, char genero[], int n);
void locacao(Filme f, Filme* filmes);
void devolucao(Filme f, Filme* filmes, Filme* acervo);
void imprimir(Filme* filmes);
void imprimirFilme(Filme f);
void relatorio(Filme* filmes, int n);
void relatorioPorAno(Filme* filmes, int n, int ano);
void relatorioPorGenero(Filme* filmes, int n, char genero[]);

int main(int argc, char** argv) {
    Filme f;
    int i, b, n, m = 1;
    char string[100];
    
    n = nFilmes();
    Filme acervo[n];
    Filme filmes[n];
    carregarAcervo(acervo);
    carregar(acervo, filmes, n);
    
    do{
        carregar(filmes, filmes, n);
        printf("\n\nLocadora do Alcemar: \n 1-Locacao \n 2-Devolucao\n 3-Buscar filme\n 4-Imprimir filmes do acervo\n 5-Gerar relatorio\n 0-Sair\nOpcao: ");
        scanf("%i",&m);        
        switch(m){
            case 1:{ 
                printf("\nInforme o codigo do filme: ");
                scanf("%i", &i);
                f = buscaPorCod(filmes, i, n);
                if(f.codigo == 999){
                    printf("Filme nao encontrado!");
                }else{
                    locacao(f, filmes);
                    printf("Bom filme!!!");
                }            
                break;
            }
            case 2:{
                printf("\nInforme o codigo do filme: ");
                scanf("%i", &i);
                f = buscaPorCod(filmes, i, n);
                if(f.codigo == 999){
                    printf("Filme nao encontrado!");
                }else{
                    devolucao(f, filmes, acervo);
                    
                }            
                break;
            }
            case 3:{
                printf("  Busca por:\n   1-Codigo\n   2-Titulo\n   3-Ano\n   4-Genero\n  Opcao: ");
                scanf("%i", &b);
                switch(b){
                    case 1:{
                        printf("\nInforme o codigo do filme: ");
                        scanf("%i", &i);
                        f = buscaPorCod(filmes, i, n);
                        imprimirFilme(f);
                        break;
                    }
                    case 2:{
                        printf("\nInforme o titulo do filme: ");
                        fflush(stdin);
                        fgets(string, 100, stdin);
                        buscaPorTitulo(filmes, string, n);
                        break;
                    }
                    case 3:{
                        printf("\nInforme o ano do filme: ");
                        scanf("%i", &i);
                        buscaPorAno(filmes, i, n);
                        break;
                    } 
                    case 4:{
                        printf("\nInforme o genero do filme: ");
                        fflush(stdin);
                        fgets(string, 100, stdin);
                        buscaPorGenero(filmes, string, n);
                        break;
                    }
                    default:{
                        printf("Opcao invalida!!!");
                    }
                }
                break;
            }
            case 4:{
                imprimir(filmes);
                break;
            }
            case 5:{
                printf("  Gerar Relatorio: \n   1-Por ano\n   2-Por genero\n   3-Todo o acervo\n  Opcao:");
                scanf("%i",&b);
                switch(b){
                    case 1:{
                        printf("\nInforme o ano do filme: ");
                        scanf("%i", &i);
                        relatorioPorAno(filmes, n, i);
                        break;
                    }
                    case 2:{
                        printf("\nInforme o genero do filme: ");
                        fflush(stdin);
                        fgets(string, 100, stdin);
                        relatorioPorGenero(filmes, n, string);
                        break;
                    }
                    case 3:{
                        relatorio(filmes, n);
                        break;
                    }
                    default:{
                        printf("Opcao invalida!!!");
                    }
                }
                break;
            }
            case 0:{
                break;
            }
            default:{
                printf("Opcao invalida!!!");
                break;
            }
        }
    }while(m!=0);
    
    return (EXIT_SUCCESS);
}

void carregarAcervo(Filme * filmes){
    FILE *acervo;
    int n; //numero total de filmes
    int c=0;//codigo do filme  
    char texto[116]; //guarda o texto lido em uma linha do arquivo
    char titulo[100];
    char ano[4];
    char quantidade;
    char genero[10];
    int a; // usado para correcao de digitos do ano
    int y; //contadores
    int x=0;
    
    if((acervo=fopen("entrada.txt", "rt"))==NULL){
        printf("Erro ao abrir o arquivo!");
    }
   
    fseek(acervo,0,SEEK_SET);
    fscanf(acervo, "%i \n", &n);
    
    while(fscanf(acervo, "%[^\n]\n", texto)!=EOF){ //le o acervo linha por linha
        //printf("\n\n %s", texto);   
        y=0;
        while(texto[y]!=';'){ //le o texto da linha até o ;
           titulo[y]=texto[y]; //atribui esse texto ao titulo
           y++;
        }
        titulo[y]='\0'; //delimita os espaços de memoria usados pelo titulo
        y++; //corrige a posicao do y (pula o caracter do ;)
        x=0; 
        while(texto[y]!=';'){ //le o texto da linha até o proximo ;
            ano[x]=texto[y]; 
            y++;
            x++;
        }
        y++; //corrige a posicao do y (pula o caracter do ;)
        while(texto[y]!=';'){ //le o texto da linha até o proximo ;
            quantidade=texto[y];
            y++;
        }
        y++; //corrige a posicao do y (pula o caracter do ;)
        x=0;
        while(texto[y]!='\0'){ //le o texto da linha até o proximo ;
            genero[x]=texto[y];        
            x++;
            y++;
        }
        genero[x]='\0'; //delimita os espaços de memoria usados pelo titulo

        a = atoi(ano); //converte o ano para int
                  
        //corrige a quantidade de caracteres do ano
        if(a>10000000){
            a = a /10000;
        }
        if(a>1000000){
            a = a/1000;
        }
        if(a>100000){
            a = a/100;
        }
        if(a>10000){
            a = a/10;
        }
        
        strcpy(filmes[c].titulo, titulo);
        filmes[c].ano = a;
        filmes[c].quantidade = quantidade - '0';
        strcpy(filmes[c].genero, genero);
        filmes[c].codigo=c;
        c++;
        
    }

    fclose(acervo);
}

Filme buscaPorCod(Filme* filmes, int c, int n){
    int x;
    Filme f;
    f.codigo = 999;
    for(x=0;x<n;x++){
        if(filmes[x].codigo == c){
            f = filmes[x];
        }
    }   
    return f;
}

int nFilmes(){
    FILE* acervo;
    int n;
    
    if((acervo=fopen("entrada.txt", "rt"))==NULL){
        printf("Erro ao abrir o arquivo!");
    }
    
    fseek(acervo,0,SEEK_SET);
    fscanf(acervo, "%i \n", &n);
    
    fclose(acervo);
    return n;
}

void locacao(Filme f, Filme* filmes){
    if(filmes[f.codigo].quantidade!=0){
        filmes[f.codigo].quantidade--;
    }else{
        printf("Filme nao disponivel!!!");
    }
}

void imprimir(Filme* filmes){
    int x, n;
    n = nFilmes();
    for(x=0;x<n;x++){
        printf("\n\nCodigo: %i", filmes[x].codigo);
        printf("\nTitulo: %s", filmes[x].titulo);       
        printf("\nAno: %d", filmes[x].ano);   
        printf("\nQuantidade: %d", filmes[x].quantidade);       
        printf("\nGenero: %s\n", filmes[x].genero);
    }
}

void imprimirFilme(Filme f){
     printf("\n\nCodigo: %i", f.codigo);
     printf("\nTitulo: %s", f.titulo);       
     printf("\nAno: %d", f.ano);   
     printf("\nQuantidade: %d", f.quantidade);       
     printf("\nGenero: %s\n", f.genero);
    
}

void carregar(Filme* filmes, Filme* f, int n){
    FILE *acervo;
    int x;

    if((acervo=fopen("acervo.txt", "w"))==NULL){
        printf("Erro ao abrir o arquivo!");
    }
   
    fseek(acervo,0,SEEK_SET);
    fprintf(acervo, "%i \n", n);
    
    for(x=0;x<n;x++){
        fprintf(acervo,"%s;", filmes[x].titulo);
        fprintf(acervo,"%i;", filmes[x].ano);
        fprintf(acervo,"%i;", filmes[x].quantidade);
        fprintf(acervo,"%s \n", filmes[x].genero);
        
        strcpy(f[x].titulo,filmes[x].titulo);
        f[x].ano = filmes[x].ano;
        f[x].quantidade = filmes[x].quantidade;
        strcpy(f[x].genero,filmes[x].genero);
        f[x].codigo = x;
    }
    
    fclose(acervo);
}

void devolucao(Filme f, Filme* filmes, Filme* acervo){
    int q; //quantidade original do filme
    q = acervo[f.codigo].quantidade;
    
    if(filmes[f.codigo].quantidade<q){
        filmes[f.codigo].quantidade++;
        printf("Filme devolvido com sucesso!!!");
    }else{
        printf("Nao e possivel devolver esse filme!!!");
    }
}

void buscaPorTitulo(Filme* filmes, char titulo[], int n){
    int x, c=0;
    for(x=0;x<n;x++){
        if(strcasecmp(filmes[x].titulo, strtok(titulo, "\n"))==0){
            imprimirFilme(filmes[x]);
            c++;
        }
    }
    if(c==0){
        printf("\nFilme nao encontrado! :( \n");
    }
}

void buscaPorAno(Filme* filmes, int ano, int n){
    int x, c = 0;
    for(x=0;x<n;x++){
        if(filmes[x].ano == ano){
            imprimirFilme(filmes[x]);
            c++;
        }
    }
    if(c==0){
        printf("\nFilme nao encontrado! :(\n");
    }
}

void buscaPorGenero(Filme* filmes, char genero[], int n){
    int x, c=0;
    for(x=0;x<n;x++){
        if(strcasecmp(filmes[x].genero, strtok(genero, "\n"))==0){
            imprimirFilme(filmes[x]);
            c++;
        }
    }
    if(c==0){
        printf("\nFilme nao encontrado! :(\n");
    }
}

void relatorio(Filme* filmes, int n){
    FILE *acervo;
    int x;

    if((acervo=fopen("acervo_completo_atual.txt", "w"))==NULL){
        printf("Erro ao abrir o arquivo!");
    }
   
    fseek(acervo,0,SEEK_SET);
    
    for(x=0;x<n;x++){
        fprintf(acervo,"%s;", filmes[x].titulo);
        fprintf(acervo,"%i;", filmes[x].ano);
        fprintf(acervo,"%i;", filmes[x].quantidade);
        fprintf(acervo,"%s \n", filmes[x].genero);
    }
    
    fclose(acervo);
}
void relatorioPorAno(Filme* filmes, int n, int ano){
    FILE *acervo;
    int x;

    if((acervo=fopen("relatorioAno.txt", "w"))==NULL){
        printf("Erro ao abrir o arquivo!");
    }
   
    fseek(acervo,0,SEEK_SET);
    printf("%i", ano);
    
    for(x=0;x<n;x++){
        if(filmes[x].ano == ano){
            fprintf(acervo,"%s;", filmes[x].titulo);
            fprintf(acervo,"%i;", filmes[x].ano);
            fprintf(acervo,"%i;", filmes[x].quantidade);
            fprintf(acervo,"%s \n", filmes[x].genero);
        }
    }
    
    fclose(acervo);
}

void relatorioPorGenero(Filme* filmes, int n, char genero[]){
    FILE *acervo;
    int x;

    if((acervo=fopen("relatorioGenero.txt", "w"))==NULL){
        printf("Erro ao abrir o arquivo!");
    }
   
    fseek(acervo,0,SEEK_SET);
    fprintf(acervo, "%s \n", genero);
    
    for(x=0;x<n;x++){
        if(strcasecmp(filmes[x].genero, strtok(genero, "\n"))==0){
            fprintf(acervo,"%s;", filmes[x].titulo);
            fprintf(acervo,"%i;", filmes[x].ano);
            fprintf(acervo,"%i;", filmes[x].quantidade);
            fprintf(acervo,"%s \n", filmes[x].genero);
        }
    }
    
    fclose(acervo);
}
