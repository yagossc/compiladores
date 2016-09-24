CC=gcc
CFLAGS=-Wall -g

all:
	$(CC) scanner.c resolver.c  -o scanner -lm

table:
	$(CC) hashmap.c -o hash -lm

clean:
	rm -f scanner hash
