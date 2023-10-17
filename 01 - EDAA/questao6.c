#include <stdio.h>
int main()
{
    float celsius;
    printf("Informe uma temperatura em graus Celsius (°C):\n");
    scanf("%f",&celsius);
    printf("Essa temperatura equivale a %.1f °F.\n", (celsius * 1.8) + 32);
    return 0;
}