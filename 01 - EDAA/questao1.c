#include <stdio.h>
int main(){
    float vetNotas[3];
    printf("Insira tres notas, em sequencia: ");
    scanf("%f%f%f",&vetNotas[0],&vetNotas[1],&vetNotas[2]);
    printf("A media entre essas tres notas e %2.f.", (vetNotas[0]+vetNotas[1]+vetNotas[2])/3);
    return 0;
}