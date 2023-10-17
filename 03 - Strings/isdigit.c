//FUNÇÃO: isdigit

#include <stdio.h>
#include <ctype.h>

int main()
{
    char texto;
	printf("Informe uma letra ou número:\n");
    scanf("%c", &texto);
    if(isdigit(texto))
    {
        printf("É um dígito");
    }else{
        printf("Não é um dígito");
    }

    return 0;
}