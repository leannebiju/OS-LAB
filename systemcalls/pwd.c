//code to execute execlp system call in LINUX using C
//code to display the current path

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
	execlp("pwd", "pwd", NULL);
}