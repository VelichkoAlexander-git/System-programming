#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

double ts_random();
void *MonteKarlo(void *min_a);

int Ncirc = 0;
int Nmax = 100000;
int CountThreads = 1;

pthread_mutex_t lock;

int main(int argc, char *argv[])
{
	CountThreads = atoi(argv[1]);

	if (CountThreads < 0)
	{
		printf("Arg %d < 0\n", CountThreads);
		return -1;
	}

	pthread_t thread[CountThreads];
	pthread_mutex_init(&lock, NULL);

	for (int i = 0; i < CountThreads; i++)
	{
		if (pthread_create(&thread[i], NULL, MonteKarlo, NULL) != 0)
		{
			printf("Creating thread %d failed\n", i);
			return 1;
		}
	}

	for (int i = 0; i < CountThreads; i++)
	{
		if (pthread_join(thread[i], NULL) != 0)
		{
			printf("Joing thread %d failed",i);
			return 1;
		}
	}

	pthread_mutex_destroy(&lock);

	double result = (Ncirc/(double)Nmax)*4;
	printf("Pi = %f\n", result);
	
	return 0;
}

void *MonteKarlo(void *min_a)
{
	double x;
	double y;
	double _Nmax = (double)(Nmax/CountThreads);
	int i = 0;

	while (i < _Nmax)
	{
		x = ts_random();
		y = ts_random();
		if (x*x + y*y < 1)
		{
			pthread_mutex_lock(&lock);
			Ncirc++;
			pthread_mutex_unlock(&lock);
		}
		i++;
	}

	pthread_exit(NULL);
}
