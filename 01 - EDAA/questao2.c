#include <stdio.h>
#include<time.h>
int main(){
    struct tm *data_atual;
    time_t segundos;
    time(&segundos);
    data_atual=localtime(&segundos);
    int anoNascimento, idadeatual, idade2050;
    printf("Informe seu ano de nascimento: ");
    scanf("%d",&anoNascimento);
    printf("Nesse ano voce tem ou ira completar %d anos.\n", (data_atual->tm_year+1900)-anoNascimento);
    printf("Em 2050 voce estara com %d anos.", 2050-anoNascimento);
    return 0;
}