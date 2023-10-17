#include<stdio.h>
#include<math.h> 
int main(){
    float raio;
    const float pi = 3.14;
    printf("Informe o raio de um círculo:\n");
    scanf("%f",&raio);
    float comprimento = 2*pi*raio;
    float area =pi*pow(raio,2);
    float volume = (3/4)*pi*pow(raio,3);
    printf("Comprimento: %f\nArea: %f\nVolume: %f",comprimento,area,volume);
    return 0;
}