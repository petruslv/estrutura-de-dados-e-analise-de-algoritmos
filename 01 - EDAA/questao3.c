#include <stdio.h>
int main()
{
    float dolar, qtdDolar;
    printf("Insira a cotacao atual do dolar (em R$):\n");
    scanf("%f",&dolar);
    printf("Qual valor voce possui em dolar (em US$)?\n");
    scanf("%f",&qtdDolar);
    printf("Voce possui R$%.2f.\n", (qtdDolar*dolar) );
    return 0;
}