.PHONY: build run test clean

CC=gcc
CFLAGS=-std=c11 -O2 -Wall
LDFLAGS=-lm

build:
	$(CC) $(CFLAGS) calculator.c -o calculator $(LDFLAGS)

run: build
	./calculator

test: build
	bash tests/run_tests.sh

clean:
	rm -f calculator
