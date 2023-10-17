#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 10

#include "pilha.h"

int main() {
    pilha p;
    CriarPilha(&p);

    // Ler 10 registros de funcionários do teclado e empilhar
    printf("Digite informações de 10 funcionários:\n");
    for (int i = 0; i < TAM; i++) {
        Funcionario func;
        LerFuncionario(&func);
        Empilhar(&p, func);
    }

    // Gravar a pilha em um arquivo binário
    GravarPilhaEmArquivo(&p, "funcionarios.bin");

    // Limpar a pilha
    while (PilhaVazia(&p) == FALSO) {
        Desempilhar(&p);
    }

    // Ler a pilha do arquivo binário
    CarregarPilhaDeArquivo(&p, "funcionarios.bin");

    // Pesquisar funcionário por CPF
    char cpfPesquisa[12];
printf("Digite o CPF a ser pesquisado: ");
scanf("%s", cpfPesquisa);
Funcionario encontrado = PesquisarPorCPF(&p, cpfPesquisa);

if (strcmp(encontrado.cpf, "") != 0) {
    printf("Funcionário encontrado:\n");
    printf("CPF: %s\n", encontrado.cpf);
    printf("Nome: %s\n", encontrado.nome);
    printf("Endereço: %s\n", encontrado.endereco);
    printf("Telefone: %s\n", encontrado.telefone);
    printf("Celular: %s\n", encontrado.celular);
    printf("Data de Nascimento: %s\n", encontrado.dataNascimento);
    printf("Data de Admissão: %s\n", encontrado.dataAdmissao);
    printf("Departamento: %s\n", encontrado.departamento);
    printf("Cargo: %s\n", encontrado.cargo);
    printf("Salário: %.2f\n", encontrado.salario);
} else {
    printf("Funcionário não encontrado.\n");
}


    return 0;
}



