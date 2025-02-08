CC = gcc
SRC = source/*.c
TARGET = prog < pokemon.txt

all: clean $(TARGET)
	@echo "=== Executando ==="
	./$(TARGET)

$(TARGET):
	@echo "=== Compilando ==="
	$(CC) $(SRC) -o $(TARGET)

clean:
	@echo "=== Limpando arquivos ==="
	rm -f $(TARGET) # Remove o arquivo executável (prog)