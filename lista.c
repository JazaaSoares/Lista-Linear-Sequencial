#include "lista.h"
#include <stdlib.h>


void criarLista(Lista *lista){
    lista->tamanho = 0;

}

int elementoNoFinal(Lista *lista, int valor){

    if(lista->tamanho > MAX){
        printf("-LISTA CHEIA-")
        return 0;
    }
    lista->elementos[lista->tamanho] = valor;
        lista->tamanho++
        return 1;

} // : Adiciona um elemento inteiro ao final da lista.



int inserirElementoPosicao(Lista *lista, int posi, int valor){

    if (lista->tamanho >= MAX){
        printf("ERRO -LISTA CHEIA-\n");
        return 0; //conferir agui
    }
    if (posi < 0 || posi > lista->tamanho){
        printf("ERRO -POSI��O INV�LIDA-\n");
        return 0; // e agui

    for (int i = lista->tamanho; i > posi; i--) {
        lista->elementos[i] = lista->elementos[i - 1];
    }
    lista->elementos[posi] = valor;
    lista->tamanho++;
    return 1; // e agui

}
} //Adiciona um elemento inteiro em uma posi��o espec�fica da lista


int removerElementoPosicao(Lista *lista, int posi){

    if (posi < 0 || posi >= lista->tamanho){
       printf("ERRO -POSI��O INV�LIDA-\n");
       return 0;
    }
    for (int i = posi; i < lista->tamanho - 1; i++){
        lista->elementos[i] = lista->elementos[i+1];
    }
    lista->tamanho--;
    return 1;

} // remo��o em posi��o espec�fica

int removerElementoValor(Lista *lista, int valor){

    int posi = -1;
    for (int i = 0; i < lista->tamanho; i++){
        if(lista->elementos[i] == valor){
            posi = i;
        }
    }
    if(posi == -1){
        printf("-ELEMENTO N�O ENCONTRADO-");
        return 0;
    }

    return removerElementoPosicao(lista, posi);


}


int obterElementoPosicao(Lista *lista, int posi, int *valor){

    if (posi < 0 || posi >= lista->tamanho){
        printf("-POSI��O INV�LIDA!-");
        return 0;
    }
    *valor = lista->elementos[posi]
    return 1;
}



int procurarElemento(Lista *lista, int valor){

    int i = 0;
    while (i < lista ->tamanho){
        if (lista->elementos[i] == valor){
            return i; //posi�ao do elemento encontrado
        }
        i++
    }

     return -1 //elemento nao foi encontrado
}


int tamanhoLista(Lista *lista){
    return lista->tamanho;

}


void imprimirLista(Lista *lista){

    printf("-LISTA-");
    for (int i = 0; i < lista->tamanho; i++) {
        printf("%d ", lista->elementos[i]);
    }

    printf("\n");
}

