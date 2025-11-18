// tester.c
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

int	main(void)
{
	int fd1, fd2, fd3;
	char *line;

	fd1 = open("test1.txt", O_RDONLY);
	fd2 = open("test2.txt", O_RDONLY);
	fd3 = open("test3.txt", O_RDONLY);
	

	line = get_next_line(fd1);
	printf("line 1 fd1: %s", line);
	free(line);
	line = get_next_line(fd2);
	printf("line 1 fd2: %s", line);
	free(line);
	line = get_next_line(fd3);
	printf("line 1 fd3: %s", line);
	free(line);

	line = get_next_line(fd1);
	printf("line 2 fd1: %s", line);
	free(line);
	line = get_next_line(fd2);
	printf("line 2 fd2: %s", line);
	free(line);
	line = get_next_line(fd3);
	printf("line 2 fd3: %s", line);
	free(line);

	return (0);
}
