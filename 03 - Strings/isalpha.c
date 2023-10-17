//FUNÇÃO: isalpha

#include <stdio.h>
#include <ctype.h>

int main()
{
    char texto;
	printf("Informe uma letra ou número:\n");
    scanf("%c", &texto);
    if(isalpha(texto))
    {
        printf("É uma letra");
    }else{
        printf("Não é uma letra");
    }

    return 0;
}