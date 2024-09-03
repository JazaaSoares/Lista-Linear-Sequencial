#include <stdlib.h>
#include <stdio.h>
#define MAX 100

typedef struct Lista Lista;

void criarLista(Lista *lista);
int elementoNoFinal(Lista *lista, int valor);
int inserirElementoPosicao(Lista *lista, int posi, int valor);
int removerElementoPosicao(Lista *lista, int posi);
int removerElementoValor(Lista *lista, int valor);
int obterElementoPosicao(Lista *lista, int posi, int *valor);
int procurarElemento(Lista *lista, int valor);
int tamanhoLista(Lista *lista);
void imprimirLista(Lista *lista);
void liberarLista(Lista *lista);












