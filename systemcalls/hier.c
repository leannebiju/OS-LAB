//to create processes in the hierarchy parent - child1 - child2 - child3

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
	setvbuf(stdout, NULL, _IONBF, 0); //disabling buffering for stdout
	
	pid_t pid1 = fork();

	if(pid1 == 0)
	{
		printf("\nParent process id : %d", getppid());
		printf("\nChild process id : %d", getpid());
		
		pid_t pid2 = fork();
		
		if(pid2 == 0)
		{
			printf("\nParent process id : %d", getppid());
			printf("\nChild process id : %d", getpid());
			
			pid_t pid3 = fork();
			
			if(pid3 == 0)
			{
				printf("\nParent process id : %d", getppid());
				printf("\nChild process id : %d", getpid());
			}
			else 
				wait(NULL);
		}
		else 
			wait(NULL);
	}
	else
		wait(NULL);
}