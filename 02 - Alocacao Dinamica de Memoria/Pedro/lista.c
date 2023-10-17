/*
* Programa que lê números inteiros a partir
* do teclado e os armazena em uma lista.
*/
#include <stdio.h>
#include <stdlib.h>
#define TAM 5
typedef int elemento;
#include "lista.h"
int main() {
    int num, pos = 0;
    lista l;
    CriarLista(&l);
    while(ListaCheia(&l) == FALSO) {
        printf("\nInforme um numero inteiro: ");
        scanf("%d", &num);
        Alistar(&l, num, pos);
    }
    printf("\nNumeros informados: ");
    while(ListaVazia(&l) == FALSO) {
        num = Desalistar(&l, pos);
        printf("\n%d", num);
    }
    printf("\n");
    system("pause");
    return 0;
}