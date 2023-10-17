#include <stdio.h>
int main(){
    float peso, aumentoPeso, perdaPeso;
    printf("Quanto você pesa? (em kg)\n");
    scanf("%f", &peso);
    aumentoPeso = peso+(peso*0.15);
    perdaPeso = peso-(peso*0.20);
    printf("Caso você engorde 15%%, seu novo peso será de %.1f kg. E se emagrecer 20%%, estará pesando %.1f kg.", aumentoPeso, perdaPeso);
    return 0;
}