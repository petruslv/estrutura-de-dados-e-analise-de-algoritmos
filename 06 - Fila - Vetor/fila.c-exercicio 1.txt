//fila.c

#include <stdio.h>
#include <stdlib.h>
#define TAM 3
typedef int elemento;
#include "fila.h"

int main() {
    int num;
    fila f;
    CriarFila(&f);

    while (FilaCheia(&f) == FALSO) {
        printf("\nInforme um numero inteiro: ");
        scanf("%d", &num);
        Enfileirar(&f, num);
    }

    printf("\nNumeros informados: ");
    ImprimeFila(&f);

    while (FilaVazia(&f) == FALSO) {
        num = Desenfileirar(&f);
    }

    printf("\n");
    system("pause");
    return 0;
}
