#include "lista.h"
#include <stdlib.h>


void criarLista(Lista *lista){
    lista -> tamanho = 0;

}

int elementoFinal(Lista *lista, int valor);




int elementoPosicao(Lista *lista, int posi, int valor){
    if (lista->tamanho >= MAX){
        printf("ERRO -LISTA CHEIA-\n");
        return 0; //conferir agui
    }
    if (posi < 0 || posi > lista->tamanho){
        printf("ERRO -POSIÇÃO INVÁLIDA-\n");
        return 0; // e agui

    for (int i = lista->tamanho; i > posi; i--) {
        lista->elementos[i] = lista->elementos[i - 1];
    }
    lista->elementos[posi] = valor;
    lista->tamanho++;
    return 1; // e agui

}




int removerElementoPosicao(Lista *lista, int posi){
    if (posi < 0 || posi >= lista->tamanho){
       printf("ERRO -POSIÇÃO INVÁLIDA-\n");
       return 0;
    }
    for (int i = posi; i < lista->tamanho - 1; i++){
        lista->elementos[i] = lista->elementos[i+1];
    }
    lista->tamanho--;
    return 1;

}




int removerElementoValor(Lista *lista, int valor);




int obterElementoPosicao(Lista *lista, int posi, int *valor);




int procurarElemento(Lista *lista, int valor){
    int i = 0;
    while (i < lista ->tamanho){
        if (lista->elementos[i] == valor){
            return i; //posiçao do elemento encontrado
        }
        i++
    }

     return -1 //elemento nao foi encontrado
}
