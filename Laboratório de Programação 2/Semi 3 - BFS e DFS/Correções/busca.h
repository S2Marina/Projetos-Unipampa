struct lista {
    int info;
    struct lista * prox;
}; typedef struct lista Lista;

struct pilha {
    Lista * prim;
    int tamanho;
}; typedef struct pilha Pilha;

Pilha * criapilha();
void pilhaPush(Pilha * p, int n);
int pilhaPop(Pilha * p);
void liberaPilha(Pilha * p);
void imprimePilha(Pilha * p);
void dfs(Nodo* nodo);
