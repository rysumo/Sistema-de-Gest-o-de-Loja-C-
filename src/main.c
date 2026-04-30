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
