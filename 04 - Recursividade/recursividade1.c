#include <stdio.h>

// Função recursiva para calcular a potência
int calcularPotencia(int base, int expoente) {
    // Caso base: quando o expoente é 0, o resultado é sempre 1.
    if (expoente == 0) {
        return 1;
    }
    // Caso base: quando o expoente é 1, o resultado é a própria base.
    else if (expoente == 1) {
        return base;
    }
    // Caso geral: calcula a potência recursivamente.
    else {
        return base * calcularPotencia(base, expoente - 1);
    }
}

int main() {
    int base, expoente;
    
    printf("Digite a base: ");
    scanf("%d", &base);
    
    printf("Digite o expoente: ");
    scanf("%d", &expoente);

    if (expoente < 0) {
        printf("O expoente deve ser um número inteiro não negativo.\n");
    } else {
        int resultado = calcularPotencia(base, expoente);
        printf("%d elevado a %d é igual a %d\n", base, expoente, resultado);
    }

    return 0;
}

