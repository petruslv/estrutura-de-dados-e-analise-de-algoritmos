#include <stdio.h>
#include <stdlib.h>
int main() {

    int array=0, n;
    printf("Digite o tamanho do array: ");
    scanf("%d", &n);
    int impressao(array,n);
   return 0;
}

int impressao(int a, int n){
    
    // Imprimir o array
    printf("Array: ");
    for (int i = 0; i < n; i++) {
    printf("%d ", a[i]);
    return a, n;
}
