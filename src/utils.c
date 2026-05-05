#include <stdio.h>
#include <stdlib.h>
#include "../include/utils.h"

void limparTela() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void exibirSeparador() {
    printf("------------------------------------------------------------\n");
}

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void pausar() {
    printf("\nPressione Enter para continuar...");
    limparBuffer();
}

void menuPrincipal() {
    int opcao;
    
    do {
        limparTela();
        exibirSeparador();
        printf("       SISTEMA DE GESTAO DE LOJA\n");
        exibirSeparador();
        printf("  1 - Cadastro de produtos\n");
        printf("  2 - Listar produtos\n");
        printf("  3 - Cadastro de clientes\n");
        printf("  4 - Listar clientes\n");
        printf("  5 - Realizar venda\n");
        printf("  6 - Relatorio geral\n");
        printf("  7 - Sair\n");
        exibirSeparador();
        printf("  Opcao: ");
        
        if (scanf("%d", &opcao) != 1) {
            opcao = -1;
        }
        limparBuffer();
        
        switch (opcao) {
            case 1:
                printf("\n--- Cadastro de Produtos ---\n");
                // TODO: cadastrarProduto(); (Membro 2)
                break;
            case 2:
                printf("\n--- Listagem de Produtos ---\n");
                // TODO: listarProdutos(); (Membro 3)
                break;
            case 3:
                printf("\n--- Cadastro de Clientes ---\n");
                // TODO: cadastrarCliente(); (Membro 4)
                break;
            case 4:
                printf("\n--- Listagem de Clientes ---\n");
                // TODO: listarClientes(); (Membro 3)
                break;
            case 5:
                printf("\n--- Realizar Venda ---\n");
                // TODO: realizarVenda(); (Membro 5)
                break;
            case 6:
                printf("\n--- Relatorio Geral ---\n");
                // TODO: exibirRelatorioGeral(); (Membro 6)
                break;
            case 7:
                printf("\nSaindo do sistema. Ate logo!\n");
                break;
            default:
                printf("\nOpcao invalida! Tente novamente.\n");
        }
        
        if (opcao != 7) {
            pausar();
        }
        
    } while (opcao != 7);
}