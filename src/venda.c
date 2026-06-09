#include <stdio.h>
#include "../include/venda.h"
#include "../include/produto.h"
#include "../include/cliente.h"
#include "../include/utils.h"

// Implementação da função de venda - membro 5
void realizarVenda() {
    int idCliente, idProduto, quantidadeDesejada;
    int i, indiceCliente = -1, indiceProduto = -1;

    // verifica se tem clientes cadastrados
    if (totalClientes == 0) {
        printf("Nenhum cliente cadastrado. Cadastre um cliente primeiro.\n");
        return;
    }

    // verifica se tem produtos cadastrados
    if (totalProdutos == 0) {
        printf("Nenhum produto cadastrado. Cadastre um produto primeiro.\n");
        return;
    }

    exibirCabecalho("Realizar Venda");

    printf("Informe o codigo do cliente: ");
    //verifica se o codigo do cliente é valido
    if (scanf("%d", &idCliente) != 1) {
        limparBuffer();
        printf("Entrada invalida!\n");
        return;
    }
    limparBuffer();
    //procura o cliente no array de clientes
    for (i = 0; i < totalClientes; i++) { 
        if (clientes[i].id == idCliente) {
            indiceCliente = i;
            break;
        }
    }
    //se o cliente não for encontrado, exibe uma mensagem de erro
    if (indiceCliente == -1) {
        printf("Cliente não encontrado.\n");
        return;
    }
    
    printf("Informe o codigo do produto: ");
    //verifica se o codigo do produto é valido
    if (scanf("%d", &idProduto) != 1) {
        limparBuffer();
        printf("Entrada invalida!\n");
        return;
    }
    limparBuffer();
    //procura o produto no array de produtos
    for (i = 0; i < totalProdutos; i++) {
        if (produtos[i].id == idProduto) {
            indiceProduto = i;
            break;
        }
    }
    //se o produto não for encontrado, exibe uma mensagem de erro
    if (indiceProduto == -1) {
        printf("Produto não encontrado.\n");
        return;
    }
    
    printf("Informe a quantidade desejada: ");
    //verifica se a quantidade desejada é valida
    if (scanf("%d", &quantidadeDesejada) != 1) {
        limparBuffer();
        printf("Entrada invalida!\n");
        return;
    }
    limparBuffer();

    //verifica se a quantidade desejada é maior que zero
    if (quantidadeDesejada <= 0) {
        printf("Quantidade invalida. A quantidade deve ser maior que zero.\n");
        return;
    }
    //verifica se o estoque é suficiente
    if (produtos[indiceProduto].quantidade < quantidadeDesejada) {
        printf("Estoque insuficiente. Quantidade disponivel: %d\n", produtos[indiceProduto].quantidade);
        return;
    }

    // Realizar a venda: subtrair do estoque e calcular total
    produtos[indiceProduto].quantidade -= quantidadeDesejada;
    float valorTotal = produtos[indiceProduto].preco * quantidadeDesejada;

    exibirCabecalho("Resumo da Venda");
    printf("Cliente: %s\n", clientes[indiceCliente].nome);
    printf("Produto: %s\n", produtos[indiceProduto].nome);
    printf("Quantidade: %d\n", quantidadeDesejada);
    printf("Valor Total: R$ %.2f\n", valorTotal);
    exibirSeparador();
    printf("Venda realizada com sucesso!\n");
}
