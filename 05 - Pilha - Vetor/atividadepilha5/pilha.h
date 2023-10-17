#define VERDADEIRO 1
#define FALSO 0


struct tipo_pilha {
    elemento vet[TAM];
    int topo;
};

typedef struct tipo_pilha pilha;

// Cria pilha.
void CriarPilha(pilha *p) {
    p->topo = 0;
}

// Verifica se a pilha está vazia.
int PilhaVazia(pilha *p) {
    return (p->topo == 0);
}

// Verifica se a pilha está cheia.
int PilhaCheia(pilha *p) {
    return (p->topo == TAM);
}

// Insere um elemento na pilha.
void Empilhar(pilha *p, elemento e) {
    if (PilhaCheia(p)) {
        printf("A representação binária possui mais de 5 bits.\n");
        return ;
    }
      
    
    if (!PilhaCheia(p)) {
        p->vet[p->topo] = e;
        p->topo++;
    }
}

// Retira um elemento da pilha.
elemento Desempilhar(pilha *p) {
    p->topo--;
    return p->vet[p->topo];
}