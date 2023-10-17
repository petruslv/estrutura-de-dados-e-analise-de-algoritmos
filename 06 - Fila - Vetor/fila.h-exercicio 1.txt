//fila.h

/*
* Arquivo: fila.h
* Biblioteca de operações para fila implementada
* com vetor.
*/
#define VERDADEIRO 1
#define FALSO 0

struct tipo_fila {
    elemento vet[TAM];
    int inicio, fim;
};

typedef struct tipo_fila fila;

// Cria fila.
void CriarFila(fila *f) {
    f->inicio = -1;
    f->fim = -1;
}

// Verifica se a fila está vazia.
int FilaVazia(fila *f) {
    return (f->inicio == -1);
}

// Verifica se a fila está cheia.
int FilaCheia(fila *f) {
    return (f->fim == TAM - 1);
}

// Insere um elemento na fila.
void Enfileirar(fila *f, elemento e) {
    if (FilaCheia(f)) {
        printf("Fila cheia, não é possível enfileirar.\n");
    } else {
        if (FilaVazia(f)) {
            f->inicio = 0;
        }
        f->vet[++f->fim] = e;
    }
}

// Retira um elemento na fila.
elemento Desenfileirar(fila *f) {
    if (FilaVazia(f)) {
        printf("Fila vazia, não é possível desenfileirar.\n");
        return -1;
    } else {
        elemento valor = f->vet[f->inicio];
        if (f->inicio == f->fim) {
            
            CriarFila(f);
        } else {
            f->inicio++;
        }
        return valor;
    }
}

// Imprime o conteúdo da fila.
void ImprimeFila(fila *f) {
    if (FilaVazia(f)) {
        printf("Fila vazia.\n");
    } else {
        for (int i = f->inicio; i <= f->fim; i++) {
            printf("%d ", f->vet[i]);
        }
        printf("\n");
    }
}
