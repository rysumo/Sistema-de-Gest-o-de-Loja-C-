#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

// ==========================================
// 3. DECLARAR CONSTANTES
// ==========================================
#define MAX_PRODUTOS 100
#define MAX_CLIENTES 100

// ==========================================
// 2. DEFINIR AS STRUCTS PRODUTO E CLIENTE
// ==========================================
typedef struct {
    int id;
    char nome[50];
    float preco;
    int quantidade;
} Produto;

typedef struct {
    char cpf[15];
    char nome[50];
    char telefone[20];
    char cidade[50];
} Cliente;

// ==========================================
// 3. VETORES GLOBAIS E CONTADORES
// ==========================================
Produto produtos[MAX_PRODUTOS];
int totalProdutos = 0;

Cliente clientes[MAX_CLIENTES];
int totalClientes = 0;

// ==========================================
// 5. SEPARADORES VISUAIS NO TERMINAL
// ==========================================
void exibirSeparador() {
    printf("\n==================================================\n");
}

void exibirCabecalho(char* titulo) {
    exibirSeparador();
    printf("   %s\n", titulo);
    exibirSeparador();
}

// ==========================================
// 1. ESTRUTURA GERAL (main)
// ==========================================
int main() {
    // Configurar para aceitar acentuação em português
    setlocale(LC_ALL, ".UTF-8");

    int opcao;

    // ==========================================
    // 4. IMPLEMENTAR O MENU COM SWITCH/CASE E LOOP
    // ==========================================
    do {
        exibirCabecalho("SISTEMA DE GESTÃO DE LOJA");
        printf("1. Cadastrar Produto\n");
        printf("2. Listar Produtos\n");
        printf("3. Cadastrar Cliente\n");
        printf("4. Listar Clientes\n");
        printf("5. Realizar Venda\n");
        printf("6. Relatório Geral\n");
        printf("7. Sair\n");
        exibirSeparador();
        
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        
        // Limpar o buffer de entrada após o scanf (muito importante antes de usar fgets depois)
        while (getchar() != '\n'); 

        switch (opcao) {
            case 1:
                exibirCabecalho("CADASTRAR PRODUTO");
                // TODO: Chamar função de cadastrar produto
                printf("Funcionalidade em desenvolvimento...\n");
                break;
            case 2:
                exibirCabecalho("LISTAR PRODUTOS");
                // TODO: Chamar função de listar produtos
                printf("Funcionalidade em desenvolvimento...\n");
                break;
            case 3:
                exibirCabecalho("CADASTRAR CLIENTE");
                // TODO: Chamar função de cadastrar cliente
                printf("Funcionalidade em desenvolvimento...\n");
                break;
            case 4:
                exibirCabecalho("LISTAR CLIENTES");
                // TODO: Chamar função de listar clientes
                printf("Funcionalidade em desenvolvimento...\n");
                break;
            case 5:
                exibirCabecalho("REALIZAR VENDA");
                // TODO: Chamar função de realizar venda
                printf("Funcionalidade em desenvolvimento...\n");
                break;
            case 6:
                exibirCabecalho("RELATÓRIO GERAL");
                // TODO: Chamar função de relatório
                printf("Funcionalidade em desenvolvimento...\n");
                break;
            case 7:
                exibirCabecalho("SAINDO DO SISTEMA...");
                printf("Obrigado por usar o nosso sistema!\n");
                break;
            default:
                printf("\n[!] Opção inválida. Tente novamente.\n");
        }
        
        if (opcao != 7) {
            printf("\nPressione ENTER para continuar...");
            getchar(); // Pausa a tela até o usuário dar enter
        }

    } while (opcao != 7);

    return 0;
}
