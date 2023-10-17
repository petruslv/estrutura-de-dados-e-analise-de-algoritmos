#include <stdio.h>

// Função recursiva para calcular a soma dos primeiros n números naturais
int somaNaturais(int n) {
    // Caso base: a soma dos primeiros 0 números naturais é 0.
    if (n == 0) {
        return 0;
    }
    // Caso geral: soma o número atual (n) com a soma dos anteriores (n - 1).
    else {
        return n + somaNaturais(n - 1);
    }
}

int main() {
    int n;
    
    printf("Digite o valor de n: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("O valor de n deve ser um número inteiro não negativo.\n");
    } else {
        int resultado = somaNaturais(n);
        printf("A soma dos primeiros %d números naturais é igual a %d\n", n, resultado);
    }

    return 0;
}
