struct tabela {
  int codigo;
  char desc[40];
  float valor;
};
typedef struct tabela Tabela;

void imprimir(Tabela* hash);
Tabela* inserir (Tabela* hash);
Tabela* inicializa(Tabela *hash);
int endereco(int codigo);
void consultar(Tabela* hash);
