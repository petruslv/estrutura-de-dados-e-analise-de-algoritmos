#include <stdio.h>
#include <stdlib.h>

#define TAM_MAX 5  // Tamanho máximo da pilha

typedef int elemento;

#include "pilhacircular.h"



int main() {
    PilhaCircular pilha;
    CriarPilha(&pilha);

    int opcao, valor;

    do {
        printf("Escolha uma opção:\n");
        printf("1. Empilhar\n");
        printf("2. Desempilhar\n");
        printf("3. Imprmir Pilha\n"); 
        printf("0. Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o valor a ser empilhado: ");
                scanf("%d", &valor);
                Empilhar(&pilha, valor);
                break;
                
            case 2:
                valor = Desempilhar(&pilha);
                if (valor != -1) {
                    printf("Valor desempilhado: %d\n", valor);
                }
                
                break;
            case 3:
                ImprimirPilha(&pilha);
                break;
                
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}
