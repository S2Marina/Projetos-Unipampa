struct aresta {
  int chave_adj; //destino
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

struct listaNodos{
    int chave;
    struct listaNodos *prox;
};typedef struct listaNodos Lista;


Nodo* criaNodo();
Aresta* criaAresta();
Grafo* criaGrafo();
Aresta* insereAresta(Nodo* n, int chave, int peso);
Grafo* lerArquivo();
void imprimirGrafo(Grafo* g);
Lista* dfs(Nodo* nodo);
void imprimirLista(Lista* lista);