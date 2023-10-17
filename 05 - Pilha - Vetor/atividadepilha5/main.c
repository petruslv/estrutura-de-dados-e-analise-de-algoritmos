

#include <stdio.h>
#include <stdlib.h>
#define TAM 5

typedef int elemento;

#include "pilha.h"


int main() {
    int num, resto;
    pilha p;
    CriarPilha(&p);

    printf("\nInforme um numero inteiro: ");
    scanf("%d", &num);

    // Limitar o valor máximo a 31
    if (num > 31) {
        num = 31;
        
        printf("\nNumero descimal maximo a ser convertido: 31");
    }

    while (num != 0) {
        resto = num % 2;
        Empilhar(&p, resto);
        num /= 2;
    }

    printf("\nCorrespondente em binario: ");
    if (PilhaVazia(&p)) {
        printf("0"); // Se o número for 0, imprime 0.
    }

    while (!PilhaVazia(&p)) {
        resto = Desempilhar(&p);
        printf("%d", resto);
    }

    return 0;
}    