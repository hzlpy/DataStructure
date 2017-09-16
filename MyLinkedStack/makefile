.PHONY: clean all
CC=gcc
CFLAGS=-Wall -g
BIN= MyLinkedStack

all: $(BIN)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	rm -rf *.o $(BIN) *.dSYM