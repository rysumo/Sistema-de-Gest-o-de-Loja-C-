#include <stdio.h>
#include <string.h>
#include "../include/cliente.h"
#include "../include/utils.h"

// Membro 4 — Implementar cadastrarCliente() aqui
void cadastrarCliente() {
    if (totalClientes >= MAX_CLIENTES) {
        printf("Erro: Limite máximo de clientes atingido.\n");
        return;
    }

    Cliente novoCliente = {0};
    int codigoDuplicado;

    // Solicita o ID do cliente
    printf("Digite o código do cliente: ");
    scanf("%d", &novoCliente.id);

    // Verifica se o ID já existe
    codigoDuplicado = 0;
    for (int i = 0; i < totalClientes; i++) {
        if (clientes[i].id == novoCliente.id) {
            codigoDuplicado = 1;
            break;
        }
    }

    if (codigoDuplicado) {
        printf("Erro: Código já cadastrado.\n");
        limparBuffer();
        return;
    }

    limparBuffer();

    printf("Digite o nome do cliente: ");
    fgets(novoCliente.nome, sizeof(novoCliente.nome), stdin);
    novoCliente.nome[strcspn(novoCliente.nome, "\n")] = '\0';

    printf("Digite o CPF do cliente: ");
    fgets(novoCliente.cpf, sizeof(novoCliente.cpf), stdin);
    novoCliente.cpf[strcspn(novoCliente.cpf, "\n")] = '\0';

    printf("Digite o telefone do cliente: ");
    fgets(novoCliente.telefone, sizeof(novoCliente.telefone), stdin);
    novoCliente.telefone[strcspn(novoCliente.telefone, "\n")] = '\0';

    printf("Digite a cidade do cliente: ");
    fgets(novoCliente.cidade, sizeof(novoCliente.cidade), stdin);
    novoCliente.cidade[strcspn(novoCliente.cidade, "\n")] = '\0';

    // Adiciona o cliente ao array
    clientes[totalClientes] = novoCliente;
    totalClientes++;

    printf("Cliente cadastrado com sucesso!\n");
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


