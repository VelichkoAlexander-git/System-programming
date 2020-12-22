#include <stdio.h>
 
/* remove all 'c' characters from str */
void drop_c(char *str, char c)
{
	int k = 0;
	for(int i = 0; str[i] != '\0'; i++)
	{
		if(str[i] == c)
			continue;
 
		if(k != i)
			str[k] = str[i];

		k++;
	}
	str[k] = '\0';
}
 
int main(int argc, char **argv)
{
	char s[] = "test string a a a";
	drop_c(s, ' ');
 
	printf("%s\n", s);
 
	return 0;
}
