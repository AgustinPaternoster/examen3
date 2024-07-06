#include <stdio.h>

int printt(int n)
{
	int i = 0;
	int r = 3;
	while (i < n)
	{
		printf("%d", i);
		r++;
	}
	return r;
}


int main (void)
{
	char *str = "123";
	printf("%c",str[1]);
}
