#ifndef PRODUTO_H
#define PRODUTO_H

#define MAX_PRODUTOS 100

typedef struct {
    int id;
    char nome[50];
    float preco;
    int quantidade;
} Produto;

extern Produto produtos[MAX_PRODUTOS];
extern int totalProdutos;

void cadastrarProduto();
void listarProdutos();

#endif
