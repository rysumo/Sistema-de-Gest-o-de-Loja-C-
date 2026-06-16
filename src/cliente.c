#include <stdio.h>
#include <string.h>
#include "../include/cliente.h"
#include "../include/utils.h"

// Função auxiliar para remover \n do final da string
void limpar_newline(char *str) {
    int len = strlen(str);
    if (len > 0 && str[len - 1] == '\n')
        str[len - 1] = '\0';
}

// Membro 4 — Implementar cadastrarCliente() aqui
void cadastrarCliente() {
    if (totalClientes >= MAX_CLIENTES) {
        printf("Erro: Limite máximo de clientes atingido.\n");
        return;
    }

    Cliente novo;
    novo.id = 100001 + totalClientes;

    exibirCabecalho("NOVO CLIENTE");
    printf("Código gerado automaticamente: %d\n\n", novo.id);

    do {
        printf("Nome completo : ");
        fgets(novo.nome, sizeof(novo.nome), stdin);
        limpar_newline(novo.nome);
        if (strlen(novo.nome) == 0)
            printf("Nome nao pode ser vazio. Tente novamente\n");
    } while (strlen(novo.nome) == 0);

    do {
        printf("CPF           : ");
        fgets(novo.cpf, sizeof(novo.cpf), stdin);
        limpar_newline(novo.cpf);
        if (strlen(novo.cpf) == 0)
            printf("CPF nao pode ser vazio. Tente novamente\n");
    } while (strlen(novo.cpf) == 0);

    do {
        printf("Telefone      : ");
        fgets(novo.telefone, sizeof(novo.telefone), stdin);
        limpar_newline(novo.telefone);
        if (strlen(novo.telefone) == 0)
            printf("Telefone nao pode ser vazio. Tente novamente\n");
    } while (strlen(novo.telefone) == 0);

    do {
        printf("Cidade        : ");
        fgets(novo.cidade, sizeof(novo.cidade), stdin);
        limpar_newline(novo.cidade);
        if (strlen(novo.cidade) == 0)
            printf("Cidade nao pode ser vazia. Tente novamente\n");
    } while (strlen(novo.cidade) == 0);

    clientes[totalClientes] = novo;
    totalClientes++;

    exibirSeparador();
    printf("Cliente cadastrado com sucesso!\n");
    printf("Codigo atribuido: %d\n", novo.id);
    exibirSeparador();
}

// Membro 3 — Implementar listarClientes() aqui
void listarClientes() {
    exibirCabecalho("Lista de Clientes");

    if (totalClientes == 0) {
        printf("Nenhum cliente cadastrado.\n");
    } else {
        for (int i = 0; i < totalClientes; i++) {
            printf("Cliente %d:\n", i + 1);
            printf("ID        : %d\n", clientes[i].id);
            printf("Nome      : %s\n", clientes[i].nome);
            printf("CPF       : %s\n", clientes[i].cpf);
            printf("Telefone  : %s\n", clientes[i].telefone);
            printf("Cidade    : %s\n", clientes[i].cidade);
            exibirSeparador();
        }
    }
}


