#include <stdio.h>
#include "../include/relatorio.h"
#include "../include/produto.h"
#include "../include/cliente.h"
#include "../include/utils.h"

// Membro 6 — Implementar exibirRelatorioGeral() aqui

void exibirRelatorioGeral() {
    exibirCabecalho("RELATORIO GERAL");

    if (totalProdutos == 0) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }

    int maior = 0;
    int menor = 0;
    int quantidadeTotal = 0;
    float valorTotal = 0;

    for (int i = 0; i < totalProdutos; i++) {
        if (produtos[i].preco > produtos[maior].preco)
            maior = i;
        if (produtos[i].preco < produtos[menor].preco)
            menor = i;

        quantidadeTotal += produtos[i].quantidade;
        valorTotal += produtos[i].preco * produtos[i].quantidade;
    }

    printf("Total de produtos: %d\n", totalProdutos);

    printf("\nProduto mais caro: %s (R$ %.2f)\n",
           produtos[maior].nome,
           produtos[maior].preco);

    printf("Produto mais barato: %s (R$ %.2f)\n",
           produtos[menor].nome,
           produtos[menor].preco);

    printf("\nQuantidade total em estoque: %d\n",
           quantidadeTotal);

    printf("Valor total do estoque: R$ %.2f\n",
           valorTotal);
}
