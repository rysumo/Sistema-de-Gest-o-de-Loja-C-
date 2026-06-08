#ifndef CLIENTE_H
#define CLIENTE_H

#define MAX_CLIENTES 100

typedef struct {
    char cpf[15];
    char nome[50];
    char telefone[20];
    char cidade[50];
} Cliente;

extern Cliente clientes[MAX_CLIENTES];
extern int totalClientes;

void cadastrarCliente();
void listarClientes();

#endif
