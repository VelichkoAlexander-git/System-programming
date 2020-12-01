#include<stdio.h>
#include<signal.h>
#include<unistd.h>

void handle_alarm(int var)
{
	puts("Hello World \n");
	_Exit(0);
}

int main(int argc, char *argv[])
{
	unsigned int time = atoi(argv[1]);
	signal(SIGALRM, handle_alarm);
	alarm(time);

	while(1) {}
	return 0;
}
