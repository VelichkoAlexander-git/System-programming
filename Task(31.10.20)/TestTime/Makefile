.PHONY: all clean test

CC=gcc

all : TaskV1 TaskV2 TimeTest

TaskV1: TaskThreadV1 ts_random
	$(CC) TaskThreadV1.c ts_random.c -o TaskV1 -lpthread

TaskV2: TaskThreadV2 ts_random
	$(CC) TaskThreadV2.c ts_random.c -o TaskV2 -lpthread 

TaskThreadV1: TaskThreadV1.c
	$(CC) -c TaskThreadV1.c

TaskThreadV2: TaskThreadV2.c
	$(CC) -c TaskThreadV2.c

ts_random: ts_random.c
	$(CC) -c ts_random.c

TimeTest: TimeTest.c
	$(CC) TimeTest.c -o TimeTest -lrt

clean: 
	-rm *.o $(objects)

test: clean
	./TimeTest V1 "./TaskV1 10"
	./TimeTest V2 "./TaskV2 10"

