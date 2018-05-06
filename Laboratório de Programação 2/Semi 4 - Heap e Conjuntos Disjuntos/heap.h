//Heap mínima

//função que constroi um novo heap com o elemento inserido
int *buildHeap (int *heap,int tamanho,int elemento);

//função para deletar o elemento da heap
int * deleteHeap(int *heap,int tamanho);

//função para imprimir o estado atual da heap
void printHeap(int *heap,int tamanho);

//função sift-down para posicionar os elementos da heap
int * siftDown(int* heap, int tamanho);

//função percolate para posicionar os elementos da heap
int * percolate(int* heap, int tamanho);

//retorna o maior da heap
int getRaiz(int *heap);
