.PHONY: all clean test

CC=gcc

all : Task

Task: InMemory FromMemory
	$(CC) InMemory.o -o InMemory
	$(CC) FromMemory.o -o FromMemory

InMemory: InMemory.c
	$(CC) InMemory.c -o -с InMemory.o

FromMemory: FromMemory.c
	$(CC) FromMemory.c -o -c FromMemory.o

test: Task
	./InMemory
	./FromMemory
