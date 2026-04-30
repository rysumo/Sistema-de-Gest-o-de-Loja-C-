CC = gcc
CFLAGS = -Wall -I include
SRC = src/main.c src/utils.c src/produto.c src/cliente.c src/venda.c src/relatorio.c
OUT = sistema_loja

all: $(OUT)

$(OUT): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)

clean:
	del $(OUT).exe 2>nul
