/* Arquivo: lista.h
* Biblicoteca de operações para lista implementada
* com vetor.
*/
#define VERDADEIRO 1
#define FALSO 0
struct tipo_lista {
    elemento vet[TAM];
    int inicio, fim;
}
typedef struct tipo_lista lista;

//Cria lista.
void CriarLista(lista *l) {
    l->inicio = -1;
    l->fim = -1;
}
//Verifica se a lista está vazia.
int ListaVazia(lista *l) {
    return(l->inicio == l->fim);
}
//Verifica se a fila está cheia.
int ListaCheia(lista *l) {
    return(l->fim == TAM);
}
//Insere um elemento na lista.
void Alistar(lista *l, elemento e, int pos) {
    int i;
    if(ListaCheia(l))
        printf ("\n ERRO: lista cheia!");
    else if((pos < l->inicio) || (pos > l->fim)) {
        printf("\n ERRO: posição não existe!");
        printf("\n Posicoes validas: [0, %d].", l->fim);
    }else {
        for(i = l->fim; i > pos; i--)
        l->vet[i] = l->vet[i - 1];
        l->vet[pos] = e;
        l->fim++;
    }
}
//Retira um elemento da lista.
elemento Desalistar(lista *l, int pos) {
    int i;
    elemento e;
    if(ListaVazia(l))
        printf ("\n ERRO: lista vazia!");
    else
    if((pos < l->inicio) || (pos >= l->fim)) {
        printf("\n ERRO: posição não existe!");
        printf("\n Posicoes validas: [0, %d].", l->fim - 1);
    } else {
        e = l->vet[pos];
        for(i = pos; i < (l->fim - 1); i++)
        l->vet[i] = l->vet[i + 1];
        l->fim--;
    }
    return (e);
}

void ImprimeLista(){

}