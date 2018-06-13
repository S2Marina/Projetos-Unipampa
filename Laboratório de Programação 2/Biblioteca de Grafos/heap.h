//Heap mínima

//função que constroi um novo heap com o elemento inserido
Aresta ** buildHeap(Aresta** heap, int tamanho, Aresta* elemento);

//função para deletar o elemento da heap
Aresta ** deleteHeap(Aresta** heap, int tamanho);

//função para imprimir o estado atual da heap
void printHeap(Aresta** heap, int tamanho);

//função sift-down para posicionar os elementos da heap
Aresta** siftDown(Aresta** heap, int tamanho);

//função percolate para posicionar os elementos da heap
Aresta **  percolate(Aresta** heap, int tamanho);

//retorna o maior da heap
Aresta* getRaiz(Aresta** heap);

//retorna numero de elementos da heap
int getTamanho(Aresta **heap);

