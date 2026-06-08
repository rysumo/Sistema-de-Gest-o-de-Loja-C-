#include <stdio.h>
#include <string.h>
#include "../include/produto.h"
#include "../include/utils.h"

// Membro 2 — Implementar cadastrarProduto() aqui

void cadastrarProduto() {
    if (totalProdutos >= MAX_PRODUTOS) {
        printf("Erro: Limite maximo de produtos atingido.\n");
        return;
    }

    Produto novoProduto = {0};
    int codigoDuplicado;

    printf("Digite o código do produto: ");
    scanf("%d", &novoProduto.id);

    codigoDuplicado = 0;

    for (int i = 0; i < totalProdutos; i++) {
        if (produtos[i].id == novoProduto.id) {
            codigoDuplicado = 1;
            break;
        }
    }

    if (codigoDuplicado) {
        printf("Erro: código já cadastrado.\n");
        limparBuffer();
        return;
    }

    limparBuffer();

    printf("Digite o nome do produto: ");
    fgets(novoProduto.nome, sizeof(novoProduto.nome), stdin);

    novoProduto.nome[strcspn(novoProduto.nome, "\n")] = '\0';

    printf("Digite o preço do produto: ");
    scanf("%f", &novoProduto.preco);

    do {
        printf("Digite a quantidade do produto: ");
        scanf("%d", &novoProduto.quantidade);

        if (novoProduto.quantidade < 0) {
            printf("Quantidade nao pode ser negativa.\n");
        }
    } while (novoProduto.quantidade < 0);

    limparBuffer();

    produtos[totalProdutos] = novoProduto;
    totalProdutos++;

    printf("Cadastro realizado com sucesso.\n");
}

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
}

