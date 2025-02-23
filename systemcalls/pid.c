#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
	printf("Parent process id : %d", getppid());
	printf("\nChild process id : %d", getpid());
	return 1;
}