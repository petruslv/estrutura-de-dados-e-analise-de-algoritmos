//fila.c

#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
#include <string.h>

#define TAM 2

int main() {
    fila f;
    CriarFila(&f);

    
    printf("Informe os dados de 10 funcionários:\n");
    for (int i = 0; i < TAM; i++) {
        elemento funcionario;
        printf("Funcionário %d:\n", i + 1);
        printf("CPF: ");
        scanf("%s", funcionario.cpf);
        printf("Nome: ");
        scanf("%s", funcionario.nome);
        printf("Endereço: ");
        scanf("%s", funcionario.endereco);
        printf("Telefone: ");
        scanf("%s", funcionario.telefone);
        printf("Celular: ");
        scanf("%s", funcionario.celular);
        printf("Data de Nascimento (dd/mm/aaaa): ");
        scanf("%s", funcionario.dataNascimento);
        printf("Data de Admissão (dd/mm/aaaa): ");
        scanf("%s", funcionario.dataAdmissao);
        printf("Departamento: ");
        scanf("%s", funcionario.departamento);
        printf("Cargo: ");
        scanf("%s", funcionario.cargo);
        printf("Salário: ");
        scanf("%f", &funcionario.salario);
        Enfileirar(&f, funcionario);
    }

    // Desenfileiramento e gravação em arquivo binário
    DesenfileirarParaArquivo(&f, "funcionarios.dat");

    // Leitura de registros a partir do arquivo binário e enfileiramento
    EnfileirarDoArquivo(&f, "funcionarios.dat");

   
    char cpfPesquisa[12];
    printf("Informe o CPF para pesquisa: ");
    scanf("%s", cpfPesquisa);
    PesquisarPorCPF(&f, cpfPesquisa);

    return 0;
}