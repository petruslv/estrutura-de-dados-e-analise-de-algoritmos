//filacirucular.h

#define TAM_MAX 5 

struct Fila {
    int capacidade;
    float dados[TAM_MAX];
    int primeiro;
    int ultimo;
    int nItens;
};

void criarFila(struct Fila *f) {
    f->capacidade = TAM_MAX;
    f->primeiro = 0;
    f->ultimo = -1;
    f->nItens = 0;
}

void inserir(struct Fila *f, float v) {
    if (f->ultimo == f->capacidade - 1)
        f->ultimo = -1;

    f->ultimo++;
    f->dados[f->ultimo] = v;
    f->nItens++;
}

float remover(struct Fila *f) {
    float temp = f->dados[f->primeiro++];
    if (f->primeiro == f->capacidade)
        f->primeiro = 0;
    f->nItens--;
    return temp;
}

int estaVazia(struct Fila *f) {
    return (f->nItens == 0);
}

int estaCheia(struct Fila *f) {
    return (f->nItens == f->capacidade);
}

void mostrarFila(struct Fila *f) {
    if (estaVazia(f)) {
        printf("\nFila vazia!!!\n\n");
        return;
    }
    
    int cont, i;
    for (cont = 0, i = f->primeiro; cont < f->nItens; cont++) {
        printf("Posicao %d: %.2f\n", i, f->dados[i]); 
        if (i == f->capacidade - 1) {
            i = 0;
        } else {
            i++;
        }
    }
    printf("\n");
}
