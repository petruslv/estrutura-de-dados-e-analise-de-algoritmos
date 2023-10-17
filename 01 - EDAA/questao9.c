#include<stdio.h>
#include<math.h> 
int main(){
    float cateto[2];
    printf("Digite o valor de dois catetos de um triângulo equilátero, em sequência:\n");
    scanf("%f%f",&cateto[0],&cateto[1]);
    float hipotenusa = hypot(cateto[0],cateto[1]);
    printf("A hipotenusa desse triângulo é %.0f.", hipotenusa);
    return 0;
}