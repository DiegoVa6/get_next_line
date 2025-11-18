#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static void test_single_file(const char *filename)
{
    int   fd;
    char *line;
    int   i = 1;

    fd = open(filename, O_RDONLY);
    if (fd < 0)
    {
        perror("open");
        return;
    }
    printf("=== Reading file: %s ===\n", filename);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("line %d: %s", i, line);
        free(line);
        i++;
    }
    close(fd);
    printf("=== End of file ===\n\n");
}

static void test_stdin(void)
{
    char *line;
    int   i = 1;

    printf("=== Reading from stdin (Ctrl+D to end) ===\n");
    while ((line = get_next_line(STDIN_FILENO)) != NULL)
    {
        printf("stdin line %d: %s", i, line);
        free(line);
        i++;
    }
    printf("=== End of stdin ===\n\n");
}

static void test_multi_fd(void)
{
    int   fd1, fd2, fd3;
    char *line;

    fd1 = open("tests/test1.txt", O_RDONLY);
    fd2 = open("tests/test2.txt", O_RDONLY);
    fd3 = open("tests/test3.txt", O_RDONLY);
    if (fd1 < 0 || fd2 < 0 || fd3 < 0)
    {
        perror("open");
        return;
    }
    printf("=== Multi-fd test (bonus) ===\n");

    line = get_next_line(fd1);
    printf("fd1: %s", line); free(line);
    line = get_next_line(fd2);
    printf("fd2: %s", line); free(line);
    line = get_next_line(fd3);
    printf("fd3: %s", line); free(line);

    line = get_next_line(fd1);
    printf("fd1: %s", line); free(line);
    line = get_next_line(fd2);
    printf("fd2: %s", line); free(line);
    line = get_next_line(fd3);
    printf("fd3: %s", line); free(line);

    close(fd1);
    close(fd2);
    close(fd3);
    printf("=== End of multi-fd test ===\n\n");
}

int main(int argc, char **argv)
{
    if (argc == 2)
        test_single_file(argv[1]);
    else
        test_stdin();

    /* Prueba opcional del bonus con varios fds */
    test_multi_fd();
    return 0;
}

