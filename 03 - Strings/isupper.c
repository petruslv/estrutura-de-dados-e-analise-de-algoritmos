//FUNÇÃO: isupper

#include <stdio.h>
#include <ctype.h>

int main()
{
    char texto;
    printf("Informe uma letra ou número:\n");
    scanf("%c", &texto);
    if(isupper(texto))
    {
        printf("É uma letra maiúscula");
    }else{
        printf("Não é uma letra maiúscula");
    }

    return 0;
}