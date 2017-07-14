CC=gcc
CFLAGS=-Wall -g

all:
	$(CC) sintatic_analyser.c lexic_resolver.c sintatic_resolver.c data_structures.c -o sintatic -lm

table:
	$(CC) hashmap.c -o hash -lm

clean:
	rm -f sintatic hash
