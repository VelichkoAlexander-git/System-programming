CC=gcc

all : Task

Task: TaskThread ts_random
	$(CC) TaskThread.c ts_random.c -o Task -lpthread

TaskThread: TaskThread.c
	$(CC) -c TaskThread.c

ts_random: ts_random.c
	$(CC) -c ts_random.c
