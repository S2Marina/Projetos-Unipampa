struct lista {
    Nodo* info;
    struct lista * prox;
}; typedef struct lista Lista;

struct pilha {
    Lista * prim;
    int tamanho;
}; typedef struct pilha Pilha;

struct fila {
    Lista * ini;
    Lista *fim;
    int tamanho;
};
typedef struct fila Fila;

Pilha * criapilha();
void pilhaPush(Pilha * p, Nodo* n);
Nodo* pilhaPop(Pilha * p);
void liberaPilha(Pilha * p);
void imprimePilha(Pilha * p);

Fila * criaFila();
void filaInsere(Fila* f, Nodo* n);
Nodo* filaRetira(Fila * f);
void liberaFila(Fila * f);
void imprimeFila(Fila* f);

void dfs(Grafo* grafo);
void bfs(Grafo* grafo);
