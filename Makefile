# Nome do executável
EXEC = biblioteca

# Compilador e flags de compilação
CC = gcc
CFLAGS = -Wall -Wextra -std=c99

# Arquivos fonte e objetos
SRCS = main.c biblioteca.c
OBJS = $(SRCS:.c=.o)

# Regra padrão: compilar o programa
$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJS)

# Compilar arquivos .c em arquivos .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Limpar arquivos gerados na compilação
clean:
	rm -f $(OBJS) $(EXEC)

# Regra para limpar e compilar novamente
rebuild: clean $(EXEC)

# Regra para compilar e executar o programa
run: $(EXEC)
	./$(EXEC)

# Definir o arquivo .PHONY para evitar conflitos com arquivos de mesmo nome
.PHONY: clean rebuild
