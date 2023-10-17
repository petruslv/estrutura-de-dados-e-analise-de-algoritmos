#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pilha.h"

typedef Nodo* PilhaLivros;

int main() {
    PilhaLivros pilha = NULL;
    int opcao;
    char PilhaArquivo[MAX_TITULO];
    char tituloDesejado[MAX_TITULO];

    do {
        printf("Opções:\n");
        printf("1. Empilhar livro\n");
        printf("2. Imprimir pilha na tela\n");
        printf("3. Salvar pilha em arquivo binário\n");
        printf("4. Ler pilha de arquivo binário\n");
        printf("5. Encontrar livro por título\n");
        printf("6. Desempilhar livro\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        while (getchar() != '\n'); // Limpa o buffer de entrada

        switch (opcao) {
            case 1: {
                Livro livro;
                printf("Título: ");
                fgets(livro.titulo, MAX_TITULO, stdin);
                livro.titulo[strcspn(livro.titulo, "\n")] = '\0'; // Remover o caractere de nova linha
                printf("Autor: ");
                fgets(livro.autor, MAX_AUTOR, stdin);
                printf("Edição: ");
                fgets(livro.edicao, MAX_EDICAO, stdin);

                EmpilharLivro(&pilha, livro);
                break;
            }
            case 2:
                ImprimirPilha(pilha);
                break;
            case 3:
                printf("Nome do arquivo binário: ");
                fgets(PilhaArquivo, MAX_TITULO, stdin);
                PilhaArquivo[strcspn(PilhaArquivo, "\n")] = '\0'; // Remover o caractere de nova linha
                SalvarPilhaEmArquivo(pilha, PilhaArquivo);
                break;
            case 4:
                printf("Nome do arquivo binário: ");
                fgets(PilhaArquivo, MAX_TITULO, stdin);
                PilhaArquivo[strcspn(PilhaArquivo, "\n")] = '\0'; // Remover o caractere de nova linha
                LerPilhaDeArquivo(&pilha, PilhaArquivo);
                break;
            case 5:
                printf("Título do livro desejado: ");
                fgets(tituloDesejado, MAX_TITULO, stdin);
                tituloDesejado[strcspn(tituloDesejado, "\n")] = '\0'; // Remover o caractere de nova linha
                int posicao = EncontrarLivroPorTitulo(pilha, tituloDesejado);
                if (posicao != -1) {
                    printf("Livro encontrado na posição %d da pilha.\n", posicao);
                } else {
                    printf("Livro não encontrado na pilha.\n");
                }
                break;
            case 6:
                // Opção para desempilhar um livro
                DesempilharLivro(&pilha);
                break;
        }
    } while (opcao != 7);

    // Liberar memória alocada para os livros na pilha
    Nodo* atual = pilha;
    while (atual != NULL) {
        Nodo* proximo = atual->prox;
        free(atual);
        atual = proximo;
    }

    return 0;
}

