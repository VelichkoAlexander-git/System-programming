#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define RefRate 500000

void printTree(int);
void printLog(int);

int main()
{
	srand(time(NULL));
	int ht = 9;

	printf("\n*** CHRISTMAS TREE ***\n\n");
	
	while(1)
	{
		system("@cls||clear");
		printTree(ht);
		printLog(ht);
		usleep(RefRate);
	}

	return(0);
}

void Reset()
{
	printf("\033[0m");
}
void Brown()
{
	printf("\033[0;33m");
}
void Green()
{
	printf("\033[0;32m");
}
void Color(char str[])
{
	printf("%s", str);
}

void printRandLeaf()
{
	char leafTypes[5] = {'.','*','+','o','0'};
	char *colorTypes[4] = {"\033[0;31m","\033[0;34m","\033[0;35m","\033[1;33m"};
	int temp = rand() % 5;

	if (temp == 1)
	{
		Color(colorTypes[rand() % 4]);
		printf("%c", leafTypes[rand() % 5]);
		Reset();
	}
	else
	{
		Green();
		printf("%c", leafTypes[1]);
		Reset();
	}
}

void triangle(int f, int n, int toth)
{
	int k = 2 * toth - 2;

	for (int i = 0; i < f - 1; i++)
		k--;

	for (int i = f - 1; i < n; i++)
	{
		for (int j = 0; j < k; j++)
		{
			printf(" ");
		}

		k = k-1;
		
		for (int j = 0; j <=2*i; j++)
		{
			printRandLeaf();
		}
		
		printf("\n");
	}
}

void printTree(int h)
{
	int start = 1;
	int stop = 0;
	int diff = 3;
	
	while(stop < h + 1)
	{
		stop = start + diff;
		triangle(start, stop, h);
		diff++;
		start = stop - 2;
	}
	Reset();
}

void printLog (int n)
{
	int k = 2*n-4;
	Brown();
	for (int i = 1; i <= 6; i++)
	{
		for (int j = 0; j < k; j++)
		{
			printf(" ");
		}

		for (int j = 1; j <= 5; j++)
		{
			printf("#");
		}

		printf("\n");
	}
	Reset();
}
