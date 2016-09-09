CC=gcc
CFLAGS=-Wall -g
DIR=src/

all:
	$(CC) scanner.c -o scanner

clean:
	rm -f ex18

