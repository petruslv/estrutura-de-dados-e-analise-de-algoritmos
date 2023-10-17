#include <stdio.h>
#include <stdlib.h>
#define TAM 10

typedef int elemento;
#include "pilha.h"



void GravarPilhaEmArquivo(pilha *p, const char *pilhaArquivo);
void CarregarPilhaDeArquivo(pilha *p, const char *pilhaArquivo);

int main() {
    int num;
    pilha p;

    CriarPilha(&p);

    // Ler 10 números reais do teclado e empilhar
    printf("Digite 10 números inteiros para empilhar:\n");
    while (PilhaCheia(&p) == FALSO) {
        printf("\nInforme um numero inteiro: ");
        scanf("%d", &num);
        Empilhar(&p, num);
    }

    // Imprimir a pilha
    printf("\nConteúdo da pilha:\n");
    ImprimirPilha(&p);

    // Gravar a pilha em um arquivo de texto
    GravarPilhaEmArquivo(&p, "pilha.txt");

    // Limpar a pilha
    while (PilhaVazia(&p) == FALSO) {
        num = Desempilhar(&p);
    }

    // Ler a pilha do arquivo
    CarregarPilhaDeArquivo(&p, "pilha.txt");

    // Imprimir a pilha lida do arquivo
    printf("\nConteúdo da pilha lida do arquivo:\n");
    ImprimirPilha(&p);

    return 0;
}


void GravarPilhaEmArquivo(pilha *p, const char *pilhaArquivo) {
    FILE *arquivo = fopen(pilhaArquivo, "w");
    if (arquivo == NULL) {
        fprintf(stderr, "Erro ao abrir o arquivo para escrita.\n");
        exit(1);
    }

    while (PilhaVazia(p) == FALSO) {
        int num = Desempilhar(p);
        fprintf(arquivo, "%d\n", num);
    }

    fclose(arquivo);
}

void CarregarPilhaDeArquivo(pilha *p, const char *pilhaArquivo) {
    FILE *arquivo = fopen(pilhaArquivo, "r");
    if (arquivo == NULL) {
        fprintf(stderr, "Erro ao abrir o arquivo para leitura.\n");
        exit(1);
    }

    int num;
    while (fscanf(arquivo, "%d", &num) == 1) {
        Empilhar(p, num);
    }

    fclose(arquivo);
}

