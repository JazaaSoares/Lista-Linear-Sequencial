#include "lista.h"
#include <stdlib.h>

struct Lista {
    int elementos[MAX];
    int tamanho;
};

void criarLista(Lista *lista){
    lista->tamanho = 0;
}

int elementoNoFinal(Lista *lista, int valor){

    if(lista->tamanho > MAX){
        printf("-LISTA CHEIA-");
        return 0;
    }
    lista->elementos[lista->tamanho] = valor;
        lista->tamanho++;
        return 1;

} // : Adiciona um elemento inteiro ao final da lista.

int inserirElementoPosicao(Lista *lista, int posi, int valor){

    if (posi < 0 || posi >= MAX) {
        printf("ERRO -POSICAO INVALIDA-\n");
        return 0;
    }

    if (posi < lista->tamanho) {
        lista->elementos[posi] = valor;
        printf("Valor inserido com sucesso!");
        return 1;
    }

    if (posi == lista->tamanho) {
        lista->elementos[posi] = valor;
        lista->tamanho++;
        printf("Valor inserido com sucesso!");
        return 1;
    }

    printf("ERRO -POSICAO INVALIDA-\n");
    return 0;

} //Adiciona um elemento inteiro em uma posição específica da lista


int removerElementoPosicao(Lista *lista, int posi){

    if (posi < 0 || posi >= lista->tamanho){
       printf("ERRO -POSICAO INVALIDA-\n");
       return 0;
    }
    for (int i = posi; i < lista->tamanho - 1; i++){
        lista->elementos[i] = lista->elementos[i+1];
    }
    lista->tamanho--;
    printf("Elemento removido com sucesso!");
    return 1;

} // remoção em posição específica

int removerElementoValor(Lista *lista, int valor){

    int posi = -1;
    for (int i = 0; i < lista->tamanho; i++){
        if(lista->elementos[i] == valor){
            posi = i;
        }
    }
    if(posi == -1){
        printf("-ELEMENTO NAO ENCONTRADO-");
        return 0;
    }
    printf("Valor removido com sucesso!");
    return removerElementoPosicao(lista, posi);
}

int obterElementoPosicao(Lista *lista, int posi, int *valor){

    if (posi < 0 || posi >= lista->tamanho){
        printf("-POSICAO INVALIDA!-");
        return 0;
    }
    *valor = lista->elementos[posi];
    return 1;
}

int procurarElemento(Lista *lista, int valor){

    int i = 0;
    while (i < lista ->tamanho){
        if (lista->elementos[i] == valor){
            return i;
        }
        i++;
    }

     return -1;
}


int tamanhoLista(Lista *lista){
    return lista->tamanho;
}


void imprimirLista(Lista *lista){

    printf("-LISTA-\n");
    for (int i = 0; i < lista->tamanho; i++) {
        printf("%d ", lista->elementos[i]);
    }
    printf("\n");
}

void liberarLista(Lista *lista){
    lista->tamanho = 0;
    for(int i=0;i<MAX; i++){
        lista->elementos[i] = NULL;
    }
}

void menu() {
    Lista lista;
    criarLista(&lista);
    int opc, valor, posicao, resultado;

    do {
        printf("    ===== MENU =====\n");
        printf("1. Inserir elemento no final\n");
        printf("2. Inserir elemento em uma posicao especifica\n");
        printf("3. Remover elemento por posicao\n");
        printf("4. Remover elemento por valor\n");
        printf("5. Obter elemento por posicao\n");
        printf("6. Procurar elemento por valor\n");
        printf("7. Mostrar tamanho da lista\n");
        printf("8. Imprimir lista\n");
        printf("0. Sair\n");
        printf("==========================\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opc);

        system("cls || clear");

        switch (opc) {
            case 1:
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &valor);
                elementoNoFinal(&lista, valor);
                printf("Valor inserido com sucesso!");
                sleep(1);
                system("cls || clear");
                break;
            case 2:
                printf("Digite a posicao onde deseja inserir: ");
                scanf("%d", &posicao);
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &valor);
                inserirElementoPosicao(&lista, posicao, valor);
                sleep(1);
                system("cls || clear");
                break;
            case 3:
                printf("Digite a posicao do elemento a ser removido: ");
                scanf("%d", &posicao);
                removerElementoPosicao(&lista, posicao);
                sleep(1);
                system("cls || clear");
                break;
            case 4:
                printf("Digite o valor do elemento a ser removido: ");
                scanf("%d", &valor);
                removerElementoValor(&lista, valor);
                sleep(1);
                system("cls || clear");
                break;
            case 5:
                printf("Digite a posicao do elemento: ");
                scanf("%d", &posicao);
                if (obterElementoPosicao(&lista, posicao, &valor)) {
                    printf("Valor na posicao %d: %d\n", posicao, valor);
                }
                sleep(1);
                system("cls || clear");
                break;
            case 6:
                printf("Digite o valor a ser procurado: ");
                scanf("%d", &valor);
                resultado = procurarElemento(&lista, valor);
                if (resultado != -1) {
                    printf("Elemento encontrado na posicao: %d\n", resultado);
                } else {
                    printf("Elemento não encontrado\n");
                }
                sleep(1);
                system("cls || clear");
                break;
            case 7:
                printf("Tamanho da lista: %d\n", tamanhoLista(&lista));
                sleep(1);
                system("cls || clear");
                break;
            case 8:
                imprimirLista(&lista);
                system("pause");
                system("cls || clear");
                break;
            case 0:
                liberarLista(&lista);
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao inválida\n");
                sleep(1);
                system("cls || clear");
                break;
        }
    } while (opc != 0);
}



