/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

// Estrutura para representar uma pessoa
struct Pessoa {
    long long CPF;
    char nome[50];
    float salario;
};

// Função para alocar dinamicamente um vetor de estruturas Pessoa
struct Pessoa* alocarPessoas(int n) {
    struct Pessoa* pessoas = (struct Pessoa*)calloc(n, sizeof(struct Pessoa));
    if (pessoas == NULL) {
        printf("Falha na alocação de memória.\n");
        exit(1);
    }
    return pessoas;
}

// Função para preencher o vetor de estruturas Pessoa
void preencherPessoas(struct Pessoa* pessoas, int n) {
    for (int i = 0; i < n; i++) {
        printf("Digite o CPF da pessoa %d: ", i + 1);
        scanf("%lld", &pessoas[i].CPF);
        printf("Digite o nome da pessoa %d: ", i + 1);
        scanf("%s", pessoas[i].nome);
        printf("Digite o salário da pessoa %d: ", i + 1);
        scanf("%f", &pessoas[i].salario);
    }
}

// Função para imprimir o vetor de estruturas Pessoa
void imprimirPessoas(struct Pessoa* pessoas, int n) {
    printf("Pessoas:\n");
    for (int i = 0; i < n; i++) {
        printf("Pessoa %d\n", i + 1);
        printf("CPF: %lld\n", pessoas[i].CPF);
        printf("Nome: %s\n", pessoas[i].nome);
        printf("Salário: %.2f\n", pessoas[i].salario);
        printf("\n");
    }
}

int main() {
    struct Pessoa* pessoas;
    int n;
    printf("Digite o número de pessoas: ");
    scanf("%d", &n);

    // Alocar o vetor de estruturas Pessoa dinamicamente
    pessoas = alocarPessoas(n);

    // Preencher o vetor de estruturas Pessoa
    preencherPessoas(pessoas, n);

    // Imprimir o vetor de estruturas Pessoa
    imprimirPessoas(pessoas, n);

    // Liberar a memória alocada com calloc
    free(pessoas);

    return 0;
}