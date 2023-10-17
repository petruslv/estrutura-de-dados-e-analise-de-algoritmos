#include <stdio.h>
int main()
{
    float salario; 
    printf("Digite seu salario (em R$):\n"); 
    scanf("%f",&salario);
    printf("Seu salario apos reajuste e de R$%.2f.\n", salario+(salario*0.25));    
    return 0;
}