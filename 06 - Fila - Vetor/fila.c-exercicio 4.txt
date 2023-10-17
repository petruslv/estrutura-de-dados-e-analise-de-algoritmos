//fila.c

#include <stdio.h>
#include <stdlib.h>

#include "filacircular.h"

int main() {
    int opcao;
    float valor;
    struct Fila umaFila;

    criarFila(&umaFila);
    printf("A fila possui 5 posições!\n");

    while (1) {
        printf("1 - Inserir elemento\n2 - Remover elemento\n3 - Mostrar Fila\n0 - Sair\n\nOpcao? ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 0:
                exit(0);

            case 1:
                if (estaCheia(&umaFila)) {
                    printf("\nFila Cheia!!!\n\n");
                } else {
                    printf("\nValor do elemento a ser inserido? ");
                    scanf("%f", &valor);
                    inserir(&umaFila, valor);
                }
                break;

            case 2:
                if (estaVazia(&umaFila)) {
                    printf("\nFila vazia!!!\n\n");
                } else {
                    valor = remover(&umaFila);
                    printf("\n%.2f removido com sucesso\n\n", valor);
                }
                break;

            case 3:
                mostrarFila(&umaFila);
                break;

            default:
                printf("\nOpcao Invalida\n\n");
        }
    }
}