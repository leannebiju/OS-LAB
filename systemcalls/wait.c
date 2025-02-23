//code to execute wait system call in LINUX using C

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

void main()
{
	pid_t pid = fork();
	if(pid == -1)
		perror("fork failed");
	else if(pid == 0)
		printf("child process exists\n");
	else
	{
		printf("child process begins\n");
		wait(NULL);
		printf("child process ends\n");
	}
}