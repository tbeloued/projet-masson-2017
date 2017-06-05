CC=gcc
CFLAGS=-Wall -ansi -pedantic -std=c99
LDFLAGS=-lm
EXEC=prog2
BIN=prog2.o main.o
SRC=prog2.c main.c
HEAD=prog2.h

all: $(EXEC)

prog2: $(BIN)
	$(CC) -o prog2 $(BIN) $(LDFLAGS)

%.o: %.c $(HEAD)
	$(CC) -c $< $(CFLAGS)

clean:
	rm -f *.o *~ 2> /dev/null

clear: clean
	rm -f $(EXEC) $(USER)_prog2.tgz 2> /dev/null

zip: clear
	mkdir -p $(USER)_prog2
	cp Makefile *.c *.h $(USER)_prog2
	tar czf $(USER)_prog2.tgz $(USER)_prog2
	rm -rf $(USER)_prog2
