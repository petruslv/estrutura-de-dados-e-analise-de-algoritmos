//FUNÇÃO: isalnum

#include <stdio.h>
#include <ctype.h>

int main()
{
    char texto;
	printf("Informe uma letra, um número ou um caracter especial:\n");
    scanf("%c", &texto);
    if(isalnum(texto))
    {
        printf("É uma letra ou um dígito");
    }else{
        printf("Não é uma letra nem um dígito");
    }

    return 0;
}