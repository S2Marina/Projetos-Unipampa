struct nodo {
  int codigo;
  char desc[40];
  float valor;
  struct nodo *prox;
};
typedef struct nodo Nodo;

Nodo** criaTabela(int tamanho);
