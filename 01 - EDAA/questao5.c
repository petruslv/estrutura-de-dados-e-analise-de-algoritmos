#include <stdio.h>
int main(){
    float diagonalMaior, diagonalMenor;
    printf("Informe a diagonal maior e a menor de um losango, respectivamente:\n");
    scanf("%f%f",&diagonalMaior,&diagonalMenor);
    printf("A área do losango é de %2.f", (diagonalMaior*diagonalMenor)/2);
    return 0;
}