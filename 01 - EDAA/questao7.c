#include <stdio.h>
int main(){
    float salarioMin, salario;
    printf("Insira o salario minimo atual (em R$):\n");
    scanf("%f",&salarioMin);
    printf("Qual é o seu sálario? (em R$)\n");
    scanf("%f",&salario);
    if (salario>=salarioMin)
    {
        printf("Voce recebe por volta de %1.f salários mínimos.\n", salario/salarioMin );
    }else
        printf("Voce recebe abaixo de 1 salário mínimo.");
    
    return 0;
}