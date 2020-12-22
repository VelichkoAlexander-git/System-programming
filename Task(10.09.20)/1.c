#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
 
#define SIZE 5
 
int main(void)
{
	char *arr_strs[SIZE] = {
		"helicopter",
		"cat",
		"dog",
		"red",
		"watermelon"
	};
 
	int f = 1;
	while(f)
	{
		f = 0;
		for(int i = 0; i < SIZE-1; i++)
		{
			if(*arr_strs[i] > *arr_strs[i+1])
			{
				char *t = arr_strs[i];
				arr_strs[i] = arr_strs[i+1];
				arr_strs[i+1] = t;
 
				f = 1;
			}
		}
	}
 
	for(int i = 0; i < SIZE; i++)
	{
		printf("%s\n", arr_strs[i]);
	}
 
	return 0;
}
