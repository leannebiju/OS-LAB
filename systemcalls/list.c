//code to execute execlp system call in LINUX using C
//code to list the files in working directory

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
	//use one execlp at a time
	//display along with permissions
	//execlp("ls", "ls", "-la", NULL);
	//display only the file names without permissions and date created etc
	execlp("ls", "ls", NULL);
}