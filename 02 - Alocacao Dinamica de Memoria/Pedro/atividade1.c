#include <stdio.h>
#include <stdlib.h>

// Alocação dinâmica de memória usando malloc
int *alocarVetor(int *array, int n)
{
    array = (int *) malloc(n * sizeof(int));
    
    if(array == NULL)
    {
        printf("Falha na alocação de memória.\n");
        exit(1);
    }
}

// Preencher o array
int preencher(int *array, int n)
{
     for (int i = 0; i < n; i++) 
    {
        array[i] = i * 10;
    }
}


// Imprimir o array
int impressao(int *array, int n)
{
    printf("Array: ");
    for (int i = 0; i < n; i++) 
    {
    printf("%d ", array[i]);
    }
    return impressao;
}

int main() 
{
    int *array, n, p, i;
    printf("Digite o tamanho do array: ");
    scanf("%d", &n);
    
    array = alocarVetor(array, n);
    p = preencher(array, n);  
    i = impressao(array, n);
    
    // Liberar a memória alocada com malloc
    free(array);
return 0;
}