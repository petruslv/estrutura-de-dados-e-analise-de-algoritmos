#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definindo a estrutura para representar um aluno
struct Aluno {
    int codigo;
    char nome[50];
    struct Aluno* proximo;
};

// Função para comparar dois alunos pelo nome
int CompararAlunos(const struct Aluno* aluno1, const struct Aluno* aluno2) {
    return strcmp(aluno1->nome, aluno2->nome);
}

// Função para pesquisar a posição onde um aluno deve ser inserido na lista
struct Aluno* PesquisarLista(struct Aluno* lista, struct Aluno* novo_aluno) {
    struct Aluno* atual = lista;
    struct Aluno* anterior = NULL;

    while (atual != NULL && CompararAlunos(atual, novo_aluno) < 0) {
        anterior = atual;
        atual = atual->proximo;
    }

    return anterior;
}

// Função para inserir um novo aluno na lista de forma ordenada
void InserirAluno(struct Aluno** lista, int codigo, const char* nome) {
    struct Aluno* novo_aluno = (struct Aluno*)malloc(sizeof(struct Aluno));
    novo_aluno->codigo = codigo;
    strcpy(novo_aluno->nome, nome);
    novo_aluno->proximo = NULL;

    if (*lista == NULL || CompararAlunos(*lista, novo_aluno) >= 0) {
        novo_aluno->proximo = *lista;
        *lista = novo_aluno;
    } else {
        struct Aluno* posicao_anterior = PesquisarLista(*lista, novo_aluno);
        novo_aluno->proximo = posicao_anterior->proximo;
        posicao_anterior->proximo = novo_aluno;
    }
}

// Função para imprimir a lista de alunos
void ImprimirLista(struct Aluno* lista) {
    struct Aluno* atual = lista;
    printf("Lista de Alunos:\n");
    while (atual != NULL) {
        printf("Código: %d, Nome: %s\n", atual->codigo, atual->nome);
        atual = atual->proximo;
    }
}

// Função principal
int main() {
    struct Aluno* lista_alunos = NULL;

    InserirAluno(&lista_alunos, 101, "Maria");
    InserirAluno(&lista_alunos, 102, "João");
    InserirAluno(&lista_alunos, 103, "Ana");
    InserirAluno(&lista_alunos, 104, "Pedro");

    ImprimirLista(lista_alunos);

    // Lembre-se de liberar a memória alocada para os alunos ao final do programa
    while (lista_alunos != NULL) {
        struct Aluno* temp = lista_alunos;
        lista_alunos = lista_alunos->proximo;
        free(temp);
    }

    return 0;
}
