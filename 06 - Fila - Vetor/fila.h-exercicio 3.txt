//fila.h


#include <string.h>

#define VERDADEIRO 1
#define FALSO 0

#define TAM 2

struct Funcionario {
    char cpf[12];
    char nome[100];
    char endereco[100];
    char telefone[15];
    char celular[15];
    char dataNascimento[11];
    char dataAdmissao[11];
    char departamento[100];
    char cargo[100];
    float salario;
};

typedef struct Funcionario elemento;

struct tipo_fila {
    elemento vet[TAM];
    int inicio, fim;
};

typedef struct tipo_fila fila;


void CriarFila(fila *f) {
    f->inicio = -1;
    f->fim = -1;
}

int FilaVazia(fila *f) {
    return (f->inicio == -1);
}

int FilaCheia(fila *f) {
    return (f->fim == TAM - 1);
}

void Enfileirar(fila *f, elemento e) {
    if (FilaCheia(f)) {
        printf("Fila cheia, não é possível enfileirar.\n");
    } else {
        if (FilaVazia(f)) {
            f->inicio = 0;
        }
        f->vet[++f->fim] = e;
    }
}

elemento Desenfileirar(fila *f) {
    if (FilaVazia(f)) {
        printf("Fila vazia, não é possível desenfileirar.\n");
        elemento erro;
        memset(erro.cpf, 0, sizeof(erro.cpf)); 
        return erro;
    } else {
        elemento valor = f->vet[f->inicio];
        if (f->inicio == f->fim) {
            CriarFila(f);
        } else {
            f->inicio++;
        }
        return valor;
    }
}

void ImprimeFuncionario(const struct Funcionario *funcionario) {
    printf("CPF: %s\n", funcionario->cpf);
    printf("Nome: %s\n", funcionario->nome);
    printf("Endereço: %s\n", funcionario->endereco);
    printf("Telefone: %s\n", funcionario->telefone);
    printf("Celular: %s\n", funcionario->celular);
    printf("Data de Nascimento: %s\n", funcionario->dataNascimento);
    printf("Data de Admissão: %s\n", funcionario->dataAdmissao);
    printf("Departamento: %s\n", funcionario->departamento);
    printf("Cargo: %s\n", funcionario->cargo);
    printf("Salário: %.2f\n", funcionario->salario);
}

void ImprimeFila(fila *f) {
    if (FilaVazia(f)) {
        printf("Fila vazia.\n");
    } else {
        for (int i = f->inicio; i <= f->fim; i++) {
            ImprimeFuncionario(&f->vet[i]);
        }
    }
}

void DesenfileirarParaArquivo(fila *f, const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "wb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        exit(1);
    }

    while (FilaVazia(f) == FALSO) {
        elemento funcionario = Desenfileirar(f);
        fwrite(&funcionario, sizeof(elemento), 1, arquivo);
    }

    fclose(arquivo);
    printf("Elementos desenfileirados e gravados no arquivo '%s'.\n", nomeArquivo);
}

void EnfileirarDoArquivo(fila *f, const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para leitura.\n");
        exit(1);
    }

    elemento funcionario;

    while (fread(&funcionario, sizeof(elemento), 1, arquivo)) {
        Enfileirar(f, funcionario);
    }

    fclose(arquivo);
    printf("Elementos lidos do arquivo '%s' e enfileirados na fila.\n", nomeArquivo);
}

void PesquisarPorCPF(fila *f, const char *cpf) {
    int encontrado = FALSO;

    for (int i = f->inicio; i <= f->fim; i++) {
        if (strcmp(f->vet[i].cpf, cpf) == 0) {
            ImprimeFuncionario(&f->vet[i]);
            encontrado = VERDADEIRO;
            break;
        }
    }

    if (!encontrado) {
        printf("Funcionário com CPF %s não encontrado.\n", cpf);
    }
}
