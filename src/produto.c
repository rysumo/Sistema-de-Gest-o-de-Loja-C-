#include <stdio.h>
#include <string.h>
#include "../include/produto.h"
#include "../include/utils.h"

// Membro 2 — Implementar cadastrarProduto() aqui

#include <stdio.h>
#include <string.h>

struct Produto {
    int codigo;
    char nome[100];
    float preco;
    int quantidade;
};

int main() {
    struct Produto produto;
    int codigos[100];
    int totalProdutos = 0;
    int codigoDuplicado;

    printf("Digite o código do produto: ");
    scanf("%d", &produto.codigo);

    codigoDuplicado = 0;

    for (int i = 0; i < totalProdutos; i++) {
        if (codigos[i] == produto.codigo) {
            codigoDuplicado = 1;
            break;
        }
    }

    if (codigoDuplicado) {
        printf("Erro: código já cadastrado.\n");
        return 1;
    }

    getchar();

    printf("Digite o nome do produto: ");
    fgets(produto.nome, sizeof(produto.nome), stdin);

    produto.nome[strcspn(produto.nome, "\n")] = '\0';

    printf("Digite o preço do produto: ");
    scanf("%f", &produto.preco);

    do {
        printf("Digite a quantidade do produto: ");
        scanf("%d", &produto.quantidade);

        if (produto.quantidade < 0) {
            printf("Quantidade nao pode ser negativa.\n");
        }
    } while (produto.quantidade < 0);

    codigos[totalProdutos] = produto.codigo;
    totalProdutos++;

    printf("Cadastro realizado com sucesso.\n");

    return 0;
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

    printf("\nPressione Enter para voltar ao menu...");

    getchar();

}

