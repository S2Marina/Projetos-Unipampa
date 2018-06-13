struct aresta {
  int chave_adj; //destino
  int chave_partida;
  int peso;
  struct aresta *prox;
};
typedef struct aresta Aresta;

struct nodo {
  int chave; //origem
  struct nodo *prox;
  struct aresta *adj;
};
typedef struct nodo Nodo;

struct grafo {
  struct nodo *listaNodos;
  int tamanho;
};
typedef struct grafo Grafo;

Nodo* criaNodo();
Aresta* criaAresta(int origem, int destino, int peso);
Grafo* criaGrafo(int tamanho);
void insereAresta(Nodo* n, int origem, int destino, int peso);
Grafo* lerArquivo();
void imprimirGrafo(Grafo* g);
