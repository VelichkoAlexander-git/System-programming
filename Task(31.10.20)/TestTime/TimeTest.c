#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	if (argc != 3) return 1;
	char *Name = argv[1];
	char *Path = argv[2];

	struct timespec mt1, mt2;
	long int tt;

	clock_gettime(CLOCK_REALTIME, &mt1);
	system(Path);
	clock_gettime(CLOCK_REALTIME, &mt2);

	tt = 1000000000*(mt2.tv_sec - mt1.tv_sec)+(mt2.tv_nsec - mt1.tv_nsec);

	printf("TIME TEST\nName : %s\nTime : %ld nsec\n", Name, tt);

	return 0;
}
