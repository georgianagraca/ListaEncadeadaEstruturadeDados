CC = gcc
CFLAGS = -Wall -g
TARGET = lista_encadeada

all: $(TARGET)

$(TARGET): lista_encadeada.c
	$(CC) $(CFLAGS) -o $(TARGET) lista_encadeada.c

clean:
	rm -f $(TARGET)