.PHONY: clean all
CC=gcc
CXX=g++
CFLAGS=-Wall -g
BIN= MyBinaryTree

all: $(BIN)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	rm -rf *.o $(BIN) *.dSYM
