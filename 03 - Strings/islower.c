//FUNÇÃO: islower

#include <stdio.h>
#include <ctype.h>

int main()
{
    char texto;
	printf("Informe uma letra ou número:\n");
    scanf("%c", &texto);
    if(islower(texto))
    {
        printf("É uma letra minúscula");
    }else{
        printf("Não é uma letra minúscula");
    }

    return 0;
}