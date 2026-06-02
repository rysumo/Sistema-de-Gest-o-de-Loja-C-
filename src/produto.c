#include <stdio.h>
#include <string.h>
#include "../include/produto.h"
#include "../include/utils.h"

// Membro 2 — Implementar cadastrarProduto() aqui

// Membro 3 — Implementar listarProdutos() aqui

void listarProdutos() {

    exibirCabecalho("Lista de Produtos");

    if (totalProdutos == 0) {

        printf("Nenhum produto cadastrado.\n");

    } else {

        for (int i = 0; i < totalProdutos; i++) {
            printf("Produto %d:\n", i + 1);
            printf("Nome      : %s\n", produtos[i].nome);
            printf("ID        : %d\n", produtos[i].id);
            printf("Preco     : R$ %.2f\n", produtos[i].preco);
            printf("Quantidade: %d\n", produtos[i].quantidade);
            exibirSeparador();
        }
    }

    printf("\nPressione Enter para voltar ao menu...");

    getchar();

}

