#define MAX_TITULO 100
#define MAX_AUTOR 100
#define MAX_EDICAO 20

typedef struct {
    char titulo[MAX_TITULO];
    char autor[MAX_AUTOR];
    char edicao[MAX_EDICAO];
} Livro;

typedef struct Nodo {
    Livro livro;
    struct Nodo* prox;
} Nodo;

typedef Nodo* PilhaLivros;

// Função para verificar se a pilha está vazia
int PilhaVazia(PilhaLivros pilha) {
    return pilha == NULL;
}

// Função para empilhar um livro
void EmpilharLivro(PilhaLivros* pilha, Livro livro) {
    Nodo* novoLivro = (Nodo*)malloc(sizeof(Nodo));
    novoLivro->livro = livro;
    novoLivro->prox = *pilha;
    *pilha = novoLivro;
}

// Função para desempilhar um livro
void DesempilharLivro(PilhaLivros* pilha) {
    if (*pilha != NULL) {
        Nodo* topo = *pilha;
        *pilha = topo->prox;
        free(topo);
        printf("Livro desempilhado com sucesso.\n");
    } else {
        printf("A pilha está vazia. Nenhum livro para desempilhar.\n");
    }
}

// Procedimento para imprimir o conteúdo da pilha na tela
void ImprimirPilha(PilhaLivros pilha) {
    Nodo* atual = pilha;
    if (PilhaVazia(pilha)) {
        printf("Pilha vazia, nada a imprimir.\n");
    } else {
        while (atual != NULL) {
            printf("Título: %s\nAutor: %s\nEdição: %s\n\n", atual->livro.titulo, atual->livro.autor, atual->livro.edicao);
            atual = atual->prox;
        }
    }
}

// Procedimento para salvar o conteúdo da pilha em um arquivo binário
void SalvarPilhaEmArquivo(PilhaLivros pilha, const char* PilhaArquivo) {
    FILE* arquivo = fopen(PilhaArquivo, "wb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    Nodo* atual = pilha;
    while (atual != NULL) {
        fwrite(&atual->livro, sizeof(Livro), 1, arquivo);
        atual = atual->prox;
    }

    fclose(arquivo);
}

// Procedimento para ler o conteúdo de um arquivo binário para a pilha
void LerPilhaDeArquivo(PilhaLivros* pilha, const char* PilhaArquivo) {
    FILE* arquivo = fopen(PilhaArquivo, "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return;
    }

    Livro livro;
    while (fread(&livro, sizeof(Livro), 1, arquivo) == 1) {
        EmpilharLivro(pilha, livro);
    }

    fclose(arquivo);
}

// Função para encontrar a posição de um livro pelo título
int EncontrarLivroPorTitulo(PilhaLivros pilha, const char* tituloDesejado) {
    Nodo* atual = pilha;
    int posicao = 0;
    while (atual != NULL) {
        posicao++;
        if (strcmp(atual->livro.titulo, tituloDesejado) == 0) {
            return posicao;
        }
        atual = atual->prox;
    }
    return -1; // Livro não encontrado
}