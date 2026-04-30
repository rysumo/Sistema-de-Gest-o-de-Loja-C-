# 📦 Sistema de Gestão de Loja (C) — Projeto Final

Este repositório contém o código-fonte de um sistema de gestão comercial desenvolvido em Linguagem C, como projeto final da disciplina de Desenvolvimento Desktop. O software simula as operações essenciais de uma loja, funcionando inteiramente via terminal (console).

## 🎯 Objetivo do Projeto

Aplicar conhecimentos fundamentais de programação estruturada para resolver um problema real de automação comercial, focando em organização de dados, validações de entrada e interface amigável para o utilizador.

## 🚀 Funcionalidades (Menu Principal)

O sistema foi estruturado para ser intuitivo, permitindo as seguintes operações:

| Opção | Funcionalidade | Descrição |
|:-----:|---------------|-----------|
| 1 | **Cadastrar Produto** | Registo de código (ID único), nome, preço e quantidade |
| 2 | **Listar Produtos** | Exibição detalhada de todos os itens em inventário |
| 3 | **Cadastrar Cliente** | Registo de nome completo, CPF, telefone e cidade |
| 4 | **Listar Clientes** | Listagem organizada de todos os clientes registados |
| 5 | **Realizar Venda** | Transação que abate o stock e calcula o valor total |
| 6 | **Relatório Geral** | Estatísticas com totais, maior/menor preço e valor do stock |
| 7 | **Sair** | Encerramento seguro da execução |

## 📂 Estrutura do Projeto

```
Sistema-de-Gest-o-de-Loja-C-/
│
├── README.md                ← Documentação do projeto
├── GUIA_DO_PROJETO.md       ← Guia interno para os membros do grupo
├── Makefile                 ← Compilação automatizada
├── .gitignore               ← Arquivos ignorados pelo Git
│
├── include/                 ← Headers (.h) — Definições e protótipos
│   ├── utils.h              ← Funções utilitárias (separadores visuais)
│   ├── produto.h            ← Struct Produto + protótipos de cadastro/listagem
│   ├── cliente.h            ← Struct Cliente + protótipos de cadastro/listagem
│   ├── venda.h              ← Protótipo da função de venda
│   └── relatorio.h          ← Protótipo da função de relatório
│
├── src/                     ← Código-fonte (.c) — Implementações
│   ├── main.c               ← Ponto de entrada, menu principal e variáveis globais
│   ├── utils.c              ← Implementação dos separadores visuais
│   ├── produto.c            ← Cadastro e listagem de produtos
│   ├── cliente.c            ← Cadastro e listagem de clientes
│   ├── venda.c              ← Lógica de realização de vendas
│   └── relatorio.c          ← Geração do relatório geral
│
└── docs/                    ← Documentação complementar
    └── relatorio_final.pdf  ← Relatório acadêmico do grupo (PDF)
```

## 🛠️ Requisitos Técnicos Aplicados

Conforme exigido pelo regulamento do projeto, o código utiliza:

- **Estruturas de Controlo:** `if`/`else` e `switch` para lógica de menu e decisões
- **Laços de Repetição:** `for` e `while` para processamento de listas e loop principal
- **Estruturas de Dados:** `structs` para organização de entidades e vetores para armazenamento
- **Entrada de Dados:** Uso obrigatório de `fgets()` para leitura segura de strings
- **Modularização:** Separação em múltiplos arquivos `.c` e `.h` com responsabilidades definidas

## 🛡️ Regras de Negócio e Validações

- **ID Único:** Impede o cadastro de produtos com códigos repetidos
- **Validação de Stock:** Verifica existência de itens e disponibilidade antes de concluir vendas
- **Campos Obrigatórios:** Não permite cadastro de clientes com nomes vazios
- **Quantidades Válidas:** Não permite quantidades negativas no cadastro de produtos
- **Feedback ao Utilizador:** Mensagens claras de confirmação e erro em todas as operações

## 📁 Como Executar o Projeto

**Pré-requisitos:** Ter um compilador C instalado (GCC, Clang ou MinGW).

### 1. Clonar o repositório

```bash
git clone https://github.com/seu-usuario/Sistema-de-Gest-o-de-Loja-C-.git
cd Sistema-de-Gest-o-de-Loja-C-
```

### 2. Compilar o código

**Usando o Makefile (recomendado):**
```bash
make
```

**Ou manualmente:**
```bash
gcc -I include src/main.c src/utils.c src/produto.c src/cliente.c src/venda.c src/relatorio.c -o sistema_loja
```

### 3. Executar

- No Windows:
  ```cmd
  sistema_loja.exe
  ```
- No Linux/macOS:
  ```bash
  ./sistema_loja
  ```

## 👥 Equipe e Divisão de Tarefas

| Membro | Responsabilidade | Arquivo(s) |
|--------|-----------------|------------|
| Membro 1 | Estrutura base + menu principal | `src/main.c`, `src/utils.c` |
| Membro 2 | Cadastro de produtos | `src/produto.c` |
| Membro 3 | Listagem de produtos e clientes | `src/produto.c`, `src/cliente.c` |
| Membro 4 | Cadastro de clientes | `src/cliente.c` |
| Membro 5 | Realizar venda | `src/venda.c` |
| Membro 6 | Relatório geral + documentação | `src/relatorio.c` |

## 📝 Observação Acadêmica

Este projeto acompanha um relatório em PDF que detalha a arquitetura do sistema, a explicação técnica do código e a divisão de tarefas entre os membros do grupo, conforme solicitado nos requisitos da disciplina.
