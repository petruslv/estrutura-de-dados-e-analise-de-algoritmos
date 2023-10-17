/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

// Estrutura para representar um veículo
struct Veiculo {
    long long numeroChassi;
    char marca[50];
    char modelo[50];
    float preco;
};

// Função para alocar dinamicamente um vetor de estruturas Veículo
struct Veiculo* alocarVeiculos(int n) {
    struct Veiculo* veiculos = (struct Veiculo*)malloc(n * sizeof(struct Veiculo));
    if (veiculos == NULL) {
        printf("Falha na alocação de memória.\n");
        exit(1);
    }
    return veiculos;
}

// Função para preencher o vetor de estruturas Veículo
void preencherVeiculos(struct Veiculo* veiculos, int n) {
    for (int i = 0; i < n; i++) {
        printf("Digite o número do chassi do veículo %d: ", i + 1);
        scanf("%lld", &veiculos[i].numeroChassi);
        printf("Digite a marca do veículo %d: ", i + 1);
        scanf("%s", veiculos[i].marca);
        printf("Digite o modelo do veículo %d: ", i + 1);
        scanf("%s", veiculos[i].modelo);
        printf("Digite o preço do veículo %d: ", i + 1);
        scanf("%f", &veiculos[i].preco);
    }
}

// Função para imprimir o vetor de estruturas Veículo
void imprimirVeiculos(struct Veiculo* veiculos, int n) {
    printf("Veículos:\n");
    for (int i = 0; i < n; i++) {
        printf("Veículo %d\n", i + 1);
        printf("Número do Chassi: %lld\n", veiculos[i].numeroChassi);
        printf("Marca: %s\n", veiculos[i].marca);
        printf("Modelo: %s\n", veiculos[i].modelo);
        printf("Preço: %.2f\n", veiculos[i].preco);
        printf("\n");
    }
}

// Função para realocar o vetor de estruturas Veículo
struct Veiculo* realocarVeiculos(struct Veiculo* veiculos, int n, int novoTamanho) {
    veiculos = (struct Veiculo*)realloc(veiculos, novoTamanho * sizeof(struct Veiculo));
    if (veiculos == NULL) {
        printf("Falha na realocação de memória.\n");
        exit(1);
    }
    return veiculos;
}

int main() {
    struct Veiculo* veiculos;
    int n;
    printf("Digite o número de veículos: ");
    scanf("%d", &n);

    // Alocar o vetor de estruturas Veículo dinamicamente
    veiculos = alocarVeiculos(n);

    // Preencher o vetor de estruturas Veículo
    preencherVeiculos(veiculos, n);

    // Imprimir o vetor de estruturas Veículo
    imprimirVeiculos(veiculos, n);

    // Realocar o vetor de estruturas Veículo
    int novoTamanho = n + 5;
    veiculos = realocarVeiculos(veiculos, n, novoTamanho);

    // Preencher os elementos adicionais
    preencherVeiculos(veiculos + n, 5);

    // Imprimir o vetor de estruturas Veículo após a realocação
    imprimirVeiculos(veiculos, novoTamanho);

    // Liberar a memória alocada
    free(veiculos);

    return 0;
}\