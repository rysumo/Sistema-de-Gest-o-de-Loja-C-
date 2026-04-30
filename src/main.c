#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#include "../include/utils.h"
#include "../include/produto.h"
#include "../include/cliente.h"
#include "../include/venda.h"
#include "../include/relatorio.h"

// Definição dos vetores globais (única vez)
Produto produtos[MAX_PRODUTOS];
int totalProdutos = 0;

Cliente clientes[MAX_CLIENTES];
int totalClientes = 0;

// Membro 1 — Implementar a main() com menu switch/case e loop while aqui

int main() {
    setlocale(LC_ALL, "Portuguese");
    
    int opcao;
    
    do {
        printf("\n--- Sistema de Gestão de Loja ---\n");
        printf("1. Gerenciar Produtos\n");
        printf("2. Gerenciar Clientes\n");
        printf("3. Gerenciar Vendas\n");
        printf("4. Gerar Relatórios\n");
        printf("0. Sair\n");
        printf("Digite sua opção: ");
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1:
                // Gerenciar produtos
                printf("Gerenciando produtos...")
                break;
            case 2:
                // Gerenciar clientes
                printf("Gerenciando clientes...");
                break;
            case 3:
                // Gerenciar vendas
                printf("Gerenciando vendas...");
                break;
            case 4:
                // Gerar relatórios
                printf("Gerando relatórios...");
                break;
            case 0:
                printf("Saindo do sistema...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 0);
    
    return 0;
}
