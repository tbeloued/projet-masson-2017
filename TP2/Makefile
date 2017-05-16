CC=gcc
CFLAGS=-Wall -ansi -pedantic
LDFLAGS=-lm
EXEC=exo1
BIN=exo1.o main.o
SRC=exo1.c main.c
HEAD=exo1.h

all: $(EXEC)

exo1: $(BIN)
	$(CC) -o exo1 $(BIN) $(LDFLAGS)

%.o: %.c $(HEAD)
	$(CC) -c $< $(CFLAGS)

clean:
	rm -f *.o *~ 2> /dev/null

clear: clean
	rm -f $(EXEC) $(USER)_exo1.tgz 2> /dev/null

zip: clear
	mkdir -p $(USER)_exo1
	cp Makefile *.c *.h $(USER)_exo1
	tar czf $(USER)_exo1.tgz $(USER)_exo1
	rm -rf $(USER)_exo1
