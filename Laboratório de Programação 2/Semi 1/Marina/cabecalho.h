struct descritorPilha {
	int quantidade;
	int maximo;
	struct InformacoesAlunos *topo;
}; typedef struct descritorPilha Pilha;

struct InformacoesAlunos{
	int matricula;
	char nome[50];
	float media;
	struct InformacoesAlunos *prox;
}; typedef struct InformacoesAlunos aluno;

Pilha * criarPilha(int max);
void inserir(Pilha * p, int mat, char nome[50], float media);
aluno remover(Pilha* p);
void liberar(Pilha* p);
void imprimir(Pilha * p);
void buscar(Pilha *p, int matricula);
int tamanho(Pilha *p);
