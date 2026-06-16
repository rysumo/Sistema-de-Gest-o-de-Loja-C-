#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/utils.h"
#include "../include/produto.h"
#include "../include/cliente.h"
#include "../include/venda.h"
#include "../include/relatorio.h"


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

void exibirCabecalho(const char *titulo) {
    exibirSeparador();
    printf("%s\n", titulo);
    exibirSeparador();
}

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void pausar() {
    printf("\nPressione Enter para continuar...");
    limparBuffer();
}

// Função auxiliar para remover \n do final da string
void limpar_newline(char *str) {
    int len = strlen(str);
    if (len > 0 && str[len - 1] == '\n')
        str[len - 1] = '\0';
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
                cadastrarProduto();
                break;
            case 2:
                printf("\n--- Listagem de Produtos ---\n");
                listarProdutos();
                break;
            case 3:
                printf("\n--- Cadastro de Clientes ---\n");
                cadastrarCliente();
                break;
            case 4:
                printf("\n--- Listagem de Clientes ---\n");
                listarClientes();
                break;
            case 5:
                printf("\n--- Realizar Venda ---\n");
                realizarVenda();
                break;
            case 6:
                printf("\n--- Relatorio Geral ---\n");
                exibirRelatorioGeral();
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
