#include<stdio.h>
#include<signal.h>
#include<unistd.h>

void mysleep(unsigned int*);

void main(int argc, char *argv[])
{
	unsigned int time = atoi(argv[1]);

	mysleep(&time);

	printf("Hello World\n");
	return 0;
}
