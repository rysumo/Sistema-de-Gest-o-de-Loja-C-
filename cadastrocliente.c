#include <stdio.h>
#include <string.h>

#define MAX_CLIENTES 100

typedef struct {
    int codigo;
    char nome[100];
    char cpf[20];
    char telefone[20];
    char cidade[100];
} Cliente;

Cliente clientes[MAX_CLIENTES];
int total = 0;

void limpar_newline(char *str) {
    int len = strlen(str);
    if (len > 0 && str[len - 1] == '\n')
        str[len - 1] = '\0';
}


//MOSTRA TODOS CLIENTES CADASTRADOS
void listar_clientes() {
    if (total == 0) {
        printf("Nenhum cliente cadastrado ainda.\n");
        return;
    }

    for (int i = 0; i < total; i++) {
        printf("Codigo: %d\n", clientes[i].codigo);
        printf("Nome: %s\n", clientes[i].nome);
        printf("CPF: %s\n", clientes[i].cpf);
        printf("Telefone: %s\n", clientes[i].telefone);
        printf("Cidade: %s\n", clientes[i].cidade);
    }
}

void cadastrar_cliente() {

    Cliente novo;
    novo.codigo = 100001 + total;

    printf("    NOVO CLIENTE    \n");

  //PEDE AS INFORMAÇOES DO CLIENTE

    do {
        printf("Nome completo : ");
        fgets(novo.nome, sizeof(novo.nome), stdin);
        limpar_newline(novo.nome);
        if (strlen(novo.nome) == 0)
            printf("Nome nao pode ser vazio. Tente novamente\n");
    } while (strlen(novo.nome) == 0);

    do {
        printf("CPF: ");
        fgets(novo.cpf, sizeof(novo.cpf), stdin);
        limpar_newline(novo.cpf);
        if (strlen(novo.cpf) == 0)
            printf("CPF nao pode ser vazio. Tente novamente\n");
    } while (strlen(novo.cpf) == 0);

    do {
        printf("Telefone: ");
        fgets(novo.telefone, sizeof(novo.telefone), stdin);
        limpar_newline(novo.telefone);
        if (strlen(novo.telefone) == 0)
            printf("Telefone nao pode ser vazio. Tente novamente\n");
    } while (strlen(novo.telefone) == 0);

    do {
        printf("Cidade: ");
        fgets(novo.cidade, sizeof(novo.cidade), stdin);
        limpar_newline(novo.cidade);
        if (strlen(novo.cidade) == 0)
            printf("Cidade nao pode ser vazia. Tente novamente\n");
    } while (strlen(novo.cidade) == 0);

    clientes[total] = novo;
    total++;

    printf("Cliente cadastrado com sucesso!\n");
    printf("Codigo atribuido: %d\n", novo.codigo);
}

int main() {
    int opcao;
    printf("   SISTEMA DE CADASTRO DE CLIENTES      \n");

    do {
        printf("1 Ver todos os clientes\n");
        printf("2 Adicionar novo cliente\n");
        printf("0 Sair\n");
        printf("Escolha uma opcao: \n");

        if (scanf("%d", &opcao) != 1) {
            opcao = -1;
        }
        int c;
        while ((c = getchar()) != '\n' && c != EOF);

        // VE QUAL É A ESCOLHA E QUAL COMANDO TERA QUE REALIZAR DEPENDENDO DO NUMERO ENVIADO
        switch (opcao) {
            case 1:
                listar_clientes();
                break;
            case 2:
                cadastrar_cliente();
                break;
            case 0:
                printf("Encerrando o sistema. Ate logo!\n\n");
                break;
            default:
                printf("Opcao invalida. Digite 0, 1 ou 2.\n");
        }

    } while (opcao != 0);

    return 0;
}
