//fila.c

#include <stdio.h>
#include <stdlib.h>
#define TAM 10
typedef float elemento;
#include "fila.h"

int main() {
    elemento num;
    fila f;
    CriarFila(&f);


    printf("Informe uma sequência de 10 números reais:\n");
    for (int i = 0; i < TAM; i++) {
        printf("Número %d: ", i + 1);
        scanf("%f", &num);
        Enfileirar(&f, num);
    }


    DesenfileirarParaArquivo(&f, "numeros.txt");

    EnfileirarDoArquivo(&f, "numeros.txt");

    ImprimeFilaNaTela(&f);

    return 0;
}
