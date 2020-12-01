#include <stdio.h>
#include <aio.h>
#include <time.h>
#include <stdlib.h>
#include <errno.h>

const int LENGTH = 150000000;

void GenerateChar(char *ch)
{
	srand(time(NULL));
	for(int i = 0; i < LENGTH; i++)
	{
		ch[i] = 'a' + rand() % 26;
	}
}

void OutputOnDisplay(struct aiocb *op)
{
	struct timespec tw = {0,200000000};
	int i = 0;
	char spin[] = "\\|/-";
	printf(" ");
	while(aio_error(op) == EINPROGRESS)
	{
		printf("\r%c loading...", spin[i]);
		fflush(stdout);
		i = (i+1)%4;
		nanosleep(&tw, NULL);
	}
	printf("\n");
}

int main()
{
	char *CONTENT = calloc(LENGTH,sizeof(char));
	GenerateChar(CONTENT);
	FILE *file = fopen("outfile.txt", "w");
	int fd = fileno(file);
	struct aiocb op;
		op.aio_fildes = fd;
		op.aio_offset = 0;
		op.aio_buf = CONTENT;
		op.aio_nbytes = LENGTH;
	int ret = aio_write(&op);
	OutputOnDisplay(&op);
	fseek(file, 0L, SEEK_END);
	printf("%ld bytes\n", aio_return(&op));
	fclose(file);
}
