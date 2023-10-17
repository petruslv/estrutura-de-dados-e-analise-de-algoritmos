/*
* Arquivo: pilha.h
* Biblicoteca de operações para pilha
* implementada com vetor.
*/
#define VERDADEIRO 1
#define FALSO 0

typedef struct {
    elemento vet[TAM_MAX];
    int topo;
} PilhaCircular;

void CriarPilha(PilhaCircular *p) {
    p->topo = 0;
}

int PilhaVazia(PilhaCircular *p) {
    if(p->topo!=0){
        
    }
    else
        printf("pilha vazia");
    return (p->topo == 0);
}

int PilhaCheia(PilhaCircular *p) {
    return (p->topo == TAM_MAX);
}

void Empilhar(PilhaCircular *p, elemento e) {
    if (PilhaCheia(p)) {
        printf("A pilha está cheia. Novos elementos serão empilhados a partir do início da pilha.\n");

        // Avança o topo de forma circular, sobrescrevendo a posição mais antiga
        p->topo = (p->topo + 1) % TAM_MAX;

        // Insere o novo elemento na posição onde o topo está agora
        p->vet[p->topo] = e;
    } else {
        p->vet[p->topo] = e;
        p->topo = (p->topo + 1) % TAM_MAX;
    }
}


elemento Desempilhar(PilhaCircular *p) {
    if (PilhaVazia(p)) {
        printf("A pilha está vazia.\n");
        return -1;  // Valor inválido
    }
    int valor = p->vet[p->topo];
    p->vet[p->topo] = 0;  // Limpa a posição anterior
    p->topo = (p->topo - 1 + TAM_MAX) % TAM_MAX;  // Retrocede o topo de forma circular
    return valor;
}




void ImprimirPilha(PilhaCircular *p) {
    int i = p->topo;
    do {
        i = (i - 1 + TAM_MAX) % TAM_MAX;
        printf("%d ", p->vet[i]);
    } while (i != p->topo);

    printf("\n");
}
