/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

// Função para alocar dinamicamente um array de inteiros
int* alocarArray(int n) {
    int* array = (int*)malloc(n * sizeof(int));
    if (array == NULL) {
        printf("Falha na alocação de memória.\n");
        exit(1); // Encerrar o programa em caso de falha na alocação
    }
    return array;
}

// Função para preencher o array com valores
void preencherArray(int* array, int n) {
    for (int i = 0; i < n; i++) {
        array[i] = i * 10;
    }
}

// Função para imprimir o array
void imprimirArray(int* array, int n) {
    printf("Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int *array, n;
    printf("Digite o tamanho do array: ");
    scanf("%d", &n);

    // Alocar o array dinamicamente
    array = alocarArray(n);

    // Preencher o array
    preencherArray(array, n);

    // Imprimir o array
    imprimirArray(array, n);

    // Liberar a memória alocada com malloc
    free(array);

    return 0;
}