struct nodo {
  int codigo;
  char desc[40];
  float valor;
  struct nodo *prox;
};
typedef struct nodo Nodo;
#define TAM 5
Nodo *tabela[TAM];
void inicializa(void);
void criaTabela(void);
void imprime(void);
void busca(int valor);
