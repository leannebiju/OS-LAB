//shows path

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
	execlp("pwd", "pwd", NULL);
}