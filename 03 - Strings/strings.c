FUNÇÃO:
isalpha

#include <stdio.h>
#include <ctype.h>

int main()
{
    char texto;
	printf("Informe uma letra ou número:\n");
    scanf("%c", &texto);
    if(isalpha(texto))
    {
        printf("É uma letra");
    }else{
        printf("Não é uma letra");
    }

    return 0;
}
======================================================
FUNÇÃO:
isdigit

#include <stdio.h>
#include <ctype.h>

int main()
{
    char texto;
	printf("Informe uma letra ou número:\n");
    scanf("%c", &texto);
    if(isdigit(texto))
    {
        printf("É um dígito");
    }else{
        printf("Não é um dígito");
    }

    return 0;
}
======================================================
FUNÇÃO:
isupper

#include <stdio.h>
#include <ctype.h>

int main()
{
    char texto;
    printf("Informe uma letra ou número:\n");
    scanf("%c", &texto);
    if(isupper(texto))
    {
        printf("É uma letra maiúscula");
    }else{
        printf("Não é uma letra maiúscula");
    }

    return 0;
}
======================================================
FUNÇÃO:
islower

#include <stdio.h>
#include <ctype.h>

int main()
{
    char texto;
	printf("Informe uma letra ou número:\n");
    scanf("%c", &texto);
    if(islower(texto))
    {
        printf("É uma letra minúscula");
    }else{
        printf("Não é uma letra minúscula");
    }

    return 0;
}
======================================================
FUNÇÃO:
isalnum

#include <stdio.h>
#include <ctype.h>

int main()
{
    char texto;
	printf("Informe uma letra, um número ou um caracter especial:\n");
    scanf("%c", &texto);
    if(isalnum(texto))
    {
        printf("É uma letra ou um dígito");
    }else{
        printf("Não é uma letra nem um dígito");
    }

    return 0;
}
======================================================
/*
* Arquivo: fila.h
* Biblicoteca de operações para fila implementada
* com vetor.
*/
#define VERDADEIRO 1
#define FALSO 0
struct tipo_fila {
elemento vet[TAM];
int inicio, fim;
};
typedef struct tipo_fila fila;
//Cria fila.
void CriarFila(fila *f) {
(*f).inicio = 0;
(*f).fim = 0;
}
//Verifica se a fila está vazia.
int FilaVazia(fila *f) {
return((*f).inicio == (*f).fim);
}
//Verifica se a fila está cheia.
int FilaCheia(fila *f) {
return((*f).fim == TAM);
}
//Insere um elemento na fila.
void Enfileirar(fila *f, elemento e) {
(*f).vet[(*f).fim++] = e;
}
//Retira um elemento na fila.
elemento Desenfileirar(fila *f) {
return((*f).vet[(*f).inicio++]);
}
//Imprime o conteúdo da fila.
void ImprimeFila(fila *f) {
    if (FilaVazia(f)) {
        printf("A fila está vazia.\n");
        return;
    }

    printf("Conteúdo da fila: ");
    for (int i = (*f).inicio; i < (*f).fim; i++) {
        printf("%d ", (*f).vet[i]);
    }
    printf("\n");
}
=========
/*
* Programa que lê números inteiros a partir
* do teclado e os armazena em uma fila.
*/
#include <stdio.h>
#include <stdlib.h>
#define TAM 3
typedef int elemento;
#include "fila.h"
int main() {
int num;
fila f;
CriarFila(&f);
while(FilaCheia(&f) == FALSO) {
printf("\nInforme um numero inteiro: ");
scanf("%d", &num);
Enfileirar(&f, num);
}
printf("\nNumeros informados: ");
while(FilaVazia(&f) == FALSO) {
num = Desenfileirar(&f);
printf("\n%d", num);
}
printf("\n");
system("pause");
return 0;
}