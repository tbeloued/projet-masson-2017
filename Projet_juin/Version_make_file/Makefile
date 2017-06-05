CC=gcc
CFLAGS=-Wall -ansi -pedantic -std=c99
LDFLAGS=-lm
EXEC=prog1
BIN=prog1.o main.o
SRC=prog1.c main.c
HEAD=prog1.h

all: $(EXEC)

prog1: $(BIN)
	$(CC) -o prog1 $(BIN) $(LDFLAGS)

%.o: %.c $(HEAD)
	$(CC) -c $< $(CFLAGS)

clean:
	rm -f *.o *~ 2> /dev/null

clear: clean
	rm -f $(EXEC) $(USER)_prog1.tgz 2> /dev/null

zip: clear
	mkdir -p $(USER)_exo1
	cp Makefile *.c *.h $(USER)_prog1
	tar czf $(USER)_prog1.tgz $(USER)_prog1
	rm -rf $(USER)_prog1
