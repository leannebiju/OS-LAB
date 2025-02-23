//to create processes in the hierarchy parent - child1 - child2 - child3 using recursion

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void create(int l)
{
	if(l>3)
	{
		return;
	}
	pid_t pid = fork();
	if(pid<0)
	{
		perror("fork failed");
		return;
	}
	else if(pid == 0)
	{
		printf("\nParent process id : %d", getppid());
		printf("\nChild process id : %d", getpid());
		sleep(1);
		create(l+1);
	}
	else
	{
		wait(NULL);
	}
}

void main()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	create(1);
	return;
}