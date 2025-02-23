//program to copy the contents of one file to another 
// ./a.out filename1 filename2 to run the code

#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

#define BUF_SIZE 1024

void main(int argc, char*argv[])
{
		int source_fd = open(argv[1],O_RDONLY);
		int dest_fd = open(argv[2],O_WRONLY|O_CREAT|O_TRUNC, 0644);
		if (source_fd == -1 || dest_fd == -1)
			return;
		char buffer[BUF_SIZE];
		ssize_t bytes_read, bytes_written;
		
		while((bytes_read = read(source_fd, buffer, BUF_SIZE)) > 0)
		{
			bytes_written = write(dest_fd, buffer, bytes_read);
			if (bytes_written != bytes_read)
				return;
		}
		
		if (bytes_read == -1)
			return;
		
		close(source_fd);
		close(dest_fd);
		printf("file copied successfully");
		return;
}