#include <stdlib.h>
#include <stdio.h>
#define MAX 100

typedef struct {
    int elementos[MAX];
    int tamanho;

} Lista;

void criarLista(Lista *lista);

int elementoFinal(Lista *lista, int valor);

int elementoPosicao(Lista *lista, int posi, int valor);

int removerElementoPosicao(Lista *lista, int posi);

int removerElementoValor(Lista *lista, int valor);

int obterElementoPosicao(Lista *lista, int posi, int *valor);

int procurarElemento(Lista *lista, int valor);

int tamanhoLista(Lista *lista);

void imprimirLista(Lista *lista);











/*01. Criar Lista: Inicializa uma nova lista vazia.
02. Inserir Elemento no Final: Adiciona um elemento inteiro ao final da lista.
03. Inserir Elemento em uma Posição: Adiciona um elemento inteiro em uma posição específica da lista.*/
