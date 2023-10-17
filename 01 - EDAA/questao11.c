#include <stdio.h>
int main(){
    int numero;
    printf("Informe um número de 0 a 9: ");
    scanf("%d", &numero);
    printf("A tabuada de %d é:\n", numero);
    for(int i=0; i <= 10; i++){
        printf("%d x %d = %d\n", numero, i, numero*i);
    }
    return 0;
}