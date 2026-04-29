# 📦 Sistema de Gestão de Loja (C) - Projeto Final

Este repositório contém o código-fonte de um sistema de gestão comercial desenvolvido em Linguagem C, como projeto final da disciplina de Desenvolvimento Desktop. O software simula as operações essenciais de uma loja, funcionando inteiramente via terminal (console).

## 🎯 Objetivo do Projeto

O objetivo principal é aplicar conhecimentos fundamentais de programação estruturada para resolver um problema real de automação comercial, focando em organização de dados, validações de entrada e interface amigável para o utilizador.

## 🚀 Funcionalidades (Menu Principal)

O sistema foi estruturado para ser intuitivo, permitindo as seguintes operações:

- **Cadastrar Produto:** Registo de código (ID único), nome, preço e quantidade.
- **Listar Produtos:** Exibição detalhada de todos os itens em inventário.
- **Cadastrar Cliente:** Registo de nome completo, documento (CPF), telefone e cidade.
- **Listar Clientes:** Listagem organizada de todos os clientes registados.
- **Realizar Venda:** Sistema de transação que abate o stock e calcula o valor total.
- **Relatório Geral:** Painel de estatísticas com totais, maior/menor preço e valor total do stock.
- **Sair:** Encerramento seguro da execução.

## 🛠️ Requisitos Técnicos Aplicados

Conforme exigido pelo regulamento do projeto, o código utiliza:

- **Estruturas de Controlo:** `if`/`else` e `switch` para lógica de menu e decisões.
- **Laços de Repetição:** `for` e `while` para processamento de listas e manutenção do loop principal.
- **Estruturas de Dados:** `structs` para organização de entidades e vetores para armazenamento em memória.
- **Entrada de Dados:** Uso obrigatório de `fgets()` para leitura segura de strings, evitando erros de buffer.

## 🛡️ Regras de Negócio e Validações

O sistema garante a integridade dos dados através de:

- **ID Único:** Impede o cadastro de produtos com códigos repetidos.
- **Validação de Stock:** Verifica a existência de itens e a disponibilidade antes de concluir uma venda.
- **Campos Obrigatórios:** Não permite o cadastro de clientes com nomes vazios.
- **Feedback ao Utilizador:** Mensagens claras de confirmação (ex: "Cadastro realizado com sucesso") e erros (ex: "Estoque insuficiente").

## 📁 Como Executar o Projeto

**Pré-requisitos:** Ter um compilador C instalado (GCC, Clang ou MinGW).

1. **Clonar o repositório:**
   ```bash
   git clone https://github.com/seu-usuario/sistema-loja-c.git
   ```

2. **Compilar o código:**
   ```bash
   gcc Main.c -o sistema_loja
   ```
   *(Nota: Se o seu arquivo principal se chamar de outra forma, substitua `Main.c` pelo nome correto).*

3. **Executar:**
   - No Linux/macOS:
     ```bash
     ./sistema_loja
     ```
   - No Windows:
     ```cmd
     sistema_loja.exe
     ```

## 📝 Observação Académica

Este projeto acompanha um relatório em PDF que detalha a arquitetura do sistema, a explicação técnica do código e a divisão de tarefas entre os membros do grupo, conforme solicitado nos requisitos da disciplina.
