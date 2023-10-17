/*
* Arquivo: pilha.h
* Biblicoteca de operações para pilha
* implementada com vetor.
*/
#define VERDADEIRO 1
#define FALSO 0

typedef struct {
    char cpf[12];
    char nome[50];
    char endereco[100];
    char telefone[15];
    char celular[15];
    char dataNascimento[11];
    char dataAdmissao[11];
    char departamento[50];
    char cargo[50];
    float salario;
} Funcionario;

typedef struct tipo_pilha {
    Funcionario vet[TAM];
    int topo;
} pilha;

Funcionario Empilhar(pilha *p, Funcionario e);
void GravarPilhaEmArquivo(pilha *p, const char *pilhaArquivo);
void CarregarPilhaDeArquivo(pilha *p, const char *pilhaArquivo);
Funcionario PesquisarPorCPF(pilha *p, const char *cpf);
void LerFuncionario(Funcionario *funcionario);

typedef struct tipo_pilha pilha;
//Cria pilha.
void CriarPilha(pilha *p) {
    p->topo = 0;
}

//Verifica se a pilha está vazia.
int PilhaVazia(pilha *p) {
    return(p->topo == 0);
}

//Verifica se a pilha está cheia.
int PilhaCheia(pilha *p) {
return(p->topo == TAM);
}

void LerFuncionario(Funcionario *funcionario) {
    printf("CPF: ");
    scanf("%s", funcionario->cpf);
    printf("Nome: ");
    scanf(" %49[^\n]", funcionario->nome);
    printf("Endereço: ");
    scanf(" %99[^\n]", funcionario->endereco);
    printf("Telefone: ");
    scanf("%s", funcionario->telefone);
    printf("Celular: ");
    scanf("%s", funcionario->celular);
    printf("Data de Nascimento (dd/mm/aaaa): ");
    scanf("%s", funcionario->dataNascimento);
    printf("Data de Admissão (dd/mm/aaaa): ");
    scanf("%s", funcionario->dataAdmissao);
    printf("Departamento: ");
    scanf(" %49[^\n]", funcionario->departamento);
    printf("Cargo: ");
    scanf(" %49[^\n]", funcionario->cargo);
    printf("Salário: ");
    scanf("%f", &funcionario->salario);
}

//Insere um elemento na pilha.
Funcionario Empilhar(pilha *p, Funcionario e) {
    p->vet[p->topo] = e;
    p->topo++;
    return e;
}



//Retira um elemento na pilha.
Funcionario Desempilhar(pilha *p) {
    if (PilhaVazia(p)) {
        Funcionario elementoVazio;
        strcpy(elementoVazio.cpf, "");
        return elementoVazio;
    } 
    else {
        p->topo--;
        return p->vet[p->topo];
    }
}

void GravarPilhaEmArquivo(pilha *p, const char *pilhaArquivo) {
    FILE *arquivo = fopen(pilhaArquivo, "wb");
    if (arquivo == NULL) {
        fprintf(stderr, "Erro ao abrir o arquivo para escrita.\n");
        exit(1);
    }

    while (PilhaVazia(p) == FALSO) {
        Funcionario func = Desempilhar(p);
        fwrite(&func, sizeof(Funcionario), 1, arquivo);
    }

    fclose(arquivo);
}

void CarregarPilhaDeArquivo(pilha *p, const char *pilhaArquivo) {
    FILE *arquivo = fopen(pilhaArquivo, "rb");
    if (arquivo == NULL) {
        fprintf(stderr, "Erro ao abrir o arquivo para leitura.\n");
        exit(1);
    }

    Funcionario func;
    while (fread(&func, sizeof(Funcionario), 1, arquivo) == 1) {
        Empilhar(p, func);
    }

    fclose(arquivo);
}



Funcionario PesquisarPorCPF(pilha *p, const char *cpf) {
    Funcionario func;
    Funcionario nao_encontrado;
    strcpy(nao_encontrado.cpf, "");
    
    while (PilhaVazia(p) == FALSO) {
        func = Desempilhar(p);
        if (strcmp(func.cpf, cpf) == 0) {
            Empilhar(p, func);
            return func;
        }
    }
    
    return nao_encontrado;
}



    
