#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

int main()
{
	int flags = 0;
	alarm(1);

	while(1)
		printf("++flags %d\t",++flags);

	return 0;
}

