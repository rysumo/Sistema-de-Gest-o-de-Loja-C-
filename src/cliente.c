#include <stdio.h>
#include <string.h>
#include "../include/cliente.h"
#include "../include/utils.h"

// Membro 4 — Implementar cadastrarCliente() aqui
// Lembrar de pedir Id para o cadastro

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


