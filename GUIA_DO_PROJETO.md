# 📘 Guia do Projeto — Sistema de Gestão de Loja em C

Fala galera! Este guia explica como o projeto está organizado, onde cada um vai trabalhar, e como tudo se conecta. **Leiam tudo antes de começar a codar!**

---

## 📂 Estrutura de Pastas

```
Sistema-de-Gest-o-de-Loja-C-/
│
├── README.md               ← Descrição do projeto pro GitHub
├── GUIA_DO_PROJETO.md      ← Este arquivo que vocês estão lendo
├── Makefile                ← Comando de compilação automática
├── .gitignore              ← Arquivos que o Git ignora (.exe, .o)
│
├── include/                ← 📋 HEADERS (arquivos .h)
│   ├── utils.h
│   ├── produto.h
│   ├── cliente.h
│   ├── venda.h
│   └── relatorio.h
│
└── src/                    ← 💻 CÓDIGO-FONTE (arquivos .c)
    ├── main.c
    ├── utils.c
    ├── produto.c
    ├── cliente.c
    ├── venda.c
    └── relatorio.c
```

---

## 🤔 O que é a pasta `include/` e os arquivos `.h`?

Os arquivos `.h` (headers) são como **fichas de contrato**. Eles dizem:
- Quais **structs** existem (Produto, Cliente)
- Quais **funções** existem (só o nome e os parâmetros)
- Quais **variáveis globais** são compartilhadas

> ⚠️ **IMPORTANTE:** Os arquivos `.h` **NÃO TÊM código de implementação**. Eles só declaram o que existe. O código real fica nos `.c`.

### Por que precisamos dos `.h`?

Imagine que o Membro 5 (venda) precisa acessar o vetor de `produtos[]` que foi definido no `main.c`. Sem o `.h`, o compilador não saberia que esse vetor existe. O header `produto.h` diz: *"ei, existe um vetor chamado `produtos` e uma struct chamada `Produto`"* — e aí qualquer arquivo `.c` que fizer `#include "produto.h"` consegue usar.

### O que significa cada coisa dentro do `.h`?

```c
#ifndef PRODUTO_H        // ← "Se PRODUTO_H ainda não foi definido..."
#define PRODUTO_H        // ← "...defina agora" (evita incluir 2x)

#define MAX_PRODUTOS 100 // ← Constante: máximo de produtos

typedef struct {         // ← Definição da struct Produto
    int id;
    char nome[50];
    float preco;
    int quantidade;
} Produto;

extern Produto produtos[MAX_PRODUTOS]; // ← "Esse vetor EXISTE em outro arquivo"
extern int totalProdutos;              // ← "Esse contador EXISTE em outro arquivo"

void cadastrarProduto();  // ← "Essa função EXISTE em outro arquivo"
void listarProdutos();    // ← "Essa função EXISTE em outro arquivo"

#endif                    // ← Fecha o #ifndef
```

**Resumindo:**
- `#ifndef / #define / #endif` → Proteção para não incluir o mesmo arquivo duas vezes
- `extern` → Diz que a variável existe, mas foi **criada em outro arquivo** (no `main.c`)
- `void cadastrarProduto();` → Só o **protótipo** (assinatura) da função, sem o corpo `{}`

---

## 💻 O que é a pasta `src/` e os arquivos `.c`?

É aqui que vocês vão **escrever o código de verdade**. Cada arquivo `.c` é responsável por uma parte do sistema.

### `src/main.c` — Membro 1

O **coração do programa**. Contém:
- A função `main()` com o loop do menu
- O `switch/case` que chama as funções dos outros membros
- A **definição real** dos vetores globais (`produtos[]`, `clientes[]` e seus contadores)

> 🔑 Os vetores estão **definidos aqui** (sem `extern`), e todos os outros arquivos acessam eles através dos headers.

### `src/utils.c` — Membro 1

Funções visuais do terminal:
- `exibirSeparador()` → Imprime a linha `===========`
- `exibirCabecalho(char* titulo)` → Imprime título entre separadores

### `src/produto.c` — Membro 2 (cadastrar) + Membro 3 (listar)

Duas funções para implementar:
- `cadastrarProduto()` → **Membro 2** escreve essa função
- `listarProdutos()` → **Membro 3** escreve essa função

### `src/cliente.c` — Membro 4 (cadastrar) + Membro 3 (listar)

Duas funções para implementar:
- `cadastrarCliente()` → **Membro 4** escreve essa função
- `listarClientes()` → **Membro 3** escreve essa função

### `src/venda.c` — Membro 5

Uma função para implementar:
- `realizarVenda()` → Lógica completa de venda

### `src/relatorio.c` — Membro 6

Uma função para implementar:
- `exibirRelatorioGeral()` → Estatísticas do estoque

---

## 👥 Quem mexe em qual arquivo?

| Membro | Arquivo(s) que vai editar | O que implementar |
|--------|--------------------------|-------------------|
| **1** | `src/main.c` + `src/utils.c` | Menu principal + separadores visuais |
| **2** | `src/produto.c` | Função `cadastrarProduto()` |
| **3** | `src/produto.c` + `src/cliente.c` | Funções `listarProdutos()` e `listarClientes()` |
| **4** | `src/cliente.c` | Função `cadastrarCliente()` |
| **5** | `src/venda.c` | Função `realizarVenda()` |
| **6** | `src/relatorio.c` | Função `exibirRelatorioGeral()` |

> ⚠️ **NÃO MEXAM nos arquivos `.h`!** Eles já estão prontos. Vocês só precisam escrever código nos `.c`.

---

## 🔧 Como começar a codar (passo a passo)

### 1. Abra seu arquivo `.c`

Por exemplo, se você é o **Membro 5**, abra `src/venda.c`. Você vai ver:

```c
#include <stdio.h>
#include "../include/venda.h"
#include "../include/produto.h"
#include "../include/cliente.h"
#include "../include/utils.h"

// Membro 5 — Implementar realizarVenda() aqui
```

### 2. Escreva sua função logo abaixo do comentário

```c
void realizarVenda() {
    // Seu código aqui dentro
    // Você pode usar: produtos[], totalProdutos, clientes[], totalClientes
    // Você pode chamar: exibirCabecalho(), exibirSeparador()
}
```

### 3. Use as variáveis e funções dos outros membros

Como os `#include` já estão configurados, você pode usar diretamente:

| O que usar | Vem de qual header | Exemplo |
|------------|-------------------|---------|
| `produtos[i]` | `produto.h` | `produtos[0].nome`, `produtos[0].preco` |
| `totalProdutos` | `produto.h` | `for (int i = 0; i < totalProdutos; i++)` |
| `clientes[i]` | `cliente.h` | `clientes[0].cpf`, `clientes[0].cidade` |
| `totalClientes` | `cliente.h` | `if (totalClientes == 0)` |
| `exibirCabecalho("texto")` | `utils.h` | `exibirCabecalho("REALIZAR VENDA");` |
| `exibirSeparador()` | `utils.h` | `exibirSeparador();` |

---

## 🏗️ Como compilar e rodar

### Opção 1: Comando direto no terminal

```bash
gcc -I include src/main.c src/utils.c src/produto.c src/cliente.c src/venda.c src/relatorio.c -o sistema_loja
```

Depois para rodar:
```bash
sistema_loja.exe
```

### Opção 2: Usando o Makefile (mais fácil)

Se vocês tiverem o `make` instalado:
```bash
make
```

Para limpar o executável:
```bash
make clean
```

---

## ⚡ Fluxo de como tudo se conecta

```
Usuário escolhe opção 1 no menu
         │
         ▼
main.c → switch(1) → chama cadastrarProduto()
         │
         ▼
produto.c → cadastrarProduto() executa
         │  usa: produtos[], totalProdutos (vem do main.c via produto.h)
         │  usa: exibirCabecalho() (vem do utils.c via utils.h)
         │
         ▼
Volta pro loop do menu em main.c
```

---

## ❗ Regras importantes

1. **Não criem variáveis globais novas** — usem as que já existem (`produtos[]`, `clientes[]`, etc.)
2. **Usem `fgets()` para ler strings** — nunca `scanf("%s")`, porque não lê espaços
3. **Antes de usar `fgets()`**, limpem o buffer com `while (getchar() != '\n');` se tiverem usado `scanf` antes
4. **Testem o código compilando tudo junto**, não só o arquivo isolado
5. **Façam `git pull` antes de começar** e `git push` quando terminarem, para evitar conflitos

---

## 🆘 Dúvidas comuns

**P: Posso criar funções auxiliares no meu arquivo?**
R: Sim! Se for uma função que só você usa, crie ela dentro do seu `.c` sem precisar colocar no `.h`.

**P: E se eu precisar de uma função que outro membro criou?**
R: Se a função está declarada no `.h` e você já fez o `#include` desse header, é só chamar direto.

**P: O que é `extern`?**
R: É uma palavra que diz "essa variável existe, mas não está sendo criada aqui". A criação real está no `main.c`. O `extern` só avisa o compilador que ela existe em outro lugar.

**P: O que acontece se eu não colocar `#include "../include/produto.h"`?**
R: O compilador não vai reconhecer `Produto`, `produtos[]`, `cadastrarProduto()`, etc. Vai dar erro.

**P: Posso mexer nos arquivos `.h`?**
R: Não precisa. Eles já estão prontos. Só mexam nos `.c`.

---

Bora codar! 🚀
